#include "AnimationStateMachine.h"
#include "Conditions.h"
#include "LogicStateMachine.h"
#include "UCharacterState_Anim_Falling.h"
#include "UCharacterState_Anim_Idle.h"
#include "UCharacterState_Anim_StartJump.h"
#include "UCharacterState_Anim_Move.h"


AnimationStateMachine::~AnimationStateMachine()
{
}

void AnimationStateMachine::BuildStates()
{
#pragma region Idle
	//IDLE STATE CREATION
	FStateDefinition Idle;
	Idle.State = MakeShareable(new UCharacterState_Anim_Idle());
	Idle.Transitions.Add(FStateTransition(
		EStates::MOVING,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::MOVING);
		}
	));
	Idle.Transitions.Add(FStateTransition(
		EStates::STARTJUMP,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::JUMPING);
		}
	));
	m_stateMap.Add(EStates::IDLE, Idle);
#pragma endregion

#pragma region Move
	//MOVE STATE CREATION
	FStateDefinition Move;
	Move.State = MakeShareable(new UCharacterState_Anim_Move());
	Move.Transitions.Add(FStateTransition(
		EStates::STARTJUMP,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::JUMPING);
		}
	));
	Move.Transitions.Add(FStateTransition(
		EStates::IDLE,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::IDLE);
		}
	));
	m_stateMap.Add(EStates::MOVING, Move);
#pragma endregion

#pragma region JumpStart
	//JUMP STATE CREATION
	FStateDefinition StartJump;
	StartJump.State = MakeShareable(new UCharacterState_Anim_StartJump());
	StartJump.Transitions.Add(FStateTransition(
		EStates::FALLING,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return CanTransitionToFalling(_state, _input);
		}
	));
	m_stateMap.Add(EStates::STARTJUMP, StartJump);
#pragma endregion

#pragma region Falling
	//JUMP STATE CREATION
	FStateDefinition Falling;
	Falling.State = MakeShareable(new UCharacterState_Anim_Falling());
	Falling.Transitions.Add(FStateTransition(
		EStates::IDLE,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return _state.bGrounded;
		}
	));
	m_stateMap.Add(EStates::FALLING, Falling);
#pragma endregion
}

//void AnimationStateMachine::OnLandingFinished()
//{
//	b_landingFinished = true;
//}
//
//void AnimationStateMachine::OnJStartJumpFinished()
//{
//	b_startUpJumpingFinished = true;
//}
