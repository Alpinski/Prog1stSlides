#pragma once
#include "IBehaviour.h"
class Seek : public IBehaviour
{
public:
	Seek();
	~Seek();
	virtual bool update(Agents* agent, float deltaTime)
	{
		// TODO: apply seek force to agent
		return true;
	}

private:
	Vector2* m_targetPos;

};

