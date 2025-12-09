// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputHandler.h"
#include "GameFramework/PlayerController.h"
#include "FightingGame_PlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
class AASPCharacter;
class UGameManager;

UCLASS()
class ASP_API AFightingGame_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	void SetMappingContext(UInputMappingContext* _newMappingContext);
	virtual void SetupInputComponent() override;
	void UsingGamepad();
	void UsingKeyboard();

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
	void SetCharacterRef(AASPCharacter* _character);
	void ResetInputBuffer();
	FRawInput Input;
	
	FORCEINLINE class AASPCharacter* GetPlayer() const {return m_playerCharacter;}
	FORCEINLINE float GetPlayerID() const {return m_playerID;}
	FORCEINLINE void SetPlayerID(float _playerID) {m_playerID = _playerID;}
	FORCEINLINE void SetGameManager(UGameManager* _gameManager) {m_gameManager = _gameManager;}
	FORCEINLINE UGameManager* GetGameManager() const {return m_gameManager;}

	void SetupMappingContext();
private:
	
	UPROPERTY(EditAnywhere)
	class AASPCharacter* m_playerCharacter;
	UPROPERTY(EditAnywhere)
	class UGameManager* m_gameManager;

	//Movement Bools
	bool b_leftPressed		= false;
	bool b_rightPressed		= false;
	bool b_downPressed		= false;
	bool b_upPressed		= false;
	bool b_jumpPressed		= false;
	bool b_Attack1Pressed	= false;
	bool b_Attack2Pressed	= false;
	bool b_blockPressed		= false;

	//Deadzone
	//Controller = 40
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float m_deadzone = 0.3f;
	//ID
	int m_playerID;
public:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
private:
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;
	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;
};




