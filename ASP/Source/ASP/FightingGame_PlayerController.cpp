// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGame_PlayerController.h"
#include "ASPCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameManager.h"
#include "InputHandler.h"
#include "LogicStateMachine.h"
#include "StateMachine.h"

void AFightingGame_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	m_gameManager = GetGameInstance()->GetSubsystem<UGameManager>();
}

void AFightingGame_PlayerController::SetCharacterRef(AASPCharacter* _character)
{
	m_playerCharacter = _character;
	if (_character)
	{
		_character->SetPlayerController(this);
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

		// Rollback
		enhancedInput->BindAction(RollbackAction, ETriggerEvent::Started, this,
		                          &AFightingGame_PlayerController::OnRollbackPressed);
	}
}

void AFightingGame_PlayerController::Update(float _deltatime)
{
	if (!m_gameManager)
	{
		return;
	}

	// ==============================
	// 1. RAW INPUT 
	// ==============================
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

	// ==============================
	// 2. FRAME 
	// ==============================
	const int32 currentFrame = m_gameManager->GetFrameNumber() + 1;

	static int32 lastSentFrame = -1;
	static int32 HoldInputUntilFrame = -1;

	// ==============================
	// 3. DEBUG: ROLLBACK 
	// ==============================
	if (bDebugRollbackPressed && HoldInputUntilFrame < 0)
	{
		HoldInputUntilFrame = currentFrame;
		bDebugRollbackPressed = false;

		UE_LOG(LogTemp, Warning, TEXT("[Debug] Holding input at frame %d"),
		       HoldInputUntilFrame);
	}

	// ==============================
	// 4. HOLDING BACK INPUT 
	// ==============================
	constexpr int32 FakeLagFrames = 16;

	if (currentFrame == HoldInputUntilFrame)
	{
		//Prediction is targeted
		return;
	}

	// ==============================
	// 5. SENT DELAYED INPUT 
	// ==============================
	if (HoldInputUntilFrame >= 0 && currentFrame == HoldInputUntilFrame + FakeLagFrames)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Debug] Sending late input for frame %d"),
		       HoldInputUntilFrame);

		FInputPacket latePacket(
			HoldInputUntilFrame,
			encoded,
			0,
			0
		);

		m_gameManager->AddInputToQueue(this, latePacket);

		HoldInputUntilFrame = -1;
		return;
	}

	// ==============================
	// 6. NORMAL INPUT-FLOW
	// ==============================
	if (currentFrame == lastSentFrame)
		return;

	FInputPacket packet(currentFrame, encoded, 0, 0);
	m_gameManager->AddInputToQueue(this, packet);

	lastSentFrame = currentFrame;
}

void AFightingGame_PlayerController::SampleInput()
{
	m_raw.Left = b_leftPressed;
	m_raw.Right = b_rightPressed;
	m_raw.Up = b_upPressed;
	m_raw.Down = b_downPressed;
	m_raw.Jump = b_jumpPressed;
	m_raw.Attack1 = b_Attack1Pressed;
	m_raw.Attack2 = b_Attack2Pressed;
	m_raw.Block = b_blockPressed;
}

void AFightingGame_PlayerController::CommitInput(int32 _frame)
{
	const int32 currentFrame = _frame + 1;

	if (currentFrame == m_lastSentFrame)
		return;

	uint8 encoded = InputHandler::EncodeInput(m_raw);

	static int32 HoldInputUntilFrame = -1;

	// ==============================
	// 3. DEBUG: ROLLBACK 
	// ==============================
	if (bDebugRollbackPressed && HoldInputUntilFrame < 0)
	{
		HoldInputUntilFrame = currentFrame;
		bDebugRollbackPressed = false;

		UE_LOG(LogTemp, Warning, TEXT("[Debug] Holding input at frame %d"),
		       HoldInputUntilFrame);
	}

	// ==============================
	// 4. HOLDING BACK INPUT 
	// ==============================
	constexpr int32 FakeLagFrames = 20;

	if (currentFrame == HoldInputUntilFrame)
	{
		//Prediction is targeted
		return;
	}

	// ==============================
	// 5. SENT DELAYED INPUT 
	// ==============================
	if (HoldInputUntilFrame >= 0 && currentFrame == HoldInputUntilFrame + FakeLagFrames)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Debug] Sending late input for frame %d"),
		       HoldInputUntilFrame);

		FInputPacket latePacket(
			HoldInputUntilFrame,
			encoded,
			0,
			0
		);

		m_gameManager->AddInputToQueue(this, latePacket);
		HoldInputUntilFrame = -1;

		FInputPacket packet(currentFrame, encoded, 0, 0);
		m_gameManager->AddInputToQueue(this, packet);
		
		return;
	}

	FInputPacket packet(currentFrame, encoded, 0, 0);
	m_gameManager->AddInputToQueue(this, packet);

	m_lastSentFrame = currentFrame;
}

void AFightingGame_PlayerController::ResetInputBuffer()
{
	b_leftPressed = b_rightPressed = b_upPressed = b_downPressed = false;
	b_jumpPressed = b_Attack1Pressed = b_Attack2Pressed = b_blockPressed = false;
	Input = FRawInput();
}

void AFightingGame_PlayerController::OnPressedMovement(const FInputActionValue& _value)
{
	const FVector2d movementVector = _value.Get<FVector2d>();

	//UE_LOG(LogTemp, Log, TEXT("OnPressedMovement: X=%.2f, Y=%.2f"), movementVector.X, movementVector.Y);

	b_upPressed = movementVector.Y > m_deadzone;
	//b_downPressed = movementVector.Y < -m_deadzone;
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

void AFightingGame_PlayerController::OnPressedJump() { b_jumpPressed = true; }
void AFightingGame_PlayerController::OnJumpReleased() { b_jumpPressed = false; }
void AFightingGame_PlayerController::OnPressedCrouch() { b_downPressed = true; }
void AFightingGame_PlayerController::OnCrouchReleased() { b_downPressed = false; }
void AFightingGame_PlayerController::OnPressedAttack1() { b_Attack1Pressed = true; }
void AFightingGame_PlayerController::OnAttack1Released() { b_Attack1Pressed = false; }
void AFightingGame_PlayerController::OnPressedAttack2() { b_Attack2Pressed = true; }
void AFightingGame_PlayerController::OnAttack2Released() { b_Attack2Pressed = false; }
void AFightingGame_PlayerController::OnPressedBlock() { b_blockPressed = true; }
void AFightingGame_PlayerController::OnBlockReleased() { b_blockPressed = false; }

void AFightingGame_PlayerController::OnRollbackPressed()
{
	if (!m_gameManager)
		return;
	if (GetPlayerID() == 0)
		bDebugRollbackPressed = true;
	
	//m_gameManager->TriggerDebugRollback(60);
}

void AFightingGame_PlayerController::UsingGamepad() { m_deadzone = 40.f; }
void AFightingGame_PlayerController::UsingKeyboard() { m_deadzone = 0.3f; }

void AFightingGame_PlayerController::SetMappingContext(UInputMappingContext* _newMappingContext)
{
	if (!_newMappingContext) return;
	DefaultMappingContext = _newMappingContext;

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AFightingGame_PlayerController::SetupMappingContext()
{
	if (!DefaultMappingContext || !GetLocalPlayer())
	{
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, [this]() { SetupMappingContext(); }, 0.01f, false);
		return;
	}

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
