#pragma once
#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "FightingGame_PlayerController.h"
#include "AnimationStateMachine.h"
#include "GameManager.h"
#include "InputTriggers.h"
#include "StateMachine.h"

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
	return _state.bAnimLanded;
}

inline bool CanTransitionToFalling(const FCharacterState _state, const FFrameInput& _input)
{
	return _state.Velocity.Z < 0.f || _state.bAnimJumpStartupFinished;
}

/*_statemachine.GetCharacter()->GetNoChaosMovementComponent()->GetOwnVelocity().Z < 0.0f || animFSM->GetStartUpJumpedFinished()*/