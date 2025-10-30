#include "TurnManager.h"

TurnManager::TurnManager(std::vector<Character*>& party)
    : characters(party), currentIndex(0) {
}

void TurnManager::nextTurn() {
    characters[currentIndex]->unprotect(); // Reset protection
    characters[currentIndex]->noAttack();  // Reset attack flag

    do {
        currentIndex = (currentIndex + 1) % characters.size();
    } while (characters[currentIndex]->isDead());
}

Character* TurnManager::getCurrentCharacter() {
    return characters[currentIndex];
}

bool TurnManager::isBattleOver() {
    int aliveCount = 0;
    for (auto* c : characters) {
        if (!c->isDead()) aliveCount++;
    }
    return aliveCount <= 1;
}
