#pragma once
#include "Agent.h"
class StateMachine;

class AI : public Agent
{
public:
	AI();
	~AI();

	void update(float fDeltaTime);
	void Draw(Renderer2D* pRenderer);

private:
	StateMachine* m_pStateMachine;
};

