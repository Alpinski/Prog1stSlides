#include "Player.h"
#include <stdlib.h>

typedef struct Player
{
	int m_nHealth;
	float m_fPosX;
	float m_fPosY;

} Player;

Player* Player_Constructor()
{
	Player* pPlayer = malloc(sizeof(Player));
	pPlayer->m_fPosX = 0.0f;
	pPlayer->m_fPosY = 0.0f;
	pPlayer->m_nHealth = 100;

	return pPlayer;
}

void Player_Destructor(Player* pThis)
{
	free(pThis);
}

int Player_GetHealth(Player* pThis)
{
	return pThis->m_nHealth;
}

void Player_SetHealth(Player* pThis, int health)
{
	pThis->m_nHealth = health;
}

void Player_SetPosition(Player* pThis, float x, float y)
{
	pThis->m_fPosX = x;
	pThis->m_fPosY = y;
}

void Player_GetPosition(Player* pThis, float* x, float* y)
{
	*x = pThis->m_fPosX;
	*y = pThis->m_fPosY;
}