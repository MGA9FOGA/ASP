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
	int32 m_previousMoveDir = 0;
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
	if (!_stateMachine || !_stateMachine->GetCharacter()) return;

	auto* character = _stateMachine->GetCharacter();
	auto velocityY = character->GetNoChaosMovementComponent()->GetOwnVelocity().Y;
	auto forwardX  = character->GetActorForwardVector().X;

	// Bestimme Bewegungsrichtung: +1 = vorwärts, -1 = rückwärts, 0 = stillstand
	int32 currentMoveDir = 0;
	if (forwardX > 0.5f && velocityY > 0.1f) currentMoveDir = 1;        // vorwärts
	else if (forwardX < -0.5f && velocityY < -0.1f) currentMoveDir = 1; // vorwärts rückwärts gespiegelt
	else if (forwardX > 0.5f && velocityY < -0.1f) currentMoveDir = -1; // rückwärts
	else if (forwardX < -0.5f && velocityY > 0.1f) currentMoveDir = -1; // rückwärts rückwärts gespiegelt
	
	// Wenn die Richtung sich geändert hat, reset b_hasPlayedMontage
	if (currentMoveDir != m_previousMoveDir)
	{
		b_hasPlayedMontage = false;
		m_previousMoveDir = currentMoveDir;
	}

	if (currentMoveDir == 0 ) return;

	// Abspielen der passenden Animation
	if (!b_hasPlayedMontage)
	{
		EStates targetState = (currentMoveDir > 0) ? EStates::MOVINGFWD : EStates::MOVINGBWD;
		PlayAnimationMontage(_stateMachine, targetState);
		b_hasPlayedMontage = true;
	}
}
