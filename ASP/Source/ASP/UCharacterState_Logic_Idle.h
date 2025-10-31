#pragma once
#include "CustomMoveComponent.h"
#include "StateMachine.h"
#include "UCharacterBaseState.h"

class UCharacterState_Logic_Idle : public UCharacterBaseState
{
public:
	using UCharacterBaseState::UCharacterBaseState;
	
	FString Name = "Idle";
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;
};


inline void UCharacterState_Logic_Idle::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("ENTER: Idle"));

	if (_stateMachine == nullptr) return;
	_stateMachine->SetCurrentState(State);

	// Sicherstellen, dass Controller und Charakter existieren
	AFightingGame_PlayerController* PC = _stateMachine->GetPlayerController();
	if (PC == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("StateMachine PlayerController ist NULL"));
		return;
	}

	AASPCharacter* Player = PC->GetPlayer();
	if (Player == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController hat keinen gültigen Player (Character ist NULL)"));
		return;
	}

	Player->StopMove();
}

inline void UCharacterState_Logic_Idle::ExitState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("EXIT: Idle"));
}

inline void UCharacterState_Logic_Idle::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
}