#include "AnimationResolver.h"
#include "Conditions.h"




//void AnimationStateMachine::BuildStates()
//{
#pragma region Idle
//	//IDLE STATE CREATION
//	FStateDefinition Idle;
//	Idle.State = MakeShareable(new UCharacterState_Anim_Idle());
//	Idle.Transitions.Add(FStateTransition(
//		EStates::MOVINGFWD,
//		[this](const FCharacterState& _state, const FFrameInput& _input)
//		{
//			return GetMoveDirection(_state) == 1;
//		}
//	));
//	Idle.Transitions.Add(FStateTransition(
//	EStates::MOVINGBWD,
//	[this](const FCharacterState& _state, const FFrameInput& _input)
//	{
//		return GetMoveDirection(_state) == -1;
//	}
//));
//	Idle.Transitions.Add(FStateTransition(
//		EStates::STARTJUMP,
//		[this](const FCharacterState& _state, const FFrameInput& _input)
//		{
//			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::JUMPING);
//		}
//	));
//	m_stateMap.Add(EStates::IDLE, Idle);
#pragma endregion

#pragma region MoveFWD
	//MOVE STATE CREATION
//	FStateDefinition MoveFWD;
//	MoveFWD.State = MakeShareable(new UCharacterState_Anim_MoveFwd());
//	MoveFWD.Transitions.Add(FStateTransition(
//		EStates::STARTJUMP,
//		[this](const FCharacterState& _state, const FFrameInput& _input)
//		{
//			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::JUMPING);
//		}
//	));
//	MoveFWD.Transitions.Add(FStateTransition(
//		EStates::IDLE,
//		[this](const FCharacterState& _state, const FFrameInput& _input)
//		{
//			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::IDLE);
//		}
//	));
//	MoveFWD.Transitions.Add(FStateTransition(
//	EStates::MOVINGBWD,
//	[this](const FCharacterState& _state, const FFrameInput& _input)
//	{
//		return GetMoveDirection(_state) == -1;
//	}
//));
// 	m_stateMap.Add(EStates::MOVINGFWD, MoveFWD);
#pragma endregion

#pragma region MoveBWD
//	//MOVE STATE CREATION
//	FStateDefinition MoveBWD;
//	MoveBWD.State = MakeShareable(new UCharacterState_Anim_MoveBwd());
//	MoveBWD.Transitions.Add(FStateTransition(
//		EStates::STARTJUMP,
//		[this](const FCharacterState& _state, const FFrameInput& _input)
//		{
//			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::JUMPING);
//		}
//	));
//	MoveBWD.Transitions.Add(FStateTransition(
//		EStates::IDLE,
//		[this](const FCharacterState& _state, const FFrameInput& _input)
//		{
//			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::IDLE);
//		}
//	));
//	MoveBWD.Transitions.Add(FStateTransition(
//	EStates::MOVINGFWD,
//	[this](const FCharacterState& _state, const FFrameInput& _input)
//	{
//		return GetMoveDirection(_state) == 1;
//	}
//));
//	m_stateMap.Add(EStates::MOVINGBWD, MoveBWD);
#pragma endregion
	
#pragma region JumpStart
	//JUMP STATE CREATION
//      	FStateDefinition StartJump;
//      	StartJump.State = MakeShareable(new UCharacterState_Anim_StartJump());
//      	StartJump.Transitions.Add(FStateTransition(
//      		EStates::FALLING,
//      		[this](const FCharacterState& _state, const FFrameInput& _input)
//      		{
//      			return CanTransitionToFalling(_state, _input);
//      		}
//      	));
//      	m_stateMap.Add(EStates::STARTJUMP, StartJump);
#pragma endregion

#pragma region Falling
	//JUMP STATE CREATION
//	FStateDefinition Falling;
//	Falling.State = MakeShareable(new UCharacterState_Anim_Falling());
//	Falling.Transitions.Add(FStateTransition(
//		EStates::IDLE,
//		[this](const FCharacterState& _state, const FFrameInput& _input)
//		{
//			return _state.bGrounded ||  m_logicStateMachine.HasStateJustChangedTo(_state, EStates::IDLE);
//		}
//	));
//	m_stateMap.Add(EStates::FALLING, Falling);
#pragma endregion
//}

AnimationResolver::AnimationResolver()
{
}

void AnimationResolver::Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
	const EStates desiredAnim = Resovle(_state, _input);

	if (_state.AnimState != desiredAnim)
	{
		_state.AnimState = desiredAnim;
		_state.AnimCommand = EAnimCommand::PlayMontage;
	}
}

EStates AnimationResolver::Resovle(const FCharacterState& _state, const FFrameInput& _input)
{
	// =============================
	// === AIR ===
	// =============================
	if (!_state.bGrounded)
	{
		if (_state.LogicState == EStates::JUMPING &&
			_state.Velocity.Z >= 0.f)
		{
			return EStates::STARTJUMP;
		}
		return EStates::FALLING;
	}

	// =============================
	// === GROUND ===
	// =============================
	if (FMath::Abs(_state.MoveAxis) > 0.f)
	{
		const bool bForward = (_state.MoveAxis * _state.Facing) > 0.f;

		return bForward ? EStates::MOVINGFWD : EStates::MOVINGBWD;
	}

	return EStates::IDLE;
}
