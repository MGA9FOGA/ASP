// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "ASPCharacter.h"
#include "UCharacterAnimationSet.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OnMontageEnded.AddDynamic(this, &UCharacterAnimInstance::HandleMontageEnded);
}

void UCharacterAnimInstance::HandleMontageEnded(UAnimMontage* _montage, bool _bInterrupted)
{
	if (_bInterrupted || !_montage)
	{
		return;
	}

	AASPCharacter* character = Cast<AASPCharacter>(GetOwningActor());
	if (!character) return;
	
	UCharacterAnimationSet* animSet = character->GetAnimationSet();
	if (!animSet) return;
	
	// === Landing ===
	if (UAnimMontage* Landing = animSet->MontageMap.FindRef(EStates::LANDING))
	{
		if (_montage == Landing)
		{
			OnLandingEndedNative.ExecuteIfBound();
			return;
		}
	}

	// === Jump Startup ===
	if (UAnimMontage* JumpStart = animSet->MontageMap.FindRef(EStates::STARTJUMP))
	{
		if (_montage == JumpStart)
		{
			OnJumpStartEndedNative.ExecuteIfBound();
			return;
		}
	}
}
