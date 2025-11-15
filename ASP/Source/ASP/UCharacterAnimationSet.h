#pragma once
#include "StateMachine.h"
#include "UCharacterAnimationSet.generated.h"


UCLASS(BlueprintType)
class ASP_API UCharacterAnimationSet : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	TMap<EStates, TObjectPtr<UAnimMontage>> MontageMap;
};
