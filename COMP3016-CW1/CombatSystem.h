#pragma once
#pragma once
#include "Character.h"
#include "TurnManager.h"

class CombatSystem {
public:
    CombatSystem(TurnManager* tm);
    void performAttack(Character* attacker, Character* target);
    void performProtect(Character* character);
    void update();

private:
    TurnManager* turnManager;
};


