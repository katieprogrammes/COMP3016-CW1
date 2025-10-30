#pragma once
#include <string>
#include <unordered_map>

enum AttackType //attack types
{
	FIRE,
	WATER,
	PLANT,
	LIGHTNING,
	PHYSICAL,
	DARK
};

class TypeMatchup
{
public:
	TypeMatchup();

	float getEffectiveness(AttackType playerMove, AttackType enemyType) const;

	static std::string typeToString(AttackType type); //converting to string for output

private:
	std::unordered_map<AttackType, std::unordered_map<AttackType, float>> effectivenessTable;
};

