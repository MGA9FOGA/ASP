// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "States.h"
struct FFrameInput;
struct FCharacterState;
class AFightingGame_PlayerController;


struct FStateTransition 
{
	EStates Target;
	TFunction<bool(const FCharacterState&, const FFrameInput&)> Condition;
};

struct FStateDefinition
{
	TSharedPtr<class UCharacterBaseState> State;
	TArray<FStateTransition> Transitions;
};
/**
 * 
 */
class ASP_API FFightingStateMachine
{
public:
	virtual ~FFightingStateMachine() = default;
	FFightingStateMachine();
	
	//Main Funcitons
	virtual void Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime);
	virtual void ChangeState(FCharacterState& _state, EStates _newState, const FFrameInput& _input);
	virtual void Start(FCharacterState& _state);
	
	FORCEINLINE TMap<EStates, FStateDefinition> GetMap() const {return m_stateMap;}
	
protected:
	//CurrentState
	TMap<EStates, FStateDefinition> m_stateMap;
};
