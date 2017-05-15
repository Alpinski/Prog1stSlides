#include <iostream>

//Examples of allocating memory
//The C++ way vs the C way.
int main()
{
	//Allocate an array of 10 ints (C++)
	int* data = new int[10];

	//Allocate an array of 10 ints (C)
	int* data2 = (int*)malloc(sizeof(int) * 10);

	//Set all the elements to zero using a loop
	for (int i = 0; i < 10; ++i)
	{
		data[i] = 0;
	}

	//Set all the elements to zero in one go using C function
	memset(data2, 0, sizeof(int) * 10);

	//Cleanup (C++)
	delete[] data;

	//Cleanup (C)
	free(data2);

	system("pause");

	return 0;
}