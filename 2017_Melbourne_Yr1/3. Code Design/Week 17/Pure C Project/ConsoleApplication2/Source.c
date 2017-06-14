#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

#include "Player.h"

int main()
{
	float myX = 0.0f;
	float myY = 0.0f;
	Player* p1;
	char* text;
	char* text2;
	char buffer[256];
	int health;

	printf("------------------------------------\n");
	printf("Welcome to my C project!\n");
	printf("------------------------------------\n");

	printf("Creating the player\n");
	p1 = Player_Constructor();
	if(p1)
		printf("Player created successfully\n");

	health = Player_GetHealth(p1);
	Player_SetHealth(p1, 50);

	Player_GetPosition(p1, &myX, &myY);

	printf("Player's position is: %.1f, %.1f\n", myX, myY);

	text = "Hello";
	text2 = "world";
	
	sprintf(buffer, "The string is: %s, %d, %s\n", text, health, text2);

	printf(buffer);

	Player_Destructor(p1);

	system("pause");
	return 0;
}
