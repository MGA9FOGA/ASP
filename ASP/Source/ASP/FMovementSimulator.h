#pragma once
#include "CoreMinimal.h"
#include "AnimationStateMachine.h"
#include "LogicStateMachine.h"
#include "StateMachine.h"
#include "States.h"
#include "UCharacterAnimationSet.h"
#include "ASPCharacter.h"


struct FFrameInput;

enum class EAnimCommand : uint8
{
	None,
	PlayMontage,
	StopMontage
};

struct FCharacterState
{
	// =============================
	// === Transfrom ===
	// =============================
	FVector Position;
	FVector Velocity;
	float PreviousVelocityZ = 0.f;

	// =============================
	// === Groundcheck Flags ===
	// =============================
	bool bGrounded = false;
	bool bJumpRequested = false;
	bool bHasLeftGround = true;

	// =============================
	// === Movement FLags ===
	// =============================
	bool bCanMoveBackwards = false;

	// =============================
	// === Orientation ===
	// =============================
	int8 Facing; //1 / - 1
	float Yaw; //0 / 180

	// =============================
	// === PushBox ===
	// =============================
	float PushboxHalfWidth = 0.f;

	// =============================
	// === Axis ===
	// =============================
	float MoveAxis = .0f;
	float JumpAxis = .0f;
	bool bJumpPressed = false;

	// =============================
	// === Animation State ===
	// =============================
	EStates AnimState = EStates::NONE;
	EAnimCommand AnimCommand = EAnimCommand::None;
	float AnimPlayRate = 1.f;
	bool bAnimLoop = false;

	// =============================
	// === Movement Settings ===
	// =============================
	float MoveSpeed = 300.f;
	float JumpsStrength = 500.f;
	float Gravity = 980.f;

	// =============================
	// === Stage bounds ===
	// =============================
	float MinY = 120.f;
	float MaxY = 3350.f;

	// =============================
	// === State ===
	// =============================
	EStates LogicState = EStates::IDLE;
	EStates PreviousLogicState = EStates::NONE;
	float LogicStateTimer = 0.f;
	float AnimStateTimer = 0.f;
};

struct FMovementSimulator
{
	LogicStateMachine LogicMachine;

	// =============================
	// === Constructor ===
	// =============================
	FMovementSimulator()
		: LogicMachine()
	{
	}

	// =============================
	// === Logic Update ===
	// =============================
	void UpdateLogic(FCharacterState& _state, const FFrameInput& _input, double _deltaTime)
	{
		LogicMachine.Update(_state, _input, _deltaTime);
	}

	// =============================
	// === Movement Update/Calculation ===
	// =============================
	void UpdateMovement(FCharacterState& _state, FCharacterState& _other, float _deltaTime)
	{
		// =============================
		// === Horizontal Movement ===
		// =============================
		float desiredAxis = _state.bGrounded
			                    ? _state.MoveAxis
			                    : _state.JumpAxis;

		bool bIsMovingBackwards = (desiredAxis * _state.Facing) < 0.f;

		if (!_state.bCanMoveBackwards && bIsMovingBackwards)
		{
			desiredAxis = 0.f;
		}

		// =============================
		// === Pushbox Blocking ===
		// =============================
		float minDist = _state.PushboxHalfWidth + _other.PushboxHalfWidth;
		float deltaY = _other.Position.Y - _state.Position.Y;
		float dist = FMath::Abs(deltaY);

		if (_state.bGrounded && _other.bGrounded && dist < minDist)
		{
			float dir = FMath::Sign(deltaY); 
			if (desiredAxis * dir > 0.f)      
			{
				desiredAxis = 0.f;            
			}
		}
		
		_state.Velocity.Y = desiredAxis * _state.MoveSpeed;
		
		// =============================
		// === Jump ===
		// =============================
		if (_state.bJumpRequested && _state.bGrounded)
		{
			_state.Velocity.Z = _state.JumpsStrength;
			_state.bGrounded = false;
			_state.bHasLeftGround = true;
			_state.bJumpRequested = false;
		}

		// =============================
		// === Gravity ===
		// =============================
		_state.PreviousVelocityZ = _state.Velocity.Z;
		if (!_state.bGrounded)
			_state.Velocity.Z -= _state.Gravity * _deltaTime;
		
		// =============================
		// === Integrate ===
		// =============================
		_state.Position += _state.Velocity * _deltaTime;
		
		// =============================
		// === Groundcheck ===
		// =============================
		if (_state.Position.Z <= 94.5f && !_state.bGrounded)
		{
			_state.Position.Z = 94.5f;
			_state.Velocity.Z = 0.f;
			_state.bGrounded = true;
		}

		// =============================
		// === Clamp to Stage ===
		// =============================
		_state.Position.Y = FMath::Clamp(_state.Position.Y, _state.MinY, _state.MaxY);
	}
	
	// =============================
	// === Facing ===
	// =============================
	void UpdateFacing(FCharacterState& _self, const FCharacterState& _opponent)
	{
		if (_self.Position.Y < _opponent.Position.Y)
		{
			_self.Facing = 1;
			_self.Yaw = 0.f;
		}
		else
		{
			_self.Facing = -1;
			_self.Yaw = 180.f;
		}
	}
};

class AnimationStateMachine;

struct FCharacterVisual
{
	AnimationStateMachine AnimMachine;
	AASPCharacter& Character;

	FCharacterVisual(const LogicStateMachine& _machine, AASPCharacter& _inCharacter)
		: AnimMachine(_machine), Character(_inCharacter)
	{
	}


	void ApplyState(const FCharacterState& _state)
	{
		Character.SetActorLocation(_state.Position);
		Character.SetActorRotation(FRotator(0, _state.Yaw, 0));
	}

	void ApplyAnimation(const FCharacterState& _state)
	{
		if (_state.AnimCommand != EAnimCommand::PlayMontage)
		{
			return;
		}

		UCharacterAnimationSet* animationSet = Character.GetAnimationSet();
		if (!animationSet) return;

		UAnimMontage* montage = animationSet->MontageMap.FindRef(_state.AnimState);
		if (!montage) return;

		if (UAnimInstance* anim = Character.GetSkeletalMeshComponent()->GetAnimInstance())
		{
			if (!anim->Montage_IsPlaying(montage))
			{
				anim->Montage_Play(montage, _state.AnimPlayRate);
			}
		}
	}

	void UpdateAnimation(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
	{
		AnimMachine.Update(_state, _input, _deltaTime);
	}
};
