#include "Enemy.h"

Enemy::Enemy(int health, int thwack, AttackType enemyType)
{
	attackNow = false;

	HP = health;
	maxHP = HP;
	this->enemyType = enemyType;
	isProtected = false;
}
Enemy::~Enemy() {}

void Enemy::draw() {}

void Enemy::damaged(int baseDamage, AttackType playerMove)
{
	TypeMatchup matchup;
	float effectiveness = matchup.getEffectiveness(playerMove, enemyType);

	int finalDamage = static_cast<int>(baseDamage * effectiveness);

	if (isProtected)
		HP -= finalDamage / 2;
	else
		HP -= finalDamage;

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
int Enemy::getHP() const
{
	return HP;
}
int Enemy::getMaxHP() const
{
	return maxHP;
}
AttackType Enemy::getType() const
{
	return enemyType;
}


