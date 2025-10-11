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
	
	// Set size for collision capsule
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(CharacterColliderName);
	Capsule->InitCapsuleSize(42.f, 96.0f);
	Capsule->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

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
		Mesh->SetupAttachment(Capsule);
		static FName MeshCollisionProfileName(TEXT("CharacterMesh"));
		Mesh->SetCollisionProfileName(MeshCollisionProfileName);
		Mesh->SetGenerateOverlapEvents(false);
		Mesh->SetCanEverAffectNavigation(false);
	}

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	m_movement = CreateDefaultSubobject<UCustomMoveComponent>(TEXT("MoveComponent"));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

//void AASPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	// Set up action bindings
//	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
//		
//		// Jumping
//		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
//		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
////
//		// Moving
//		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AASPCharacter::Move);
//
//		// Looking
//		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AASPCharacter::Look);
//	}
//	else
//	{
//		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
//	}
//}

void AASPCharacter::FixedUpdate(float _deltaTime)
{
	m_movement->FixedUpdate(_deltaTime);
}

void AASPCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (UGameManager* gm = GetGameInstance()->GetSubsystem<UGameManager>())
	{
		gm->RegisterMovable(this);
	}
	Register();
}


void AASPCharacter::Register()
{
	if (UGameManager* gm = GetGameInstance()->GetSubsystem<UGameManager>())
	{
		if (!gm->Player1)
		{
			gm->RegisterPlayer1(this);
			return;
		}
		else if (!gm->Player2)
		{
			gm->RegisterPlayer2(this);
		}
	}
}
