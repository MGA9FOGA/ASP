#pragma once
#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "UCharacterBaseState.h"

class UCharacterState_Logic_Jump : public UCharacterBaseState
{
public:
	using UCharacterBaseState::UCharacterBaseState;

	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};


inline void UCharacterState_Logic_Jump::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("ENTER: Jump"));
	if (!_stateMachine || !_stateMachine->GetPlayerController() || !_stateMachine->GetPlayerController()->GetPlayer())
		return;
	_stateMachine->SetCurrentState(State);
	_stateMachine->GetPlayerController()->GetPlayer()->Jump();
}

inline void UCharacterState_Logic_Jump::ExitState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Jump"));
}

inline void UCharacterState_Logic_Jump::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	switch (_stateMachine->GetAction())
	{
	case EInputAction::JumpRight:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		break;
	case EInputAction::JumpLeft:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f);
		break;
	case EInputAction::MoveRight:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		break;
	case EInputAction::MoveLeft:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f);
		break;
	default:
		break;;
	}
}
