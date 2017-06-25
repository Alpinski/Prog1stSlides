#pragma once
#include <memory>


template<typename T>
class DynamicArray
{
public:

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

	~DynamicArray() 
	{
		delete[] m_pData;
	}

	DynamicArray (const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
	}

	DynamicArray& DynamicArray::operator=(const DynamicArray& other)
	{
		if (this == &other) return *this;
		delete[] m_pData;
		m_pData = new T[other.m_nCapacity];
		m_nCapacity = other.m_nCapacity;
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
		return *this;
	}

	DynamicArray(DynamicArray&& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_pData = other.m_pData;
		other.m_nCapacity = 0;
		other.m_pData = nullptr;
	}

	DynamicArray& operator= (DynamicArray&& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_pData = other.m_pData;
		other.m_nCapacity = 0;
		other.m_pData = nullptr;

		return *this;
	}

	void pushBack(T value)
	{
		if (m_nUsed >= m_nCapacity)
		{
			Resize();
		}
			
		m_pData[m_nUsed] = value;
		++m_nUsed;
	}

	void pushFront(T value)
	{
		Insert(0, value);
	}

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

	T popBack()
	{
		if (m_nUsed <= 0)
		{
			return m_nullValue;
		}
		--m_nUsed;
		return m_pData[m_nUsed];
	}

	T popFront()
	{
		if (m_nUsed <= 0)
		{
			return m_nullValue;
		}

		return remove(0);
	}

	void Clear()
	{
		m_nUsed = 0;
	}

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

	T& operator[](const int index)
	{
		if (index >= m_nUsed)
		{
			return m_nullValue;
		}
		return m_pData[index];
	}

	int Size()
	{
		return m_nUsed;
	}

	int Capacity()
	{
		return m_nCapacity;
	}

	T Back()
	{
		return m_pData[m_nUsed - 1];
	}

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