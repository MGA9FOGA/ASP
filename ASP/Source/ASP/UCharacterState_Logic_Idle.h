#pragma once
#include "CustomMoveComponent.h"
#include "StateMachine.h"
#include "UCharacterBaseState.h"

class ASP_API UCharacterState_Logic_Idle : public UCharacterBaseState
{
public:
	using UCharacterBaseState::UCharacterBaseState;
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};


inline void UCharacterState_Logic_Idle::EnterState(FFightingStateMachine* _stateMachine)
{
	if (!_stateMachine) return;

	AASPCharacter* character = _stateMachine->GetCharacter();
	if (!character)
	{
		UE_LOG(LogTemp, Error, TEXT("Idle EnterState: Character ist NULL"));
		return;
	}

	_stateMachine->SetCurrentState(State);
}

inline void UCharacterState_Logic_Idle::ExitState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("EXIT: Idle"));
}

inline void UCharacterState_Logic_Idle::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	if (!_stateMachine || !_stateMachine->GetPlayerController() || !_stateMachine->GetPlayerController()->GetPlayer() ||
		!_stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetBoolOnGround()) { return; }
	switch (_stateMachine->GetAction())
	{
	case EInputAction::MoveRight: if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f)
		{
			_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		}
		else if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f && _stateMachine->GetCharacter()->
			GetCanMoveBackwards()) { _stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f); }
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
			else if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f && _stateMachine->GetCharacter()->
				GetCanMoveBackwards()) { _stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f); }
			else if (!_stateMachine->GetCharacter()->GetCanMoveBackwards())
			{
				_stateMachine->GetPlayerController()->GetPlayer()->StopMove();
			}
			break;
		}
	default: break;
	}
}
