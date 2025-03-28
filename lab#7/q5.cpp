#include <iostream>
using namespace std;

class Character
{
protected:
    int characterID, level, healthPoints;
    string name, weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon)
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() { cout << name << " attacks!" << endl; }
    virtual void defend() { cout << name << " defends!" << endl; }
    virtual void displayStats()
    {
        cout << "Character: " << name << " | Level: " << level
             << " | HP: " << healthPoints << " | Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character
{
    int armorStrength, meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override { cout << name << " swings sword with " << meleeDamage << " damage!" << endl; }
};

class Mage : public Character
{
    int manaPoints, spellPower;

public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int spell)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}

    void defend() override { cout << name << " casts a magical barrier using " << manaPoints << " mana!" << endl; }
};

class Archer : public Character
{
    int arrowCount, rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override { cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy!" << endl; }
};

class Rogue : public Character
{
    int stealthLevel, agility;

public:
    Rogue(int id, string n, int lvl, int hp, string weapon, int stealth, int agi)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void displayStats() override
    {
        cout << "Rogue " << name << " | Stealth: " << stealthLevel << " | Agility: " << agility << endl;
    }
};

int main()
{
    Warrior w1(1, "Hamza", 10, 100, "Sword", 50, 30);
    Mage m1(2, "Bilal", 8, 80, "Staff", 100, 40);
    Archer a1(3, "Usman", 9, 90, "Bow", 20, 85);
    Rogue r1(4, "Daniyal", 7, 70, "Dagger", 90, 60);

    w1.attack();
    m1.defend();
    a1.attack();
    r1.displayStats();

    return 0;
}
