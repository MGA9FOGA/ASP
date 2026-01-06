#pragma once
#include "StateMachine.h"

class ASP_API LogicStateMachine : public FFightingStateMachine
{
public:
	LogicStateMachine();
	virtual ~LogicStateMachine() override;
	virtual void BuildStates();
	virtual void Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
	virtual void Start(FCharacterState& _state) override;
	bool HasStateJustChangedTo(const FCharacterState& _state, EStates _targetState) const;
};
