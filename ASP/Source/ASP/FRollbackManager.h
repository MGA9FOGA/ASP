#pragma once
#include "StateMachine.h"

class AASPCharacter;
struct FAnimationMontageState;

struct FCharacterState
{
	FCharacterState()
		: Position(FVector::ZeroVector),
		  Velocity(FVector::ZeroVector),
		  LogicState(EStates::NONE),
		  StateTimer(0.f),
		  Health(100),
		  Facing(1),
		  AnimationMontage(nullptr)
	{
	}

	FCharacterState(FVector _pos, FVector _vel, EStates _state, float _timer, int32 _health, int _facing,
	                FAnimationMontageState* _montageState): Position(_pos), Velocity(_vel), LogicState(_state),
	                                                        StateTimer(_timer), Health(_health), Facing(_facing),
	                                                        AnimationMontage(nullptr)
	{
	}

	FVector Position;
	FVector Velocity;
	EStates LogicState;
	float StateTimer; // duration in the current State
	int32 Health;
	int Facing; //-1 left, +1 right
	FAnimationMontageState* AnimationMontage;
};

struct FFrameSnapshot
{
	FCharacterState State;
	FInputPacket Input;
};


class ASP_API FRollbackManager
{
public:
	// [PlayerID][FrameNumber] = CharacterState
	TMap<int32, TMap<int32, FFrameSnapshot>> History;
	
	void SaveFrame(int32 _frame, AASPCharacter* _player, const FInputPacket& _input);
	void LoadFrame(int32 _frame, AASPCharacter* _player, FInputPacket& _outInput);
	void RollbackToFrame(int32 _targetFrame, const TArray<AASPCharacter*>& _players);

	const int32 MaxStoredFrames = 120;

	void TrimOldFrames(int32 _playerID);
};
