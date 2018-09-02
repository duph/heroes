#include <iostream>
#include "infantry.hpp"
using namespace std;
Infantry::Infantry() : Unit() {
    warType = "Infantry";
    damage = 7;
    stamina = 2;
}
Infantry::~Infantry() {
    //cout << "Knight destructed" << endl;
}
void Infantry::print() {
    cout << warType << endl;
    cout << "health: " << health << endl;
    cout << endl;
}
void Infantry::printInfo() {
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


Swordman::Swordman() {
    warType = "Swordman";
    stamina = 3;
}
Swordman::~Swordman() {
    //cout << "Swordman destructed";
}


Spearman::Spearman() {
    warType = "Spearman";
    range = 2;
}
Spearman::~Spearman() {
    //cout << "Spearman destructed";
}
