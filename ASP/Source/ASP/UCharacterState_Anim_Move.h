#pragma once
#include "UCharacterAnimationBaseState.h"
#include "AnimationStateMachine.h"
#include "UCharacterAnimationBaseState.h"
#include "UCharacterBaseState.h"

class AnimationStateMachine;

class UCharacterState_Anim_Move : public UCharacterAnimationBaseState
{
	using UCharacterAnimationBaseState::UCharacterAnimationBaseState;
	virtual void EnterState(FFightingStateMachine* _stateMachine) override;
	virtual void ExitState(FFightingStateMachine* _stateMachine) override;
	virtual void UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine) override;

private:
	bool b_hasPlayedMontage = false;
};

inline void UCharacterState_Anim_Move::EnterState(FFightingStateMachine* _stateMachine)
{
	UE_LOG(LogTemp, Log, TEXT("ENTER Anim: Move"));
	_stateMachine->SetCurrentState(State);
	b_hasPlayedMontage = false;
	//else if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f && _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetVelocity().Y <= -0.5f)
	//{
	//	PlayAnimationMontage(_stateMachine, EStates::MOVINGBWD);
	//}
	//else if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f && _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetVelocity().Y <= -0.5f)
	//{
	//	PlayAnimationMontage(_stateMachine, EStates::MOVINGBWD);
	//}
	//else if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f && _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetVelocity().Y >= 0.5f)
	//{
	//	PlayAnimationMontage(_stateMachine, EStates::MOVINGFWD);
	//}
}

inline void UCharacterState_Anim_Move::ExitState(FFightingStateMachine* _stateMachine)
{
//	UE_LOG(LogTemp, Log, TEXT("EXIT: Move"));
}

inline void UCharacterState_Anim_Move::UpdateState(float _deltaTime, FFightingStateMachine* _stateMachine)
{
	if (b_hasPlayedMontage)
		return;
	UE_LOG(LogTemp, Log, TEXT("ENTER Anim: %f"), _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetOwnVelocity().Y);
	if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f && _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetOwnVelocity().Y > 1.0f)
	{
		PlayAnimationMontage(_stateMachine, EStates::MOVINGFWD);
		b_hasPlayedMontage = true;
	}
	else if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f && _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetOwnVelocity().Y <= -0.5f)
	{
		PlayAnimationMontage(_stateMachine, EStates::MOVINGFWD);
		b_hasPlayedMontage = true;
	}
	else if (_stateMachine->GetCharacter()->GetActorForwardVector().X > 0.5f && _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetOwnVelocity().Y <= -0.5f)
	{
		PlayAnimationMontage(_stateMachine, EStates::MOVINGBWD);
		b_hasPlayedMontage = true;
	}
	else if (_stateMachine->GetCharacter()->GetActorForwardVector().X < -0.5f && _stateMachine->GetCharacter()->GetNoChaosMovementComponent()->GetOwnVelocity().Y >= 0.5f)
	{
		PlayAnimationMontage(_stateMachine, EStates::MOVINGBWD);
		b_hasPlayedMontage = true;
	}

}