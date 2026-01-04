// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "ASPCharacter.generated.h"

class UCapsuleComponent;
class AFightingGame_PlayerController;
class UPushBoxComponent;
class UCharacterAnimationSet;
struct FCharacterRollbackState;
class FFightingStateMachine;
class FOnCustomOverlapBegin;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomHit, const FHitResult&, HitResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomOverlap, AActor*, OtherActor);

struct FPendingAnimEvents
{
	bool bLandingFinished = false;
	bool bJumpStartupFinished = false;
};
UCLASS(config=Game)
class ASP_API AASPCharacter : public AActor
{
	GENERATED_BODY()

public:
	AASPCharacter();
	// =============================
	// === Start ===
	// =============================
	void Start();

	// =============================
	// === Tick ===
	// =============================
	virtual void Tick(float _deltaSeconds) override;

	// ===================================
	// === Apply State from Simulaiont ===
	// ===================================
	void ApplyState(const FCharacterRollbackState& _state);

	// =============================
	// === Facing/Rotation ===
	// =============================
	void Rotate();
	void LookLeft();
	void LookRight();

	// =============================
	// === Accessors ===
	// =============================
	FORCEINLINE UPushBoxComponent* GetPushBox() const { return PushBox; }
	FORCEINLINE FVector GetMoveForwardVector() const { return m_forwardVector; }
	FORCEINLINE void SetPlayerController(AFightingGame_PlayerController* PC) { m_playerController = PC; }
	FORCEINLINE AFightingGame_PlayerController* GetPlayerController() const { return m_playerController; }
	FORCEINLINE UCharacterAnimationSet* GetAnimationSet() const { return m_animationSet; }
	FORCEINLINE USkeletalMeshComponent* GetSkeletalMeshComponent() { return Mesh; }

protected:
	// =============================
	// === Components ===
	// =============================
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPushBoxComponent> PushBox;

	// =============================
	// === Animation ===
	// =============================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animation)
	UCharacterAnimationSet* m_animationSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animation)
	FVector m_forwardVector = FVector::ZeroVector;

	// ==================================
	// === Playercontroller/GameManager ===
	// ==================================
	UPROPERTY(VisibleAnywhere)
	class AFightingGame_PlayerController* m_playerController;

	UPROPERTY(VisibleAnywhere)
	class UGameManager* m_gameManager;

	// =============================
	// === Rotation ===
	// =============================
	UPROPERTY(EditAnywhere)
	FRotator m_targetRotation = FRotator::ZeroRotator;

	// =========================================
	// === Events for cosmetic Overlaps/Hit  ===
	// =========================================

	UPROPERTY(BlueprintAssignable, Category="CustomMove|Events")
	FOnCustomHit OnCustomHit;
	
	UPROPERTY(BlueprintAssignable)
	FOnCustomOverlap OnCustomBeginOverlap;
	
	UPROPERTY(BlueprintAssignable)
	FOnCustomOverlap OnCustomEndOverlap;
	
	UFUNCTION()
	void HandleCustomHit(const FHitResult& _hit);
	UFUNCTION()
	void HandleCustomOverlapBegin(AActor* _otherActor);
	UFUNCTION()
	void HandleCustomOverlapEnd(AActor* _otherActor);

	// =============================
	// === Collider Events (cosmetic) ===
	// =============================

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep, const FHitResult& _sweepResult);
	UFUNCTION()
	void OnHit(UPrimitiveComponent* _hitComp, AActor* _otherActor, UPrimitiveComponent* _otherComp,
			   FVector _ormalImpulse,
			   const FHitResult& _hit);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, int32 _otherBodyIndex);

	void NotifyAnimLandingFinished();
	void NotifyAnimJumpStartupFinished();
public:
	static const FName CharacterMeshName;
	static const FName CharacterColliderName;

	FPendingAnimEvents PendingAnimEvents;
};

//old stuff

//	void Start();
//	virtual void FixedUpdate(double _deltaTime) override;
//
//
//	virtual UCustomMoveComponent* GetNoChaosMovementComponent() const override { return m_movement; }
//
//	void Move(float _value) const;
//	void StopMove() const;
//	void Jump() const;
//	
//
//
//	FORCEINLINE LogicStateMachine* GetLogicStateMachine() const { return m_logicStateMachine.get(); }
//	FORCEINLINE AnimationStateMachine* GetAnimStateMachine() const { return m_animationStateMachine.get(); }
//	
//	
//
//
//	
//
//	UPROPERTY(VisibleAnywhere)
//	class UCustomMoveComponent* m_movement;
//	std::unique_ptr<LogicStateMachine> m_logicStateMachine;
//	std::unique_ptr<AnimationStateMachine> m_animationStateMachine;
//	UPROPERTY(EditAnywhere)
//	float m_jumpStrength = 800.0f;
//	UPROPERTY(EditAnywhere)
//	float m_moveSpeed = 300.0f;
//	UPROPERTY(EditAnywhere)
//	float m_rotationSpeed = 7.0f;
//
//public:
//	UFUNCTION(BlueprintCallable)
//	UCapsuleComponent* GetCapsuleComponent() { return Capsule; }
//
//	
//

