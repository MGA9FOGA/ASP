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
	// =============================
	// === Setup Input Mapping Context===
	// =============================
	void SetMappingContext(UInputMappingContext* _newMappingContext);

	// =============================
	// === Setup Input Bindings ===
	// =============================
	virtual void SetupInputComponent() override;

	// =============================
	// === Reset all Input flags ===
	// =============================
	void ResetInputBuffer();

	// =============================
	// === Update called each FixedUpdate frame, ===
	// ===pushes input packets to GameManager ===
	// =============================
	void Update(float _deltatime);
	
	// =============================
	// === Player input handlers ===
	// =============================
	void OnPressedMovement(const struct FInputActionValue& _value);
	void OnMoveReleased();
	void OnPressedJump();
	void OnJumpReleased();
	void OnPressedCrouch();
	void OnCrouchReleased();
	void OnPressedAttack1();
	void OnAttack1Released();
	void OnPressedAttack2();
	void OnAttack2Released();
	void OnPressedBlock();
	void OnBlockReleased();

	// =============================
	// === set ref to Character(cosmetic) ===
	// =============================
	void SetCharacterRef(AASPCharacter* _character);

	// =============================
	// === configure default mapping context ===
	// =============================
	void SetupMappingContext();
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	// =============================
	// === Input deadzone ===
	// =============================
	void UsingGamepad();
	void UsingKeyboard();
	

	FORCEINLINE float GetPlayerID() const {return m_playerID;}
	FORCEINLINE void SetPlayerID(float _playerID) {m_playerID = _playerID;}
	FORCEINLINE class AASPCharacter* GetPlayer() const {return m_playerCharacter;}
	FORCEINLINE void SetGameManager(UGameManager* _gameManager) {m_gameManager = _gameManager;}
	FORCEINLINE UGameManager* GetGameManager() const {return m_gameManager;}

private:
	UPROPERTY(EditAnywhere)
	class AASPCharacter* m_playerCharacter;

	int m_playerID;
	

	// =============================
	// === Jump Input Action ===
	// =============================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;
	
	// =============================
	// === Move Input Action ===
	// =============================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	// =============================
	// === Deadzone ===
	// =============================
	//Controller = 40
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float m_deadzone = 0.3f;

	// =============================
	// === Input flags ===
	// =============================
	bool b_leftPressed		= false;
	bool b_rightPressed		= false;
	bool b_downPressed		= false;
	bool b_upPressed		= false;
	bool b_jumpPressed		= false;
	bool b_Attack1Pressed	= false;
	bool b_Attack2Pressed	= false;
	bool b_blockPressed		= false;
	

	// =============================
	// === Local raw input struct ===
	// =============================
	FRawInput Input;
	
	// =============================
	// === GameManager Pointer ===
	// =============================
	UPROPERTY(EditAnywhere)
	class UGameManager* m_gameManager;
};




