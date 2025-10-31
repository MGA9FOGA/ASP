// Fill out your copyright notice in the Description page of Project Settings.


#include "UCharacterBaseState.h"

#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "StateMachine.h"


UCharacterBaseState::UCharacterBaseState()
{}

UCharacterBaseState::UCharacterBaseState(EStates _state)
{
	State = _state;
}

UCharacterBaseState::~UCharacterBaseState()
{}

void UCharacterBaseState::EnterState(FFightingStateMachine* _stateMachine)
{
}

void UCharacterBaseState::ExitState(FFightingStateMachine* _stateMachine)
{
}

void UCharacterBaseState::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
}

