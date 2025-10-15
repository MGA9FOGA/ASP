// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FightingGame_PlayerController.generated.h"

/**
 * 
 */

USTRUCT()
struct FInputPacket
{
	GENERATED_BODY()

	int32 FrameNumber;
	int8 Buttons;
	int8 ExtraFlags;
	int16 RandomSeed;
	
};
UCLASS()
class ASP_API AFightingGame_PlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void SpawnCharacter();
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;

	void OnMovement(const struct FInputActionValue& _value);
	void OnReleased(const FInputActionValue& _value);
	UFUNCTION()
	void Jump();
	void Crouch();
private:
	UPROPERTY(EditAnywhere)
	class AASPCharacter* m_playerCharacter;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> playerClass;
	UPROPERTY(EditAnywhere)
	float m_jumpSpeed = 10.0f;
	UPROPERTY(EditAnywhere)
	float m_moveSpeed = 200.0f;
	UPROPERTY(EditAnywhere)
	FVector m_forwardDirection;
	UPROPERTY(EditAnywhere)
	class UGameManager* m_gameManager;

	//Movement Left/Right
	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bNeutralizeOnConflict = true;
	bool b_leftPressed = false;
	bool b_rightPressed = false;
	float m_lastInputDirection = 0.0f;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

public:
	
	
};

