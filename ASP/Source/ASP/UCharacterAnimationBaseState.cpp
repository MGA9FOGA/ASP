#include "UCharacterAnimationBaseState.h"
#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"
#include "UCharacterAnimationSet.h"

//UCharacterAnimationBaseState::UCharacterAnimationBaseState()
//{
//	animations.Add("Idle", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/Idle_Montage.Idle_Montage'")));
//	animations.Add("Move", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/'")));
//	animations.Add("JumpStart", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/'")));
//	animations.Add("Fall", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/'")));
//
//}


void UCharacterAnimationBaseState::PlayAnimationMontage(const FFightingStateMachine* _stateMachine,
                                                        const EStates& _states)
{
	if (!_stateMachine) return;

	AASPCharacter* character = _stateMachine->GetCharacter();
	if (!character) return;

	UCharacterAnimationSet* set = character->GetAnimationSet();
	if (!set)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character has no AnimationSet."));
		return;
	}

	TObjectPtr<UAnimMontage>* montagePtr = set->MontageMap.Find(_states);
	if (!montagePtr)
	{
		UE_LOG(LogTemp, Warning, TEXT("State not found in MontageMap."));
		return;
	}

	UAnimMontage* foundMontage = montagePtr->Get();
	if (!foundMontage)
	{
		UE_LOG(LogTemp, Warning, TEXT("Montage found in MontageMap but it is NULL."));
		return;
	}

	if (UAnimInstance* animInstance = character->GetSkeletalMeshComponent()->GetAnimInstance())
	{
		animInstance->Montage_Play(foundMontage, 1.0f);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimInstance is NULL on character mesh."));
	}
}
