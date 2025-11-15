#include "LogicStateMachine.h"

#include "Conditions.h"
#include "UCharacterState_Logic_Idle.h"
#include "UCharacterState_Logic_Jump.h"
#include "UCharacterState_Logic_Move.h"

LogicStateMachine::LogicStateMachine()
{
	LogicStateMachine::BuildStates();
}

LogicStateMachine::LogicStateMachine(AASPCharacter& _character)
{
	m_character = &_character;
	LogicStateMachine::BuildStates();
}

LogicStateMachine::~LogicStateMachine()
{
}

void LogicStateMachine::BuildStates()
{
	FFightingStateMachine::BuildStates();

#pragma region Idle
	//IDLE STATE CREATION
	FStateDefinition Idle;
	Idle.State = MakeShared<UCharacterState_Logic_Idle>(EStates::IDLE);
	Idle.Transitions.Add(FStateTransition(EStates::MOVING, [this]()-> bool { return IdleToMoving(*this); }));
	Idle.Transitions.Add(FStateTransition(EStates::JUMPING, [this]()-> bool { return IdleOrWalkToJump(*this); }));
	m_stateMap.Add(EStates::IDLE, Idle);
#pragma endregion
#pragma region Move
	FStateDefinition Move;
	Move.State = MakeShared<UCharacterState_Logic_Move>(EStates::MOVING);
	Move.Transitions.Add(FStateTransition(EStates::JUMPING, [this]()-> bool { return IdleOrWalkToJump(*this); }));
	Move.Transitions.Add(FStateTransition(EStates::IDLE, [this]()-> bool { return WalkingToIdle(*this); }));
	m_stateMap.Add(EStates::MOVING, Move);
#pragma endregion
#pragma region Jump
	FStateDefinition Jump;
	Jump.State = MakeShared<UCharacterState_Logic_Jump>(EStates::JUMPING);
	Jump.Transitions.Add(FStateTransition(EStates::IDLE, [this]()-> bool { return JumpToIdle(*this); }));
	m_stateMap.Add(EStates::JUMPING, Jump);
#pragma endregion
	
}

bool LogicStateMachine::HasStateJustChangedTo(EStates _targetState) const
{
	return m_ECurrentState == _targetState && m_EPreviousState != _targetState;
}
