#include "DynamicArray.h"
#include "MyMap.h"
#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	
	DynamicArray<int> DA(6);
	Stack<int>St(6);

	//AssocArray<int>AA(string);
	cout << "DYNAMIC ARRAY TESTS" << endl;
	cout << "Size test." << endl;

	cout << DA.Size() << endl;


	cout << "Capacity test." << endl;

	cout << DA.Capacity() << endl;


	cout << "Push back test." << endl;

	for (int i = 0; i < 6; ++i)
	{
		cout << DA[i] << endl;
	}
	cout << "Before/After." << endl;

	DA.pushBack(1);
	DA.pushBack(2);
	DA.pushBack(3);
	DA.pushBack(4);

	for (int i = 0; i < 6; ++i)
	{
		cout << DA[i] << endl;
	}


	cout << "Push front test." << endl;

	for (int i = 0; i < 6; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "Before/After." << endl;

	DA.pushFront(5);
	DA.pushFront(5);
	DA.pushFront(5);
	DA.pushFront(5);

	for (int i = 0; i < 6; ++i)
	{
		cout << DA[i] << endl;
	}


	cout << "Insert test." << endl;

	for (int i = 0; i < 6; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "Before/After." << endl;

	DA.Insert(5, 21);

	for (int i = 0; i < 6; ++i)
	{
		cout << DA[i] << endl;
	}


	cout << "Remove test." << endl;

	cout << "Size Before "<<DA.Size() << endl;

	cout << "Before/After." << endl;

	DA.remove(4);

	cout << "Size sfter " << DA.Size() << endl;

	cout << "Pop back test." << endl;

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "Before/After." << endl;

	DA.popBack();

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}


	cout << "Pop front test." << endl;

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "Before/After." << endl;

	DA.popFront();

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}
	

	cout << "Shrink test." << endl;
	cout <<"Capacity Before :" <<DA.Capacity() << endl;
	DA.Shrink();
	cout << "Capacity after :"<< DA.Capacity() << endl;



	cout << "Clear test." << endl;

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "Before/After." << endl;

	DA.Clear();

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}


	cout << "Operator[] test." << endl;

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "Before/After." << endl;

	DA.operator[](10);

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}

	for (int i = 0; i < 9; ++i)
	{
		DA.pushBack(i);
	}
	cout << "Back test." << endl;

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "Before/After." << endl;
	cout << "what it went back to: "<< DA.Back() << endl;

	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}

	cout << "SecondLast test" << endl;
	for (int i = 0; i < 9; ++i)
	{
		cout << DA[i] << endl;
	}
	cout << DA.SecondLast() << endl;
	cout << "Success" << endl;
	cout << "Dynamic Array test end" << endl;
	cout << endl;
	//--------------------------------------
	//Stack test
	//--------------------------------------
	
	cout <<"STACK TESTS"<< endl;
	cout << endl;
	cout << "IsEmpty test" << endl;	
	St.IsEmpty();
	if (St.IsEmpty() == true)
	{
		cout << "Stack is Empty" << endl;
		cout << "Test success" << endl;
	}
	cout << endl;


	cout << "Size check test" << endl;
	St.Size();
	cout << St.Size() << endl;
	cout << "Success" << endl;
	cout << endl;


	cout << "Push test" << endl;
	St.Push(3);
	cout << St.Size() << endl;
	cout << "Success" << endl;
	cout << endl;


	cout << "Pop test" << endl;
	St.Pop();
	cout << St.Size() << endl;
	cout << "Success" << endl;
	cout << endl;


	cout << "Top test" << endl;
	St.Top();
	cout << St.Size() << endl;
	cout << "Success" << endl;
	cout << endl;

	St.Push(1);
	St.Push(2);
	St.Push(3);
	St.Push(4);
	cout << "SecondL test" << endl;
	St.SecondL();
	cout << St.SecondL() << endl;
	cout << "Success" << endl;
	cout << endl;
	cout << "Stack test end" << endl;

	system("pause");
}