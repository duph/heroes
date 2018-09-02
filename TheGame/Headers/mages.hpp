#ifndef MAGES_HPP_INCLUDED
#define MAGES_HPP_INCLUDED
#include "unit.hpp"
using namespace std;
class Mage : public Unit {
protected:
    string warType;
    int mana;
public:
    Mage();
    ~Mage();
    string getWarType();
    void setMana(int anam);
    int getMana();
    void manaPlus();
public:
    void print();
    void printInfo();
    void makeDamage(Unit &target);
};


class Wizard : public Mage {
public:
    Wizard();
    ~Wizard();
};


class Priest : public Mage {
public:
    Priest();
    ~Priest();
};
#endif // MAGES_HPP_INCLUDED
