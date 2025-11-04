#pragma once
#include "TypeMatchup.h"
#include "Enemy.h"

class Player {
public:
    Player(int health, int baseDamage);

    std::pair<float, int> attack(Enemy& target, AttackType moveType);
    void takeDamage(int damage);

    bool isDead() const;
    int getHP() const;
    int getMaxHP() const;

private:
    int HP;
    int maxHP;
    int baseDamage;
};


