#pragma once
#include <vector>
#include "Character.h"

class TurnManager {
public:
    TurnManager(std::vector<Character*>& party);
    void nextTurn();
    Character* getCurrentCharacter();
    bool isBattleOver();

private:
    std::vector<Character*> characters;
    int currentIndex;
};
