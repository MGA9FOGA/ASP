// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMoveComponent.h"

#include "ASPCharacter.h"
#include "CollisionDebugDrawingPublic.h"
#include "EngineUtils.h"
#include "Components/CapsuleComponent.h"

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

	if (GetWorld())
	{
		m_world = GetWorld();
	}
	LineTraceIgnoreClass(GetWorld(), TSubclassOf<AASPCharacter>());

	AActor* Owner = GetOwner();
	if (Owner)
	{
		AASPCharacter* CharacterOwner = Cast<AASPCharacter>(Owner);
		if (CharacterOwner)
		{
			Capsule = CharacterOwner->GetCapsuleComponent();
		}
		else
		{
			Capsule = Owner->FindComponentByClass<UCapsuleComponent>();
		}
	}

	if (Capsule)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Using capsule: %s"), *GetOwner()->GetName(), *Capsule->GetName());

		Capsule->OnComponentHit.AddDynamic(this, &UCustomMoveComponent::OnHit);
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &UCustomMoveComponent::OnOverlapBegin);
		Capsule->OnComponentEndOverlap.AddDynamic(this, &UCustomMoveComponent::OnOverlapEnd);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] No capsule found!"), *GetOwner()->GetName());
	}
}

void UCustomMoveComponent::FixedUpdate(float _deltaTime)
{
	//Apply the calculated Velocity
	if (!b_OnGround || b_JustJumped)
	{
		ApplyGravity(_deltaTime);
	}

	if (AActor* owner = GetOwner())
	{
		FColor LineColor = b_OnGround ? FColor::Red : FColor::Green;
		DrawDebugLine(GetWorld(), m_start, m_end, LineColor, false, 1.0f, 0, 2.0f);
		m_newLocation = GetOwner()->GetActorLocation() + m_velocity * _deltaTime;
		owner->SetActorLocation(m_newLocation, true);
		//UE_LOG(LogTemp, Warning, TEXT("Update"));
	}
	b_JustJumped = false;
	b_OnGround = CheckIfOnGround(m_world, m_hitResult, m_start, m_end, m_collisionParams);
}


void UCustomMoveComponent::ApplyGravity(float _deltaTime)
{
	//Calculate Gravitiy Velocity
	m_velocity.Z -= Gravity * _deltaTime;
}

void UCustomMoveComponent::Move(float _value, float _speed)
{
	//Calculate Velocity
	//if (Velocity.Y > 200.0f || Velocity.Y < - 200.0f) return;
	//Velocity += _direction * _speed;
	m_velocity.Y = _value * _speed;
}

void UCustomMoveComponent::StopMove()
{
	m_velocity.Y = 0.0f;
}

void UCustomMoveComponent::Jump(float _jumpStrength)
{
	if (!b_OnGround) return;
	UE_LOG(LogTemp, Warning, TEXT("Jump"));
	m_velocity.Z = _jumpStrength;
	b_OnGround = false;
	b_JustJumped = true;
}

void UCustomMoveComponent::OnHit(UPrimitiveComponent* _hitComp, AActor* _otherActor, UPrimitiveComponent* _otherComp,
                                 FVector _ormalImpulse, const FHitResult& _hit)
{
	if (_otherActor && _otherActor != GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("CustomMoveComponent Hit with %s"), *_otherActor->GetName());
		OnCustomHit.Broadcast(_hit);
		
	}

	if (_otherActor && _otherActor->Tags.Contains(FName("Ground")) && _otherActor != GetOwner())
	{
		m_velocity.Z = 0.0f;
	}
}

void UCustomMoveComponent::OnOverlapBegin(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,
                                          UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep,
                                          const FHitResult& _sweepResult)
{
	if (_otherActor && _otherActor != GetOwner())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Overlap Begin: %s"), *GetOwner()->GetName(), *_otherActor->GetName());
		OnCustomBeginOverlap.Broadcast(_otherActor);
	}
}

void UCustomMoveComponent::OnOverlapEnd(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,
                                        UPrimitiveComponent* _otherComp, int32 _otherBodyIndex)
{
	if (_otherActor && _otherActor != GetOwner())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Overlap End: %s"), *GetOwner()->GetName(), *_otherActor->GetName());
		OnCustomEndOverlap.Broadcast(_otherActor);
	}
}

void UCustomMoveComponent::LineTraceIgnoreClass(UWorld* _world, TSubclassOf<AASPCharacter> _ignoreClass)
{
	for (TActorIterator<AASPCharacter> it(_world, _ignoreClass); it; ++it)
	{
		m_collisionParams.AddIgnoredActor(*it);
	}
	m_collisionParams.AddIgnoredActor(GetOwner());
}

bool UCustomMoveComponent::CheckIfOnGround(UWorld* _world, FHitResult& _outHit, FVector _start, FVector _end,
                                           FCollisionQueryParams _params) const
{
	if (!m_world) return false;
	return m_world->LineTraceSingleByChannel(_outHit, _start, _end, ECC_Visibility, _params);
}
