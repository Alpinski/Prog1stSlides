#pragma once

#include "Vector2.h"
class Agent;

class IBehaviour
{
public:
	IBehaviour(float fWeighting)
	{
		m_fWeighting = fWeighting;
	}

	//Update function
	virtual Vector2 Calculate(Agent* pAgent, float fDeltaTime) = 0;

	float m_fWeighting;
};