#include "CombatSystem.h"
#include <iostream>

CombatSystem::CombatSystem(TurnManager* tm)
    : turnManager(tm) {
}

void CombatSystem::performAttack(Character* attacker, Character* target) {
    if (!attacker->isDead() && !target->isDead()) {
        std::cout << attacker->getAttack() << " hits for 10 damage!\n";
        target->damaged(10); // You can customize damage logic
    }
}

void CombatSystem::performProtect(Character* character) {
    character->protect();
    std::cout << character->getAttack() << " is protecting!\n";
}

void CombatSystem::update() {
    if (turnManager->isBattleOver()) {
        std::cout << "Battle is over!\n";
        return;
    }

    Character* current = turnManager->getCurrentCharacter();
    current->attackCheck(); // You can use this to trigger UI or input
}
