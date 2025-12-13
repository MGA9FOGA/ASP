// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ASPGameMode.generated.h"

class UGameManager;
class AASPCharacter;
class AFightingGame_PlayerController;

UCLASS(minimalapi)
class AASPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AASPGameMode();

	class UFighting_GameGameInstance* GI;

private:
	virtual void BeginPlay() override;
	void StartOrder();
	void SpawnCharacterForController(AFightingGame_PlayerController* _pc, AASPCharacter*& _outCharacter,
	                                const FVector& _spawnPos, const FRotator& _spawnRot);
	void InitializeFighters(AASPCharacter* _character, AFightingGame_PlayerController* _pc);
public:
	FORCEINLINE UGameManager* GetGameManager() const {return m_gameManager;}

private:
	//Player 1
	UPROPERTY(EditAnywhere)
	class AASPCharacter* m_player1 = nullptr;
	UPROPERTY(EditAnywhere)
	class AFightingGame_PlayerController* m_playerController1 = nullptr;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AASPCharacter> m_characterClass1;

	//Player 2
	UPROPERTY(EditAnywhere)
	TSubclassOf<AFightingGame_PlayerController> ControllerClass;
	UPROPERTY(EditAnywhere)
	class AASPCharacter* m_player2 = nullptr;
	UPROPERTY(EditAnywhere)
	class AFightingGame_PlayerController* m_playerController2 = nullptr;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AASPCharacter> m_characterClass2;
	
	//Spawnpoints
	FVector m_player1Position = FVector(730.0f,1230.0f,400.0f);
	FRotator m_player1Rotation = FRotator(0.0f,0.0f,0.0f);
	FVector m_player2Position = FVector(730.0f,2030.0f,400.0f);
	FRotator m_player2Rotation = FRotator(0.0f,180.0f,0.0f);

	UPROPERTY(EditAnywhere)
	class UGameManager* m_gameManager;
};



