#pragma once
#include "BaseState.h"

class MenuState : public BaseState
{
public:
	MenuState();
	~MenuState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:

	Font*		m_font;
};

