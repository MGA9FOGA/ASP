// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputHandler.h"
#include "UCharacterBaseState.h"
class AFightingGame_PlayerController;


struct FAnimationMontageState
{
	FAnimationMontageState(): MontageID(0), Time(0)
	{
	}

	FAnimationMontageState(int32 _id, float _time): MontageID(_id), Time(_time) {};

	int32 MontageID; //f.e. Attack1_Montage
	float Time; //progess in Secounds
};

struct FCharacterState
{
	FCharacterState();
	FCharacterState(FVector _pos, FVector _vel, EAction _act, float _timer, int32 _facing,
						 FAnimationMontageState* _montageState): Position(_pos), Velocity(_vel), EAction(_act),
						                                         StateTimer(_timer), Facing(_facing),
						                                         AnimationMontage(nullptr)
	{
	}

	FVector Position;
	FVector Velocity;
	EAction EAction;
	float StateTimer; // duration in the current State
	int32 Facing; //-1 left, +1 right
	FAnimationMontageState* AnimationMontage;
};

struct FStateTransition
{
	EAction TargetStateAction;
	TFunction<bool()> Condition;

	FStateTransition(EAction _inTarget, TFunction<bool()> _inCondition)
	 : TargetStateAction(_inTarget), Condition(_inCondition) {}
};

struct FStateDefinition
{
	FStateDefinition(){}
	
	TSharedPtr<class UCharacterBaseState> State;
	TArray<FStateTransition> Transitions;
};
/**
 * 
 */
class ASP_API FFightingStateMachine final
{
public:
	virtual ~FFightingStateMachine() = default;
	FFightingStateMachine();
	//CurrentState
	UCharacterBaseState* CurrentState;
	FCharacterState CurrentCharacterStateInfo = FCharacterState(FVector::ZeroVector, FVector::ZeroVector, Idle, 0.0f, 1, new FAnimationMontageState());

	//Main Funcitons
	void Update(float _deltaTime);
	void ChangeState(EAction _newAction);
	void TryTransitions();
	
	FORCEINLINE void SetAction(EAction _newAction){m_ECurrentInputAction = _newAction;}
	FORCEINLINE EAction GetAction() const {return m_ECurrentInputAction;}
	
	FORCEINLINE void SetPlayerController(AFightingGame_PlayerController* _playerController){m_playerController = _playerController;}
	FORCEINLINE AFightingGame_PlayerController* GetPlayerController() const {return m_playerController;}
	FORCEINLINE TMap<EAction, FStateDefinition> GetMap() const {return m_stateMap;}
private:
	TMap<EAction, FStateDefinition> m_stateMap;
	AFightingGame_PlayerController* m_playerController;
	EAction m_ECurrentInputAction = EAction::None;
	
	/* States */
	FStateDefinition m_idle_State			= FStateDefinition();
	FStateDefinition m_moving_State			= FStateDefinition();
	FStateDefinition m_jumping_State		= FStateDefinition();
	FStateDefinition m_attackig1_State		= FStateDefinition();
	FStateDefinition m_attackig2_State		= FStateDefinition();
	FStateDefinition m_crouching_State		= FStateDefinition();
};
