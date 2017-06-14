#include "MenuState.h"
#include "StateMachine.h"
#include "Input.h"


MenuState::MenuState()
{
}


MenuState::~MenuState()
{
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
	}

}

void MenuState::OnDraw(Renderer2D * m_2dRenderer)
{

}

void MenuState::OnExit()
{
}
