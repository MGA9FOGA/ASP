#include "LogicStateMachine.h"

#include "Conditions.h"
#include "UCharacterState_Logic_Idle.h"
#include "UCharacterState_Logic_Jump.h"
#include "UCharacterState_Logic_Move.h"

LogicStateMachine::LogicStateMachine()
{
#pragma region Idle
	//IDLE STATE CREATION
	m_idle_State.State = MakeShared<UCharacterState_Logic_Idle>(EStates::IDLE);
	m_idle_State.Transitions.Add(FStateTransition(EStates::MOVING, [this]()-> bool { return IdleToMoving(*this); }));
	m_idle_State.Transitions.Add(FStateTransition(EStates::JUMPING, [this]()-> bool { return IdleOrWalkToJump(*this); }));
#pragma endregion
#pragma region Move 
	m_moving_State.State = MakeShared<UCharacterState_Logic_Move>(EStates::MOVING);
	m_moving_State.Transitions.Add(FStateTransition(EStates::JUMPING, [this]()-> bool { return IdleOrWalkToJump(*this); }));
	m_moving_State.Transitions.Add(FStateTransition(EStates::IDLE, [this]()-> bool { return WalkingToIdle(*this); }));
#pragma endregion
#pragma region Jump 
	m_jumping_State.State = MakeShared<UCharacterState_Logic_Jump>(EStates::JUMPING);
	m_jumping_State.Transitions.Add(FStateTransition(EStates::IDLE, [this]()-> bool { return JumpToIdle(*this); }));
#pragma endregion

	m_stateMap.Add(EStates::IDLE, m_idle_State);
	m_stateMap.Add(EStates::MOVING, m_moving_State);
	m_stateMap.Add(EStates::JUMPING, m_jumping_State);
	CurrentState = m_idle_State.State.Get();
	m_ECurrentState = EStates::IDLE;
}

LogicStateMachine::~LogicStateMachine()
{
}
