#pragma once
#include "StateMachine.h"
class AASPCharacter;
class LogicStateMachine;



class ASP_API AnimationResolver 
{
public:
	AnimationResolver();
	void Update(FCharacterState& _state,
				const FFrameInput& _input,
				float _deltaTime);

private:
EStates Resovle(const FCharacterState& _state,
				const FFrameInput& _input);
};
