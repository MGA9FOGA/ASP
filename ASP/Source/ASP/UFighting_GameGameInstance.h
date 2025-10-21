#pragma once
#include "UFighting_GameGameInstance.generated.h"
class AASPCharacter;

UCLASS(Blueprintable)
class ASP_API UFighting_GameGameInstance : public UGameInstance
{
	GENERATED_BODY()
	UFighting_GameGameInstance();
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<AASPCharacter> SelectedPlayer1Class;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<AASPCharacter> SelectedPlayer2Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AASPCharacter>> SelectablePlayers;	
};
