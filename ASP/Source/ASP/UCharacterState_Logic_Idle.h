#pragma once
#include "CustomMoveComponent.h"
#include "StateMachine.h"
#include "UCharacterBaseState.h"

class ASP_API UCharacterState_Logic_Idle : public UCharacterBaseState
{
public:
	UCharacterState_Logic_Idle()
		: UCharacterBaseState(EStates::IDLE) {}
	
	virtual void EnterState(FCharacterState& _state,const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
};


inline void UCharacterState_Logic_Idle::EnterState(FCharacterState& _state,const FFrameInput& _input)
{
	_state.MoveAxis = 0.f;
}

inline void UCharacterState_Logic_Idle::ExitState(FCharacterState& _state)
{
}

inline void UCharacterState_Logic_Idle::UpdateState(FCharacterState& _state, const FFrameInput& _input,
                                                    float _deltaTime)
{
	if (!_state.bGrounded)
		return;

	switch (_input.Action)
	{
	// =============================
	// === Facing = 1 -> looking to the right ===
	// =============================
	case EInputAction::MoveRight:
		{
			if (_state.Facing == 1)
			{
				_state.MoveAxis = 1.f;
			}
			// =============================
			// === Facing = -1 -> backwards ===
			// =============================
			else if (_state.Facing == -1 && _state.bCanMoveBackwards)
			{
				_state.MoveAxis = 1.f;
			}
			else
			{
				_state.MoveAxis = 0.f;
			}
			break;
		}
//
	// =============================
	// === Facing = -1 -> looking to the left ===
	// =============================
	case EInputAction::MoveLeft:
		{
			if (_state.Facing == -1)
			{
				_state.MoveAxis = -1.f;
			}
			// =============================
			// === Facing = 1 -> backwards ===
			// =============================
			else if (_state.Facing == 1 && _state.bCanMoveBackwards)
			{
				_state.MoveAxis = -1.f;
			}
			else
			{
				_state.MoveAxis = 0.f;
			}
			break;
		}
	default:
		{
			_state.MoveAxis = 0.f;
			break;
		}
	}
}//
