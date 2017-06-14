#include "MenuState.h"
#include "StateMachine.h"
#include "Font.h"
#include "Input.h"


MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}

void MenuState::OnEnter(StateMachine* pMachine)
{
	m_font = new Font("./font/consolas.ttf", 32);
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

void MenuState::OnExit()
{
	delete m_font;
}
