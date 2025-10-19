#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "GameManager.h"
#include "InputTriggers.h"
#include "StateMachine.h"


inline bool IdleToWalkingForwad(FFightingStateMachine* _statemachine)
{
	if (_statemachine->GetAction() == EAction::MoveForward) return true;
	return false;
}