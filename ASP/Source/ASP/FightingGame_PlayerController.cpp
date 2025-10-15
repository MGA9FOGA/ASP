// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGame_PlayerController.h"
#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AFightingGame_PlayerController::SpawnCharacter()
{
	if (UWorld* world = GetWorld())
	{
		//!!!!!!!!!!!!!!In GameManager zwei  position zum spaenen setzten!!!!!!!!!!!!!!!!!!!!!!!
		FVector spawnLocation = FVector(730.0f,1230.0f,1800.0f);
		FRotator spawnRotation = FRotator(0.0f);
		
		if (playerClass)
		{
			m_playerCharacter  = world->SpawnActor<AASPCharacter>(playerClass, spawnLocation, spawnRotation);
			if (m_playerCharacter)
			{
				UE_LOG(LogTemp, Warning, TEXT("Actor erfolgreich gespawnt!"));
				m_forwardDirection = m_playerCharacter->GetActorForwardVector();
			}
		}
	}
}

void AFightingGame_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	SpawnCharacter();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
	m_gameManager = GetGameInstance()->GetSubsystem<UGameManager>();
}

void AFightingGame_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//if (m_playerCharacter)
	//	m_playerCharacter->GetMovementComponent()->Move(FVector(0,5,0),10);
}

void AFightingGame_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Jumping
		enhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AFightingGame_PlayerController::Jump);
		// Moving
		enhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFightingGame_PlayerController::OnMovement);
		enhancedInput->BindAction(MoveAction, ETriggerEvent::Completed, this, &AFightingGame_PlayerController::OnReleased);
		enhancedInput->BindAction(MoveAction, ETriggerEvent::Canceled, this, &AFightingGame_PlayerController::OnReleased);

	}

}

void AFightingGame_PlayerController::OnMovement(const FInputActionValue& _value)
{
	
	if (m_playerCharacter->GetClass()->ImplementsInterface(UMoveableInterface::StaticClass()))
	{
		const FVector2d movementVector = _value.Get<FVector2d>();
		m_playerCharacter->GetMovementComponent()->Move(FVector(0.0f, movementVector.X, 0.0), m_moveSpeed);
	}
}

void AFightingGame_PlayerController::OnReleased(const FInputActionValue& _value)
{
	if (m_playerCharacter->GetClass()->ImplementsInterface(UMoveableInterface::StaticClass()))
	{
		const FVector2d movementVector = _value.Get<FVector2d>();
		m_playerCharacter->GetMovementComponent()->StopMove(m_moveSpeed, m_gameManager->GetFixedDeltatime());
	}
}

void AFightingGame_PlayerController::Jump()
{
	if (m_playerCharacter->GetClass()->ImplementsInterface(UMoveableInterface::StaticClass()))
	{
		m_playerCharacter->GetMovementComponent()->Jump(500.0f);
	}
}
           
void AFightingGame_PlayerController::Crouch()
{
}
