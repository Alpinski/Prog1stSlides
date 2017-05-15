#include <iostream>
using namespace std;

//--------------------------------------------------------
//Enemy Base Class.
//--------------------------------------------------------
class Enemy
{
public:
	//Pure virtual function: must be overriden by derived classes.
	virtual void Print() = 0;

	//Virtual function. Overidding is optional.
	virtual void Move()
	{
		cout << "The enemy rushes towards you." << endl;
	}
};

//--------------------------------------------------------
//Derived class, inherits from Enemy.
//--------------------------------------------------------
class Zombie : public Enemy
{
public:
	void Print() //Override pure virtual function in base class.
	{
		cout << "I'm a zombie." <<endl;
	}

	void Move() //Override virtual function in base class.
	{
		cout << "The zombie shambles towards you." << endl;
	}
};

//--------------------------------------------------------
//Derived class, inherits from Enemy.
//--------------------------------------------------------
class Demigorgan : public Enemy
{
public:
	void Print() //Override pure virtual function in base class.
	{
		cout << "DEMIGORGAN! RUN!" << endl;
	}
};

//--------------------------------------------------------
//--------------------------------------------------------
int main()
{
	//Creating my polymorphic enemy army
	Enemy** enemyArray = new Enemy*[10];
	for(int i = 0; i < 10; ++i)
	{
		//Randomly create either a Zombie or a Demigorgan and store pointer in Enemy array.
		int random = rand()%2;
		if(random == 0)
		{
			//Creates a pointer to the Zombie.
			//Zombie pointer can be stored in the Enemy array even though types are different 
			//because it inherits from Enemy. This is called polymorphism.
			enemyArray[i] = new Zombie();
		}
		else
		{
			//Create pointer to Demigorgan and store in Enemy array.
			enemyArray[i] = new Demigorgan();
		}
	}

	//Call Print() function on each Enemy.
	//Polymorphism causes the correct version of virtual functions to be called.
	for(int i = 0; i < 10; ++i)
	{
		enemyArray[i]->Print();
	}

	//Don't forget to delete.
	for(int i = 0; i < 10; ++i)
	{
		delete enemyArray[i]; //Delete each enemy on the Heap.
	}
	delete[] enemyArray; //Delete array from the Heap.
	
	system("pause");
	return 0;
}