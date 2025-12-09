#pragma once
#include "AnimationStateMachine.h"
#include "CharacterAnimInstance.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_Falling : public UCharacterAnimationBaseState
{
	using UCharacterAnimationBaseState::UCharacterAnimationBaseState;
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline void UCharacterState_Anim_Falling::EnterState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("ENTER: Falling"));
	_stateMachine->SetCurrentState(State);
	AnimationStateMachine* animStateMachine = static_cast<AnimationStateMachine*>(_stateMachine);
	animStateMachine->SetIsStartUpJumpFinished(false);
	PlayAnimationMontage(_stateMachine, EStates::FALLING);
}

inline void UCharacterState_Anim_Falling::ExitState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("EXIT: Falling"));
}

inline void UCharacterState_Anim_Falling::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Display, TEXT("Anim Falling State"));
}
