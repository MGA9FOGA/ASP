#pragma once
#include "FightingGame_PlayerController.h"
#include "UCharacterBaseState.h"


class ASP_API UCharacterState_Logic_Jump : public UCharacterBaseState
{
public:
	UCharacterState_Logic_Jump()
		: UCharacterBaseState(EStates::JUMPING)
	{
	}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
	void MoveDirection(FFightingStateMachine* _stateMachine);
};

inline void UCharacterState_Logic_Jump::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
	// =============================
	// === setting Flags ===
	// =============================
	_state.bJumpRequested = true;
	_state.bHasLeftGround = false;
	
	// =============================
	// === Locking Jump Direction ===
	// =============================
	_state.JumpAxis = 0.f;

	// =============================
	// === Locking Jump Direction ===
	// =============================
	switch (_input.Action)
	{
	case EInputAction::JumpRight:
		{
			if (_state.Facing == 1 || _state.bCanMoveBackwards)
			{
				_state.JumpAxis = 1.f;
			}
			break;
		}

	case EInputAction::JumpLeft:
		{
			if (_state.Facing == -1 || _state.bCanMoveBackwards)
			{
				_state.JumpAxis = -1.f;
			}
			break;
		}
	default:
		_state.JumpAxis = 0.f;
		break;
	}
}

inline void UCharacterState_Logic_Jump::ExitState(FCharacterState& _state)
{
	_state.bHasLeftGround = false;
}

inline void UCharacterState_Logic_Jump::UpdateState(FCharacterState& _state, const FFrameInput& _input,
                                                    float _deltaTime)
{
	UCharacterBaseState::UpdateState(_state, _input, _deltaTime);
}
