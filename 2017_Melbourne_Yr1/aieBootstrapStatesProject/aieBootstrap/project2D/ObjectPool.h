#pragma once
#include "MeObject.h"
class Entity;

class ObjectPool
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
	ObjectPool(int nMaxSize);
	~ObjectPool();
	//--------------------------------------------------
	//Updates the object pool's objects
	//
	//Parameters:
	//			takes in a float delta time(updates in delta time)
	//Returns:
	//		None
	//-------------------------------------------------
	void Update(float fDeltaTime);
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
	//Allocates an object in the object pool
	//
	//Parameters:
	//		None
	//Returns:
	//		None
	//-------------------------------------------------
	MeObject* Allocate();
	//--------------------------------------------------
	//Deallocates an object in the object pool
	//
	//Parameters:
	//		None
	//Returns:
	//		None
	//-------------------------------------------------
	void Deallocate(MeObject * object);

private:
	MeObject** m_pPool;
	int m_nMaxSize;
};