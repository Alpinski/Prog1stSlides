#pragma once
#include "BaseState.h"
#include "ObjectPool.h"

using namespace aie;

class GameState : public BaseState
{
public:
	GameState();
	~GameState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:
	bool		m_draw = false;
	float		m_timer;
	Font*		m_font;
	ObjectPool*  obj;
};

