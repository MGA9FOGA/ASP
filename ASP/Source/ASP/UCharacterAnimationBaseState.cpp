#include "D:\Github\ASP\ASP\Intermediate\Build\Win64\x64\ASPEditor\Development\UnrealEd\SharedPCH.UnrealEd.Project.ValApi.Cpp20.h"
#include "UCharacterAnimationBaseState.h"

#include "ASPCharacter.h"
#include "FightingGame_PlayerController.h"

UCharacterAnimationBaseState::UCharacterAnimationBaseState()
{
	animations.Add("Idle", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/Idle_Montage.Idle_Montage'")));
	animations.Add("Move", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/'")));
	animations.Add("JumpStart", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/'")));
	animations.Add("Fall", LoadObject<UAnimMontage>(nullptr, TEXT("AnimMontage'/Game/Animations/'")));

}


void UCharacterAnimationBaseState::PlayAnimationMontage(const FFightingStateMachine* _stateMachine,const FString& _animationName)
{
	auto* pc = _stateMachine->GetPlayerController();
	if (!pc) return;

	AASPCharacter* character = Cast<AASPCharacter>(pc->GetPawn());
	if (!character) return;

	if (UAnimInstance* anim = character->GetSkeletalMeshComponent()->GetAnimInstance())
	{
		if (UAnimMontage** foundMontage = animations.Find(_animationName))
		{
			if (UAnimMontage* montage = *foundMontage)
			{
				anim->Montage_Play(montage);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Animation '%s' is null in map."), *_animationName);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Animation '%s' not found in animations map."), *_animationName);
		}
	}
}
