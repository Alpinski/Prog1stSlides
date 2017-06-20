#pragma once
#include "MyMap.h"
#include "Resource.h"
#include <string.h>
#include <crtdbg.h>

template<typename T>
class ResourceManager
{
public:

	T* LoadResource(char* szFileName , int Size)
	{
		//check if resource is already loaded
		//if it is, return it
			if (m_ResourceList.IsItem(szFileName))
			{
				return m_ResourceList[szFileName]->m_Data;
			}
		//resource is not loaded, so load it
		Resource<T>* pResource = new Resource<T>(szFileName, Size);
		_ASSERT(pResource);
		m_ResourceList.AddItem(szFileName, pResource);
		return pResource->m_Data;
	}

	//Delete everything
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}
		m_ResourceList.Clear();
	}

	static void Create()
	{
		if (!m_pInstance)
		{
			m_pInstance = new ResourceManager<T>();
		}
	}

	static void Destroy()
	{
		delete m_pInstance;
	}

	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}
private:
	ResourceManager()
	{
	}
	~ResourceManager()
	{
		UnloadAllResources();
	}

	AssocArray<Resource<T>*>m_ResourceList;
	static ResourceManager<T>* m_pInstance;
};

template<typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;