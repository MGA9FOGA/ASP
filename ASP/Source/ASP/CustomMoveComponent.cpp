// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMoveComponent.h"

#include "ASPCharacter.h"
#include "CollisionDebugDrawingPublic.h"
#include "DynamicCamera.h"
#include "EngineUtils.h"
#include "UPushBoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

constexpr float PushboxHeightTolerance = 40.0f;
constexpr float diff = 194.5f ;

UCustomMoveComponent::UCustomMoveComponent()
{
}

void UCustomMoveComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCustomMoveComponent::BeginPlay()
{
	Super::BeginPlay();

//	if (GetWorld())
//	{
//		m_world = GetWorld();
//	}
//	LineTraceIgnoreClass(GetWorld(), TSubclassOf<AASPCharacter>());
//
//	AActor* Owner = GetOwner();
//	if (Owner)
//	{
//		AASPCharacter* CharacterOwner = Cast<AASPCharacter>(Owner);
//		if (CharacterOwner)
//		{
//			Capsule = CharacterOwner->GetCapsuleComponent();
//		}
//		else
//		{
//			Capsule = Owner->FindComponentByClass<UCapsuleComponent>();
//		}
//	}
//
//	if (Capsule)
//	{
//		UE_LOG(LogTemp, Log, TEXT("[%s] Using capsule: %s"), *GetOwner()->GetName(), *Capsule->GetName());
//
//		//Capsule->OnComponentHit.AddDynamic(this, &UCustomMoveComponent::OnHit);
//		Capsule->OnComponentBeginOverlap.AddDynamic(this, &UCustomMoveComponent::OnOverlapBegin);
//		Capsule->OnComponentEndOverlap.AddDynamic(this, &UCustomMoveComponent::OnOverlapEnd);
//	}
//	else
//	{
//		UE_LOG(LogTemp, Warning, TEXT("[%s] No capsule found!"), *GetOwner()->GetName());
//	}
//
//	m_camera = Cast<ADynamicCamera>(UGameplayStatics::GetActorOfClass(m_world, ADynamicCamera::StaticClass()));
}

void UCustomMoveComponent::FixedUpdate(float _deltaTime)
{
//	AActor* owner = GetOwner();
//	if (!owner) return;
//	// 1. Ground check
//	b_OnGround = CheckIfOnGround(
//		m_world, m_hitResult, m_start, m_end, m_collisionParams
//	);
//
//	//// 2. Gravity
//	if (!b_OnGround || b_JustJumped)
//	{
//		ApplyGravity(_deltaTime);
//	}
//
//	// 4. Ground-Snap
//	if (b_OnGround && m_velocity.Z <= 0)
//	{
//		m_newLocation.Z = m_hitResult.ImpactPoint.Z + Capsule->GetScaledCapsuleHalfHeight();
//		m_velocity.Z = 0;
//		b_OnGround = true;
//	}
//	else
//	{
//		b_OnGround = false;
//	}
//
//	m_newLocation = owner->GetActorLocation();
//	m_newLocation += m_velocity * _deltaTime;
//	owner->SetActorLocation(m_newLocation, false);
//
//	if (b_OnGround || b_JustJumped)
//		ResolvePushBoxes();
//	ClampToStage(owner);
//	b_JustJumped = false;
}

void UCustomMoveComponent::ApplyGravity(float _deltaTime)
{
	//Calculate Gravitiy Velocity
////	m_velocity.Z -= Gravity * _deltaTime * 2;
}

void UCustomMoveComponent::Move(float _value, float _speed)
{
	//Calculate Velocity
//	m_velocity.Y = _value * _speed;
}

void UCustomMoveComponent::StopMove()
{
//	m_velocity.Y = 0.0f;
}

void UCustomMoveComponent::Jump(float _jumpStrength)
{
//	if (!b_OnGround) return;
//	UE_LOG(LogTemp, Warning, TEXT("Jump"));
//
//	m_velocity.Z = _jumpStrength;
//	b_OnGround = false;
//	b_JustJumped = true;
}

void UCustomMoveComponent::ClampToStage(AActor* _actor)
{
//	FVector location = _actor->GetActorLocation();
//	location.Y = FMath::Clamp(location.Y, MinY, MaxY);
//	_actor->SetActorLocation(location, false);
}

void UCustomMoveComponent::ResolvePushBoxes()
{
//	AActor* Owner = GetOwner();
//	if (!Owner) return;
//
//	AASPCharacter* selfChar = Cast<AASPCharacter>(Owner);
//	
//	if (!selfChar || !selfChar->GetPushBox()) return;
//
//	for (TActorIterator<AASPCharacter> It(GetWorld()); It; ++It)
//	{
//		AASPCharacter* Other = *It;
//		if (Other == selfChar || !Other->GetPushBox()) continue;
//		if (!GetBoolOnGround() || !Other->GetNoChaosMovementComponent()->GetBoolOnGround())
//			continue; 
//
//		const float selfY = selfChar->GetActorLocation().Y;
//		const float otherY = Other->GetActorLocation().Y;
//
//		const float minDist =
//			selfChar->GetPushBox()->GetHalfWidth() +
//			Other->GetPushBox()->GetHalfWidth();
//
//		const float Delta = selfY - otherY;
//		const float Dist = FMath::Abs(Delta);
//
//		if (Dist < minDist)
//		{
//			const float Push = (minDist - Dist);
//			const float Dir = FMath::Sign(Delta);
//
//			FVector L1 = selfChar->GetActorLocation();
//
//			L1.Y += Push * Dir;
//
//			selfChar->SetActorLocation(L1, false);;
//		}
//	}
}

//oid UCustomMoveComponent::OnHit(UPrimitiveComponent* _hitComp, AActor* _otherActor,
//                                UPrimitiveComponent* _otherComp,
//                                FVector _ormalImpulse, const FHitResult& _hit)
//
///	if (_otherActor && _otherActor
///		!=
///		GetOwner()
///	)
///	{
///		UE_LOG(LogTemp, Warning, TEXT("CustomMoveComponent Hit with %s"), *_otherActor->GetName());
///		OnCustomHit.Broadcast(_hit);
///	}
//

//oid UCustomMoveComponent::OnOverlapBegin(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,
//                                         UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep,
//                                         const FHitResult& _sweepResult)
//
///	if (_otherActor && _otherActor
///		!=
///		GetOwner()
///	)
///	{
///		UE_LOG(LogTemp, Log, TEXT("[%s] Overlap Begin: %s"), *GetOwner()->GetName(), *_otherActor->GetName());
///		OnCustomBeginOverlap.Broadcast(_otherActor);
///	}
//

void UCustomMoveComponent::OnOverlapEnd(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,
                                        UPrimitiveComponent* _otherComp, int32 _otherBodyIndex)
{
//	if (_otherActor && _otherActor
//		!=
//		GetOwner()
//	)
//	{
//		UE_LOG(LogTemp, Log, TEXT("[%s] Overlap End: %s"), *GetOwner()->GetName(), *_otherActor->GetName());
//		OnCustomEndOverlap.Broadcast(_otherActor);
//	}
}

void UCustomMoveComponent::LineTraceIgnoreClass(UWorld* _world, TSubclassOf<AASPCharacter> _ignoreClass)
{
//	for (TActorIterator<AASPCharacter> it(_world, _ignoreClass); it; ++it)
//	{
//		m_collisionParams.AddIgnoredActor(*it);
//	}
//	m_collisionParams.AddIgnoredActor(GetOwner());
//	TArray<AActor*> ActorsToIgnore;
//	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("IgnoreCollision"), ActorsToIgnore);
//
//	for (AActor* Actor : ActorsToIgnore)
//	{
//		if (Actor)
//		{
//			m_collisionParams.AddIgnoredActor(Actor);
//		}
//	}
}

//bool UCustomMoveComponent::CheckIfOnGround(UWorld* _world, FHitResult& _outHit, FVector _start, FVector _end,
//                                           FCollisionQueryParams _params) const
//{
////	if (!m_world) return false;
////	return m_world->LineTraceSingleByChannel(_outHit, _start, _end, ECC_Visibility, _params);
//}
