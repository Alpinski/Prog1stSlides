#pragma once
#include "IBehaviour.h"

class SeekBehaviour : public IBehaviour
{
public:
	SeekBehaviour(float fWeighting);
	~SeekBehaviour();

	Vector2 Calculate(Agent* pAgent, float fDeltaTime);
};

