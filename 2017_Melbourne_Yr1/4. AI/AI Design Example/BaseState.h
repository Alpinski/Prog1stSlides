#pragma once
#include <vector>
using namespace std;
class Agent;
class IBehaviour;

class BaseState
{
public:
	virtual void OnUpdate(Agent* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};