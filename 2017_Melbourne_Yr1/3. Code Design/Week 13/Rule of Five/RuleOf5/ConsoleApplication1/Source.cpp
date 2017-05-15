#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "String.h"

String MyFunction(String data)
{
	return data;
}

int main()
{ 
	//String S1;

	/*String* pS1 = new String();
	delete pS1;*/
	
	String S2("Hello World");
	//String S3(S2);
	//S2 = S3;

	std::cout << std::endl;
	std::cout << "--------------" <<std::endl;
	std::cout << std::endl;

	String S4 = MyFunction(S2);
	
	std::cout << std::endl;
	std::cout << "--------------" <<std::endl;
	std::cout << std::endl;

	system("pause");
}