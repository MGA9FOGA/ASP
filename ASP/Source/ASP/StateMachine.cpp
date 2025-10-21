// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine.h"
#include "Conditions.h"
#include "GameManager.h"
#include "UCharacterBaseState.h"
#include "UCharacterState_Idle.h"
#include "UCharacterState_Jump.h"
#include "UCharacterState_Move.h"


FFightingStateMachine::FFightingStateMachine()
{
#pragma region Idle
	//IDLE STATE CREATION
	m_idle_State.State = MakeShared<UCharacterState_Idle>();
	m_idle_State.Transitions.Add(FStateTransition(EAction::Moving, [this]()-> bool { return IdleToMoving(*this); }));
	m_idle_State.Transitions.Add(FStateTransition(EAction::Jump, [this]()-> bool { return IdleOrWalkToJump(*this); }));
#pragma endregion
#pragma region Move 
	m_moving_State.State = MakeShared<UCharacterState_Move>();
	m_moving_State.Transitions.Add(FStateTransition(EAction::Jump, [this]()-> bool { return IdleOrWalkToJump(*this); }));
	m_moving_State.Transitions.Add(FStateTransition(EAction::Idle, [this]()-> bool { return WalkingToIdle(*this); }));
#pragma endregion
#pragma region Jump 
	m_jumping_State.State = MakeShared<UCharacterState_Jump>();
	m_jumping_State.Transitions.Add(FStateTransition(EAction::Idle, [this]()-> bool { return JumpToIdle(*this); }));
#pragma endregion

	m_stateMap.Add(EAction::Idle, m_idle_State);
	m_stateMap.Add(EAction::Moving, m_moving_State);
	m_stateMap.Add(EAction::Jump, m_jumping_State);
	CurrentState = m_idle_State.State.Get();
}

void FFightingStateMachine::Update(float _deltaTime)
{
	if (m_stateMap.Contains(CurrentCharacterStateInfo.EAction))
	{
		TSharedPtr<UCharacterBaseState> stateObj = m_stateMap[CurrentCharacterStateInfo.EAction].State;
		if (stateObj.IsValid())
		{
			stateObj->UpdateState(_deltaTime, this);
		}
	}
	TryTransitions();
}


void FFightingStateMachine::ChangeState(EAction _newAction)
{
	if (CurrentCharacterStateInfo.EAction== _newAction) return;

	// Exit des alten States
	if (m_stateMap.Contains(CurrentCharacterStateInfo.EAction) && m_stateMap[CurrentCharacterStateInfo.EAction].State.IsValid())
	{
		m_stateMap[CurrentCharacterStateInfo.EAction].State->ExitState(this);
	}

	// tatsächlicher Zustandswechsel
	CurrentCharacterStateInfo.EAction = _newAction;
	CurrentCharacterStateInfo.StateTimer = 0.0f;

	// Enter des neuen States
	if (m_stateMap.Contains(_newAction) && m_stateMap[_newAction].State.IsValid())
	{
		m_stateMap[_newAction].State->EnterState(this);
	}
}

void FFightingStateMachine::TryTransitions()
{
	if (!m_stateMap.Contains(CurrentCharacterStateInfo.EAction)) return;
    
	auto& Def = m_stateMap[CurrentCharacterStateInfo.EAction];
	for (const auto& Transition : Def.Transitions)
	{
		// Condition() kann jetzt direkt Input benutzen!
		if (Transition.Condition && Transition.Condition())
		{
			UE_LOG(LogTemp, Warning, TEXT("Transition TRUE -> Changing to %d"), (int)Transition.TargetStateAction);
			ChangeState(Transition.TargetStateAction);
			break;
		}
	}
}

