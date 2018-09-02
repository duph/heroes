#ifndef UNIT_HPP_INCLUDED
#define UNIT_HPP_INCLUDED
//#include "unit.cpp"
class Coordinate {
private:
    int x;
    int y;
public:
    Coordinate();
    Coordinate(int newX, int newY);
    Coordinate &operator=(Coordinate newOne);
    bool operator==(Coordinate two);
public:
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    void print()const;
};


class Unit {
protected:
    int health;
    int stamina;
    int damage;
    int range;
    bool action;
public:
    Unit();
    virtual ~Unit();
public:
    int getHealth() const;
    void setHealth(int newHealth);
    int getStamina() const;
    void setStamina(int newStamina);
    int getDamage() const;
    void setDamage(int newDamage);
    bool getAction() const;
    void setAction(bool newAction);
    int getRange() const;
    void setRange(int newRange);
public:
    virtual void makeDamage(Unit &target);
    virtual void print() const;
    virtual void printInfo() const;
};

#endif // UNIT_HPP_INCLUDED
