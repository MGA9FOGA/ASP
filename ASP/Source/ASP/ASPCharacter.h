// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameManager.h"
#include "MoveableInterface.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "ASPCharacter.generated.h"

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

public:
	AASPCharacter();

	static const FName CharacterMeshName;
	static const FName CharacterColliderName;
	
	virtual void BeginPlay() override;
	
	virtual void FixedUpdate(float _deltaTime) override;
	virtual UCustomMoveComponent* GetMovementComponent() const override{return m_movement;}

protected:

	/** Register Player to GameManager **/
	void Register();
	UFUNCTION()
	void HandleCustomHit(const FHitResult& _hit);
	UFUNCTION()
	void HandleCustomOverlapBegin(AActor * _otherActor);
	UFUNCTION()
	void HandleCustomOverlapEnd(AActor * _otherActor);

protected:
	UPROPERTY(VisibleAnywhere)
	class UCustomMoveComponent* m_movement;

public:
	UFUNCTION(BlueprintCallable)
	UCapsuleComponent* GetCapsuleComponent(){return Capsule;}

	
};

