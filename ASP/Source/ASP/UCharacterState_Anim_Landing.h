#pragma once
#include "AnimationStateMachine.h"
#include "CharacterAnimInstance.h"
#include "FMovementSimulator.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterAnimationSet.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_Landing : public UCharacterAnimationBaseState
{
public:
	UCharacterState_Anim_Landing(): UCharacterAnimationBaseState(EStates::LANDING)
	{
	}

	virtual void EnterState(FCharacterState& _state, FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
};

inline void UCharacterState_Anim_Landing::EnterState(FCharacterState& _state, FFrameInput& _input)
{
	UCharacterAnimationBaseState::EnterState(_state, _input);
	_state.bAnimLanded = true;
	RequestMontage(_state, EStates::LANDING);
}

inline void UCharacterState_Anim_Landing::ExitState(FCharacterState& _state)
{
	UCharacterAnimationBaseState::ExitState(_state);
}

inline void UCharacterState_Anim_Landing::UpdateState(FCharacterState& _state, const FFrameInput& _input,
	float _deltaTime)
{
	UCharacterAnimationBaseState::UpdateState(_state, _input, _deltaTime);
}
