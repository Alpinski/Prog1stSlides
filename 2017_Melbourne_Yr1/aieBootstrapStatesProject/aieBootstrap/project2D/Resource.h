#pragma once
#include <string.h>
#include <crtdbg.h>

template<typename T>
class Resource
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
	Resource(char* szFileName, int size)
	{
		int length = strlen(szFileName) + 1;
		m_szFileName = new char [length];
		_ASSERT(m_szFileName);
		strcpy_s(m_szFileName, length, szFileName);
		
		m_Data = new T(szFileName, size);
	}
	~Resource()
	{
		delete m_Data;
		delete[] m_szFileName;
	}

	char* m_szFileName;
	T* m_Data;
};

