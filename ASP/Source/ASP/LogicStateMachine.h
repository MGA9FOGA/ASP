#pragma once
#include "StateMachine.h"

class ASP_API LogicStateMachine : public FFightingStateMachine
{
public:
	LogicStateMachine();
	virtual ~LogicStateMachine() override;

private:
	/* States */
	FStateDefinition m_idle_State			= FStateDefinition();
	FStateDefinition m_moving_State			= FStateDefinition();
	FStateDefinition m_jumping_State		= FStateDefinition();
	FStateDefinition m_attackig1_State		= FStateDefinition();
	FStateDefinition m_attackig2_State		= FStateDefinition();
	FStateDefinition m_crouching_State		= FStateDefinition();
};
