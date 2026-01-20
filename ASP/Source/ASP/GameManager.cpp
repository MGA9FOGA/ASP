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
	m_inputHistory.Empty();
	m_playerInputQueues.Empty();
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

	if (m_bDebugRollbackOnDesync)
	{
		for (auto It = BeforeRollbackStates.CreateIterator(); It; ++It)
		{
			SpawnSnapshotDebug(It.Key(), It.Value(), true, false);
		}
		m_bDebugRollbackOnDesync = false;
	}
	
	m_accumulatedTime += _deltaTime;
	while (m_accumulatedTime >= FIXED_UPDATE_RATE)
	{
		FixedGameUpdate60Hz(FIXED_UPDATE_RATE);
		m_accumulatedTime -= FIXED_UPDATE_RATE;
	}
	RenderUpdate(m_accumulatedTime / FIXED_UPDATE_RATE);
}

void UGameManager::FixedGameUpdate60Hz(double _fixedDeltatime)
{
	FGameState newState;
	newState.FrameNumber = FrameNumber;

	// =============================
	// INPUT
	// =============================
	if (m_playerController1)
		m_playerController1->CommitInput(FrameNumber);

	if (m_playerController2)
		m_playerController2->CommitInput(FrameNumber);
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
	m_movementSimP1.UpdateMovement(newState.P1, newState.P2, _fixedDeltatime);
	m_movementSimP2.UpdateMovement(newState.P2, newState.P1, _fixedDeltatime);

	// =============================
	// FACING
	// =============================
	m_movementSimP1.UpdateFacing(newState.P1, newState.P2);
	m_movementSimP2.UpdateFacing(newState.P2, newState.P1);

	// =============================
	// SAVE FOR ROLLBACK
	// =============================
	m_rollbackManager.SaveFrame(FrameNumber, newState);

	// =============================
	// APPLY
	// =============================
	m_currentGameState = newState;
	LastSimulatedFrame = FrameNumber;
	FrameNumber++;
}

void UGameManager::RenderUpdate(double _fixedDeltatime)
{
	if (!m_player1 || !m_player2)
		return;

	if (m_playerController1)
		m_playerController1->SampleInput();

	if (m_playerController2)
		m_playerController2->SampleInput();

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
	m_visualP1->PostVisualUpdate(m_currentGameState.P1);
	m_visualP2->PostVisualUpdate(m_currentGameState.P2);

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

void UGameManager::BuildFrameInput(int32 _frame, FGameState& _outState)
{
	_outState.P1Input = BuildPlayerInput(m_playerController1, _frame);
	_outState.P2Input = BuildPlayerInput(m_playerController2, _frame);
}

FFrameInput UGameManager::BuildPlayerInput(AFightingGame_PlayerController* _pc, int32 _frame)
{
	TMap<int32, FStoredFrameInput>& history = m_inputHistory.FindOrAdd(_pc);

	// =============================
	// 1. REAL INPUT
	// =============================
	if (const FInputPacket* Packet = GetInputQueueAtFrame(_pc, _frame))
	{
		FFrameInput input;
		input.Buttons = Packet->Buttons;
		input.Action = CheckForCombo(_pc, _frame);

		history.FindOrAdd(_frame) = {
			input,
			false,
			_frame
		};
		return input;
	}

	// =============================
	// 2. Prediction
	// =============================
	constexpr int32 MaxPredictionFrames = 30;
	if (const FStoredFrameInput* last = history.Find(_frame - 1))
	{
		const int32 predictedCount = _frame - last->SourceFrame;

		if (predictedCount > MaxPredictionFrames)
		{
			UE_LOG(LogTemp, Error,
			       TEXT(" Prediction limit reached at frame %d"), _frame);

			FFrameInput empty{};
			history.Add(_frame, {
				            empty,
				            false,
				            _frame
			            });
			return empty;
		}

		FFrameInput predicted = last->Packet;
		if (!history.Contains(_frame))
		{
			UE_LOG(LogTemp, Warning,
			       TEXT("Predicted frame %d (count %d)"), _frame, predictedCount);

			history.Add(_frame, {
				            predicted,
				            true,
				            _frame
			            });
		}
		return predicted;
	}

	// =============================
	// 1. Default
	// =============================
	FFrameInput empty{};
	return empty;
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
			m_movementSimP1.LogicMachine.Start(m_currentGameState.P1);
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
			m_movementSimP2.LogicMachine.Start(m_currentGameState.P2);
		}
	}
}

void UGameManager::AddInputToQueue(AFightingGame_PlayerController* _pc, const FInputPacket& _packet)
{
	TMap<int32, FInputPacket>& playerMap = m_playerInputQueues.FindOrAdd(_pc);
	TMap<int32, FStoredFrameInput>& history = m_inputHistory.FindOrAdd(_pc);
	playerMap.Add(_packet.FrameNumber, _packet);

	if (_packet.FrameNumber > LastSimulatedFrame)
	{
		return;
	}

	const FStoredFrameInput* stored = history.Find(_packet.FrameNumber);

	if (!stored)
		return;

	if (stored->bPredicted &&
		stored->Packet.Buttons != _packet.Buttons)
	{
		FFrameInput input;
		input.Buttons = _packet.Buttons;
		input.Action = CheckForCombo(_pc, _packet.FrameNumber);

		FStoredFrameInput& entry = history[_packet.FrameNumber];
		entry.Packet = input;
		entry.bPredicted = false;
		
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Rollbacked frame %d"), _packet.FrameNumber);

		for (const auto& Pair : m_rollbackManager.GetFrameSnapshots())
		{
			BeforeRollbackStates.Add(Pair.Key, Pair.Value.GameState);
		}
		
		m_bDebugRollbackOnDesync = true;
		m_rollbackManager.RollbackToFrame(
			_packet.FrameNumber,
			FrameNumber,
			m_currentGameState,
			[this](int32 _simFrame, FGameState& _state)
			{
				FixedGameUpdateForRollback(_simFrame, _state);
			}
		);
	}

	// Cleanup
	const int32 MaxHistory = 30;
	const int32 minFrame = _packet.FrameNumber - MaxHistory;

	for (auto It = playerMap.CreateIterator(); It; ++It)
	{
		if (It.Key() < minFrame)
		{
			It.RemoveCurrent();
		}
	}

	for (auto It = history.CreateIterator(); It; ++It)
	{
		if (It.Key() < minFrame)
		{
			It.RemoveCurrent();
		}
	}
}


void UGameManager::FixedGameUpdateForRollback(int32 _frame, FGameState& _state)
{
	// Input bauen
	BuildFrameInput(_frame, _state);

	// =============================
	// Character Movelimit
	// =============================
	if (m_camera)
	{
		if (m_player1)
		{
			CheckBackMovement(_state.P1);
		}
		if (m_player2)
		{
			CheckBackMovement(_state.P2);
		}
	}

	// Logic Update
	m_movementSimP1.UpdateLogic(_state.P1, _state.P1Input, FIXED_UPDATE_RATE);
	m_movementSimP2.UpdateLogic(_state.P2, _state.P2Input, FIXED_UPDATE_RATE);

	// Movement
	m_movementSimP1.UpdateMovement(_state.P1, _state.P2, FIXED_UPDATE_RATE);
	m_movementSimP2.UpdateMovement(_state.P2, _state.P1, FIXED_UPDATE_RATE);

	// Facing
	m_movementSimP1.UpdateFacing(_state.P1, _state.P2);
	m_movementSimP2.UpdateFacing(_state.P2, _state.P1);

	m_rollbackManager.SaveFrame(_frame, _state);

	SpawnSnapshotDebug(_frame, _state, false, false);
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

void UGameManager::SpawnSnapshotDebug(int32 _frame, const FGameState& _state, bool _bool, bool _bIsLogicstate)
{
	if (!m_cachedWorld.IsValid()) return;
	
	FVector Pos = _state.P1.Position;
	
	FColor Color = (_bIsLogicstate) ? GetColorForState(_state.P1.LogicState) : GetColorForState(_state.P1.AnimState);

	if (m_playerController1)
	{
		if (TMap<int32, FStoredFrameInput>* History =
			m_inputHistory.Find(m_playerController1))
		{
			if (const FStoredFrameInput* Input = History->Find(_frame))
			{
				if (Input->bPredicted)
				{
					Color = FColor::Red; 
				}
			}
		}
	}
	if (_bool)
	{
		DrawDebugPoint(
			m_cachedWorld.Get(),
			Pos + FVector(5.f, 0.f, 0.f),
			15.f,
			Color,
			true,
			30.f
		);
	}
	DrawDebugPoint(
		m_cachedWorld.Get(),
		Pos,
		15.f,
		Color,
		true,
		30.f
	);

	//Pos = _state.P2.Position + FVector(0, 0, _frame * 5.f);
	//Color = FColor::MakeFromHSV8(_frame * 10 % 255, 200, 255);
	//DrawDebugPoint(
	//	m_cachedWorld.Get(),
	//	Pos,
	//	15.f,
	//	Color,
	//	true,
	//	30.f
	//);
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
