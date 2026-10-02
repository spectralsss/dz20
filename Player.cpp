#include "Player.h"
#include <iostream>

int Player::playerCount = 0;

int Player::getStrLen(const char* str) const {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void Player::copyStr(char* dest, const char* src) const {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

Player::Player(const char* name, int health, int level)
    : health(health < 0 ? 0 : (health > 100 ? 100 : health)), level(level) {
    this->name = new char[getStrLen(name) + 1];
    copyStr(this->name, name);

    playerCount++;
}

Player::Player() : Player("Unknown", 100, 1) {}

Player::~Player() {
    delete[] name;
    playerCount--;
}

const char* Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getLevel() const {
    return level;
}

void Player::setName(const char* newName) {
    delete[] name;
    name = new char[getStrLen(newName) + 1];
    copyStr(name, newName);
}

void Player::setHealth(int newHealth) {
    if (newHealth < 0) {
        health = 0;
    }
    else if (newHealth > 100) {
        health = 100;
    }
    else {
        health = newHealth;
    }
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

void Player::heal(int amount) {
    health += amount;
    if (health > 100) {
        health = 100;
    }
}

void Player::levelUp() {
    level++;
}

void Player::printStats() const {
    std::cout << "Гравець: " << name << "\n";
    std::cout << "Здоров'я: " << health << "/100\n";
    std::cout << "Рівень: " << level << "\n";
    std::cout << "-------------------------\n";
}

int Player::getPlayerCount() {
    return playerCount;
}