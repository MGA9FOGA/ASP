#pragma once
#include "FMovementSimulator.h"
#include "InputHandler.h"

/* =============================
 * === INPUT PER FRAME ===
 * ============================= */
struct FFrameInput
{
	uint8 Buttons = 0;
	EInputAction Action = EInputAction::None;
};


/* =============================
 * === GAME STATE ===
 * ============================= */
struct FGameState
{
	int64 FrameNumber = 0;

	FCharacterState P1;
	FCharacterState P2;

	FFrameInput P1Input;
	FFrameInput P2Input;
};

struct FStoredFrameInput
{
	FFrameInput Packet;
	bool bPredicted = false;
	int32 SourceFrame;
};