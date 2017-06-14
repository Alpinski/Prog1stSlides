#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h" 
#include "BaseState.h"
#include "Stack.h"
using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void PushState(int nStateIndex);
	void AddState(int nStateIndex, BaseState* pState);
	void PopState();
	void SetBackgroundRender(bool onOff);

private:
	bool Onoff = false;
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_CurrentStack;
};