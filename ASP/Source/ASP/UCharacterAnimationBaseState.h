#pragma once
#include "UCharacterBaseState.h"

class ASP_API UCharacterAnimationBaseState : public UCharacterBaseState
{
	using UCharacterBaseState::UCharacterBaseState;
	
public:
	void PlayAnimationMontage(const FFightingStateMachine* _stateM, const EStates& _states);
};
