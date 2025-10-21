// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "ASPCharacter.h"
#include "DynamicCamera.h"
#include "FightingGame_PlayerController.h"
#include "MoveableInterface.h"
#include "StateMachine.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "UFighting_GameGameInstance.h"
#include "Kismet/GameplayStatics.h"

UGameManager::UGameManager(): GI(nullptr), m_camera(nullptr)
{
}

void UGameManager::Initialize(FSubsystemCollectionBase& _collection)
{
	Super::Initialize(_collection);

	FWorldDelegates::OnPostWorldInitialization.AddUObject(
		this,
		&UGameManager::OnWorldInitialization
	);
}

void UGameManager::Deinitialize()
{
	Super::Deinitialize();

	FWorldDelegates::OnPostWorldInitialization.RemoveAll(this);

	if (m_cachedWorld.IsValid())
	{
		m_cachedWorld = nullptr;
	}
}

void UGameManager::Tick(float _deltaTime)
{
	m_accumulatedTime += _deltaTime;
	while (m_accumulatedTime >= FIXED_UPDATE_RATE)
	{
		FixedGameUpdate60Hz(FIXED_UPDATE_RATE);
		m_accumulatedTime -= FIXED_UPDATE_RATE;
	}
}

void UGameManager::BeginPlaySetup()
{

	GI = Cast<UFighting_GameGameInstance>(GetGameInstance());
	if (!GI)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnCharacterForController: GameInstance ist NULL!"));
		return;
	}
	
	if (!m_cachedWorld.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("GameManager: World noch nicht verfügbar."));
		return;
	}

	// PlayerController 
	m_playerController1 = Cast<AFightingGame_PlayerController>(
		UGameplayStatics::GetPlayerController(m_cachedWorld.Get(), 0)
	);

	m_playerController2 = Cast<AFightingGame_PlayerController>(
		UGameplayStatics::GetPlayerController(m_cachedWorld.Get(), 1)
	);

	if (!m_playerController1 /* || !m_playerController2*/)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController(s) existieren noch nicht."));
		// Try aigan
		m_cachedWorld->GetTimerManager().SetTimerForNextTick([this]()
		{
			BeginPlaySetup();
		});
		return;
	}
	m_playerController1->SetPlayerID(0);
	//m_playerController2->SetPlayerID(1);

	// Spawn Characters
	SpawnCharacterForController(m_playerController1, m_player1, m_player1Position, m_player1Rotation);
	//SpawnCharacterForController(m_playerController2, m_player2, m_player2Position, m_player2Rotation);

	InitializeFighters(m_player1, m_playerController1);
	//InitializeFighters(m_player2, m_playerController2);

	UE_LOG(LogTemp, Log, TEXT("GameManager: Beide Spieler initialisiert"));
}

void UGameManager::AddInputToQueue(AFightingGame_PlayerController* _playerController, const FInputPacket& _packet)
{
	int32 PlayerIndex = _playerController->GetPlayer()->GetPlayerID();
	TArray<FInputPacket>& queue = m_playerInputQueues.FindOrAdd(PlayerIndex);

	queue.Add(_packet);
	if (queue.Num() > 60)
	{
		queue.RemoveAt(0);
	}
}

const TArray<FInputPacket>& UGameManager::GetInputQueue(int _playerIndex) const
{
	return m_playerInputQueues[_playerIndex];
}

void UGameManager::ProcessInputs()
{
	for (auto& pair : m_playerInputQueues)
	{
		int PlayerIndex = pair.Key;
		EAction action = CheckForCombo(PlayerIndex);
		if (action == EAction::None)
			continue;
		UE_LOG(LogTemp, Warning, TEXT("SetAction: %d"), action);
		AASPCharacter* character = (PlayerIndex == 0) ? GetPlayer1() : GetPlayer2();
		if (character)
			character->GetStateMachine()->SetAction(action);
	}
}

EAction UGameManager::CheckForCombo(int _playerIndex)
{
	constexpr int COMBOWINDOW = 4;

	const TArray<FInputPacket>* queuePtr = m_playerInputQueues.Find(_playerIndex);
	if (!queuePtr || queuePtr->Num() < 2)
	{
		return EAction::Idle;
	}

	const TArray<FInputPacket>& queueRef = *queuePtr;
	int32 startIndex = FMath::Max(0, queueRef.Num() - COMBOWINDOW);

	TArray<EAction> recentActions;
	for (int32 i = startIndex; i < queueRef.Num(); i++)
	{
		FRawInput raw = InputHandler::DecodeInput(queueRef[i].Buttons);
		EAction action = InputHandler::NormalizeInput(raw);
		if (action != EAction::Idle)
		{
			recentActions.Add(action);
		}
	}

	if (recentActions.Contains(Up))
	{
		if (recentActions.Contains(Attack1)) return UpAttack1;
		if (recentActions.Contains(Attack2)) return UpAttack2;
	}
	if (recentActions.Contains(Jump))
	{
		if (recentActions.Contains(Attack1)) return JumpAttack1;
		if (recentActions.Contains(Attack2)) return JumpAttack2;
	}
	if (recentActions.Contains(Crouch))
	{
		if (recentActions.Contains(Attack1)) return LowAttack1;
		if (recentActions.Contains(Attack2)) return LowAttack2;
	}

	return recentActions.Num() > 0 ? recentActions.Last() : EAction::Idle;
}

void UGameManager::FixedGameUpdate60Hz(float _fixedDeltatime)
{
	if (FrameNumber > 60)
	{
		FrameNumber = 0;
		return;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow,
	//  FString::Printf(TEXT("Frame: %d | Player1: %s | Player2: %s"),
	//  FrameNumber,
	//  *GetNameSafe(Player1),
	//  *GetNameSafe(Player2)));

	for (auto& movable : m_movables)
	{
		if (movable)
		{
			movable->FixedUpdate(_fixedDeltatime);
			ProcessInputs();
		}
	}

	FrameNumber++;
}

void UGameManager::RegisterMovable(TScriptInterface<IMoveableInterface> _movable)
{
	m_movables.Add(_movable);
}

void UGameManager::OnWorldInitialization(UWorld* _world, const UWorld::InitializationValues _ivs)
{
	if (!_world || !_world->IsGameWorld()) return;

	m_cachedWorld = _world;	
	m_camera = UGameplayStatics::GetActorOfClass(_world, ADynamicCamera::StaticClass());
}

void UGameManager::SpawnCharacterForController(AFightingGame_PlayerController* _pc, 
											   AASPCharacter*& _outCharacter, 
											   const FVector& _spawnPos, const FRotator& _spawnRot)
{
	if (!_pc || !GI)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnCharacterForController: PlayerController oder GameInstance ist NULL!"));
		return;
	}

	if (!GI->SelectedPlayer1Class || !GI->SelectedPlayer2Class)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnCharacterForController: CharacterClasses sind NULL!"));
		return;
	}

	TSubclassOf<AASPCharacter> classToSpawn = (_pc->GetPlayerID() == 0) ? GI->SelectedPlayer1Class : GI->SelectedPlayer2Class;

	_outCharacter = m_cachedWorld->SpawnActor<AASPCharacter>(classToSpawn, _spawnPos, _spawnRot);

	if (!_outCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("GameManager: Character konnte nicht gespawnt werden!"));
		return;
	}

	_pc->SetCharacterRef(_outCharacter);
	_pc->SetGameManager(this);
	_pc->Start();
}

void UGameManager::InitializeFighters(AASPCharacter* _character, AFightingGame_PlayerController* _pc)
{
	if (!_character || !_pc) return;

	FFightingStateMachine* fsm = _character->GetStateMachine();
	if (!fsm) return;

	fsm->SetPlayerController(_pc);
	_character->SetPlayerController(_pc);
	_pc->ResetInputBuffer();
	//_character->SetHealth(_character->GetMaxHealth());
}