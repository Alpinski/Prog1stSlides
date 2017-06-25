#pragma once
#include "Renderer2D.h"
using namespace aie;

class StateMachine;
//--------------------------------------------------
//The base state every other state inherits from this sate
//
//Parameters:
//			None
//Returns:
//		None
//--------------------------------------------------
class BaseState
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
	BaseState();
	~BaseState();
	//--------------------------------------------------
	//Determines what will happen, when you enter the state 
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//Returns:
	//		None
	//--------------------------------------------------
	virtual void OnEnter(StateMachine* pMachine) = 0;
	//--------------------------------------------------
	//Updates the state you are on in accordance with delta time(if there is anything to even update).
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//			Also takes in a float.
	//Returns:
	//		None
	//--------------------------------------------------
	virtual void OnUpdate(float fDeltaTime, StateMachine* pMachine) = 0;
	//--------------------------------------------------
	//Initiates the renderer to draw the object of your choosing
	//
	//Parameters:
	//			Takes in  renderer2d which is what allows you to render anything in the game
	//Returns:
	//		None
	//--------------------------------------------------
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	//--------------------------------------------------
	//Determines what will happen, when you enter the state 
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//Returns:
	//		None
	//--------------------------------------------------
	virtual void OnExit(StateMachine* pMachine) = 0;
};

