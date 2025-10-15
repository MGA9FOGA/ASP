// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomMoveComponent.generated.h"


class UCapsuleComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomHit, const FHitResult&, HitResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomOverlap, AActor*, OtherActor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASP_API UCustomMoveComponent : public UActorComponent
{
	GENERATED_BODY()

	UCustomMoveComponent();
public:
	virtual void BeginPlay() override;
	void FixedUpdate(float _deltaTime);
	void ApplyGravity(float _deltaTime);
	void Move(FVector _direction, float _speed);
	void StopMove(float _speed, float _deltatime);
	void Jump(float _jumpStrength);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Gravity = 980.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity = FVector::ZeroVector;

	//Getter / Setter
	UFUNCTION(BlueprintCallable)
	bool GetBoolOnGround () const {return b_OnGround;}
	UFUNCTION(BlueprintCallable)
	void SetBoolOnGround (bool _bool){b_OnGround = _bool;}
	UFUNCTION(BlueprintCallable)
	FVector GetLineTraceOnGroundStart() const {return  m_start;}
	UFUNCTION(BlueprintCallable)
	void SetLineTraceOnGroundStart(FVector _start){m_start = _start;}
	UFUNCTION(BlueprintCallable)
	FVector GetLineTraceOnGroundEnd() const {return m_end;}
	UFUNCTION(BlueprintCallable)
	void SetLineTraceOnGroundEnd(FVector _end){m_end = _end;}
	UFUNCTION(BlueprintCallable)
	FHitResult GetHitResultOnGround() const {return m_hitResult;}
	UFUNCTION(BlueprintCallable)
	void AddLinetraceIgnore(AActor* _actor){m_collisionParams.AddIgnoredActor(_actor) ;}

	//Ref on Character Capsule
	UPROPERTY()
	UCapsuleComponent* Capsule = nullptr;

	//Collider Hit
	UPROPERTY(BlueprintAssignable, Category="CustomMove|Events")
	FOnCustomHit OnCustomHit;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* _hitComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, FVector _ormalImpulse, const FHitResult& _hit);

	//Overlap Begin
	UPROPERTY(BlueprintAssignable)
	FOnCustomOverlap OnCustomBeginOverlap;
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep, const FHitResult& _sweepResult);

	//Overlap End
	UPROPERTY(BlueprintAssignable)
	FOnCustomOverlap OnCustomEndOverlap;
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,UPrimitiveComponent* _otherComp, int32 _otherBodyIndex);
	
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	bool b_OnGround = false;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	bool b_JustJumped = false;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	bool b_isColliderOnTheGround = false;	
	FCollisionQueryParams m_collisionParams;
	UWorld* m_world;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	FVector m_start;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	FVector m_end;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	FHitResult m_hitResult;

	void LineTraceIgnoreClass(UWorld* _world, TSubclassOf<class AASPCharacter> _ignoreClass);
	bool CheckIfOnGround(UWorld* _world, FHitResult& _outHit, FVector _start, FVector _end, FCollisionQueryParams _params) const;
};

