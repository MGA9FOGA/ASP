#pragma once
#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "UCharacterBaseState.h"

class ASP_API UCharacterState_Logic_Move : public UCharacterBaseState
{
public:
	UCharacterState_Logic_Move()
		: UCharacterBaseState(EStates::MOVING)
	{
	}

	virtual void EnterState(FCharacterState& _state, const FFrameInput& _input) override;
	virtual void ExitState(FCharacterState& _state) override;
	virtual void UpdateState(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
};

inline void UCharacterState_Logic_Move::EnterState(FCharacterState& _state, const FFrameInput& _input)
{
}

inline void UCharacterState_Logic_Move::ExitState(FCharacterState& _state)
{
}

inline void UCharacterState_Logic_Move::UpdateState(FCharacterState& _state, const FFrameInput& _input,
                                                    float _deltaTime)
{

	if (!_state.bGrounded)
	{
		_state.MoveAxis = 0.f;
		return;
	}

    switch (_input.Action)
    {
    case EInputAction::MoveRight:
        _state.MoveAxis = (_state.Facing == 1 || (_state.Facing == -1 && _state.bCanMoveBackwards)) ? 1.f : 0.f;
        break;

    case EInputAction::MoveLeft:
        _state.MoveAxis = (_state.Facing == -1 || (_state.Facing == 1 && _state.bCanMoveBackwards)) ? -1.f : 0.f;
        break;

    default:
        _state.MoveAxis = 0.f;
        break;
    }
	
}
