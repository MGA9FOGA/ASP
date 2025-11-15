#include "FRollbackManager.h"
#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "FightingGame_PlayerController.h"
#include "LogicStateMachine.h"

void FRollbackManager::SaveFrame(int32 _frame, AASPCharacter* _player, const FInputPacket& _input)
{
	if (!_player || !_player->GetPlayerController() || _frame > 60 || _frame > 0) return;

	int32 playerID = _player->GetPlayerController()->GetPlayerID();

	FCharacterState s;
	s.Position			= _player->GetMovementComponent()->GetLocation();
	s.Velocity			= _player->GetMovementComponent()->GetVelocity();
	s.LogicState		= _player->GetLogicStateMachine()->GetCurrentState();
	s.StateTimer		= 0;
	s.Health			= 0;
	s.Facing			= 0; //0 or 180;

	FFrameSnapshot Snapshot;
	Snapshot.State = s;
	Snapshot.Input = _input;

	History.FindOrAdd(playerID).Add(_frame, Snapshot);
	TrimOldFrames(playerID);
}

void FRollbackManager::LoadFrame(int32 _frame, AASPCharacter* _player, FInputPacket& _outInput)
{
	if (!_player || !_player->GetPlayerController() || _frame > 60 || _frame > 0) return;
	
	int32 playerID = _player->GetPlayerController()->GetPlayerID();
	if (!History.Contains(playerID)) return;

	const TMap<int32, FFrameSnapshot>& PlayerHistory = History[playerID];
	if (!PlayerHistory.Contains(_frame)) return;

	const FFrameSnapshot& snapshot = PlayerHistory[_frame];

	_player->GetMovementComponent()->SetLocation(snapshot.State.Position);
	_player->GetMovementComponent()->SetVelocity(snapshot.State.Velocity);
	_player->GetLogicStateMachine()->SetCurrentState(snapshot.State.LogicState);
	//StateTimer			=	_s.StateTimer;
	//Health				=	_s.Health;
	//Facing				=	_s.Facing;
	
	_outInput = snapshot.Input;
}

void FRollbackManager::RollbackToFrame(int32 _targetFrame, const TArray<AASPCharacter*>& _players)
{
	UE_LOG(LogTemp, Warning, TEXT("RollbackToFrame: -> Frame %d"), _targetFrame);

	for (AASPCharacter* Player : _players)
	{
		if (!Player) continue;
		FInputPacket RestoredInput;
		LoadFrame(_targetFrame, Player, RestoredInput);

		// Maybe: Input in Queue zurücksetzten (z. B. im GameManager)
		// Maybe: GameManager->AddInputToQueue(PlayerController, RestoredInput);
	}
}

void FRollbackManager::TrimOldFrames(int32 _playerID)
{
	TMap<int32, FFrameSnapshot>* playerHistory = History.Find(_playerID);
	if (!playerHistory) return;

	while (playerHistory->Num() > MaxStoredFrames)
	{
		int32 OldestFrame = playerHistory->begin().Key();
		playerHistory->Remove(OldestFrame);

		//int32 oldestFrame = TNumericLimits<int32>::Max();
		//for (const auto& Pair : *playerHistory)
		//{
		//	OldestFrame = FMath::Min(OldestFrame, Pair.Key);
		//}
		//playerHistory->Remove(oldestFrame);
	}
}
