// Copyright Epic Games, Inc. All Rights Reserved.

#include "ASPCharacter.h"
#include "CharacterAnimInstance.h"
#include "Engine/LocalPlayer.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
#include "FRollbackManager.h"
#include "UPushBoxComponent.h"


//////////////////////////////////////////////////////////////////////////
// AASPCharacter

const FName AASPCharacter::CharacterMeshName(TEXT("CharacterMesh"));
const FName AASPCharacter::CharacterColliderName(TEXT("Collider"));

void AASPCharacter::SetRollbackDebugColor(bool bActive)
{
	USkeletalMeshComponent* mesh = GetSkeletalMeshComponent();
	if (!mesh)
		return;

	mesh->SetRenderCustomDepth(bActive);
	mesh->SetCustomDepthStencilValue(bActive ? 2 : 0);
}

AASPCharacter::AASPCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(CharacterColliderName);
	RootComponent = Capsule;
	Capsule->InitCapsuleSize(42.f, 96.0f);

	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Capsule->SetCollisionResponseToAllChannels(ECR_Block);
	Capsule->SetGenerateOverlapEvents(true);
	Capsule->SetNotifyRigidBodyCollision(true);

	Capsule->CanCharacterStepUpOn = ECB_No;
	Capsule->SetShouldUpdatePhysicsVolume(true);
	Capsule->SetCanEverAffectNavigation(false);
	Capsule->bDynamicObstacle = true;

	PushBox = CreateDefaultSubobject<UPushBoxComponent>(TEXT("PushBox"));
	PushBox->SetupAttachment(RootComponent);
	PushBox->SetBoxExtent(FVector(10.f, 40.f, 80.f));

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(CharacterMeshName);
	if (Mesh)
	{
		Mesh->AlwaysLoadOnClient = true;
		Mesh->AlwaysLoadOnServer = true;
		Mesh->bOwnerNoSee = false;
		Mesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
		Mesh->bCastDynamicShadow = true;
		Mesh->bAffectDynamicIndirectLighting = true;
		Mesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Mesh->SetupAttachment(RootComponent);
		static FName MeshCollisionProfileName(TEXT("CharacterMesh"));
		Mesh->SetCollisionProfileName(MeshCollisionProfileName);
		Mesh->SetGenerateOverlapEvents(false);
		Mesh->SetCanEverAffectNavigation(false);
		Mesh->SetAnimInstanceClass(UCharacterAnimInstance::StaticClass());
	}

	//OnCustomHit.AddDynamic(this, &AASPCharacter::HandleCustomHit);
	//OnCustomBeginOverlap.AddDynamic(this, &AASPCharacter::HandleCustomOverlapBegin);
	//OnCustomEndOverlap.AddDynamic(this, &AASPCharacter::HandleCustomOverlapEnd);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AASPCharacter::Tick(float _deltaSeconds)
{
	Super::Tick(_deltaSeconds);
}

void AASPCharacter::OnOverlapBegin(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,
                                   UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep,
                                   const FHitResult& _sweepResult)
{
	if (_otherActor && _otherActor
		!=
		GetOwner()
	)
	{
		OnCustomBeginOverlap.Broadcast(_otherActor);
	}
}

void AASPCharacter::OnHit(UPrimitiveComponent* _hitComp, AActor* _otherActor,
                          UPrimitiveComponent* _otherComp,
                          FVector _ormalImpulse, const FHitResult& _hit)
{
	if (_otherActor && _otherActor
		!=
		GetOwner()
	)
	{
		OnCustomHit.Broadcast(_hit);
	}
}

void AASPCharacter::OnOverlapEnd(UPrimitiveComponent* _overlappedComp, AActor* _otherActor,
                                 UPrimitiveComponent* _otherComp, int32 _otherBodyIndex)
{
	if (_otherActor && _otherActor
		!=
		GetOwner()
	)
	{
		OnCustomEndOverlap.Broadcast(_otherActor);
	}
}

void AASPCharacter::Start()
{
	if (Capsule)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Using capsule: %s"), *GetName(), *Capsule->GetName());

		Capsule->OnComponentHit.AddDynamic(this, &AASPCharacter::OnHit);
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &AASPCharacter::OnOverlapBegin);
		Capsule->OnComponentEndOverlap.AddDynamic(this, &AASPCharacter::OnOverlapEnd);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] No capsule found!"), *GetOwner()->GetName());
	}
	m_forwardVector = GetActorForwardVector();

	if (USkeletalMeshComponent* mesh = GetSkeletalMeshComponent())
	{
		OriginalMaterial = mesh->GetMaterial(0);
	}
}

void AASPCharacter::HandleCustomHit(const FHitResult& _hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Character got hit event from component, hit actor: %s"),
	       *_hit.GetActor()->GetName());
}

void AASPCharacter::HandleCustomOverlapBegin(AActor* _otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Character BeginOverlap with %s"), *_otherActor->GetName());
}

void AASPCharacter::HandleCustomOverlapEnd(AActor* _otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Character EndOverlap with %s"), *_otherActor->GetName());
}

void AASPCharacter::LookLeft()
{
	m_targetRotation = FRotator(0.0f, -180.0f, 0.0f);
}

void AASPCharacter::LookRight()
{
	m_targetRotation = FRotator(0.0f, 0.0f, 0.0f);
}

void AASPCharacter::Rotate()
{
	SetActorRotation(m_targetRotation);
	m_forwardVector = GetActorForwardVector();
}
