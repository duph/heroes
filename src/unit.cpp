#ifndef _UNIT_CPP_
#define _UNIT_CPP_

#include <iostream>
#include <cmath>

using namespace std;
int ymax = 16;
int xmax = 16;
class Coordinate {
private:
    int x;
    int y;
public:
    Coordinate() {
        x = -1;
        y = -1;
    }
    Coordinate(int newX, int newY) : x(newX), y(newY){

    }
    Coordinate &operator=(Coordinate newOne) {
        x = newOne.x;
        y = newOne.y;
        return *this;
    }
    bool operator==(Coordinate two) {
        if (x == two.x && y == two.y) {
            return true;
        }
        return false;
    }
public:
    int getX() {
        return x;
    }
    void setX(int newX) {
        x = newX;
    }
    int getY() {
        return y;
    }
    void setY(int newY) {
        y = newY;
    }
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
class Unit {
protected:
    int army;
    //string warType;
    int health;
    int stamina;
    int damage;
    int range;
    bool action;
    Coordinate crd;
public:
    Unit(int arm, int w, int h) {
        army = arm;
        //warType = "Common"
        health = 100;
        stamina = 3;
        damage = 5;
        action = false;
        range = 1;
        //crd;
        crd.setX(w);
        crd.setY(h);
    }
    /*Unit &operator=(Unit &other) {
        this->army =other.army;
        this->health = other.health;
        this->stamina = other.stamina;
        this->damage = other.damage;
        this->range = other.range;
        this->action = false;
        this->x = other.x;
        this->y = other.y;
        return *this;
    }*/
    Unit() {
        army = 1;
        health = 100;
        stamina = 3;
        damage = 5;
        range = 1;
        action = false;
        setX(0);
        setY(0);
    }
    virtual ~Unit(){
        //cout << "Unit destructed" << endl;
    }
public:
    Coordinate getCrd() {
        return crd;
    }
    int getX() {
        return crd.getX();
    }
    void setX(int coordinate) {
        crd.setX(coordinate);
    }
    int getY() {
        return crd.getY();
    }
    void setY(int coordinate) {
        crd.setY(coordinate);
    }
    int getHealth() const {
        return health;
    }
    void setHealth(int newHealth) {
         health = newHealth;
    }
    int getStamina() const {
        return stamina;
    }
    void setStamina(int newStamina) {
        stamina = newStamina;
    }
    int getDamage() const {
        return damage;
    }
    void setDamage(int newDamage) {
        damage = newDamage;
    }
    bool getAction() const {
        return action;
    }
    void setAction(bool newAction) {
        action = newAction;
    }
    int getRange() const {
        return range;
    }
    void setRange(int newRange) {
        range = newRange;
    }
    int getArmy() {
        return army;
    }
    void setArmy(int arm) {
        army = arm;
    }
public:
    virtual void makeDamage(Unit &target) {
        if (action == true || target.army == this->army) {
            return;
        }
        target.health -= this->damage;
        this->action = true;
    }
    Coordinate walkto(Coordinate newOne) {
        if (newOne.getX() >= xmax || newOne.getX() < 0 || newOne.getY() >= ymax || newOne.getY() < 0 || abs(getX() - newOne.getX()) + abs(getY() - newOne.getY()) > stamina) {
            cout << "Can't walk over there" << endl;
            return crd;
        }
        action = true;
        setX(newOne.getX());
        setY(newOne.getY());
        return newOne;
    }
    virtual void print() {
        cout << "health: " << health << endl;
        cout << "coordinates: ";
        crd.print();
        cout << endl;
    }
    virtual void printInfo() {
        cout << endl;
        for (int i = 0; i < 32; i++) {
            cout << "~";
        }
        cout << endl;
        cout << "Usual unit" << endl;
        crd.print();
        cout << "Army: " << army << endl;
        cout << "Health: " << health << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "Range: " << range << endl;
        cout << "Damage: " << damage << endl;
        for (int i = 0; i < 32; i++) {
            cout << "~";
        }
        cout << endl;
    }
    void crdt() {
        cout << "coordinates: ";
        crd.print();
    }
};
#endif // _UNIT_CPP_
