#pragma once
#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "UCharacterBaseState.h"

class UCharacterState_Move : public UCharacterBaseState
{
public:
	UCharacterState_Move();

	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline UCharacterState_Move::UCharacterState_Move()
{
}

inline void UCharacterState_Move ::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("ENTER: Move"));
	_stateMachine->CurrentCharacterStateInfo.EAction = EAction::Moving;
}

inline void UCharacterState_Move ::ExitState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Move"));
}

inline void UCharacterState_Move ::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	//if (!_stateMachine || !_stateMachine->GetPlayerController() || !_stateMachine->GetPlayerController()->GetPlayer() ) return;
	switch (_stateMachine->GetAction())
	{
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

