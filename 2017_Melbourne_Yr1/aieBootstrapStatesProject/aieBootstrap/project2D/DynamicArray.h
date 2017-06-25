#pragma once
#include <memory>


template<typename T>
class DynamicArray
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
	DynamicArray(int initialSize = 0)
	{
		int initial = initialSize;
		if (initial <= 0)
		{
			initial = 1;
		}

		m_pData = new T[initial];
		m_nCapacity = initial;
		m_nUsed = 0;
		memset(&m_nullValue, 0, sizeof(T));
	}
	//--------------------------------------------------
	//Default destructor
	//
	//Parameters:
	//			None
	//Returns:
	//		None
	//-------------------------------------------------
	~DynamicArray() 
	{
		delete[] m_pData;
	}
	//--------------------------------------------------
	//Copy constructor
	//
	//Parameters:
	//			Takes in a constant dynamicarray
	//Returns:
	//		None
	//-------------------------------------------------
	DynamicArray (const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
	}
	//--------------------------------------------------
	//copy assignment operator
	//
	//Parameters:
	//			None
	//Returns:
	//		None
	//-------------------------------------------------
	DynamicArray& DynamicArray::operator=(const DynamicArray& other)
	{
		if (this == &other) return *this;
		delete[] m_pData;
		m_pData = new T[other.m_nCapacity];
		m_nCapacity = other.m_nCapacity;
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
		return *this;
	}
	//--------------------------------------------------
	//Move constructor
	//
	//Parameters:
	//			takes in dynamicarray
	//Returns:
	//		None
	//-------------------------------------------------
	DynamicArray(DynamicArray&& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_pData = other.m_pData;
		other.m_nCapacity = 0;
		other.m_pData = nullptr;
	}
	//--------------------------------------------------
	//move assignment operator =
	//
	//Parameters:
	//			takes in dynamicarray
	//Returns:
	//		None
	//-------------------------------------------------
	DynamicArray& operator= (DynamicArray&& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_pData = other.m_pData;
		other.m_nCapacity = 0;
		other.m_pData = nullptr;

		return *this;
	}
	//--------------------------------------------------
	//pushes a value to the back of the array
	//
	//Parameters:
	//			take in a T (any type).
	//Returns:
	//		None
	//-------------------------------------------------
	void pushBack(T value)
	{
		if (m_nUsed >= m_nCapacity)
		{
			Resize();
		}
			
		m_pData[m_nUsed] = value;
		++m_nUsed;
	}
	//--------------------------------------------------
	//pushes a value to the front of the array
	//
	//Parameters:
	//			take in a T (any type).
	//Returns:
	//		None
	//-------------------------------------------------
	void pushFront(T value)
	{
		Insert(0, value);
	}
	//--------------------------------------------------
	//inserts a value into the array
	//
	//Parameters:
	//			take in a T (any type).
	//			also takes in the postion you want to insert in(index)
	//Returns:
	//		None
	//-------------------------------------------------
	void Insert(int index, T value)
	{
		if (index > m_nUsed)
		{
			return ;
		}

		if (m_nUsed >= m_nCapacity)
		{
			Resize();
		}

		memcpy(m_pData + index + 1, m_pData + index,sizeof(T) * (m_nUsed - index));
		
		/*for (int i = m_nUsed - 1; i >= index; --i)
		{
			m_pData[i + 1] = m_pData[i];
		}*/

		m_pData[index] = value;
		++m_nUsed;
	}
	//--------------------------------------------------
	//Removes a member from the array
	//
	//Parameters:
	//		takes in the postion you want to remove from(index)
	//Returns:
	//		return removed value
	//-------------------------------------------------
	T remove(int index)
	{
		if (index >= m_nUsed)
		{
			return 0;
		}
		//backup value removed from array
		T value = m_pData[index];
		//shuffle all other values across to fill removed space 
		for (int i = index; i < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;
		//return removed value
		return value;
	}
	//--------------------------------------------------
	//Pop's off an element from the array's back
	//
	//Parameters:
	//			none
	//Returns:
	//		the remove function since it pops from back of array
	//-------------------------------------------------
	T popBack()
	{
		if (m_nUsed <= 0)
		{
			return m_nullValue;
		}
		--m_nUsed;
		return m_pData[m_nUsed];
	}
	//--------------------------------------------------
	//Pop's off an element from the array's front
	//
	//Parameters:
	//			none
	//Returns:
	//		the remove function since it pops from front of array
	//-------------------------------------------------
	T popFront()
	{
		if (m_nUsed <= 0)
		{
			return m_nullValue;
		}

		return remove(0)
	}
	//--------------------------------------------------
	//Wipes the array clean. Clears the array
	//
	//Parameters:
	//			none
	//Returns:
	//		None
	//-------------------------------------------------
	void Clear()
	{
		m_nUsed = 0;
	}
	//--------------------------------------------------
	//Shrinks the array size accordint o what is being used and isn't being used.
	//
	//Parameters:
	//			none
	//Returns:
	//		None
	//-------------------------------------------------
	void Shrink()
	{
		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
		{
			nCapacity = 1;
		}
		T* newData = new T[nCapacity];
		memcpy(newData, m_pData, sizeof(T) * nCapacity);
		delete m_pData;
		m_pData = newData;
		m_nCapacity = nCapacity;
	}
	//--------------------------------------------------
	//subscript operator overload
	//
	//Parameters:
	//			Takes in an int
	//Returns:
	//		None
	//-------------------------------------------------
	T& operator[](const int index)
	{
		if (index >= m_nUsed)
		{
			return m_nullValue;
		}
		return m_pData[index];
	}
	//--------------------------------------------------
	//Tells you the size of the array when used
	//
	//Parameters:
	//			none
	//Returns:
	//		returns how much of array is used
	//-------------------------------------------------
	int Size()
	{
		return m_nUsed;
	}
	//--------------------------------------------------
	//tells you the capacity of the array when used
	//
	//Parameters:
	//			none
	//Returns:
	//		returns the capacity
	//-------------------------------------------------
	int Capacity()
	{
		return m_nCapacity;
	}
	//--------------------------------------------------
	//goes back one element in array
	//
	//Parameters:
	//			none
	//Returns:
	//		Returns the array it went back to
	//-------------------------------------------------
	T Back()
	{
		return m_pData[m_nUsed - 1];
	}
	//--------------------------------------------------
	//Shows you the second last member of the array
	//
	//Parameters:
	//			none
	//Returns:
	//		m_pData whatever is secondlast in array
	//-------------------------------------------------
	T SecondLast()
	{
		return m_pData[m_nUsed - 2];
	}
protected:


	void Resize()
	{
		//creates new array that is twice as big
		T* newData = new T[m_nCapacity * 2];
		//copy old data across into new array
		memcpy(newData, m_pData, sizeof(T) * m_nCapacity);
		//delete old array
		delete m_pData;
		//make sure pointers work
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	}


	T* m_pData;
	int m_nCapacity;
	int m_nUsed;
	T m_nullValue;
};