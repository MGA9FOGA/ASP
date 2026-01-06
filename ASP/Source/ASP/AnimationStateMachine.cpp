#include "AnimationStateMachine.h"
#include "Conditions.h"
#include "LogicStateMachine.h"
#include "UCharacterState_Anim_Falling.h"
#include "UCharacterState_Anim_Idle.h"
#include "UCharacterState_Anim_MoveBwd.h"
#include "UCharacterState_Anim_StartJump.h"
#include "UCharacterState_Anim_MoveFwd.h"


AnimationStateMachine::AnimationStateMachine(const LogicStateMachine& _logic): m_logicStateMachine(_logic)
{
	AnimationStateMachine::BuildStates();
}

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
		EStates::MOVINGFWD,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return GetMoveDirection(_state) == 1;
		}
	));
	Idle.Transitions.Add(FStateTransition(
	EStates::MOVINGBWD,
	[this](const FCharacterState& _state, const FFrameInput& _input)
	{
		return GetMoveDirection(_state) == -1;
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

#pragma region MoveFWD
	//MOVE STATE CREATION
	FStateDefinition MoveFWD;
	MoveFWD.State = MakeShareable(new UCharacterState_Anim_MoveFwd());
	MoveFWD.Transitions.Add(FStateTransition(
		EStates::STARTJUMP,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::JUMPING);
		}
	));
	MoveFWD.Transitions.Add(FStateTransition(
		EStates::IDLE,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::IDLE);
		}
	));
	MoveFWD.Transitions.Add(FStateTransition(
	EStates::MOVINGBWD,
	[this](const FCharacterState& _state, const FFrameInput& _input)
	{
		return GetMoveDirection(_state) == -1;
	}
));
	m_stateMap.Add(EStates::MOVINGFWD, MoveFWD);
#pragma endregion

#pragma region MoveBWD
	//MOVE STATE CREATION
	FStateDefinition MoveBWD;
	MoveBWD.State = MakeShareable(new UCharacterState_Anim_MoveBwd());
	MoveBWD.Transitions.Add(FStateTransition(
		EStates::STARTJUMP,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::JUMPING);
		}
	));
	MoveBWD.Transitions.Add(FStateTransition(
		EStates::IDLE,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return m_logicStateMachine.HasStateJustChangedTo(_state, EStates::IDLE);
		}
	));
	MoveBWD.Transitions.Add(FStateTransition(
	EStates::MOVINGFWD,
	[this](const FCharacterState& _state, const FFrameInput& _input)
	{
		return GetMoveDirection(_state) == 1;
	}
));
	m_stateMap.Add(EStates::MOVINGBWD, MoveBWD);
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

void AnimationStateMachine::ChangeState(FCharacterState& _state, EStates _newState, const FFrameInput& _input)
{
	if (_newState == m_currentState)
		return;

	// =============================
	// === Exit old state ===
	// =============================
	if (m_stateMap.Contains(m_currentState))
	{
		auto& oldDef = m_stateMap[m_currentState];
		if (oldDef.State.IsValid())
		{
			oldDef.State->ExitState(_state);
		}
	}

	// =============================
	// === Switch state ===
	// =============================
	m_currentState = _newState;
	_state.AnimState = _newState;
	_state.AnimStateTimer = 0.f;

	// =============================
	// === Enter new state ===
	// =============================
	if (m_stateMap.Contains(_newState))
	{
		auto& newDef = m_stateMap[_newState];
		if (newDef.State.IsValid())
		{
			newDef.State->EnterState(_state, _input);
		}
	}
}

void AnimationStateMachine::Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
	if (!m_stateMap.Contains(_state.AnimState)) return;
	auto& def = m_stateMap[_state.AnimState];

	// State-Update ausführen
	if (def.State.IsValid())
	{
		_state.AnimStateTimer += _deltaTime;
		def.State->UpdateState(_state, _input, _deltaTime);
	}

	for (const FStateTransition& transition : def.Transitions)
	{
		if (transition.Condition(_state, _input))
		{
			ChangeState(_state, transition.Target, _input);
			break;
		}
	}
}

void AnimationStateMachine::Start(FCharacterState& _state)
{
	m_currentState = EStates::IDLE;
	_state.AnimState = m_currentState;
	_state.AnimStateTimer = 0.f;
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
