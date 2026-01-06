#include "LogicStateMachine.h"

#include "Conditions.h"
#include "EditorCategoryUtils.h"
#include "UCharacterState_Logic_Idle.h"
#include "UCharacterState_Logic_Jump.h"
#include "UCharacterState_Logic_Move.h"

LogicStateMachine::LogicStateMachine()
{
	LogicStateMachine::BuildStates();
}


LogicStateMachine::~LogicStateMachine()
{
}

void LogicStateMachine::BuildStates()
{
#pragma region Idle
	// =============================
	// === Idle State Creation ===
	// =============================
	FStateDefinition Idle;
	Idle.State = MakeShared<UCharacterState_Logic_Idle>();
	Idle.Transitions.Add(FStateTransition(
		EStates::MOVING,
		[this](const FCharacterState& _state, const FFrameInput& _input) // FFrameInput statt FInputPacket
		{
			return _input.Action == EInputAction::MoveLeft
			|| _input.Action == EInputAction::MoveRight;
		}
	));
	Idle.Transitions.Add(FStateTransition(
		EStates::JUMPING,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return IdleOrWalkToJump(_state, _input);
		}
	));
	m_stateMap.Add(EStates::IDLE, Idle);
#pragma endregion
#pragma region Move
	// =============================
	// === Move State Creation ===
	// =============================
	FStateDefinition Move;
	Move.State = MakeShared<UCharacterState_Logic_Move>();
	Move.Transitions.Add(FStateTransition(
		EStates::JUMPING,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return _input.Action == EInputAction::JumpLeft
				|| _input.Action == EInputAction::JumpRight
				|| _input.Action == EInputAction::Jump;
		}
	));
	Move.Transitions.Add(FStateTransition(
		EStates::IDLE,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return FMath::Abs(_state.MoveAxis) == 0.f;
		}
	));
	m_stateMap.Add(EStates::MOVING, Move);
#pragma endregion
#pragma region Jump
	// =============================
	// === Jump State Creation ===
	// =============================
	FStateDefinition Jump;
	Jump.State = MakeShared<UCharacterState_Logic_Jump>();
	Jump.Transitions.Add(FStateTransition(
		EStates::IDLE,
		[this](const FCharacterState& _state, const FFrameInput& _input)
		{
			return JumpToIdle(_state, _input);
		}
	));
	m_stateMap.Add(EStates::JUMPING, Jump);
#pragma endregion
}

void LogicStateMachine::Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime)
{
	FFightingStateMachine::Update(_state, _input, _deltaTime);
}

void LogicStateMachine::Start(FCharacterState& _state)
{
	m_currentState = EStates::IDLE;
	_state.LogicState = m_currentState;
	_state.LogicStateTimer = 0.f;
}

bool LogicStateMachine::HasStateJustChangedTo(const FCharacterState& _state, EStates _targetState) const
{
	return _state.LogicState == _targetState && _state.PreviousLogicState != _targetState;
}
