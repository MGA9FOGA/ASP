#include "UCharacterAnimationBaseState.h"
#include "FMovementSimulator.h"


void UCharacterAnimationBaseState::RequestMontage(FCharacterState& _state, EStates _animState)
{
	_state.AnimCommand = EAnimCommand::PlayMontage;
}

void UCharacterAnimationBaseState::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
}
