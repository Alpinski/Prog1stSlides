#include "ObjectPool.h"
#include "Entity.h"
#include "Renderer2D.h"
#include <crtdbg.h>

using namespace aie;

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	m_pPool = new MeObject*[nMaxSize];
	_ASSERT(m_pPool);
	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new MeObject();
		_ASSERT(m_pPool[i]);
	}
}

ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}
	delete[] m_pPool;
}

void ObjectPool::Update(float fDeltaTime)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->UpdateTransforms(fDeltaTime);
		}
	}
}

void ObjectPool::Draw(Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->Draw(m_2dRenderer);
		}			
	}
}

MeObject* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pPool[i]->GetActive())
		{
			m_pPool[i]->SetActive(true);
			return m_pPool[i];
		}
	}
	return nullptr;
}

void ObjectPool::Deallocate(MeObject* object)
{
	object->SetActive(false);
}