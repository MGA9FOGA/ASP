// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class AASPCharacter;
DECLARE_DELEGATE(FOnLandingEndedNative);
DECLARE_DELEGATE(FOnJumpStartEndedNative);
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
	FOnJumpStartEndedNative OnJumpStartEndedNative;
private:
	AASPCharacter* m_character;
};
