#pragma once
#include "AnimationStateMachine.h"
#include "CharacterAnimInstance.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_Falling : public UCharacterAnimationBaseState
{
public:
	UCharacterState_Anim_Falling(): UCharacterAnimationBaseState(EStates::FALLING)
	{
	}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
};

inline void UCharacterState_Anim_Falling::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
	UCharacterAnimationBaseState::EnterState(_state, _input);
	RequestMontage(_state, EStates::FALLING);
}

inline void UCharacterState_Anim_Falling::ExitState(FCharacterState& _state)
{
	UCharacterAnimationBaseState::ExitState(_state);
}

inline void UCharacterState_Anim_Falling::UpdateState(FCharacterState& _state, const FFrameInput& _input,
                                                      float _deltaTime)
{
	UCharacterAnimationBaseState::UpdateState(_state, _input, _deltaTime);
}
