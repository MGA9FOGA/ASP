#pragma once
#include "AnimationStateMachine.h"
#include "CharacterAnimInstance.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterAnimationSet.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_Landing : public UCharacterAnimationBaseState
{
	using UCharacterAnimationBaseState::UCharacterAnimationBaseState;
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline void UCharacterState_Anim_Landing::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Landing"));
	if (!_stateMachine) return;
	AnimationStateMachine* animStateMachine = static_cast<AnimationStateMachine*>(_stateMachine);
	animStateMachine->SetBoolIsLanded(false);
	_stateMachine->SetCurrentState(State);
	PlayAnimationMontage(_stateMachine, EStates::LANDING);
}

inline void UCharacterState_Anim_Landing::ExitState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Landing"));
}

inline void UCharacterState_Anim_Landing::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Display, TEXT("Anim Landing State"));
}


