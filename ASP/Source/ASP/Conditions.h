#pragma once
#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "FightingGame_PlayerController.h"
#include "AnimationStateMachine.h"
#include "GameManager.h"
#include "InputTriggers.h"
#include "StateMachine.h"

//Logic
inline bool IdleToMoving(FFightingStateMachine& _statemachine)
{
	EInputAction action = _statemachine.GetAction();
	return (action == EInputAction::MoveRight || action == EInputAction::MoveLeft);
}

inline bool IdleOrWalkToJump(FFightingStateMachine& _statemachine)
{
	if (_statemachine.GetAction() == EInputAction::JumpLeft || _statemachine.GetAction() == EInputAction::JumpRight ||
		_statemachine.GetAction() == Jump) return true;
	return false;
}

inline bool WalkingToIdle(FFightingStateMachine& _statemachine)
{
	if (_statemachine.GetAction() == EInputAction::Idle || _statemachine.GetAction() == EInputAction::None ) return true;
	return false;
}

inline bool JumpToIdle(const FFightingStateMachine& _statemachine)
{
	if (_statemachine.GetPlayerController()->GetPlayer()->GetMovementComponent()->GetBoolOnGround()) return true;
	return false;
}


//Animation
inline bool CanTransitionToIdle(FFightingStateMachine& _statemachine)
{
	AnimationStateMachine* animFSM = static_cast<AnimationStateMachine*>(&_statemachine);
	if (!animFSM)
		return false;

	return animFSM->GetIsLanded();
}

inline bool CanTransitionToFalling(FFightingStateMachine& _statemachine)
{
	return _statemachine.GetCharacter()->GetMovementComponent()->GetVelocity().Z < 0.0f;
}