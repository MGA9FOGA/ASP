#pragma once
#include "UCharacterAnimationBaseState.h"
#include "AnimationStateMachine.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_Move : public UCharacterAnimationBaseState
{
	using UCharacterAnimationBaseState::UCharacterAnimationBaseState;
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline void UCharacterState_Anim_Move::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("ENTER: Move"));
	_stateMachine->SetCurrentState(State);
	PlayAnimationMontage(_stateMachine, EStates::MOVING);
}

inline void UCharacterState_Anim_Move::ExitState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Move"));
}

inline void UCharacterState_Anim_Move::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Display, TEXT("Anim Move State"));
}