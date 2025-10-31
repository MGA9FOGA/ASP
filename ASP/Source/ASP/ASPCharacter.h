// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputHandler.h"
#include "UCharacterAnimationSet.h"
#include "MoveableInterface.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "ASPCharacter.generated.h"

class AnimationStateMachine;
class LogicStateMachine;
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

public:
	AASPCharacter();

	void StartFSM();
	virtual void Tick(float _deltaSeconds) override;
	static const FName CharacterMeshName;
	static const FName CharacterColliderName;
	
	virtual void BeginPlay() override;
	void Start();
	virtual void FixedUpdate(float _deltaTime) override;
	virtual UCustomMoveComponent* GetMovementComponent() const override{return m_movement;}

	void Move(float _value) const;
	void StopMove() const;
	void Jump() const;

	void PerformAction(EInputAction _action) const;
	/** Register Player to GameManager **/
	//void Register();
	
	FORCEINLINE class AFightingGame_PlayerController* GetPlayerController() const {return m_playerController;}
	FORCEINLINE void SetPlayerController(AFightingGame_PlayerController* _playerController) {m_playerController = _playerController;}
	//FORCEINLINE float GetPlayerID() const {return m_playerID;}
	//FORCEINLINE void SetPlayerID(float _playerID) {m_playerID = _playerID;}
	FORCEINLINE LogicStateMachine* GetStateMachine() const {return m_logicStateMachine;}
protected:

	UFUNCTION()
	void HandleCustomHit(const FHitResult& _hit);
	UFUNCTION()
	void HandleCustomOverlapBegin(AActor * _otherActor);
	UFUNCTION()
	void HandleCustomOverlapEnd(AActor * _otherActor);
	UPROPERTY(VisibleAnywhere)
	class UCustomMoveComponent* m_movement;
	UPROPERTY(VisibleAnywhere)
	class AFightingGame_PlayerController* m_playerController;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//int m_playerID;
	LogicStateMachine* m_logicStateMachine;
	AnimationStateMachine* m_animationStateMachine;
	UPROPERTY(EditAnywhere)
	float m_jumpStrength = 10.0f;
	UPROPERTY(EditAnywhere)
	float m_moveSpeed = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animation)
	UCharacterAnimationSet* m_animationSet;
public:
	UFUNCTION(BlueprintCallable)
	UCapsuleComponent* GetCapsuleComponent(){return Capsule;}
	UFUNCTION()
	USkeletalMeshComponent* GetSkeletalMeshComponent(){return Mesh;}
	
};

