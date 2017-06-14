#ifndef PLAYER
#define PLAYER

typedef struct Player Player;

Player* Player_Constructor();
void Player_Destructor(Player* pThis);

int Player_GetHealth(Player* pThis);
void Player_SetHealth(Player* pThis, int health);

void Player_SetPosition(Player* pThis, float x, float y);
void Player_GetPosition(Player* pThis, float* x, float* y);

#endif
