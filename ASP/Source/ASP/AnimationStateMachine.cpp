#include "AnimationStateMachine.h"
#include "Conditions.h"
#include "LogicStateMachine.h"
#include "UCharacterState_Anim_Falling.h"
#include "UCharacterState_Anim_Idle.h"
#include "UCharacterState_Anim_Landing.h"
#include "UCharacterState_Anim_StartJump.h"
#include "UCharacterState_Anim_Move.h"

AnimationStateMachine::AnimationStateMachine(LogicStateMachine& _stateMachine, AASPCharacter& _character)
    : m_logicStateMachine(_stateMachine)  
{
	m_character = &_character;
	AnimationStateMachine::BuildStates();
}

AnimationStateMachine::~AnimationStateMachine()
{
}

void AnimationStateMachine::BuildStates()
{
	FFightingStateMachine::BuildStates();

#pragma region Idle
	//IDLE STATE CREATION
	FStateDefinition Idle;
	Idle.State = MakeShareable(new UCharacterState_Anim_Idle(EStates::IDLE));
	Idle.Transitions.Add(FStateTransition(EStates::MOVING, [this](){ return m_logicStateMachine.HasStateJustChangedTo(EStates::MOVING); }));
	Idle.Transitions.Add(FStateTransition(EStates::STARTJUMP, [this](){ return m_logicStateMachine.HasStateJustChangedTo(EStates::JUMPING); }));
	m_stateMap.Add(EStates::IDLE, Idle);
#pragma endregion

#pragma region Move
	//MOVE STATE CREATION
	FStateDefinition Move;
	Move.State = MakeShareable(new UCharacterState_Anim_Move(EStates::MOVING));
	Move.Transitions.Add(FStateTransition(EStates::STARTJUMP, [this](){ return m_logicStateMachine.HasStateJustChangedTo(EStates::JUMPING); }));
	Move.Transitions.Add(FStateTransition(EStates::IDLE, [this](){ return m_logicStateMachine.HasStateJustChangedTo(EStates::IDLE); }));
	m_stateMap.Add(EStates::MOVING, Move);
#pragma endregion

#pragma region JumpStart
	//JUMP STATE CREATION
	FStateDefinition StartJump;
	StartJump.State = MakeShareable(new UCharacterState_Anim_StartJump(EStates::STARTJUMP));
	StartJump.Transitions.Add(FStateTransition(EStates::FALLING, [this](){return CanTransitionToFalling(*this);}));
	m_stateMap.Add(EStates::STARTJUMP, StartJump);
#pragma endregion

#pragma region Falling
	//JUMP STATE CREATION
	FStateDefinition Falling;
	Falling.State = MakeShareable(new UCharacterState_Anim_Falling(EStates::FALLING));
	Falling.Transitions.Add(FStateTransition(EStates::IDLE,  [this](){return m_character->GetNoChaosMovementComponent()->GetBoolOnGround();}));
	m_stateMap.Add(EStates::FALLING, Falling);
#pragma endregion

#pragma region Landed
	//JUMP STATE CREATION
	FStateDefinition Landed;
	Landed.State = MakeShareable(new UCharacterState_Anim_Landing(EStates::LANDING));
	Landed.Transitions.Add(FStateTransition(EStates::MOVING, [this](){return IdleToMoving(m_logicStateMachine);}));
	Landed.Transitions.Add(FStateTransition(EStates::IDLE, [this](){return CanTransitionToIdle(*this);}));
	m_stateMap.Add(EStates::LANDING, Landed);
#pragma endregion	
}

void AnimationStateMachine::OnLandingFinished()
{
	b_landingFinished = true;
}

void AnimationStateMachine::OnJStartJumpFinished()
{
	b_startUpJumpingFinished = true;
}

