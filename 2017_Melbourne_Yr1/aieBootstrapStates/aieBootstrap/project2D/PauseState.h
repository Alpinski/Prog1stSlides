#pragma once
#include "BaseState.h"

class PauseState : public BaseState
{
public:
	PauseState();
	~PauseState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:

	Font*		m_font;
};

