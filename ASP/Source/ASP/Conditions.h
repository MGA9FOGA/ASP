#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "FightingGame_PlayerController.h"
#include "GameManager.h"
#include "InputTriggers.h"
#include "StateMachine.h"


inline bool IdleToMoving(FFightingStateMachine& _statemachine)
{
	if (_statemachine.GetAction() == EAction::MoveRight || _statemachine.GetAction() == EAction::MoveLeft) return true;
	return false;
}

inline bool IdleOrWalkToJump(FFightingStateMachine& _statemachine)
{
	if (_statemachine.GetAction() == EAction::JumpLeft || _statemachine.GetAction() == EAction::JumpRight) return true;
	return false;
}

inline bool WalkingToIdle(FFightingStateMachine& _statemachine)
{
	if (_statemachine.GetAction() == EAction::Idle) return true;
	return false;
}

inline bool JumpToIdle(const FFightingStateMachine& _statemachine)
{
	if (_statemachine.GetPlayerController()->GetPlayer()->GetMovementComponent()->GetBoolOnGround()) return true;
	return false;
}