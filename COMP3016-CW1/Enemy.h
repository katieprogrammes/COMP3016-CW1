#pragma once
#include "TypeMatchup.h"

class Enemy
{
public:
	Enemy(int health, int thwack, AttackType enemyType);
	~Enemy();

	void draw();

	//Reduces the health of current character by the attack damage of opponent
	void damaged(int baseDamage, AttackType playerMove);

	void noAttack();

	//Checks wether Character should attack now
	bool attackCheck();

	//Checks if the character is dead
	bool isDead();

	int getHP() const;

	int getMaxHP() const;

	AttackType getType() const;

private:
	bool attackNow;
	int HP, maxHP;
	AttackType enemyType;

};

