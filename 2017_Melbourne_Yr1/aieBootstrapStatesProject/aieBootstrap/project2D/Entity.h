#pragma once
#include "Font.h"

using namespace aie;
class Entity
{
public:
	//--------------------------------------------------
	//default Constructor and destructor
	//
	//Parameters:
	//			none
	//Returns:
	//		None
	//-------------------------------------------------
	Entity();
	~Entity();
	//--------------------------------------------------
	//uypdates an object on the screen
	//
	//Parameters:
	//			takes in a float
	//Returns:
	//		None
	//-------------------------------------------------
	void UpdateTransforms(float fDeltatime);
	//--------------------------------------------------
	//Draws the object
	//
	//Parameters:
	//		Takes in  renderer2d which is what allows you to render anything in the game
	//Returns:
	//		None
	//-------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);
	//--------------------------------------------------
	//Sets an object as active all other object calsses inherit from this class
	//
	//Parameters:
	//			takes in bool	true/false if objective is active or not
	//Returns:
	//		None
	//-------------------------------------------------
	void SetActive(bool bActive);
	//--------------------------------------------------
	//Gets the object if it's active
	//
	//Parameters:
	//			None
	//Returns:
	//		None
	//-------------------------------------------------
	bool GetActive();

private:
	bool m_bActive;
	Font* m_font;
};

