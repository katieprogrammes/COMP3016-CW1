#include "Enemy.h"

Enemy::Enemy(int health, int thwack, AttackType enemyType)
{
	attackNow = false;

	HP = health;
	maxHP = HP;
	//enemyType = AttackType;
	isProtected = false;
}
Enemy::~Enemy() {}

void Enemy::draw() {}

void Enemy::damaged(int damage)
{
	if (isProtected)
		HP = HP - damage / 2;
	else
		HP = HP - damage;
	if (HP < 0) HP = 0;
}
void Enemy::protect()
{
	isProtected = true;
}

void Enemy::unprotect()
{
	isProtected = false;
}
void Enemy::noAttack()
{
	attackNow = false;
}
bool Enemy::attackCheck()
{
	return attackNow;
}
bool Enemy::protectCheck()
{
	return isProtected;
}
bool Enemy::isDead()
{
	return HP == 0;
}
int Enemy::getHP()
{
	return HP;
}
int Enemy::getMaxHP()
{
	return maxHP;
}


