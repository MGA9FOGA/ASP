// Copyright Epic Games, Inc. All Rights Reserved.

#include "ASPCharacter.h"

#include "AnimationStateMachine.h"
#include "CharacterAnimInstance.h"
#include "CustomMoveComponent.h"
#include "Engine/LocalPlayer.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
#include "FightingGame_PlayerController.h"
#include "FRollbackManager.h"
#include "GameManager.h"
#include "StateMachine.h"
#include "FRollbackManager.h"
#include "LogicStateMachine.h"
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
		Mesh->SetAnimInstanceClass(UCharacterAnimInstance::StaticClass());
	}

	//MovmentComp for the Actor
	m_movement = CreateDefaultSubobject<UCustomMoveComponent>(TEXT("MoveComponent"));
	m_logicStateMachine = new LogicStateMachine(*this);
	m_animationStateMachine = new AnimationStateMachine(*m_logicStateMachine, *this);
	
	m_moveSpeed = 10000.0f;
	m_jumpStrength = 500.0f;
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AASPCharacter::Tick(float _deltaSeconds)
{
	Super::Tick(_deltaSeconds);
}

void AASPCharacter::FixedUpdate(float _deltaTime)
{
	m_movement->SetLineTraceOnGroundStart(GetActorLocation());
	m_movement->SetLineTraceOnGroundEnd(m_movement->GetLineTraceOnGroundStart() - FVector(0, 0, 100.0f));
	m_movement->FixedUpdate(_deltaTime);
	m_playerController->Update(_deltaTime);
	if (m_logicStateMachine != nullptr)
	{
		m_logicStateMachine->Update(_deltaTime);
	}
	if (m_animationStateMachine != nullptr)
	{
		m_animationStateMachine->Update(_deltaTime);
	}
}

void AASPCharacter::PerformAction(EInputAction _action) const
{
	//if (!m_playerController) return;
	//switch (_action)
	//{
	//case EAction::MoveRight:
	//	m_playerController->Move(1.0f);
	//	break;
	//case EAction::MoveLeft:
	//	m_playerController->Move(-1.0f);
	//	break;
	//case EAction::UpMoveRight:
	//	m_playerController->Move(1.0f);
	//	break;
	//case EAction::UpMoveLeft:
	//	m_playerController->Move(-1.0f);
	//	break;
	//case EAction::CrouchMoveRight:
	//	m_playerController->Move(1.0f);
	//	break;
	//case EAction::CrouchMoveLeft:
	//	m_playerController->Move(-1.0f);
	//	break;
	//case EAction::Jump:
	//	m_playerController->Jump(500.0f);
	//	break;
	//default:
	//	m_playerController->StopMove();
	//	break;
	//}
}

void AASPCharacter::Move(float _value) const
{
	GetMovementComponent()->Move(m_moveSpeed * _value, m_playerController->GetGameManager()->GetFixedDeltatime());
}

void AASPCharacter::StopMove() const
{
	if (!m_movement) return;
	GetMovementComponent()->StopMove();
}

void AASPCharacter::Jump() const
{
	GetMovementComponent()->Jump(m_jumpStrength);
}


void AASPCharacter::Start()
{
	if (m_movement)
	{
		m_movement->OnCustomHit.AddDynamic(this, &AASPCharacter::HandleCustomHit);
		m_movement->OnCustomBeginOverlap.AddDynamic(this, &AASPCharacter::HandleCustomOverlapBegin);
		m_movement->OnCustomEndOverlap.AddDynamic(this, &AASPCharacter::HandleCustomOverlapEnd);

		if (UGameManager* gm = GetGameInstance()->GetSubsystem<UGameManager>())
		{
			gm->RegisterMovable(this);
		}
	}

	m_logicStateMachine->Start();
	m_animationStateMachine->Start();

	UCharacterAnimInstance* animInstance = Cast<UCharacterAnimInstance>(Mesh->GetAnimInstance());
	if (animInstance && m_animationStateMachine)
	{
		animInstance->OnLandingEndedNative.BindRaw(m_animationStateMachine, &AnimationStateMachine::OnLandingFinished);
	}
}



//void AASPCharacter::Register()
//{
//	if (UGameManager* gm = GetGameInstance()->GetSubsystem<UGameManager>())
//	{Unreal Engine reflection macro
     //UPROPERTY
     //
     //
     //Properties are declared using standard C++ variable syntax, preceded by the UPROPERTY macro which defines property metadata and variable specifiers.
     //
     //Remarks:
     //
     //The UPROPERTY macro enables a member variable of a UCLASS or a USTRUCT to be used as a UPROPERTY.
     //A UPROPERTY has many uses. It can allow the variable to be replicated, serialized, and accessed from Blueprints. They are also used by the garbage collector to keep track of how many references there are to a UObject.
     //Learn more: Properties, Property Specifiers.
     //
     //Example:
     //
     //
     //
     //UPROPERTY([specifier, specifier, ...], [meta(key=value, key=value, ...)])
     //Type VariableName;
     //
     // Src.Caches.UE53_generated_header.h
//		if (!gm->GetPlayer1())
//		{
//			gm->RegisterPlayer1(this, 0);
//			UE_LOG(LogTemp, Warning, TEXT("GetPlayer1(): m_player1 ist %s"), *gm->GetPlayer1()->GetName());
//		}
//		else if (!gm->GetPlayer2())
//		{
//			gm->RegisterPlayer2(this, 1);
//			UE_LOG(LogTemp, Warning, TEXT("GetPlayer2(): m_player1 ist %s"), *gm->GetPlayer2()->GetName());
//		}
//	}
//}

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
