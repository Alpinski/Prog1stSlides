#include "SplashState.h"
#include "ResourceManager.h"
#include "Font.h"
#include "StateMachine.h"
#include <crtdbg.h>


SplashState::SplashState()
{
	timer = 0;
	ResourceManager<Font>* pTextureMan = ResourceManager<Font>::GetInstance();

	m_font = pTextureMan->LoadResource("./font/consolas.ttf", 32);
	_ASSERT(m_font);
}


SplashState::~SplashState()
{
	delete m_font;
}

void SplashState::OnEnter(StateMachine* pMachine)
{
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

void SplashState::OnExit(StateMachine* pMachine)
{
}
