// Copyright Epic Games, Inc. All Rights Reserved.

#include "ASPCharacter.h"

#include "CustomMoveComponent.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameManager.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AASPCharacter

const FName AASPCharacter::CharacterMeshName(TEXT("CharacterMesh"));
const FName AASPCharacter::CharacterColliderName(TEXT("Collider"));

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
	}

	//MovmentComp for the Actor
	m_movement = CreateDefaultSubobject<UCustomMoveComponent>(TEXT("MoveComponent"));
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AASPCharacter::FixedUpdate(float _deltaTime)
{
	m_movement->SetLineTraceOnGroundStart(GetActorLocation());
	m_movement->SetLineTraceOnGroundEnd(m_movement->GetLineTraceOnGroundStart() - FVector(0, 0, 100.0f));
	m_movement->FixedUpdate(_deltaTime);
}

void AASPCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (m_movement)
	{
		m_movement->OnCustomHit.AddDynamic(this, &AASPCharacter::HandleCustomHit);
		m_movement->OnCustomBeginOverlap.AddDynamic(this, &AASPCharacter::HandleCustomOverlapBegin);
		m_movement->OnCustomEndOverlap.AddDynamic(this, &AASPCharacter::HandleCustomOverlapEnd);

		if (UGameManager* gm = GetGameInstance()->GetSubsystem<UGameManager>())
		{
			gm->RegisterMovable(this);
		}
		Register();
	}
}


void AASPCharacter::Register()
{
	if (UGameManager* gm = GetGameInstance()->GetSubsystem<UGameManager>())
	{
		if (!gm->GetPlayer1())
		{
			gm->RegisterPlayer1(this);
			return;
		}
		else if (!gm->GetPlayer2())
		{
			gm->RegisterPlayer2(this);
		}
	}
}

void AASPCharacter::HandleCustomHit(const FHitResult& _hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Character got hit event from component, hit actor: %s"), *_hit.GetActor()->GetName());
}

void AASPCharacter::HandleCustomOverlapBegin(AActor * _otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Character BeginOverlap with %s"), *_otherActor->GetName());
}

void AASPCharacter::HandleCustomOverlapEnd(AActor * _otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Character EndOverlap with %s"), *_otherActor->GetName());
}
