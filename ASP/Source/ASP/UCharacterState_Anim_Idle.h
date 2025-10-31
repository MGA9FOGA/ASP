#pragma once
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class UCharacterState_Anim_Idle : public UCharacterAnimationBaseState
{
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
public:
	
};

inline void UCharacterState_Anim_Idle::EnterState(FFightingStateMachine* _stateMachine)
{
	PlayAnimationMontage(_stateMachine, );
}

inline void UCharacterState_Anim_Idle::ExitState(FFightingStateMachine* _stateMachine)
{
	
}

inline void UCharacterBaseState::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	
}