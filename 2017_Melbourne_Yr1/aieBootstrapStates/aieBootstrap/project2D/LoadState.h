#pragma once
#include "BaseState.h"

using namespace aie;

class LoadState : public BaseState
{
public:
	LoadState();
	~LoadState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:
	float		timer;
	Font*		m_font;
};

