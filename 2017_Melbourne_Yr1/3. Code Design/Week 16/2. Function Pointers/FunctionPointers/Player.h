#pragma once

class Player
{
public:
	Player();
	~Player();

	int Add(int lhs, int rhs);
	int Sub(int lhs, int rhs);

	typedef int (Player::*MathFunc)(int lhs, int rhs);
	MathFunc GetFunction(char opp);
};

