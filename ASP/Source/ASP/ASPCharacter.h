// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimationStateMachine.h"
#include "LogicStateMachine.h"
#include "InputHandler.h"
#include "MoveableInterface.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "ASPCharacter.generated.h"

class UPushBoxComponent;
class UCharacterAnimationSet;
struct FCharacterState;
class FFightingStateMachine;
class FOnCustomOverlapBegin;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ASP_API AASPCharacter : public AActor, public IMoveableInterface
{
	GENERATED_BODY()

	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPushBoxComponent> PushBox;
public:
	AASPCharacter();
	
	virtual void Tick(float _deltaSeconds) override;
	static const FName CharacterMeshName;
	static const FName CharacterColliderName;
	
	void Start();
	virtual void FixedUpdate(float _deltaTime) override;
	virtual UCustomMoveComponent* GetNoChaosMovementComponent() const override { return m_movement; }

	void Move(float _value) const;
	void StopMove() const;
	void Jump() const;
	void Rotate();
	
	void PerformAction(EInputAction _action) const;
	/** Register Player to GameManager **/
	//void Register();

	FORCEINLINE class AFightingGame_PlayerController* GetPlayerController() const { return m_playerController; }
	FORCEINLINE void SetPlayerController(AFightingGame_PlayerController* _playerController)
	{
		m_playerController = _playerController;
	}

	//FORCEINLINE float GetPlayerID() const {return m_playerID;}
	//FORCEINLINE void SetPlayerID(float _playerID) {m_playerID = _playerID;}
	FORCEINLINE LogicStateMachine* GetLogicStateMachine() const { return m_logicStateMachine.get(); }
	FORCEINLINE AnimationStateMachine* GetAnimStateMachine() const { return m_animationStateMachine.get(); }
	FORCEINLINE UCharacterAnimationSet* GetAnimationSet() const { return m_animationSet; }
	FORCEINLINE void SetCanMoveBackwards(bool _b) { b_canMoveBackwards = _b; }
	FORCEINLINE bool GetCanMoveBackwards() const { return b_canMoveBackwards; }
	FORCEINLINE FVector GetMoveForwardVector() const { return m_forwardVector; }
	FORCEINLINE UPushBoxComponent* GetPushBox() const { return PushBox; }
protected:
	UFUNCTION()
	void HandleCustomHit(const FHitResult& _hit);
	UFUNCTION()
	void HandleCustomOverlapBegin(AActor* _otherActor);
	UFUNCTION()
	void HandleCustomOverlapEnd(AActor* _otherActor);
	UPROPERTY(VisibleAnywhere)
	class UCustomMoveComponent* m_movement;
	UPROPERTY(VisibleAnywhere)
	class AFightingGame_PlayerController* m_playerController;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//int m_playerID;
	std::unique_ptr<LogicStateMachine> m_logicStateMachine;
	std::unique_ptr<AnimationStateMachine> m_animationStateMachine;
	UPROPERTY(EditAnywhere)
	float m_jumpStrength = 800.0f;
	UPROPERTY(EditAnywhere)
	float m_moveSpeed = 300.0f;
	UPROPERTY(EditAnywhere)
	float m_rotationSpeed = 7.0f;
	UPROPERTY(EditAnywhere)
	bool b_canMoveBackwards = true;
	UPROPERTY(EditAnywhere)
	FRotator m_targetRotation = FRotator::ZeroRotator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animation)
	UCharacterAnimationSet* m_animationSet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animation)
	FVector m_forwardVector = FVector::ZeroVector;

public:
	UFUNCTION(BlueprintCallable)
	UCapsuleComponent* GetCapsuleComponent() { return Capsule; }

	UFUNCTION()
	USkeletalMeshComponent* GetSkeletalMeshComponent() { return Mesh; }

	void LookLeft();
	void LookRight();
};
