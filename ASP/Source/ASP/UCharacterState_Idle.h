#pragma once
#include "StateMachine.h"
#include "UCharacterBaseState.h"

class UCharacterState_Idle : public UCharacterBaseState
{
public:

	UCharacterState_Idle();
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};

inline UCharacterState_Idle::UCharacterState_Idle()
{
}

inline void UCharacterState_Idle::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("ENTER: Idle"));
}

inline void UCharacterState_Idle::ExitState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Idle"));
}

inline void UCharacterState_Idle::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	
}