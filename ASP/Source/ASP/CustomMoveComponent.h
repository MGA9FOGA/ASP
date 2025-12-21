// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DynamicMesh/MeshTransforms.h"
#include "CustomMoveComponent.generated.h"


class ADynamicCamera;
class UCapsuleComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomHit, const FHitResult&, HitResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomOverlap, AActor*, OtherActor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASP_API UCustomMoveComponent : public UActorComponent
{
	GENERATED_BODY()

	UCustomMoveComponent();
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;
	void FixedUpdate(float _deltaTime);
	void ApplyGravity(float _deltaTime);
	void Move(float _value, float _speed);
	void StopMove();
	void Jump(float _jumpStrength);
	void ClampToStage(AActor* _actor);
	void ResolvePushBoxes();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Gravity = 980.f;

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

	UPROPERTY(EditAnywhere, Category="Movement|Bounds")
	float MinY = 0.0f;
	UPROPERTY(EditAnywhere, Category="Movement|Bounds")
	float MaxY = 3400.0f;
	UPROPERTY(EditAnywhere, Category="Movement|Bounds")
	float HalfArenaWidth = 1700.0f;
	UPROPERTY(EditAnywhere, Category="Movement|Bounds")
	float CameraCenterY;
	
	FORCEINLINE FVector GetLocation() const {return m_newLocation;}
	FORCEINLINE void SetLocation(const FVector& _location) {m_newLocation = _location;}
	FORCEINLINE FVector GetOwnVelocity() const {return m_velocity;}
	FORCEINLINE void SetVelocity(const FVector& _velocity) {m_velocity = _velocity;}

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	ADynamicCamera* m_camera;	
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
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess=true))
	FVector m_newLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	FVector m_velocity = FVector::ZeroVector;

	void LineTraceIgnoreClass(UWorld* _world, TSubclassOf<class AASPCharacter> _ignoreClass);
	bool CheckIfOnGround(UWorld* _world, FHitResult& _outHit, FVector _start, FVector _end, FCollisionQueryParams _params) const;
};

