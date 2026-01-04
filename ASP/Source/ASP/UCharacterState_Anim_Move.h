#pragma once
#include "UCharacterAnimationBaseState.h"
#include "AnimationStateMachine.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_Move : public UCharacterAnimationBaseState
{
public:
	UCharacterState_Anim_Move(): UCharacterAnimationBaseState(EStates::MOVING)
	{
	}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
private:
	int8 m_previousMoveDir = 0;
};


inline void UCharacterState_Anim_Move::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
	UCharacterAnimationBaseState::EnterState(_state, _input);
	m_previousMoveDir = 0;
}

inline void UCharacterState_Anim_Move::ExitState(FCharacterState& _state)
{
}

inline void UCharacterState_Anim_Move::UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
	int8 currentMoveDir = 0;

	if (FMath::Abs(_state.Velocity.Y) > 1.f)
	{
		// Vorwärts / Rückwärts relativ Facing
		currentMoveDir = (_state.Velocity.Y * _state.Facing > 0.f) ? 1 : -1;
	}

	// standing Still
	if (currentMoveDir == 0)
	{
		m_previousMoveDir = 0;
		return;
	}

	// change of direction?
	if (currentMoveDir != m_previousMoveDir)
	{
		EStates TargetAnim =
			(currentMoveDir > 0) ? EStates::MOVINGFWD : EStates::MOVINGBWD;

		RequestMontage(_state, TargetAnim);
		m_previousMoveDir = currentMoveDir;
	}
}
