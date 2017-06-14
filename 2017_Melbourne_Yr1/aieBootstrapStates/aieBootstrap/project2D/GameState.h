#pragma once
#include "BaseState.h"

class GameState : public BaseState
{
public:
	GameState();
	~GameState();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
};

