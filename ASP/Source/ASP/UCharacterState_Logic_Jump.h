#pragma once
#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "UCharacterBaseState.h"
#include "AI/NavigationSystemBase.h"

class ASP_API UCharacterState_Logic_Jump : public UCharacterBaseState
{
public:
	using UCharacterBaseState::UCharacterBaseState;

	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;

	void MoveDirection(FFightingStateMachine* _stateMachine);

	private:
	EInputAction m_EJumpDirectionState;
};


inline void UCharacterState_Logic_Jump::EnterState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("ENTER: Jump"));
	if (!_stateMachine || !_stateMachine->GetPlayerController() || !_stateMachine->GetPlayerController()->GetPlayer())
		return;
	_stateMachine->SetCurrentState(State);
	_stateMachine->GetPlayerController()->GetPlayer()->Jump();
	
	MoveDirection(_stateMachine);
}

inline void UCharacterState_Logic_Jump::ExitState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("EXIT: Jump"));
	m_EJumpDirectionState = EInputAction::None;
	_stateMachine->GetPlayerController()->GetPlayer()->StopMove();
}

inline void UCharacterState_Logic_Jump::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	if (!_stateMachine || !_stateMachine->GetPlayerController()->GetPlayer()) return;

	switch (m_EJumpDirectionState)
	{
	case EInputAction::JumpRight:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(1.0f);
		break;
	case EInputAction::JumpLeft:
		_stateMachine->GetPlayerController()->GetPlayer()->Move(-1.0f);
		break;
	default:
		break;;
	}
	
}

inline void UCharacterState_Logic_Jump::MoveDirection(FFightingStateMachine* _stateMachine)
{
	switch (_stateMachine->GetAction())
	{
	case EInputAction::JumpRight:
		if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f)
		{
			m_EJumpDirectionState = EInputAction::JumpRight;
		}
		else if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f && _stateMachine->GetCharacter()->GetCanMoveBackwards())
		{
			m_EJumpDirectionState = EInputAction::JumpRight;
		}
		else if (!_stateMachine->GetCharacter()->GetCanMoveBackwards())
		{
			_stateMachine->GetPlayerController()->GetPlayer()->StopMove();
		}
		break;
	case EInputAction::JumpLeft:
		if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f)
		{
			m_EJumpDirectionState = EInputAction::JumpLeft;
		}
		else if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f  && _stateMachine->GetCharacter()->GetCanMoveBackwards())
		{
			m_EJumpDirectionState = EInputAction::JumpLeft;
		}
		else if (!_stateMachine->GetCharacter()->GetCanMoveBackwards())
		{
			_stateMachine->GetPlayerController()->GetPlayer()->StopMove();
		}
		break;
	case EInputAction::MoveRight:
		m_EJumpDirectionState = EInputAction::MoveRight;
		break;
	case EInputAction::MoveLeft:
		m_EJumpDirectionState = EInputAction::MoveLeft;
		break;
	default:
		break;;
	}
}
