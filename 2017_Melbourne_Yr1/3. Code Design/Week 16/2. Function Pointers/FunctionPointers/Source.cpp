#include <iostream>
#include "Player.h"
using namespace std;

typedef int (*MathFunction)(int lhs, int rhs);

//--------------------------------------------------------------------
//--------------------------------------------------------------------
int Add(int lhs, int rhs)
{
	return lhs + rhs;
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
int Sub(int lhs, int rhs)
{
	return lhs - rhs;
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
//MathFunction GetFunction(char opp)
int (*GetFunction(char opp))(int lhs, int rhs)
{
	if(opp == '+')
	{
		return &Add;
	}
	else if(opp == '-')
	{
		return &Sub;
	}
	else
	{
		return nullptr;
	}
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
void main()
{
	//MathFunction Math = nullptr;
	int (*Math)(int lhs, int rhs) = nullptr;

	while(true)
	{
		system("cls");
		cout << "Enter equation (e.g. 3 + 7):" << endl;

		int lhs;
		int rhs;
		char oper;

		cin >> lhs;
		cin >> oper;
		cin >> rhs;

		//Function pointer
		Math = GetFunction(oper);
		int answer = Math(lhs, rhs);
		cout << answer << endl;

		//Member function pointer
		Player myPlayer;
		Player::MathFunc func;
		func = myPlayer.GetFunction(oper);
		int answer2 = (myPlayer.*func)(lhs, rhs);
		cout << answer2 << endl;

		system("pause");
	}

	system("pause");
}