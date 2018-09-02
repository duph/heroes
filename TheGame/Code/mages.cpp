#include <cstdlib>
#include <ctime>
#include <iostream>
#include "mages.hpp"
using namespace std;
Mage::Mage() : Unit() {
    warType = "Mage";
    mana = 20;
}
Mage::~Mage() {

}
string Mage::getWarType() {
    return warType;
}
void Mage::setMana(int anam) {
    mana = anam;
}
int Mage::getMana() {
    return mana;
}
void Mage::manaPlus() {
    mana += 5;
}
void Mage::print() {
    cout << warType << endl;
    cout << "health: " << health << endl;
    cout << "mana: " << mana << endl;
    cout << endl;
}
void Mage::printInfo() {
    cout << endl;
    for (int i = 0; i < 32; i++) {
        cout << "~";
    }
    cout << endl;
    cout << warType << endl;
    cout << "Health: " << health << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Range: " << range << endl;
    cout << "Damage: 4 - 20" << endl;
    cout << "Mana: " << mana << endl;
    for (int i = 0; i < 32; i++) {
        cout << "~";
    }
    cout << endl;
}
void Mage::makeDamage(Unit &target) {
    if (this->action == true) {
        return;
    }
    srand(time(0));
    int dmg = rand() % this->damage + 4;
    cout << "damage: " << dmg << endl;
    if (dmg > mana) {
        cout << "Not enough mana" << endl;
        return;
    }
    target.setHealth(target.getHealth() - dmg);
    this->action = true;
    this->mana -= 3;
}


Wizard::Wizard() {
    warType = "Wizard";
    stamina = 3;
    damage = 2;
}
Wizard::~Wizard() {
    //cout << "Wizard destructed";
}


Priest::Priest() {
    warType = "Priest";
    damage = 8;
    health = 50;
}
Priest::~Priest() {
    //cout << "Priest destructed";
}
