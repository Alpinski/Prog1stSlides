#include "LoadState.h"
#include "BaseState.h"
#include "ResourceManager.h"
#include "Font.h"
#include "StateMachine.h"
#include <crtdbg.h>

LoadState::LoadState()
{
	timer = 0;
	ResourceManager<Font>* pTextureMan = ResourceManager<Font>::GetInstance();
	m_font = pTextureMan->LoadResource("./font/consolas.ttf", 32);
	_ASSERT(m_font);
}

LoadState::~LoadState()
{
	delete m_font;
}

void LoadState::OnEnter(StateMachine* pMachine)
{
	pMachine->SetBackgroundRender(false);
	timer = 0;
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

void LoadState::OnExit(StateMachine* pMachine)
{
}
