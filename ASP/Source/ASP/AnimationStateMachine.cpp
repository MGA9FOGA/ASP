#include "AnimationStateMachine.h"

#include "LogicStateMachine.h"

AnimationStateMachine::AnimationStateMachine(): m_logicStateMachine(nullptr), m_character(nullptr)
{
}

AnimationStateMachine::AnimationStateMachine(LogicStateMachine& _stateMachine, AASPCharacter& _character)
{
	m_logicStateMachine = &_stateMachine;
	m_character = &_character;
}

AnimationStateMachine::~AnimationStateMachine()
{
}
