#pragma once

class Player {
private:
    char* name;
    int health;
    int level;

    static int playerCount;

    int getStrLen(const char* str) const;
    void copyStr(char* dest, const char* src) const;

public:
    Player(const char* name, int health, int level);
    Player();
    ~Player();

    const char* getName() const;
    int getHealth() const;
    int getLevel() const;

    void setName(const char* name);
    void setHealth(int health);

    void takeDamage(int damage);
    void heal(int amount);
    void levelUp();
    void printStats() const;

    static int getPlayerCount();
};