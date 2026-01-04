// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputHandler.h"
#include "StateMachine.h"

class FFightingStateMachine;
struct FAnimationMontageState;
struct FCharacterRollbackState;
/**
 * 
 */
class ASP_API UCharacterBaseState
{
public:
	explicit UCharacterBaseState(EStates _inStates);
	virtual ~UCharacterBaseState() = default;

	EStates State;
	
	virtual void EnterState(FCharacterState& _state,const FFrameInput& _input);
	virtual void ExitState(FCharacterState& _state);
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime);
};
