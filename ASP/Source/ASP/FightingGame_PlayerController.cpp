// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGame_PlayerController.h"
#include "ASPCharacter.h"
#include "CustomMoveComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameManager.h"
#include "InputHandler.h"
#include "LogicStateMachine.h"
#include "StateMachine.h"

void AFightingGame_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	Start();
	if (UGameManager* GM = GetGameInstance()->GetSubsystem<UGameManager>())
	{
		GM->BeginPlaySetup();
	}
}

void AFightingGame_PlayerController::Start()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
	GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
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

void AFightingGame_PlayerController::SetCharacterRef(AASPCharacter* _character)
{
	m_playerCharacter = _character;
	if (_character)
	{
		_character->SetPlayerController(this);
		_character->GetStateMachine()->SetPlayerController(this);
	}
}

void AFightingGame_PlayerController::ResetInputBuffer()
{
	b_leftPressed = b_rightPressed = b_upPressed = b_downPressed = false;
	b_jumpPressed = b_Attack1Pressed = b_Attack2Pressed = b_blockPressed = false;
	Input = FRawInput();
}

