#include <iostream>
#include "unit.hpp"
using namespace std;
Unit::Unit() {
    health = 100;
    stamina = 3;
    damage = 5;
    range = 1;
    action = false;
}
Unit::~Unit(){
    //cout << "Unit destructed" << endl;
}
int Unit::getHealth() const {
    return health;
}
void Unit::setHealth(int newHealth) {
     health = newHealth;
}
int Unit::getStamina() const {
    return stamina;
}
void Unit::setStamina(int newStamina) {
    stamina = newStamina;
}
int Unit::getDamage() const {
    return damage;
}
void Unit::setDamage(int newDamage) {
    damage = newDamage;
}
bool Unit::getAction() const {
    return action;
}
void Unit::setAction(bool newAction) {
    action = newAction;
}
int Unit::getRange() const {
    return range;
}
void Unit::setRange(int newRange) {
    range = newRange;
}
void Unit::makeDamage(Unit &target) {
    if (action == true) {
        return;
    }
    target.health -= this->damage;
    this->action = true;
}
void Unit::print() const {
    cout << "health: " << health << endl;
    cout << endl;
}
void Unit::printInfo() const {
    cout << endl;
    for (int i = 0; i < 32; i++) {
        cout << "~";
    }
    cout << endl;
    cout << "Usual unit" << endl;
    cout << "Health: " << health << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Range: " << range << endl;
    cout << "Damage: " << damage << endl;
    for (int i = 0; i < 32; i++) {
        cout << "~";
    }
    cout << endl;
}


Coordinate::Coordinate() {
    x = -1;
    y = -1;
}
Coordinate::Coordinate(int newX, int newY) : x(newX), y(newY){

}
Coordinate &Coordinate::operator=(Coordinate newOne) {
    x = newOne.x;
    y = newOne.y;
    return *this;
}
bool Coordinate::operator==(Coordinate two) {
    if (x == two.x && y == two.y) {
        return true;
    }
    return false;
}
int Coordinate::getX() const {
    return x;
}
void Coordinate::setX(int newX) {
    x = newX;
}
int Coordinate::getY() const {
    return y;
}
void Coordinate::setY(int newY) {
    y = newY;
}
void Coordinate::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}
