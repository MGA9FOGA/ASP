#pragma once
#include "GameManager.h"


//Logic
inline bool IdleToMoving(const FCharacterState _state, const FFrameInput& _input)
{
	EInputAction action = _input.Action;

	return action == EInputAction::MoveRight || action == EInputAction::MoveLeft;
}


inline bool IdleOrWalkToJump(const FCharacterState _state, const FFrameInput& _input)
{
	if (!_state.bGrounded)
		return false;
	
	return _input.Action == EInputAction::Jump
		|| _input.Action == EInputAction::JumpLeft
		|| _input.Action == EInputAction::JumpRight;
}

inline int8 GetMoveDirection(const FCharacterState& _state)
{
	if (FMath::Abs(_state.Velocity.Y) < 1.f)
		return 0;

	float dir = _state.Velocity.Y * _state.Facing;
	return (dir > 0.f) ? 1 : -1;
}


inline bool WalkingToIdle(const FCharacterState _state, const FFrameInput& _input)
{
	if (_input.Action == EInputAction::Idle || _input.Action == EInputAction::None ) return true;
	return false;
}

inline bool JumpToIdle(const FCharacterState _state, const FFrameInput& _input)
{
	return _state.bGrounded && !_state.bJumpRequested && _state.bHasLeftGround;
}


//Animation
inline bool CanTransitionToIdle(const FCharacterState _state, const FFrameInput& _input)
{
	return _state.bGrounded;
}

inline bool CanTransitionToFalling(const FCharacterState _state, const FFrameInput& _input)
{
	return !_state.bGrounded
		&& _state.PreviousVelocityZ > 0.f
		&& _state.Velocity.Z <= 0.f;
}

/*_statemachine.GetCharacter()->GetNoChaosMovementComponent()->GetOwnVelocity().Z < 0.0f || animFSM->GetStartUpJumpedFinished()*/