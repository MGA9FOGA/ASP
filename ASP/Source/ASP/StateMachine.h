// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



UENUM(BlueprintType)
enum class EStates : uint8
{
	NONE       		UMETA(DisplayName="None"),
	IDLE       		UMETA(DisplayName="Idle"),
	MOVING       	UMETA(DisplayName="Moving"),
	MOVINGFWD   	UMETA(DisplayName="MovingForward"),
	MOVINGBWD      	UMETA(DisplayName="MovingBackward"),
	JUMPING     	UMETA(DisplayName="Jumping"),
	STARTJUMP   	UMETA(DisplayName="StartJump"),
	FALLING     	UMETA(DisplayName="Falling"),
	LANDING     	UMETA(DisplayName="Landing"),
	ATTACKING   	UMETA(DisplayName="Attacking"),
	CROUCHING   	UMETA(DisplayName="Crouching"),
	HITTED      	UMETA(DisplayName="Hitted")
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
	
	//Main Funcitons
	void Update(float _deltaTime);
	virtual void ChangeState(EStates _newAction);
	void TryTransitions();

	virtual void BuildStates();
	virtual void Start();
	//Getter
	FORCEINLINE EInputAction GetAction() const {return m_ECurrentInputAction;}
	FORCEINLINE class AASPCharacter* GetCharacter() const {return m_character;}
	FORCEINLINE EStates GetPreviousState() const { return m_EPreviousState;}
	FORCEINLINE EStates GetCurrentState() const {return m_ECurrentState;}
	FORCEINLINE AFightingGame_PlayerController* GetPlayerController() const {return m_playerController;}
	FORCEINLINE TMap<EStates, FStateDefinition> GetMap() const {return m_stateMap;}
	//Setter
	FORCEINLINE void SetPlayerController(AFightingGame_PlayerController* _playerController){m_playerController = _playerController;}
	FORCEINLINE void SetCurrentState(EStates _state) {m_ECurrentState = _state;}
	FORCEINLINE void SetAction(EInputAction _newAction){m_ECurrentInputAction = _newAction;}
protected:
	//CurrentState
	UCharacterBaseState* m_currentState;
	TMap<EStates, FStateDefinition> m_stateMap;
	AFightingGame_PlayerController* m_playerController;
	AASPCharacter* m_character;
	EInputAction m_ECurrentInputAction = EInputAction::None;
	EStates m_ECurrentState = EStates::NONE;
	EStates m_EPreviousState = EStates::NONE;
};
