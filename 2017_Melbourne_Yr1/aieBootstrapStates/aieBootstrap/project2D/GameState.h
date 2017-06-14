#pragma once
#include "BaseState.h"

class GameState : public BaseState
{
public:
	GameState();
	~GameState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	bool		m_draw = false;
	float		m_timer;
	Font*		m_font;
};

