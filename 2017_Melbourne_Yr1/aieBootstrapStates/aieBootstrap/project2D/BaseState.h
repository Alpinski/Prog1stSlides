#pragma once
#include "Renderer2D.h"
using namespace aie;

class StateMachine;

class BaseState
{
public:
	BaseState();
	~BaseState();

	virtual void OnEnter() = 0;
	virtual void OnUpdate(float fDeltaTime, StateMachine* pMachine) = 0;
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	virtual void OnExit() = 0;
};

