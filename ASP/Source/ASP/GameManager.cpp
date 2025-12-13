// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "ASPCharacter.h"
#include "ASPGameMode.h"
#include "CustomMoveComponent.h"
#include "DynamicCamera.h"
#include "FightingGame_PlayerController.h"
#include "LogicStateMachine.h"
#include "MoveableInterface.h"
#include "StateMachine.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "UFighting_GameGameInstance.h"
#include "Kismet/GameplayStatics.h"

UGameManager::UGameManager(): m_camera(nullptr)
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
	//
	//if (!m_cachedWorld.IsValid())
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("GameManager: World noch nicht verfügbar."));
	//	return;
	//}
	//
	//m_playerController1 = Cast<AFightingGame_PlayerController>(
	//UGameplayStatics::GetPlayerController(m_cachedWorld.Get(), 0));
	//if (m_playerController1)
	//{
	//	m_playerController1->SetMappingContext(GI->DefaultMappingContext_Player1);
	//}
	//
	//if (!m_playerController2)
	//	m_playerController2 = Cast<AFightingGame_PlayerController>(UGameplayStatics::CreatePlayer(m_cachedWorld.Get(),1, true));
	//if (m_playerController2)
	//{
	//	m_playerController2->SetMappingContext(GI->DefaultMappingContext_Player2);
	//}
	m_playerController1 = Cast<AFightingGame_PlayerController>(
	UGameplayStatics::GetPlayerController(m_cachedWorld.Get(), 0));
	m_playerController2 = Cast<AFightingGame_PlayerController>(
	UGameplayStatics::GetPlayerController(m_cachedWorld.Get(), 1));
	if (!m_playerController1 || !m_playerController2)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController(s) existieren noch nicht."));
		m_cachedWorld->GetTimerManager().SetTimerForNextTick([this]()
		{
			BeginPlaySetup();
		});
		return;
	}

	m_playerControllers.Add(m_playerController1);
	m_playerControllers.Add(m_playerController2);
	
	m_player1 = m_playerController1->GetPlayer();
	m_player2 = m_playerController2->GetPlayer();

	//else
	//{
	//	m_playerController2->GetLocalPlayer()->ViewportClient->SetForceDisableSplitscreen(true);
	//}
	//m_playerController1->SetPlayerID(0);
	//m_playerController2->SetPlayerID(1);
	//
	//// Spawn Characters
	//SpawnCharacterForController(m_playerController1, m_player1, m_player1Position, m_player1Rotation);
	//SpawnCharacterForController(m_playerController2, m_player2, m_player2Position, m_player2Rotation);
	//
	//InitializeFighters(m_player1, m_playerController1);
	//InitializeFighters(m_player2, m_playerController2);
	//
	//m_player1->Start();
	//m_player2->Start();
	//UE_LOG(LogTemp, Warning, TEXT("GetPlayer1(): m_player1 ist %s"), *m_playerController1->GetPlayer()->GetName());
	//UE_LOG(LogTemp, Log, TEXT("GameManager: Beide Spieler initialisiert"));
}

void UGameManager::AddInputToQueue(AFightingGame_PlayerController* _playerController, const FInputPacket& _packet)
{
	TMap<int32, FInputPacket>& playerMap = m_playerInputQueues.FindOrAdd(_playerController);
	playerMap.Add(_packet.FrameNumber, _packet);
	
	const int32 MaxHistory = 240; // 4 Sekunden bei 60fps
	if (playerMap.Num() > MaxHistory)
	{
		int32 OldestFrame = playerMap.begin()->Key;
		playerMap.Remove(OldestFrame);
	}
}

const FInputPacket* UGameManager::GetInputQueueAtFrame(AFightingGame_PlayerController* _pc, int _frameNumber) const
{
	const TMap<int32, FInputPacket>* playerMap = m_playerInputQueues.Find(_pc);
	if (!playerMap)
		return nullptr;

	return playerMap->Find(_frameNumber);
}

void UGameManager::ProcessInputs()
{
	const int32 CurrentFrame = FrameNumber; // dein GameManager Frame Counter

	for (auto& pair : m_playerInputQueues)
	{
		AFightingGame_PlayerController* player = pair.Key;
//
		const FInputPacket* packet = GetInputQueueAtFrame(player, FrameNumber);
		if (!packet)
			continue;
//
		EInputAction action = CheckForCombo(player, FrameNumber);
		if (action == EInputAction::None)
			continue;
		
		if (player->GetPlayer())
			player->GetPlayer()->GetLogicStateMachine()->SetAction(action);
//
		if (player->GetPlayer() == m_player2)
			UE_LOG(LogTemp, Warning, TEXT("player %s, Action %d"), *m_player2->GetName(), action);
	}

//const FInputPacket* packet = GetInputQueueAtFrame(m_playerController1, FrameNumber);
//if (!packet)
//	return;
//EInputAction action = CheckForCombo(m_playerController1, FrameNumber);
//if (action == EInputAction::None)
//	return;
//if (m_playerController1->GetPlayer())
//	m_playerController1->GetPlayer()->GetLogicStateMachine()->SetAction(action);


//const FInputPacket* packet1 = GetInputQueueAtFrame(m_playerController2, FrameNumber);
//if (!packet1)
//	return;
//EInputAction action1 = CheckForCombo(m_playerController2, FrameNumber);
//if (action1 == EInputAction::None)
//	return;
//if (m_playerController2->GetPlayer())
//	m_playerController2->GetPlayer()->GetLogicStateMachine()->SetAction(action1);
}

EInputAction UGameManager::CheckForCombo(AFightingGame_PlayerController* _pc, int32 _currentFrame)
{
	constexpr int COMBOWINDOW = 4;

	const TMap<int32, FInputPacket>* playerMap = m_playerInputQueues.Find(_pc);
	if (!playerMap)
		return EInputAction::Idle;

	TArray<EInputAction> recentActions;
	
	for (int32 F = _currentFrame - COMBOWINDOW; F <= _currentFrame; F++)
	{
		const FInputPacket* Packet = playerMap->Find(F);
		if (!Packet)
			continue;
		
		FRawInput raw = InputHandler::DecodeInput(Packet->Buttons);
		EInputAction action = InputHandler::NormalizeInput(raw);

		if (action != EInputAction::Idle)
			recentActions.Add(action);
	}

	if (recentActions.Num() == 0)
		return EInputAction::Idle;

	// ---------- COMBO CHECK ----------
	if (recentActions.Contains(EInputAction::Up))
	{
		if (recentActions.Contains(EInputAction::Attack1)) return EInputAction::UpAttack1;
		if (recentActions.Contains(EInputAction::Attack2)) return EInputAction::UpAttack2;
	}

	if (recentActions.Contains(EInputAction::Jump))
	{
		if (recentActions.Contains(EInputAction::Attack1)) return EInputAction::JumpAttack1;
		if (recentActions.Contains(EInputAction::Attack2)) return EInputAction::JumpAttack2;
	}

	if (recentActions.Contains(EInputAction::Crouch))
	{
		if (recentActions.Contains(EInputAction::Attack1)) return EInputAction::LowAttack1;
		if (recentActions.Contains(EInputAction::Attack2)) return EInputAction::LowAttack2;
	}

	// sonst: letzter Action
	return recentActions.Last();
}

void UGameManager::PerformRollback(int32 _targetFrame)
{
	if (_targetFrame < 0 || _targetFrame >= FrameNumber)
	{
		UE_LOG(LogTemp, Warning, TEXT("Rollback: Ungültiger Ziel-Frame %d"), _targetFrame);
		return;
	}

	TArray<AASPCharacter*> players;
	if (m_player1) players.Add(m_player1);
	if (m_player2) players.Add(m_player2);

	RollbackManager.RollbackToFrame(_targetFrame, players);

	for (AASPCharacter* player : players)
	{
		if (!player) continue;

		FInputPacket restoredInput;
		RollbackManager.LoadFrame(_targetFrame, player, restoredInput);
		//maybe enter state einfügen
		FRawInput raw = InputHandler::DecodeInput(restoredInput.Buttons);
		EInputAction action = InputHandler::NormalizeInput(raw);
		player->GetLogicStateMachine()->SetAction(action);
	}

	//simulate forward
	for (int32 frame = _targetFrame + 1; frame <= FrameNumber; ++frame)
	{
		for (AASPCharacter* player : players)
		{
			if (!player) continue;

			FInputPacket replayInput;
			RollbackManager.LoadFrame(frame, player, replayInput);

			FRawInput raw = InputHandler::DecodeInput(replayInput.Buttons);
			EInputAction action = InputHandler::NormalizeInput(raw);
			player->GetLogicStateMachine()->SetAction(action);
			player->FixedUpdate(FIXED_UPDATE_RATE);
		}
	}
}

void UGameManager::SaveCurrentFrame(AASPCharacter* _player)
{
	if (!_player) return;

	//const TArray<FInputPacket>& queue1 = m_playerInputQueues.FindOrAdd(m_playerController1);
	//const TArray<FInputPacket>& queue2 = m_playerInputQueues.FindOrAdd(m_playerController2);

	//FInputPacket input1 = queue1.Num() > 0 ? queue1.Last() : FInputPacket();
	//FInputPacket input2 = queue2.Num() > 0 ? queue2.Last() : FInputPacket();

	//if (m_player1)
	//{
	//	RollbackManager.SaveFrame(FrameNumber, m_player1, input1);
	//}
	//if (m_player2)
	//{
	//	RollbackManager.SaveFrame(FrameNumber, m_player2, input2);
	//}
}

void UGameManager::RotateCharacters(AASPCharacter* _playToRotate, AASPCharacter* _enemy)
{
	if (!_playToRotate || !_enemy || !_playToRotate->GetNoChaosMovementComponent()) return;
	if (!_playToRotate->GetNoChaosMovementComponent()->GetBoolOnGround() && !_enemy->GetNoChaosMovementComponent()->GetBoolOnGround()) return;
	float diff = _playToRotate->GetActorLocation().Y - _enemy->GetActorLocation().Y;

	if (diff < 0)
		_playToRotate->LookRight();
	else
		_playToRotate->LookLeft();

	_playToRotate->Rotate();
}


void UGameManager::FixedGameUpdate60Hz(float _fixedDeltatime)
{
	if (FrameNumber > 60)
	{
		FrameNumber = 0;
		return;
	}
	if (m_player1 && m_player2)
	{
		RotateCharacters(m_player1, m_player2);
		RotateCharacters(m_player2, m_player1);
	}
	if (m_camera)
	{
		m_camera->Update(_fixedDeltatime);
	}
	
	//GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow,
	//  FString::Printf(TEXT("Frame: %d | Player1: %s | Player2: %s"),
	//  FrameNumber,
	//  *GetNameSafe(Player1),
	//  *GetNameSafe(Player2)));
	
	if (m_camera)
	{
		if (m_player1)
		{
			m_player1->SetCanMoveBackwards(m_camera->characterMaxDistanceAlloToMove());
		}
		if (m_player2)
		{
			m_player2->SetCanMoveBackwards(m_camera->characterMaxDistanceAlloToMove());
		}
	}
	for (auto& movable : m_movables)
	{
		if (movable)
		{
			movable->FixedUpdate(_fixedDeltatime);
		}
	}
	ProcessInputs();
	//if (m_player1)
	//	SaveCurrentFrame(m_player1);
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
	m_camera = Cast<ADynamicCamera>(UGameplayStatics::GetActorOfClass(_world, ADynamicCamera::StaticClass()));

	m_cachedWorld->GetTimerManager().SetTimerForNextTick([this]()
	{
		BeginPlaySetup();
	});
}

