#pragma once
#include "UCharacterAnimationBaseState.h"
#include "AnimationStateMachine.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_MoveFwd : public UCharacterAnimationBaseState
{
public:
	UCharacterState_Anim_MoveFwd(): UCharacterAnimationBaseState(EStates::MOVINGFWD)
	{
	}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;

};


inline void UCharacterState_Anim_MoveFwd::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
	RequestMontage(_state, EStates::MOVINGFWD);
}

inline void UCharacterState_Anim_MoveFwd::ExitState(FCharacterState& _state)
{
}

inline void UCharacterState_Anim_MoveFwd::UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
}
