#pragma once
#include "UCharacterBaseState.h"

class ASP_API UCharacterAnimationBaseState : public UCharacterBaseState
{
	using UCharacterBaseState::UCharacterBaseState;
	
public:
	void RequestMontage(FCharacterState& _state, EStates _animState);
	virtual void EnterState(FCharacterState& _state,const FFrameInput& _input) override;
};
