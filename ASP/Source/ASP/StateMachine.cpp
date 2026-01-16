// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine.h"
#include "GameManager.h"
#include "UCharacterBaseState.h"


FFightingStateMachine::FFightingStateMachine()
{
}

void FFightingStateMachine::Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
	_state.LogicStateTimer += _deltaTime;
	
	if (!m_stateMap.Contains(_state.LogicState))
		return;
	
	auto& def = m_stateMap[_state.LogicState];
	
	_state.LogicStateTimer += _deltaTime;
	def.State->UpdateState(_state, _input, _deltaTime);


	for (const FStateTransition& transition : def.Transitions)
	{
		if (transition.Condition(_state, _input))
		{
			ChangeState(_state, transition.Target, _input);
			break;
		}
	}
}

void FFightingStateMachine::ChangeState(FCharacterState& _state, EStates _newState, const FFrameInput& _input)
{
	if (_state.LogicState == _newState)
		return;

	if (!m_stateMap.Contains(_newState))
		return;

	_state.PreviousLogicState = _state.LogicState;
	_state.LogicState = _newState;
	_state.LogicStateTimer = 0.f;


	m_stateMap[_state.PreviousLogicState].State->ExitState(_state);
	m_stateMap[_newState].State->EnterState(_state, _input);
}


void FFightingStateMachine::Start(FCharacterState& _state)
{
}
