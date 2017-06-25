#pragma once
#include "MyMap.h"
#include "Resource.h"
#include <string.h>
#include <crtdbg.h>

template<typename T>
class ResourceManager
{
public:
	//--------------------------------------------------
	//Loads resources like textures and fonts
	//
	//Parameters:
	//			Takes in a char:filename and int:size
	//Returns:
	//		pResource->m_Data 
	//-------------------------------------------------
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
	//--------------------------------------------------
	//Delete everything
	//
	//Parameters:
	//
	//Returns:
	//		
	//--------------------------------------------------
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}
		m_ResourceList.Clear();
	}
	//--------------------------------------------------
	//Creates the instance that it will run on
	//
	//Parameters:
	//			
	//Returns:
	//		
	//--------------------------------------------------
	static void Create()
	{
		if (!m_pInstance)
		{
			m_pInstance = new ResourceManager<T>();
		}
	}
	//--------------------------------------------------
	//deletes the instance
	//
	//Parameters:
	//			
	//Returns:
	//		
	//--------------------------------------------------
	static void Destroy()
	{
		delete m_pInstance;
	}
	//--------------------------------------------------
	//Gets the instance
	//
	//Parameters:
	//			
	//Returns:
	//		m_pInstance
	//--------------------------------------------------
	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}
private:
	//--------------------------------------------------
	//Default constructor and destructor
	//
	//Parameters:
	//			None
	//Returns:
	//		None
	//-------------------------------------------------
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