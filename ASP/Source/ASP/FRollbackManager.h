#pragma once
#include "StateMachine.h"

class AASPCharacter;
struct FAnimationMontageState;

struct FCharacterRollbackState
{
	FCharacterRollbackState()
		: Position(FVector::ZeroVector),
		  Velocity(FVector::ZeroVector),
		  LogicState(EStates::NONE),
		  StateFrame(0.f),
		  Health(0),
		  Facing(0),
		  bGrounded(false),
		  bCanAct(false)
	{
	}

	FCharacterRollbackState(FVector _pos, FVector _vel, EStates _state, float _timer, int32 _health, int _facing,
	                bool _bGrounded, bool _bCanAct): Position(_pos), Velocity(_vel), LogicState(_state),
	                                                        StateFrame(_timer), Health(_health), Facing(_facing),
															bGrounded(_bGrounded), bCanAct(_bCanAct)

	
	{
	}

	FVector Position;
	FVector Velocity;

	EStates LogicState;
	float StateFrame;

	int32 Health;
	int Facing; //-1 left, +1 right

	bool bGrounded;
	bool bCanAct; //Stunlock or not
};

struct FFrameSnapshot
{
	int64 FrameNumber;
	uint32 RNGSeed;

	FCharacterRollbackState Player1;
	FCharacterRollbackState Player2;
};


class ASP_API FRollbackManager
{
public:
//	TMap<int32, FFrameSnapshot> History;
//
//	void SaveFrame(int32 _frame, AASPCharacter* _player, const FInputPacket& _input);
//	void LoadFrame(int32 _frame, AASPCharacter* _player, FInputPacket& _outInput);
//	void RollbackToFrame(int32 _targetFrame, const TArray<AASPCharacter*>& _players);
//
//	const int32 MaxStoredFrames = 7;
//
//	void TrimOldFrames(int32 _playerID);
};
