// Fill out your copyright notice in the Description page of Project Settings.


#include "UCharacterBaseState.h"

#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "FMovementSimulator.h"
#include "StateMachine.h"



UCharacterBaseState::UCharacterBaseState(EStates _state)
{
	State = _state;
}

void UCharacterBaseState::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
}

void UCharacterBaseState::ExitState(FCharacterState& _state)
{
}

void UCharacterBaseState::UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
}

