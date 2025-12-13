#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "UPushBoxComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASP_API UPushBoxComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UPushBoxComponent();

	float GetHalfWidth() const;
	
};
