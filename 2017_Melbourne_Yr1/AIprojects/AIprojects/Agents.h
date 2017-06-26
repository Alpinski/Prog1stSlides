#pragma once
#include "Vector2.h"
#include <list>

class Agents
{
public:
	Agents();
	~Agents();

	virtual void update(float deltaTime) 
	{
		for (auto& behaviour : m_behaviours)
			behaviour->update(this, deltaTime);
	}


protected:

	std::list<IBehavours*> m_behaviours;

	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;

};

