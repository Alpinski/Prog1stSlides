#pragma once
#include "DynamicArray.h"
#include <crtdbg.h>

template<typename T>
class Stack
{
public:
	Stack(int initialSize = 0)
	{
		m_pData = new DynamicArray<T>(initialSize);
		_ASSERT(m_pData);
	}
	~Stack()
	{
		delete m_pData;
	}

	bool IsEmpty()
	{
		return(m_pData->Size() == 0);
	}

	int Size()
	{
		return m_pData->Size();
	}

	void Push(T value)
	{
		m_pData->pushBack(value);
	}

	T Pop()
	{
		return m_pData->popBack();
	}

	T Top()
	{
		return m_pData->popFront();
	}

	T SecondL()
	{
		return m_pData->SecondLast();
	}

	DynamicArray<T>*m_pData;
};

