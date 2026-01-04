#pragma once
#include "StateMachine.h"
class AASPCharacter;
class LogicStateMachine;



class ASP_API AnimationStateMachine : public FFightingStateMachine
{
public:
	AnimationStateMachine(const LogicStateMachine& _logic)
	: m_logicStateMachine(_logic) {}
	virtual ~AnimationStateMachine() override;
	virtual void BuildStates();

private:
	const LogicStateMachine& m_logicStateMachine;

};
