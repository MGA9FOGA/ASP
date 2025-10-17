// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGame_PlayerController.h"
#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameManager.h"
#include "InputHandler.h"

void AFightingGame_PlayerController::SpawnCharacter()
{
	if (UWorld* world = GetWorld())
	{
		if (playerClass && m_gameManager)
		{
			m_playerCharacter = world->SpawnActor<AASPCharacter>(playerClass, FVector::ZeroVector,
			                                                     FRotator::ZeroRotator);
			if (m_playerCharacter)
			{
				FVector pos = (m_playerCharacter->GetPlayerID() == 0)
					              ? m_gameManager->GetPlayer1SpawnPos() 
					              : m_gameManager->GetPlayer2SpawnPos(); 
				FRotator rot = (m_playerCharacter->GetPlayerID() == 0)
					               ? m_gameManager->GetPlayer1SpawnRotation() 
					               : m_gameManager->GetPlayer2SpawnRotation(); 

				m_playerCharacter->SetActorLocationAndRotation(pos,rot);
				m_forwardDirection = m_playerCharacter->GetActorForwardVector();
				m_playerCharacter->SetPlayerController(this);
			}
		}
	}
}

void AFightingGame_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
	m_gameManager = GetGameInstance()->GetSubsystem<UGameManager>();
	FTimerHandle timerHandle;

	GetWorld()->GetTimerManager().SetTimer(
		timerHandle,
		this,
		&AFightingGame_PlayerController::SpawnCharacter,
		3.0f,
		false
	);
}

void AFightingGame_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Jumping
		enhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this,
		                          &AFightingGame_PlayerController::OnPressedJump);
		enhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this,
		                          &AFightingGame_PlayerController::OnJumpReleased);
		enhancedInput->BindAction(JumpAction, ETriggerEvent::Canceled, this,
		                          &AFightingGame_PlayerController::OnJumpReleased);
		// Moving
		enhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this,
		                          &AFightingGame_PlayerController::OnPressedMovement);
		enhancedInput->BindAction(MoveAction, ETriggerEvent::Completed, this,
		                          &AFightingGame_PlayerController::OnMoveReleased);
		enhancedInput->BindAction(MoveAction, ETriggerEvent::Canceled, this,
		                          &AFightingGame_PlayerController::OnMoveReleased);
	}
}

void AFightingGame_PlayerController::Update(float _deltatime)
{
	FRawInput raw;
	raw.Left = b_leftPressed;
	raw.Right = b_rightPressed;
	raw.Up = b_upPressed;
	raw.Down = b_downPressed;
	raw.Jump = b_jumpPressed;
	raw.Attack1 = b_Attack1Pressed;
	raw.Attack2 = b_Attack2Pressed;
	raw.Block = b_blockPressed;

	uint8 encoded = InputHandler::EncodeInput(raw);

	FInputPacket packet(m_gameManager->FrameNumber, encoded, 0, 0);

	if (m_gameManager)
	{
		m_gameManager->AddInputToQueue(this, packet);
	}
}

void AFightingGame_PlayerController::OnPressedMovement(const FInputActionValue& _value)
{
	const FVector2d movementVector = _value.Get<FVector2d>();

	b_upPressed = movementVector.Y > m_deadzone;
	b_downPressed = movementVector.Y < -m_deadzone;
	b_rightPressed = movementVector.X > m_deadzone;
	b_leftPressed = movementVector.X < -m_deadzone;
}

void AFightingGame_PlayerController::OnMoveReleased()
{
	b_downPressed = false;
	b_leftPressed = false;
	b_rightPressed = false;
	b_upPressed = false;
}

void AFightingGame_PlayerController::OnPressedJump()
{
	b_jumpPressed = true;
}

void AFightingGame_PlayerController::OnJumpReleased()
{
	b_jumpPressed = false;
}

void AFightingGame_PlayerController::OnPressedCrouch()
{
	b_downPressed = true;
}

void AFightingGame_PlayerController::OnCrouchReleased()
{
	b_downPressed = false;
}

void AFightingGame_PlayerController::OnPressedAttack1()
{
	b_Attack1Pressed = true;
}

void AFightingGame_PlayerController::OnAttack1Released()
{
	b_Attack1Pressed = false;
}

void AFightingGame_PlayerController::OnPressedAttack2()
{
	b_Attack2Pressed = true;
}

void AFightingGame_PlayerController::OnAttack1Released2()
{
	b_Attack2Pressed = false;
}

void AFightingGame_PlayerController::OnPressedBlock()
{
	b_blockPressed = true;
}

void AFightingGame_PlayerController::OnBlockReleased()
{
	b_blockPressed = false;
}

void AFightingGame_PlayerController::Move(float _value)
{
	if (m_playerCharacter->GetClass()->ImplementsInterface(UMoveableInterface::StaticClass()))
	{
		m_playerCharacter->GetMovementComponent()->Move(FVector(0.0f, _value, 0.0), m_moveSpeed);
	}
}

void AFightingGame_PlayerController::StopMove()
{
	if (m_playerCharacter->GetClass()->ImplementsInterface(UMoveableInterface::StaticClass()))
	{
		m_playerCharacter->GetMovementComponent()->StopMove(m_moveSpeed, m_gameManager->GetFixedDeltatime());
	}
}

void AFightingGame_PlayerController::Jump(float _value)
{
	if (m_playerCharacter->GetClass()->ImplementsInterface(UMoveableInterface::StaticClass()))
	{
		m_playerCharacter->GetMovementComponent()->Jump(_value);
	}
}
