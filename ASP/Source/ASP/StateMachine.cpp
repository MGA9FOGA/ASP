// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine.h"
#include "Conditions.h"
#include "GameManager.h"
#include "UCharacterBaseState.h"
#include "UCharacterState_Logic_Idle.h"
#include "UCharacterState_Logic_Jump.h"
#include "UCharacterState_Logic_Move.h"


FFightingStateMachine::FFightingStateMachine()
{
}



void FFightingStateMachine::Update(float _deltaTime)
{
	if (m_stateMap.Contains(m_ECurrentState))
	{
		TSharedPtr<UCharacterBaseState> stateObj = m_stateMap[m_ECurrentState].State;
		if (stateObj.IsValid())
		{
			stateObj->UpdateState(_deltaTime, this);
		}
	}
	TryTransitions();
}


void FFightingStateMachine::ChangeState(EStates _newState)
{
	if (m_ECurrentState == _newState) return;
	
	m_EPreviousState = m_EPreviousState;
	
	// Exit des alten States
	if (m_stateMap.Contains(m_ECurrentState) && m_stateMap[m_ECurrentState].State.IsValid())
	{
		m_stateMap[m_ECurrentState].State->ExitState(this);
	}
	else
	{
		return;
	}

	// Enter des neuen States
	if (m_stateMap.Contains(_newState) && m_stateMap[_newState].State.IsValid())
	{
		m_stateMap[_newState].State->EnterState(this);
	}
}

void FFightingStateMachine::TryTransitions()
{
	if (!m_stateMap.Contains(m_ECurrentState)) return;
    
	auto& Def = m_stateMap[m_ECurrentState];
	for (const auto& Transition : Def.Transitions)
	{
		// Condition() kann jetzt direkt Input benutzen!
		if (Transition.Condition && Transition.Condition())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Transition TRUE -> Changing to %d"), (int)Transition.TargetStateAction);
			ChangeState(Transition.TargetStateAction);
			break;
		}
	}
}

void FFightingStateMachine::BuildStates()
{
}

void FFightingStateMachine::Start()
{
	m_ECurrentState = EStates::IDLE;
	if (auto* StatePair = m_stateMap.Find(EStates::IDLE))
	{
		if (StatePair->State.IsValid())
			m_currentState = StatePair->State.Get();
	}
	m_currentState->EnterState(this);
}


