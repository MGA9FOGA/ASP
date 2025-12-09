#pragma once
#include "AnimationStateMachine.h"
#include "CharacterAnimInstance.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class ASP_API UCharacterState_Anim_Idle : public UCharacterAnimationBaseState
{
	using UCharacterAnimationBaseState::UCharacterAnimationBaseState;
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline void UCharacterState_Anim_Idle::EnterState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("ENTER: Idle"));
	_stateMachine->SetCurrentState(State);
	PlayAnimationMontage(_stateMachine, EStates::IDLE);	

}

inline void UCharacterState_Anim_Idle::ExitState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("EXIT: Idle"));
}

inline void UCharacterState_Anim_Idle::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Display, TEXT("Anim Idle State"));
}

