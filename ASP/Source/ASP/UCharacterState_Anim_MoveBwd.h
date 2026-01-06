#pragma once
#include "UCharacterAnimationBaseState.h"

class UCharacterState_Anim_MoveBwd : public UCharacterAnimationBaseState
{
public:
	UCharacterState_Anim_MoveBwd(): UCharacterAnimationBaseState(EStates::MOVINGBWD)
	{
	}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;

};


inline void UCharacterState_Anim_MoveBwd::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
	RequestMontage(_state, EStates::MOVINGBWD);
}

inline void UCharacterState_Anim_MoveBwd::ExitState(FCharacterState& _state)
{
}

inline void UCharacterState_Anim_MoveBwd::UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
}

