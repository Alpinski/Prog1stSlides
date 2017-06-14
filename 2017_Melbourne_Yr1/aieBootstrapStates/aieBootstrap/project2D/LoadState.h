#pragma once
#include "BaseState.h"


class LoadState : public BaseState
{
public:
	LoadState();
	~LoadState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	float		timer;
	Font*		m_font;
};

