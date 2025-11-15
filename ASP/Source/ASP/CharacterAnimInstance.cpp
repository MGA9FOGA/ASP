// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"

#include "ASPCharacter.h"
#include "UCharacterAnimationSet.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OnMontageEnded.AddDynamic(this, &UCharacterAnimInstance::HandleMontageEnded);

	AActor* owner = GetOwningActor();
	m_character = Cast<AASPCharacter>(owner);
}

void UCharacterAnimInstance::HandleMontageEnded(UAnimMontage* _montage, bool _bInterrupted)
{
	if (!m_character || !m_character->GetAnimationSet())
		return;

	UCharacterAnimationSet* set = m_character->GetAnimationSet();
	if (!set)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character has no AnimationSet."));
		return;
	}

	if (TObjectPtr<UAnimMontage>* montagePtr = set->MontageMap.Find(EStates::LANDING))
	{
		UAnimMontage* foundMontage = montagePtr->Get();
		if (foundMontage && _montage == foundMontage)
		{
			OnLandingEndedNative.ExecuteIfBound();
		}
		else if (!foundMontage)
		{
			UE_LOG(LogTemp, Warning, TEXT("Montage found in MontageMap but it is NULL."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("State not found in MontageMap."));
	}
}
