// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputHandler.h"
#include "StateMachine.h"

class FFightingStateMachine;
struct FAnimationMontageState;
struct FCharacterState;
/**
 * 
 */
class ASP_API UCharacterBaseState
{
public:
	UCharacterBaseState();
	virtual ~UCharacterBaseState();

	virtual void EnterState(FFightingStateMachine* _stateMachine) ;
	virtual void ExitState(FFightingStateMachine* _stateMachine) ;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) ;
protected:
};
