#include <iostream>
#include <cmath>
#define xmax 16
#define ymax 16
using namespace std;
class Coordinate {
private:
    int x;
    int y;
public:
    Coordinate() {

    }
    Coordinate(int newX, int newY) : x(newX), y(newY){

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
    void cordinate() {
        cout << "X: " << x << "  Y: " << y << endl;
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
        Coordinate crd;
        setX(0);
        setY(0);
    }
    virtual ~Unit(){
        //cout << "Unit destructed" << endl;
    }
public:
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
    void walkto(Coordinate newOne) {
        if (newOne.getX() >= xmax || newOne.getX() < 0 || newOne.getY() >= ymax || newOne.getY() < 0 || abs(getX() - newOne.getX()) + abs(getY() - newOne.getY()) > stamina) {
            cout << "Can't walk over there" << endl;
            return;
        }
        setX(newOne.getX());
        setY(newOne.getY());
        action = true;
        return;
    }
    virtual void print() {
        cout << "health: " << health << endl;
        cout << "coordinates: ";
        crd.cordinate();
        cout << endl;
    }
    void crdt() {
        cout << "coordinates: X: " << crd.getX() << "  Y: " << crd.getY() << endl;
    }
};
