#pragma once
#include "AnimationStateMachine.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_StartJump : public UCharacterAnimationBaseState
{
public:
	UCharacterState_Anim_StartJump()
		: UCharacterAnimationBaseState(EStates::STARTJUMP)
	{}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
};


inline void UCharacterState_Anim_StartJump::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
	UCharacterAnimationBaseState::EnterState(_state, _input);
	_state.bAnimJumpStartupFinished = true;
	RequestMontage(_state, EStates::STARTJUMP);
	_state.StateTimer = 0.f;
}

inline void UCharacterState_Anim_StartJump::ExitState(FCharacterState& _state)
{
	UCharacterAnimationBaseState::ExitState(_state);
}

inline void UCharacterState_Anim_StartJump::UpdateState(FCharacterState& _state, const FFrameInput& _input,
	float _deltaTime)
{
	UCharacterAnimationBaseState::UpdateState(_state, _input, _deltaTime);
}
