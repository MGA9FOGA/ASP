#pragma once
#include "StateMachine.h"

class ASP_API LogicStateMachine : public FFightingStateMachine
{
public:
	LogicStateMachine();
	LogicStateMachine(AASPCharacter& _character);
	virtual ~LogicStateMachine() override;
	virtual void BuildStates() override;
	bool HasStateJustChangedTo(EStates _targetState) const;
};
