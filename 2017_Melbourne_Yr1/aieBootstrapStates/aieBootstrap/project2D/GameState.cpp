#include "GameState.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Font.h"
#include "Input.h"
#include "MeObject.h"
#include <crtdbg.h>


GameState::GameState()
{
	m_timer = 0;

	obj = new ObjectPool(10);
	_ASSERT(obj);

	ResourceManager<Font>* pTextureMan = ResourceManager<Font>::GetInstance();
	m_font = pTextureMan->LoadResource("./font/consolas.ttf", 32);
}

GameState::~GameState()
{
	delete m_font;
}

void GameState::OnEnter(StateMachine* pMachine)
{
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
	if (input->wasKeyPressed(INPUT_KEY_A))
	{
		MeObject* CircleLookin = obj->Allocate();
	}
	obj->Update(fDeltaTime);
}

void GameState::OnDraw(Renderer2D * m_2dRenderer)
{
	//obj->Draw(m_2dRenderer);
	m_2dRenderer->drawText(m_font, "Press A to draw moving circle!", 0, 690);
	m_2dRenderer->drawText(m_font, "P to Pause!", 0, 650);
	obj->Draw(m_2dRenderer);
}

void GameState::OnExit(StateMachine* pMachine)
{

}

