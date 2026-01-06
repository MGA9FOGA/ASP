#pragma once
#include "StateMachine.h"
class AASPCharacter;
class LogicStateMachine;



class ASP_API AnimationStateMachine : public FFightingStateMachine
{
public:
	AnimationStateMachine(const LogicStateMachine& _logic);
	virtual ~AnimationStateMachine() override;
	virtual void BuildStates();
	virtual void ChangeState(FCharacterState& _state, EStates _newState, const FFrameInput& _input) override;
	virtual void Update(FCharacterState& _state, const FFrameInput& _input, float _deltaTime) override;
	virtual void Start(FCharacterState& _state) override;
private:
	const LogicStateMachine& m_logicStateMachine;

};
