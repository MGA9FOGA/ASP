// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputHandler.h"
#include "GameFramework/PlayerController.h"
#include "FightingGame_PlayerController.generated.h"

/**
 * 
 */

UCLASS()
class ASP_API AFightingGame_PlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void SpawnCharacter();
public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void Update(float _deltatime);
	void OnPressedMovement(const struct FInputActionValue& _value);
	void OnMoveReleased();
	void OnPressedJump();
	void OnJumpReleased();
	void OnPressedCrouch();
	void OnCrouchReleased();
	void OnPressedAttack1();
	void OnAttack1Released();
	void OnPressedAttack2();
	void OnAttack1Released2();
	void OnPressedBlock();
	void OnBlockReleased();

	void Move(float _value);
	void StopMove();
	void Jump(float _value);
	
	FORCEINLINE class AASPCharacter* GetPlayer() const {return m_playerCharacter;}
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

	//Movement Bools
	bool b_leftPressed = false;
	bool b_rightPressed = false;
	bool b_downPressed = false;
	bool b_upPressed = false;
	bool b_jumpPressed = false;
	bool b_Attack1Pressed = false;
	bool b_Attack2Pressed = false;
	bool b_blockPressed = false;

	//Deadzone
	float m_deadzone =0.3f;
	
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



