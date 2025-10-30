#include "Character.h"

Character::Character(int health, int thwack, std::string attack)
{
	attackNow = false;

	HP = health;
	maxHP = HP;
	att = attack;
	isProtected = false;
}
Character::~Character() {}

void Character::draw () {}

void Character::damaged(int damage) 
{
	if (isProtected)
		HP = HP - damage / 2;
	else
		HP = HP - damage;
	if (HP < 0) HP = 0;
}
void Character::protect() 
{
	isProtected = true;
}

void Character::unprotect() 
{
	isProtected = false;
}
void Character::noAttack()
{
	attackNow = false;
}
bool Character::attackCheck()
{
	return attackNow;
}
bool Character::protectCheck()
{
	return isProtected;
}
bool Character::isDead()
{
	return HP == 0;
}
int Character::getHP()
{
	return HP;
}
int Character::getMaxHP()
{
	return maxHP;
}
std::string Character::getAttack()
{
	return att;
}
