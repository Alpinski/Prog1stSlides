#include "LoadState.h"
#include "BaseState.h"
#include "ResourceManager.h"
#include "Font.h"
#include "StateMachine.h"


LoadState::LoadState()
{
	timer = 0;
}

LoadState::~LoadState()
{
}

void LoadState::OnEnter(StateMachine* pMachine)
{
	m_font = new Font("./font/consolas.ttf", 32);
	pMachine->SetBackgroundRender(false);
}

void LoadState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	timer += fDeltaTime;

	if (timer > 3)
	{
		pMachine->PopState();
		pMachine->PushState(2);
	}
}

void LoadState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "I'M LOADING FOOL!", 0, 720 - 32);	
}

void LoadState::OnExit()
{
	delete m_font;
}
