// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
/*Inputpacket for the Queue or Rollback*/

struct FInputPacket
{
	FInputPacket();
	FInputPacket(const int32 _inFrameNumber, const int8 _inButtons, const int8 _inExtraFlags, const int16 _inRandomSeed)
	: FrameNumber(_inFrameNumber)
	, Buttons(_inButtons)
	, ExtraFlags(_inExtraFlags)
	, RandomSeed(_inRandomSeed)
	{
	}
	
	int32 FrameNumber;
	int8 Buttons;
	int8 ExtraFlags;
	int16 RandomSeed;
};

/*Input*/
struct FRawInput
{
	FRawInput(): Left(false), Right(false), Up(false), Down(false), Jump(false), Attack1(false), Attack2(false),
	             Block(false)
	{
	}

	FRawInput(bool _inLeft, bool _inRight, bool _inUp, bool _inDown, bool _inJump, bool _inAttack1, bool _inAttack2, bool _inBlock)
	: Left(_inLeft)
	, Right(_inRight)
	, Up(_inUp)
	, Down(_inDown)
	, Jump(_inJump)
	, Attack1(_inAttack1)
	, Attack2(_inAttack2)
	, Block(_inBlock)
	{
	}
	
	bool Left;      // ← Taste gedrückt
	bool Right;     // → Taste gedrückt
	bool Up;        // ↑ Taste / Jump
	bool Down;      // ↓ Taste (für Spezialaktionen)
	bool Jump;		// space Jump
	bool Attack1;   // erster Angriff
	bool Attack2;   // zweiter Angriff
	bool Block;     // Blocken
};

/*PlayerActions*/
enum EAction
{
	None				= 0,
	Block				= 1,
	JumpAttack1			= 2,
	JumpAttack2			= 3,
	Jump				= 4,
	LowAttack1			= 5,
	LowAttack2			= 6,
	Crouch				= 7,
	ForwardAttack1		= 8,
	BackAttack1			= 9,
	Attack1				= 10,
	ForwardAttack2		= 11,
	BackAttack2			= 12,
	Attack2				= 13,
	MoveForward			= 14,
	MoveBackwards		= 15,
	Up					= 16,
	UpAttack1			= 17,
	UpAttack2			= 18,
	UpMoveForward		= 19,
	UpMoveBackwards		= 20,
	CrouchMoveForward	= 21,
	CrouchMoveBackwards	= 22,
	Idle				= 23,
};

class ASP_API InputHandler
{
public:
	InputHandler();
	~InputHandler();

	/*Encode for the RawInput*/
	static uint8 EncodeInput(const FRawInput& _raw)
	{
		uint8 Bits = 0;
		if (_raw.Left)    Bits |= (1 << 0);
		if (_raw.Right)   Bits |= (1 << 1);
		if (_raw.Up)      Bits |= (1 << 2);
		if (_raw.Down)    Bits |= (1 << 3);
		if (_raw.Attack1) Bits |= (1 << 4);
		if (_raw.Attack2) Bits |= (1 << 5);
		if (_raw.Block)   Bits |= (1 << 6);
		if (_raw.Jump)    Bits |= (1 << 7);
		return Bits;
	}
	/*Decode for the RawInput*/
	static FRawInput DecodeInput(uint8 _bits)
	{
		FRawInput Out;
		Out.Left    = _bits & (1 << 0);
		Out.Right   = _bits & (1 << 1);
		Out.Up      = _bits & (1 << 2);
		Out.Down    = _bits & (1 << 3);
		Out.Attack1 = _bits & (1 << 4);
		Out.Attack2 = _bits & (1 << 5);
		Out.Block   = _bits & (1 << 6);
		Out.Jump    = _bits & (1 << 7);
		return Out;
	}

	static EAction NormalizeInput(const FRawInput& Input)
	{
		if (Input.Block) return EAction::Block;
		if (Input.Jump)
		{
			return EAction::Jump;
		}
		
		// Jump
		if (Input.Up)
		{
			if (Input.Right) return EAction::UpMoveForward;
			if (Input.Left) return EAction::UpMoveBackwards;
			return EAction::Up;
		}
		
		if (Input.Down)
		{
			if (Input.Right) return EAction::CrouchMoveForward;
			if (Input.Left) return EAction::CrouchMoveBackwards;
			return EAction::Crouch;
		}

		// Normal Attacks
		if (Input.Attack1)
		{
			return EAction::Attack1;
		}

		if (Input.Attack2)
		{
			return EAction::Attack2;
		}

		// Movement
		if (Input.Right) return EAction::MoveForward;
		if (Input.Left)  return EAction::MoveBackwards;

		return EAction::Idle;
	}
};
