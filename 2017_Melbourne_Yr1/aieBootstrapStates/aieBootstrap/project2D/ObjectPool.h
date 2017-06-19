#pragma once
#include "MeObject.h"
class Entity;

class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	void Update(float fDeltaTime);

	void Draw(Renderer2D* m_2dRenderer);

	MeObject* Allocate();
	void Deallocate(MeObject * object);

private:
	MeObject** m_pPool;
	int m_nMaxSize;
};