#pragma once
#include "DynamicArray.h"
#include <crtdbg.h>

template<typename T>
class Stack
{
public:
	//--------------------------------------------------
	//Default constructor
	//
	//Parameters:
	//			None
	//Returns:
	//		None
	//-------------------------------------------------
	Stack(int initialSize = 0)
	{
		m_pData = new DynamicArray<T>(initialSize);
		_ASSERT(m_pData);
	}
	//--------------------------------------------------
	//Default destructor
	//
	//Parameters:
	//			None
	//Returns:
	//		None
	//-------------------------------------------------
	~Stack()
	{
		delete m_pData;
	}
	//--------------------------------------------------
	//Checks if the stack is empty
	//
	//Parameters:
	//			None
	//Returns:
	//		bool true or false depending on if stack is empty
	//-------------------------------------------------
	bool IsEmpty()
	{
		return(m_pData->Size() == 0);
	}
	//--------------------------------------------------
	//The size of the stack
	//
	//Parameters:
	//			None
	//Returns:
	//		returns the size of the stack
	//-------------------------------------------------
	int Size()
	{
		return m_pData->Size();
	}
	//--------------------------------------------------
	//pushes an element to the back of the stack
	//
	//Parameters:
	//			Takes in T(anytype) to put in to the stack
	//Returns:
	//		
	//-------------------------------------------------
	void Push(T value)
	{
		m_pData->pushBack(value);
	}
	//--------------------------------------------------
	//Pops an element off from the back of the stack
	//
	//Parameters:
	//			None
	//Returns:
	//		popBack from Dynamicarray
	//-------------------------------------------------
	T Pop()
	{
		return m_pData->popBack();
	}
	//--------------------------------------------------
	//Looks at the top element in stack
	//
	//Parameters:
	//			None
	//Returns:
	//		back() from Dynamicarray
	//-------------------------------------------------
	T Top()
	{
		return m_pData->Back();
	}
	//--------------------------------------------------
	//Looks at the second last element in stack
	//
	//Parameters:
	//			None
	//Returns:
	//		Secondlast() from Dynamicarray
	//-------------------------------------------------
	T SecondL()
	{
		return m_pData->SecondLast();
	}

	DynamicArray<T>*m_pData;
};

