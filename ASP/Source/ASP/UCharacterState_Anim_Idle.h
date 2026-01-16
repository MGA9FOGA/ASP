#pragma once
#include "AnimationResolver.h"
#include "CharacterAnimInstance.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationResolver;

class ASP_API UCharacterState_Anim_Idle : public UCharacterAnimationBaseState
{
public:
	UCharacterState_Anim_Idle(): UCharacterAnimationBaseState(EStates::IDLE)
	{
	}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
	virtual void ExitState(FCharacterState& _state) override;
};


inline void UCharacterState_Anim_Idle::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
	UCharacterAnimationBaseState::EnterState(_state, _input);
	RequestMontage(_state, EStates::IDLE);
}

inline void UCharacterState_Anim_Idle::UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
}

inline void UCharacterState_Anim_Idle::ExitState(FCharacterState& _state)
{
	
}
