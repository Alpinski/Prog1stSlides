#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"

using namespace aie;

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
	while (m_CurrentStack.Size() > 0)
	{
		PopState();
	}

	for (int i = 0; i < m_CurrentStack.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(float deltaTime)
{
	if (m_CurrentStack.Size() <= 0)
		return;
	
	m_CurrentStack.Top()->OnUpdate(deltaTime, this);
}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_CurrentStack.Size() <= 0)
		return;

	if (Onoff == true)
	{
		m_CurrentStack.SecondL()->OnDraw(m_2dRenderer);
	}

	m_CurrentStack.Top()->OnDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	// Example of Assert
	_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	m_CurrentStack.Push(m_StateList[nStateIndex]);
	m_CurrentStack.Top()->OnEnter(this);
}

void StateMachine::AddState(int nStateIndex, BaseState* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachine::PopState()
{
	_ASSERT(m_CurrentStack.Size());

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);
	
	m_CurrentStack.Pop();
	if (m_CurrentStack.Size() > 0)
	{
		m_CurrentStack.Top()->OnEnter(this);
	}	
}

void StateMachine::SetBackgroundRender(bool onOff)
{
	this->Onoff = onOff;
}