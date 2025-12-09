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
	character->StopMove();
}

inline void UCharacterState_Logic_Idle::ExitState(FFightingStateMachine* _stateMachine)
{
	//UE_LOG(LogTemp, Log, TEXT("EXIT: Idle"));
}

inline void UCharacterState_Logic_Idle::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
}