// Copyright Epic Games, Inc. All Rights Reserved.

#include "ASPGameMode.h"
#include "ASPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AASPGameMode::AASPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
