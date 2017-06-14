#pragma once
#include "BaseState.h"

class SplashState : public BaseState
{
public:
	SplashState();
	~SplashState();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
};
