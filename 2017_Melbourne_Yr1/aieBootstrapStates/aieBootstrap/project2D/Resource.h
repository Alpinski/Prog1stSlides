#pragma once
#include <string.h>

template<typename T>
class Resource
{
public:
	Resource(char* szFileName)
	{
		int length = strlen(szFileName) + 1;
		m_szFileName = new char [length];
		strcpy_s(m_szFileName, length, szFileName);
		
		m_Data = new T(szFileName);
	}
	~Resource()
	{
		delete m_Data;
		delete[] m_szFileName;
	}

	char* m_szFileName;
	T* m_Data;
};

