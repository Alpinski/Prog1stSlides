#pragma once
#include "Agents.h"

class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual bool update(Agents* agent, float deltaTime) = 0;
};

