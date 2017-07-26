#pragma once
#include "BaseState.h"
#include "StateMove.h"
#include "Agent.h"

class StateMachine
{
public:
	StateMachine()
	{
		m_pCurrentState = new StateMove();
	}

	~StateMachine()
	{
		delete m_pCurrentState;
	}

	void Update(Agent* pAgent, float fDeltaTime)
	{
		m_pCurrentState->OnUpdate(pAgent, fDeltaTime);
	}

private:
	BaseState* m_pCurrentState;
};