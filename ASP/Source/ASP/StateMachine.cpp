// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine.h"
#include "GameManager.h"
#include "UCharacterBaseState.h"



FFightingStateMachine::FFightingStateMachine()
{
}

void FFightingStateMachine::Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
	if (!m_stateMap.Contains(_state.LogicState)) return;
	auto& def = m_stateMap[_state.LogicState];

	// State-Update ausführen
	if (def.State.IsValid())
	{
		_state.LogicStateTimer += _deltaTime;
		def.State->UpdateState(_state, _input, _deltaTime);
	}

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
	if (_newState == m_currentState)
		return;

	// =============================
	// === Exit old state ===
	// =============================
	if (m_stateMap.Contains(m_currentState))
	{
		auto& oldDef = m_stateMap[m_currentState];
		if (oldDef.State.IsValid())
		{
			oldDef.State->ExitState(_state);
		}
	}

	// =============================
	// === Switch state ===
	// =============================
	_state.PreviousLogicState = m_currentState;
	m_currentState = _newState;
	_state.LogicState = _newState;
	_state.LogicStateTimer = 0.f;

	// =============================
	// === Enter new state ===
	// =============================
	if (m_stateMap.Contains(_newState))
	{
		auto& newDef = m_stateMap[_newState];
		if (newDef.State.IsValid())
		{
			newDef.State->EnterState(_state, _input);
		}
	}
}


void FFightingStateMachine::Start(FCharacterState& _state)
{
}
