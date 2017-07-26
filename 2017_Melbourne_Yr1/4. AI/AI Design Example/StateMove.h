#pragma once
#include "BaseState.h"

class StateMove : public BaseState
{
public:
	StateMove();
	~StateMove();

	void OnUpdate(Agent* pAgent, float fDeltaTime);
};

