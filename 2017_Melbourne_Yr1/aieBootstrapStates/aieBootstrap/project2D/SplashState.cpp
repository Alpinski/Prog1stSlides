#include "SplashState.h"
#include "ResourceManager.h"
#include "Font.h"
#include "StateMachine.h"



SplashState::SplashState()
{
	timer = 0;
}


SplashState::~SplashState()
{
}

void SplashState::OnEnter(StateMachine* pMachine)
{
	m_font = new Font("./font/consolas.ttf", 32);
	pMachine->SetBackgroundRender(false);
}

void SplashState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	timer += fDeltaTime;

	if (timer > 3)
	{
		pMachine->PopState();
		pMachine->PushState(0);
	}
}

void SplashState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Splash!!!", 0, 720 - 32);
}

void SplashState::OnExit()
{
	delete m_font;
}
