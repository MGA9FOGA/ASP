// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class AASPCharacter;
DECLARE_DELEGATE(FOnLandingEndedNative);
/**
 * 
 */
UCLASS()
class ASP_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	UFUNCTION()
	void HandleMontageEnded(UAnimMontage* _montage, bool _bInterrupted);
	
	FOnLandingEndedNative OnLandingEndedNative;

private:
	AASPCharacter* m_character;
};
