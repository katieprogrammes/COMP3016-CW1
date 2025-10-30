#pragma once
#include "TypeMatchup.h"

class Enemy
{
public:
	Enemy(int health, int thwack, AttackType enemyType);
	~Enemy();

	void draw();

	// Reduces the health of current character by the attack damage of opponent
	void damaged(int baseDamage, AttackType playerMove);

	// Blocks incoming attacks. Reduces 50% damage until this character's next turn
	void protect();

	void unprotect();

	void noAttack();

	// Checks wether Character should attack now
	bool attackCheck();

	// Checks if character is currently blocking damage
	bool protectCheck();

	// Checks if the character is dead
	bool isDead();

	int getHP();

	int getMaxHP();

	AttackType getType();

private:
	bool isProtected;
	bool attackNow;
	int HP, maxHP;
	AttackType enemyType;

};

