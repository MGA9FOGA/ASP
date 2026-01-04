// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "ASPCharacter.h"

#include "DynamicCamera.h"
#include "FightingGame_PlayerController.h"

#include "Engine/World.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "UPushBoxComponent.h"

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

	FrameNumber = 0;
	m_accumulatedTime = 0.0;
}

void UGameManager::Deinitialize()
{
	FWorldDelegates::OnPostWorldInitialization.RemoveAll(this);
	Super::Deinitialize();
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

void UGameManager::BeginPlaySetup()
{
	if (!m_cachedWorld.IsValid())
		return;
}

void UGameManager::Tick(float _deltaTime)
{
	if (!GetWorld() || !GetWorld()->IsGameWorld())
		return;

	m_accumulatedTime += _deltaTime;
	while (m_accumulatedTime >= FIXED_UPDATE_RATE)
	{
		FixedGameUpdate60Hz(FIXED_UPDATE_RATE);
		m_accumulatedTime -= FIXED_UPDATE_RATE;
	}
	RenderUpdate(m_accumulatedTime / FIXED_UPDATE_RATE);

	if (m_playerController1 && m_playerController2)
	{
		m_playerController1->Update(_deltaTime);
		m_playerController2->Update(_deltaTime);
	}
}

void UGameManager::FixedGameUpdate60Hz(double _fixedDeltatime)
{
	FGameState newState;
	newState.FrameNumber = FrameNumber;

	// =============================
	// INPUT
	// =============================
	BuildFrameInput(newState.FrameNumber, newState);

	// =============================
	// COPY PREVIOUS STATE
	// =============================
	newState.P1 = m_currentGameState.P1;
	newState.P2 = m_currentGameState.P2;

	// =============================
	// Character Movelimit
	// =============================
	if (m_camera)
	{
		if (m_player1)
		{
			CheckBackMovement(newState.P1);
		}
		if (m_player2)
		{
			CheckBackMovement(newState.P2);
		}
	}

	m_movementSimP1.UpdateLogic(newState.P1, newState.P1Input, _fixedDeltatime);
	m_movementSimP2.UpdateLogic(newState.P2, newState.P2Input, _fixedDeltatime);

	// =============================
	// MOVEMENT
	// =============================
	m_movementSimP1.UpdateMovement(newState.P1,newState.P2, _fixedDeltatime);
	m_movementSimP2.UpdateMovement(newState.P2,newState.P1, _fixedDeltatime);

	// =============================
	// PUSHBOX
	// =============================
	//m_movementSimP1.ResolvePush(newState.P1, newState.P2);
	//m_movementSimP2.ResolvePush(newState.P2, newState.P1);

	// =============================
	// FACING
	// =============================
	m_movementSimP1.UpdateFacing(newState.P1, newState.P2);
	m_movementSimP2.UpdateFacing(newState.P2, newState.P1);

	// =============================
	// SAVE FOR ROLLBACK
	// =============================
	//RollbackManager.SaveState(NewState);

	// =============================
	// APPLY
	// =============================
	m_currentGameState = newState;
	FrameNumber++;
}

void UGameManager::RenderUpdate(double _fixedDeltatime)
{
	if (!m_player1 || !m_player2)
		return;


	if (m_visualP1 && m_visualP2)
	{
		m_visualP1->UpdateAnimation(m_currentGameState.P1, m_currentGameState.P1Input, FIXED_UPDATE_RATE);
		m_visualP2->UpdateAnimation(m_currentGameState.P2, m_currentGameState.P2Input, FIXED_UPDATE_RATE);

		m_visualP1->ApplyAnimation(m_currentGameState.P1);
		m_visualP1->ApplyState(m_currentGameState.P1);

		m_visualP2->ApplyAnimation(m_currentGameState.P2);
		m_visualP2->ApplyState(m_currentGameState.P2);
	}

	// =============================
	// RESET ONE FRAME FLAGS
	// =============================
	m_currentGameState.P1.bAnimLanded = false;
	m_currentGameState.P1.bAnimJumpStartupFinished = false;
	m_currentGameState.P1.AnimCommand = EAnimCommand::None;

	m_currentGameState.P2.bAnimLanded = false;
	m_currentGameState.P2.bAnimJumpStartupFinished = false;
	m_currentGameState.P2.AnimCommand = EAnimCommand::None;

	// =============================
	// Camera Movement
	// =============================
	if (m_camera)
	{
		m_camera->Update(_fixedDeltatime);
	}
}

void UGameManager::CheckBackMovement(FCharacterState& _state) const
{
	_state.bCanMoveBackwards = m_camera->characterMaxDistanceAlloToMove();
}

void UGameManager::BuildFrameInput(int64 _frame, FGameState& _outState)
{
	_outState.P1Input = BuildPlayerInput(m_playerController1, _frame);
	_outState.P2Input = BuildPlayerInput(m_playerController2, _frame);
}

FFrameInput UGameManager::BuildPlayerInput(AFightingGame_PlayerController* _pc, int64 _frame)
{
	FFrameInput result;
	result.Buttons = 0;
	result.Action = EInputAction::None;

	if (!_pc)
	{
		return result;
	}

	const FInputPacket* Packet = GetInputQueueAtFrame(_pc, _frame);
	if (!Packet)
	{
		return result;
	}

	result.Buttons = Packet->Buttons;
	result.Action = CheckForCombo(_pc, _frame);
	return result;
}

void UGameManager::RegisterPlayer(int32 _playerIndex, AASPCharacter* _character,
                                  AFightingGame_PlayerController* _controller, FVector _location, float _yaw)
{
	if (!_character || !_controller)
		return;

	if (_playerIndex == 0)
	{
		m_player1 = _character;
		m_playerController1 = _controller;
		m_visualP1 = MakeUnique<FCharacterVisual>(
			m_movementSimP1.LogicMachine, *_character
		);

		// === Initial GameState ===
		if (m_player1)
		{
			m_currentGameState.P1.Position = _location;
			m_currentGameState.P1.Yaw = _yaw;
			m_currentGameState.P1.Facing = 1;
			m_currentGameState.P1.PushboxHalfWidth = m_player1->GetPushBox()->GetHalfWidth();
		}
	}
	else
	{
		m_player2 = _character;
		m_playerController2 = _controller;
		m_visualP2 = MakeUnique<FCharacterVisual>(
			m_movementSimP2.LogicMachine, *_character
		);

		// === Initial GameState ===
		if (m_player2)
		{
			m_currentGameState.P2.Position = _location;
			m_currentGameState.P2.Yaw = _yaw;
			m_currentGameState.P2.Facing = -1;
			m_currentGameState.P2.PushboxHalfWidth = m_player2->GetPushBox()->GetHalfWidth();
		}
	}
}

void UGameManager::AddInputToQueue(AFightingGame_PlayerController* _playerController, const FInputPacket& _packet)
{
	TMap<int32, FInputPacket>& playerMap = m_playerInputQueues.FindOrAdd(_playerController);
	playerMap.Add(_packet.FrameNumber, _packet);

	const int32 MaxHistory = 120; // 2 Sekunden bei 60fps
	const int32 minFrame = _packet.FrameNumber - MaxHistory;

	TArray<int32> keysToRemove;
	for (const auto& Elem : playerMap)
	{
		if (Elem.Key < minFrame)
		{
			keysToRemove.Add(Elem.Key);
		}
	}

	for (int32 Key : keysToRemove)
	{
		playerMap.Remove(Key);
	}
}

const FInputPacket* UGameManager::GetInputQueueAtFrame(AFightingGame_PlayerController* _pc, int _frameNumber) const
{
	const TMap<int32, FInputPacket>* playerMap = m_playerInputQueues.Find(_pc);

	if (!playerMap)
	{
		return nullptr;
	}

	const FInputPacket* packet = playerMap->Find(_frameNumber);

	return packet;
}

EInputAction UGameManager::CheckForCombo(AFightingGame_PlayerController* _pc, int32 _currentFrame)
{
	constexpr int COMBOWINDOW = 4;

	const TMap<int32, FInputPacket>* playerMap = m_playerInputQueues.Find(_pc);
	if (!playerMap)
		return EInputAction::Idle;

	TArray<EInputAction> recentActions;

	for (int32 F = _currentFrame - COMBOWINDOW; F <= _currentFrame; ++F)
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
	return recentActions.Last();
}

void UGameManager::ApplyGameStateToActors(const FGameState& _state)
{
	if (m_player1)
	{
		m_player1->SetActorLocation(_state.P1.Position);
		m_player1->SetActorRotation(FRotator(0, _state.P1.Yaw, 0));
	}

	if (m_player2)
	{
		m_player2->SetActorLocation(_state.P2.Position);
		m_player2->SetActorRotation(FRotator(0, _state.P2.Yaw, 0));
	}
}
