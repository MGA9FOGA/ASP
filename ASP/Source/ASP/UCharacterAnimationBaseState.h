#pragma once
#include "UCharacterBaseState.h"

class ASP_API UCharacterAnimationBaseState : UCharacterBaseState
{
	UCharacterAnimationBaseState();
	TMap<FString, UAnimMontage*> animations;

	
public:
	void PlayAnimationMontage(const FFightingStateMachine* _stateM, const FString& _animationNameachine);
};
