#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage);

	bool isAlive();

protected:
	int health;
	int maxHealth;
};

