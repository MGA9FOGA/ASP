#pragma once
#include "AnimationStateMachine.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_StartJump : public UCharacterAnimationBaseState
{
	using UCharacterAnimationBaseState::UCharacterAnimationBaseState;
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline void UCharacterState_Anim_StartJump::EnterState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("ENTER: StartJump"));
	_stateMachine->SetCurrentState(State);
	PlayAnimationMontage(_stateMachine, EStates::STARTJUMP);
}

inline void UCharacterState_Anim_StartJump::ExitState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("EXIT: StartJump"));
}

inline void UCharacterState_Anim_StartJump::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Display, TEXT("Anim StartJump State"));
}