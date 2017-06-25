#pragma once
#include "BaseState.h"
#include "ObjectPool.h"

using namespace aie;

class GameState : public BaseState
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
	GameState();
	~GameState();
	//--------------------------------------------------
	//Determines what will happen, when you enter the state 
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//Returns:
	//		None
	//--------------------------------------------------
	void OnEnter(StateMachine* pMachine);
	//--------------------------------------------------
	//Updates the state you are on in accordance with delta time(if there is anything to even update).
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//			Also takes in a float.
	//Returns:
	//		None
	//--------------------------------------------------
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	//--------------------------------------------------
	//Initiates the renderer to draw the object of your choosing
	//
	//Parameters:
	//			Takes in  renderer2d which is what allows you to render anything in the game
	//Returns:
	//		None
	//--------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);
	//--------------------------------------------------
	//Determines what will happen, when you enter the state 
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//Returns:
	//		None
	//--------------------------------------------------
	void OnExit(StateMachine* pMachine);

private:
	bool		m_draw = false;
	float		m_timer;
	Font*		m_font;
	ObjectPool*  obj;
};

