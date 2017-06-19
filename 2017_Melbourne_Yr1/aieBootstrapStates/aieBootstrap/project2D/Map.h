#pragma once
#include <iostream>
#include "DynamicArray.h"
using namespace std;

template <class T>
class Map
{
public:
	void Size()
	{
		DA->Size();
	}

	bool IsItem(string name)
	{
		for (int i = 0; i < Size(); i++)
		{
			if (DA[i].name == name)
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
		Name = name;
		Data = data;
		DA->pushBack(d);
		return true;
	}

	T& operator [] (string name)
	{
		for (int i = 0; i<Size(); i++)
		{
			if (DA[i].name == name)
			{
				return DA[i].Data;
			}
		}
		long idx = Size();
		
		Name = name;
		DA->pushBack(d);
		return DA[idx].Data;
	}

	string GetItemName(long index)
	{
		if (index < 0)
		{
			index = 0;
		}
		for (int i = 0; i < Size(); i++)
		{
			if (i == index)
			{
				return DA[i].name;
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
		for (int i = 0; i<Size(); i++)
		{
			if (i == index)
			{
				return DA[i].Data;
			}
		}
		return DA[0].Data;
	}
private:

	T* Data;
	string* Name;
	DynamicArray<T>* DA;
};
