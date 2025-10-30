#include "Player.h"
#include <iostream>

Player::Player(int health, int baseDamage)
    : HP(health), maxHP(health), baseDamage(baseDamage), protectedStatus(false) {
}

void Player::attack(Enemy& target, AttackType moveType) {
    TypeMatchup matchup;
    float effectiveness = matchup.getEffectiveness(moveType, target.getType());
    int damage = static_cast<int>(baseDamage * effectiveness);

    target.damaged(damage, moveType);

    std::cout << "Player used " << TypeMatchup::typeToString(moveType)
        << " attack. Effectiveness: " << effectiveness
        << "x. Damage dealt: " << damage << "\n";
}

void Player::takeDamage(int damage) {
    if (protectedStatus)
        HP -= damage / 2;
    else
        HP -= damage;

    if (HP < 0) HP = 0;
}

void Player::protect() {
    protectedStatus = true;
}

void Player::unprotect() {
    protectedStatus = false;
}

bool Player::isDead() const {
    return HP == 0;
}

bool Player::isProtected() const {
    return protectedStatus;
}

int Player::getHP() const {
    return HP;
}

int Player::getMaxHP() const {
    return maxHP;
}
