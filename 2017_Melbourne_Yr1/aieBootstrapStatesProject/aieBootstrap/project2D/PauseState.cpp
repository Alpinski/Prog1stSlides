#include "PauseState.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Font.h"
#include "Input.h"
#include <crtdbg.h>

PauseState::PauseState()
{
	ResourceManager<Font>* pTextureMan = ResourceManager<Font>::GetInstance();
	m_font = pTextureMan->LoadResource("./font/consolas.ttf", 32);
	_ASSERT(m_font);
}


PauseState::~PauseState()
{
	delete m_font;
}

void PauseState::OnEnter(StateMachine* pMachine)
{
	pMachine->SetBackgroundRender(true);
}

void PauseState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	Input* input = Input::getInstance();
	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		pMachine->PopState();
		pMachine->PushState(2);
	}
}

void PauseState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "PAUSED!", 620, 450);
	m_2dRenderer->drawText(m_font, "Press P to Unpause!", 520, 400);
}

void PauseState::OnExit(StateMachine* pMachine)
{
	pMachine->SetBackgroundRender(false);
}
