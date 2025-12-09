#pragma once
#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "UCharacterBaseState.h"

class ASP_API UCharacterState_Logic_Move : public UCharacterBaseState
{
public:
	using UCharacterBaseState::UCharacterBaseState;

	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline void UCharacterState_Logic_Move::EnterState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("ENTER: Move"));
	if (_stateMachine == nullptr) return;
	_stateMachine->SetCurrentState(State);
}

inline void UCharacterState_Logic_Move::ExitState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("EXIT: Move"));
	//_stateMachine->GetPlayerController()->GetPlayer()->StopMove();
}

inline void UCharacterState_Logic_Move::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	if (!_stateMachine || !_stateMachine->GetPlayerController() || !_stateMachine->GetPlayerController()->GetPlayer()
		|| !_stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetBoolOnGround())
	{
		return;
	}
	switch (_stateMachine->GetAction())
	{
	case EInputAction::MoveRight:
		if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f)
		{
			_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		}
		else if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f && _stateMachine->GetCharacter()->GetCanMoveBackwards())
		{
			_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		}
		else if (!_stateMachine->GetCharacter()->GetCanMoveBackwards())
		{
			_stateMachine->GetPlayerController()->GetPlayer()->StopMove();
		}
		break;
	case EInputAction::MoveLeft:
		{
			if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f)
			{
				_stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f);
			}
			else if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f  && _stateMachine->GetCharacter()->GetCanMoveBackwards())
			{
				_stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f);
			}
			else if (!_stateMachine->GetCharacter()->GetCanMoveBackwards())
			{
				_stateMachine->GetPlayerController()->GetPlayer()->StopMove();
			}
			break;
		}
	default:
		break;
	}
}
