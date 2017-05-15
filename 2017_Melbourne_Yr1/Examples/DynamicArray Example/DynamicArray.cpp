#include <iostream>
using namespace std;

//A dynamic array resizes itself as new elements are added.
//This one is a template so it
template<typename T>
class DynamicArray
{
public:
	//Constructor takes in an initial size for the array
	DynamicArray(int size)
	{
		//Allocate the initial data for the array
		data = new T[size];

		count = 0;
		maxSize = size;
	}

	//Clean up
	~DynamicArray()
	{
		delete[] data;
	}

	//Add a new value to the array
	//If there is no room in the array, resize it to make room
	void Add(T value)
	{
		//Check if the array is full
		if(count >= maxSize)
		{
			//Create a new larger array
			T* newData = new T[maxSize * 2];

			//Copy the old data across into the new larger array
			for(int i = 0; i < count; ++i)
			{
				newData[i] = data[i];
			}

			//Delete the old copy
			delete[] data;

			//Assign the new array's pointer to the old pointer so it still works.
			data = newData;
			maxSize = maxSize * 2;
		}

		//Insert the new value into the array
		data[count] = value;
		++count;
	}

private:
	//Pointer to store an array of values of type T
	T* data;

	int count;
	int maxSize;
};

class Enemy
{
public:
	int health;
};

int main()
{
	Enemy* myEnemy = new Enemy;

	//Dynamic array that holds integers.
	DynamicArray<int> Army1(10);
	Army1.Add(6);

	//Dynamic array that holds Enemy pointers.
	DynamicArray<Enemy*> Army2(10);
	Army2.Add(myEnemy);

	system("pause");
	
	return 0;
}
