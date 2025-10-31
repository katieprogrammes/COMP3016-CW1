#include "TypeMatchup.h"

TypeMatchup::TypeMatchup() {
    // Initialize effectiveness table
    effectivenessTable[AttackType::FIRE][AttackType::PLANT] = 2.0f;
    effectivenessTable[AttackType::FIRE][AttackType::WATER] = 0.5f;
    effectivenessTable[AttackType::FIRE][AttackType::DARK] = 0.5f;
    effectivenessTable[AttackType::WATER][AttackType::FIRE] = 2.0f;
    effectivenessTable[AttackType::WATER][AttackType::PLANT] = 0.5f;
    effectivenessTable[AttackType::WATER][AttackType::LIGHTNING] = 2.0f;
    effectivenessTable[AttackType::PLANT][AttackType::WATER] = 2.0f;
    effectivenessTable[AttackType::PLANT][AttackType::FIRE] = 0.5f;
    effectivenessTable[AttackType::LIGHTNING][AttackType::WATER] = 2.0f;
    effectivenessTable[AttackType::LIGHTNING][AttackType::PLANT] = 0.5f;
    effectivenessTable[AttackType::LIGHTNING][AttackType::DARK] = 2.0f;
    effectivenessTable[AttackType::DARK][AttackType::PLANT] = 0.5f;
    // Default effectiveness is 1.0 (neutral)

}
float TypeMatchup::getEffectiveness(AttackType playerMove, AttackType enemyType) const { //finding the matchup in the table
    auto attackerIt = effectivenessTable.find(playerMove);
    if (attackerIt != effectivenessTable.end()) {
        auto defenderIt = attackerIt->second.find(enemyType);
        if (defenderIt != attackerIt->second.end()) {
            return defenderIt->second;
        }
    }
    return 1.0f; // Neutral effectiveness
}

std::string TypeMatchup::typeToString(AttackType type) {
    switch (type) {
    case AttackType::FIRE: return "Fire";
    case AttackType::WATER: return "Water";
    case AttackType::PLANT: return "Plant";
    case AttackType::LIGHTNING: return "Lightning";
    case AttackType::DARK: return "Dark";
    default: return "Physical";
    }
}
std::string TypeMatchup::effectToString(float value)
{
    if (value >= 2.0f) return "It's Super Effective!";
    else if (value <= 0.5f) return "It's Not Very Effective...";
    else return "It's effective.";
}
SDL_Color TypeMatchup::effectColor(float value)
{
    if (value >= 2.0f) return { 0, 230, 0 };
    else if (value <= 0.5f) return { 230, 46, 0 };
    else return { 77, 77, 255 };
}