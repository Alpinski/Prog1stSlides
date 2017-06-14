#include "PauseState.h"
#include "StateMachine.h"
#include "Font.h"
#include "Input.h"


PauseState::PauseState()
{

}


PauseState::~PauseState()
{
}

void PauseState::OnEnter(StateMachine* pMachine)
{
	m_font = new Font("./font/consolas.ttf", 32);
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
	m_2dRenderer->drawText(m_font, "PAUSED!", 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press P to Unpause!", 0, 720 - 32);
}

void PauseState::OnExit()
{
	delete m_font;
}
