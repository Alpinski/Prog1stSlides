#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h" 
#include "BaseState.h"
#include "Stack.h"
using namespace aie;

class StateMachine
{
public:
	//--------------------------------------------------
	//Default constructor and destructor
	//
	//Parameters:
	//			None
	//Returns:
	//		None
	//-------------------------------------------------
	StateMachine();
	~StateMachine();
	//--------------------------------------------------
	//Updates statemachine in accordance with deltatime
	//
	//Parameters:
	//			float deltatime
	//Returns:
	//		None
	//-------------------------------------------------
	void Update(float deltaTime);
	//--------------------------------------------------
	//Draws on to the state
	//
	//Parameters:
	//			Takes in  renderer2d which is what allows you to render anything in the game
	//Returns:
	//		None
	//-------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);
	//--------------------------------------------------
	//Decides what state will pushed on 
	//
	//Parameters:
	//			takes in an int which determines which state gets push on
	//Returns:
	//		None
	//-------------------------------------------------
	void PushState(int nStateIndex);
	//--------------------------------------------------
	//inserts the state 
	//
	//Parameters:
	//			takes in an int which determines which state gets insrted and takes in a base state pstate
	//Returns:
	//		None
	//-------------------------------------------------
	void AddState(int nStateIndex, BaseState* pState);
	//--------------------------------------------------
	//Pop's (removes it) off your chosen state
	//
	//Parameters:
	//			
	//Returns:
	//		None
	//-------------------------------------------------
	void PopState();
	//--------------------------------------------------
	//Decides if the backgroundrenderer will be turned on 
	//
	//Parameters:
	//			takes in a bool to decide if it will be on
	//Returns:
	//		None
	//-------------------------------------------------
	void SetBackgroundRender(bool onOff);

private:
	bool Onoff = false;
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_CurrentStack;
};