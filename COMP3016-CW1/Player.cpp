#include "Player.h"
#include <iostream>

Player::Player(int health, int baseDamage)
    : HP(health), maxHP(health), baseDamage(baseDamage) {
}

std::pair<float, int> Player::attack(Enemy& target, AttackType moveType) {
    TypeMatchup matchup;
    float effectiveness = matchup.getEffectiveness(moveType, target.getType());
    int damage = static_cast<int>(baseDamage * effectiveness);

    target.damaged(damage, moveType);

    return { effectiveness, damage };
}


void Player::takeDamage(int damage) {
    HP -= damage;

    if (HP < 0) HP = 0;
}

bool Player::isDead() const {
    return HP == 0;
}


int Player::getHP() const {
    return HP;
}

int Player::getMaxHP() const {
    return maxHP;
}
