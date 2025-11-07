#pragma once
#include <string>
#include <unordered_map>
#include <SDL.h>

enum AttackType //attack types
{
	FIRE,
	WATER,
	PLANT,
	LIGHTNING,
	DARK,
	PHYSICAL,
};

class TypeMatchup
{
public:
	TypeMatchup();

	float getEffectiveness(AttackType playerMove, AttackType enemyType) const;

	static std::string typeToString(AttackType type); //converting to string for output
	static std::string effectToString(float value);
	static SDL_Color effectColor(float value); //effectiveness colour for output

private:
	std::unordered_map<AttackType, std::unordered_map<AttackType, float>> effectivenessTable;
};

