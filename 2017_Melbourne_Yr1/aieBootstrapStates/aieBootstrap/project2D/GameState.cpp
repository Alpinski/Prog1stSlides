#include "GameState.h"
#include "StateMachine.h"
#include "Font.h"
#include "Input.h"


GameState::GameState()
{
	m_timer = 0;
}

GameState::~GameState()
{
}

void GameState::OnEnter(StateMachine* pMachine)
{
	m_font = new Font("./font/consolas.ttf", 32);

}

void GameState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	m_timer += fDeltaTime;

	Input* input = Input::getInstance();
	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		pMachine->PushState(4);
	}
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
	{
		pMachine->PopState();
		pMachine->PushState(0);
	}
	if (input->isKeyDown(INPUT_KEY_1))
	{
		m_draw = true;
	}
}

void GameState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Press 1 to draw moving square!", 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "P to Pause!", 0, 720 - 32);

	if (m_draw == true)
	{
		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);
	}


}

void GameState::OnExit()
{
	delete m_font;
}

