#include <iostream>
#include "cavalry.hpp"
using namespace std;
Cavalry::Cavalry() : Unit() {
    warType = "Cavalry";
    damage = 12;
    stamina = 5;
}
Cavalry::~Cavalry() {
    //cout << "Horseman destructed" << endl;
}
void Cavalry::print() const {
    cout << warType << endl;
    cout << "health: " << health << endl;
    cout << endl;
}
void Cavalry::printInfo() const {
    cout << endl;
    for (int i = 0; i < 32; i++) {
        cout << "~";
    }
    cout << endl;
    cout << warType << endl;
    cout << "Health: " << health << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Range: " << range << endl;
    cout << "Damage: " << damage << endl;
    for (int i = 0; i < 32; i++) {
        cout << "~";
    }
    cout << endl;
}


Driver::Driver() {
    warType = "Driver";
    damage = 10;
    health = 200;
    stamina = 7;
}
Driver::~Driver() {
    //cout << "Driver destructed";
}


Horseman::Horseman() {
    warType = "Horseman";
    damage = 13;
    health = 150;
    stamina = 5;
}
Horseman::~Horseman() {
    //cout << "Horseman destructed";
}
