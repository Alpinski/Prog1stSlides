#include <iostream>
using namespace std;

class Enemy
{
};

int main()
{
	//-------------------------------------------------------------------------
	Enemy enemy; //One enemy on the Stack.

	//-------------------------------------------------------------------------
	Enemy* pEnemy = new Enemy(); //One enemy on the Heap.
	
	//-------------------------------------------------------------------------
	Enemy aEnemyArray[10]; //Array on the Stack containing 10 enemies on the Stack.
	
	//-------------------------------------------------------------------------
	Enemy* apEnemyList[10]; //Array on the Stack containing 10 pointers.
	for(int i = 0; i < 10; ++i)
	{
		apEnemyList[i] = new Enemy(); //Filling array with enemies on the Heap.
	}
	
	//-------------------------------------------------------------------------
	Enemy** ppEnemyList = new Enemy*[10]; //Pointer to array on the Heap, containing 10 pointers.
	for (int i = 0; i < 10; ++i)
	{
		ppEnemyList[i] = new Enemy();  //Filling array with enemies on the Heap.
	}

	//-------------------------------------------------------------------------
	//Don't forget to delete!
	//Only data on the Heap needs to be deleted: you need a "delete" for every "new".
	//-------------------------------------------------------------------------
	delete pEnemy; //delete one enemy on heap.

	//delete array
	for (int i = 0; i < 10; ++i)
	{
		delete apEnemyList[i]; //Delete enemies on the Heap.
	}

	for (int i = 0; i < 10; ++i)
	{
		delete ppEnemyList[i];  //Delete enemies on the Heap.
	}
	delete[] ppEnemyList; //Delete array on the Heap.

	return 0;
}
