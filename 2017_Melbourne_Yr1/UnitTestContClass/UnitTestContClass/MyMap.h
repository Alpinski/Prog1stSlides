#pragma once
#include <iostream>
#include "DynamicArray.h"
using namespace std;

template <class T>
class AssocArray
{
private:

	typedef struct Data
	{
		T m_data;
		string m_name;
	} Data;
	DynamicArray<Data> stack;

public:

	long Sized()
	{
		return stack.Size();
	}

	bool IsItem(string name)
	{
		for (int i = 0; i < Sized(); i++)
		{
			if (stack[i].m_name == name)
			{
				return true;
			}
		}
		return false;
	}

	bool AddItem(string name, T data)
	{
		if (IsItem(name))
		{
			return false;
		}
		Data d;
		d.m_name = name;
		d.m_data = data;
		stack.pushBack(d);
		return true;
	}

	T& operator [] (string name)
	{
		for (int i = 0; i < Sized(); i++)
		{
			if (stack[i].m_name == name)
			{
				return stack[i].m_data;
			}
		}
		long idx = Sized();
		Data d;
		d.m_name = name;
		stack.pushBack(d);
		return stack[idx].m_data;
	}

	string GetItemName(long index)
	{
		if (index < 0)
		{
			index = 0;
		}
			
		for (int i = 0; i < Sized(); i++)
		{
			if (i == index)
			{
				return stack[i].m_name;
			}
		}	
		return "";
	}

	T& operator [] (long index)
	{
		if (index < 0)
		{
			index = 0;
		}
		for (int i = 0; i < Sized(); i++)
		{
			if (i == index)
			{
				return stack[i].m_data;
			}		
		}
		return stack[0].m_data;
	}
};