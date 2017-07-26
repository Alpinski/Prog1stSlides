#include "StateMove.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "Agent.h"

StateMove::StateMove()
{
	m_BehaviourList.push_back(new SeekBehaviour(1.0f));
	m_BehaviourList.push_back(new FleeBehaviour(1.0f));
}

StateMove::~StateMove()
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		delete m_BehaviourList[i];
	}
}

void StateMove::OnUpdate(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2TotalForce;

	//Update the Behaviours and combine them with weighting
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		//Call each behaviour's Calculate function and record the returned result
		//Scale the returned result by the behaviours weighting.
		//Add the now scaled result to v2TotalForce

		//Limit total forces to not be higher than whatever maximum speed we want.
		
	}

	//Apply forces to player

}