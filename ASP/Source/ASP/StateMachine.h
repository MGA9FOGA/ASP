// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


UENUM(BlueprintType)
enum class EStates : uint8
{
	NONE        UMETA(DisplayName="None"),
	IDLE        UMETA(DisplayName="Idle"),
	MOVING      UMETA(DisplayName="Moving"),
	JUMPING     UMETA(DisplayName="Jumping"),
	STARTJUMP   UMETA(DisplayName="StartJump"),
	FALLING     UMETA(DisplayName="Falling"),
	ATTACKING   UMETA(DisplayName="Attacking"),
	CROUCHING   UMETA(DisplayName="Crouching"),
	HITTED      UMETA(DisplayName="Hitted")
};

#include "CoreMinimal.h"
#include "InputHandler.h"
#include "UCharacterBaseState.h"
class AFightingGame_PlayerController;


struct FStateTransition 
{
	EStates TargetStateAction;
	TFunction<bool()> Condition;

	FStateTransition(EStates _inTarget, TFunction<bool()> _inCondition)
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
class ASP_API FFightingStateMachine
{
public:
	virtual ~FFightingStateMachine() = default;
	FFightingStateMachine();
	//CurrentState
	UCharacterBaseState* CurrentState;
	
	//Main Funcitons
	void Update(float _deltaTime);
	void ChangeState(EStates _newAction);
	void TryTransitions();
	
	FORCEINLINE void SetAction(EInputAction _newAction){m_ECurrentInputAction = _newAction;}
	FORCEINLINE EInputAction GetAction() const {return m_ECurrentInputAction;}
	
	FORCEINLINE void SetPlayerController(AFightingGame_PlayerController* _playerController){m_playerController = _playerController;}
	FORCEINLINE AFightingGame_PlayerController* GetPlayerController() const {return m_playerController;}
	FORCEINLINE TMap<EStates, FStateDefinition> GetMap() const {return m_stateMap;}
	FORCEINLINE EStates GetCurrentState() const {return m_ECurrentState;}
	FORCEINLINE void SetCurrentState(EStates _state) {m_ECurrentState = _state;}
protected:
	TMap<EStates, FStateDefinition> m_stateMap;
	AFightingGame_PlayerController* m_playerController;
	EInputAction m_ECurrentInputAction = EInputAction::None;
	EStates m_ECurrentState = EStates::NONE;
};
