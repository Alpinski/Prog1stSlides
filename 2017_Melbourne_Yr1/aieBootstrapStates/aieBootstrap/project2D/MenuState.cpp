#include "MenuState.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Font.h"
#include "Input.h"
#include <crtdbg.h>


MenuState::MenuState()
{
	ResourceManager<Font>* pTextureMan = ResourceManager<Font>::GetInstance();
	m_font = pTextureMan->LoadResource("./font/consolas.ttf", 32);
	_ASSERT(m_font);
}


MenuState::~MenuState()
{
	delete m_font;
}

void MenuState::OnEnter(StateMachine* pMachine)
{
	pMachine->SetBackgroundRender(false);
}

void MenuState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
	{
		pMachine->PopState();
		pMachine->PushState(3);
	}
}

void MenuState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Press Enter to start game!", 0, 720 - 32);
}

void MenuState::OnExit(StateMachine* pMachine)
{
}
