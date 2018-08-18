#include <cstdlib>
#include <ctime>
#include ".\unit.cpp"
using namespace std;
class Archer : public Unit {
private:
    string warType;
public:
    Archer(int arm, int width, int height) : Unit(arm, width, height) {
        warType = "Archer";
        range = 5;
    }
    Archer() : Unit() {
        warType = "Archer";
    }
    ~Archer() {
        //cout << "Archer destructed" << endl;
    }
public:
    void print() {
        cout << warType << endl;
        cout << "health: " << health << endl;
        cout << "coordinates: ";
        crd.cordinate();
        cout << endl;
    }
};
class Knight : public Unit {
private:
    string warType;
public:
    Knight(int arm, int width, int height) : Unit(arm, width, height) {
        warType = "Knight";
        damage = 7;
        stamina = 2;
    }
    Knight() : Unit() {
        warType = "Knight";
        damage = 7;
        stamina = 2;
    }
    ~Knight() {
        //cout << "Knight destructed" << endl;
    }
public:
    void print() {
        cout << warType << endl;
        cout << "health: " << health << endl;
        cout << "coordinates: ";
        crd.cordinate();
        cout << endl;
    }
};
class Horseman : public Unit {
private:
    string warType;
public:
    Horseman(int arm, int width, int height) : Unit(arm, width, height) {
        warType = "Horseman";
        damage = 12;
        stamina = 5;
    }
    Horseman() : Unit() {
        warType = "Horseman";
        damage = 12;
        stamina = 5;
    }
    ~Horseman() {
        //cout << "Horseman destructed" << endl;
    }
public:
    void print() {
        cout << warType << endl;
        cout << "health: " << health << endl;
        cout << "coordinates: ";
        crd.cordinate();
        cout << endl;
    }
};
class Mage : public Unit {
private:
    string warType;
    int mana;
public:
    Mage(int arm, int width, int height) : Unit(arm, width, height) {
        warType = "Mage";
        mana = 20;
        range = 5;
        damage = 17;
    }
    Mage() : Unit() {
        warType = "Mage";
        mana = 20;
    }
    ~Mage() {
        //cout << "Mage destructed" << endl;
    }
    string getWarType() {
        return warType;
    }
    void setMana(int anam) {
        mana = anam;
    }
    int getMana() {
        return mana;
    }
    void manaPlus() {
        mana += 5;
    }
public:
    void print() {
        cout << warType << endl;
        cout << "health: " << health << endl;
        cout << "mana: " << mana << endl;
        cout << "coordinates: ";
        crd.cordinate();
        cout << endl;
    }
    void makeDamage(Unit &target) {
        if (this->action == true || target.getArmy() == this->army) {
            return;
        }
        srand(time(0));
        int dmg = rand() % this->damage + 4;
        cout << "damage: " << dmg << endl;
        if (dmg > mana) {
            dmg = mana;
            cout << "Not enough mana. Made " << dmg << " damage points" << endl;
        }
        target.setHealth(target.getHealth() - dmg);
        this->action = true;
        this->mana -= dmg;
    }
};
