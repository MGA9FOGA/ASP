#pragma once
#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "UCharacterBaseState.h"

class UCharacterState_Jump : public UCharacterBaseState
{
public:
	UCharacterState_Jump();

	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline UCharacterState_Jump::UCharacterState_Jump()
{
}

inline void UCharacterState_Jump::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("ENTER: Jump"));
	if (!_stateMachine || !_stateMachine->GetPlayerController() || !_stateMachine->GetPlayerController()->GetPlayer())
		return;
	_stateMachine->CurrentCharacterStateInfo.EAction = EAction::Jump;
	_stateMachine->GetPlayerController()->GetPlayer()->Jump();
}

inline void UCharacterState_Jump::ExitState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Jump"));
}

inline void UCharacterState_Jump::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	switch (_stateMachine->GetAction())
	{
	case EAction::JumpRight:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		break;
	case EAction::JumpLeft:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f);
		break;
	case EAction::MoveRight:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		break;
	case EAction::MoveLeft:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f);
		break;
	default:
		break;;
	}
}
