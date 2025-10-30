#pragma once
#include <string>
class Character
{
public:
	Character(int health, int thwack, std::string attack);
	~Character();

	void draw();

	// Reduces the health of current character by the attack damage of opponent
	void damaged(int damage);

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

	std::string getAttack();
private:
	bool isProtected;
	bool attackNow;
	int HP, maxHP;
	std::string att;

};

