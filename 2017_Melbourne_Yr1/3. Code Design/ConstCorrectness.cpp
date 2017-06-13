#include <iostream>
using namespace std;

class MyClass
{
	int data = 5;

	//prevents this function modifying ANY member variables
	void MemFunc() const
	{
		data += 3; //error
	}
};

//The return value cannot be changed after the function has ended
const char* MyFunction()
{
	return "Hello world";
}

int main()
{
	//const applies to whatever is on its immediate left,
	//if there is nothing then it applies to whatever is on its right.

	//Variable is constant and cannot be changed.
	const int value = 5;

	//p1 is a pointer to a constant int.
	const int* p1 = new int();
	p1 = new int(); //The pointer can change.
	*p1 = 7; //The contents cant.

	//This is the same as p1, just an alternative syntax.
	int const* p2 = new int();
	p2 = new int(); //The pointer can change.
	*p2 = 7; //The contents cant.

	//In this version it's the pointer that's const
	int* const p3 = new int();
	p3 = new int(); //The pointer can't change.
	*p3 = 7; //the value can.

	//Now nothing can change.
	int const* const p4 = new int();
	p4 = new int(); //error
	*p4 = 7; //error

	char* text = MyFunction(); //Error, function is const.
	const char* text = MyFunction(); //works and now text can't be changed.

	system("pause");
	return 0;
}