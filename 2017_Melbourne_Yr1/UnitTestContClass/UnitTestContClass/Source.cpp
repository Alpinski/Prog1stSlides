#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main()
{
	DynamicArray<int> DA(5);

	DA.pushBack(1);

	cout << DA[7] << endl;


	system("pause");
}