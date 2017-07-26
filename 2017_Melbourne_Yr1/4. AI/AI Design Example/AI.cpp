#include "AI.h"
#include "StateMachine.h"
#include "Renderer2D.h"
using namespace aie;

AI::AI()
{
	m_v2Pos.x = 400;
	m_v2Pos.y = 400;
	m_pStateMachine = new StateMachine();
}

AI::~AI()
{
}

void AI::Update(float fDeltaTime)
{
	m_pStateMachine->Update(this, fDeltaTime);
}

void AI::Draw(Renderer2D* pRenderer)
{
	pRenderer->setRenderColour(0xFF0000FF);
	pRenderer->drawCircle(m_v2Pos.x, m_v2Pos.y, 20.0f);
	pRenderer->setRenderColour(0xFFFFFFFF);
}
