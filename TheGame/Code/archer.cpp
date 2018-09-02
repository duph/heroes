#include <iostream>
#include "archer.hpp"
using namespace std;
Archer::Archer() : Unit() {
    warType = "Archer";
    range = 5;
    damage = 10;
    stamina = 3;

}
Archer::~Archer() {
    //cout << "Archer destructed" << endl;
}
void Archer::print() const {
    cout << warType << endl;
    cout << "health: " << health << endl;
    cout << endl;
}
void Archer::printInfo() const {
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


Crossbowman::Crossbowman() : Archer() {
    warType = "Crossbowman";
    damage = 12;
    range = 4;
    stamina = 3;
}
Crossbowman::~Crossbowman() {
    //cout << "crossbowman destructed";
}


Rifleman::Rifleman() : Archer() {
    warType = "Rifleman";
    damage = 15;
    range = 3;
    stamina = 3;
}
Rifleman::~Rifleman() {
    //cout << "Rifleman destructed";
}
