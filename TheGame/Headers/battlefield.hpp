#ifndef BATTLEFIELD_HPP_INCLUDED
#define BATTLEFIELD_HPP_INCLUDED
#include <iostream>
#include "infantry.hpp"
#include "cavalry.hpp"
#include "archer.hpp"
#include "mages.hpp"
using namespace std;
class Cell {
private:
    Unit *warrior;
    Coordinate crd;
public:
    Cell(Coordinate coordinate, Unit *war);
    Cell();
    Cell(int x, int y, Unit *war);
    ~Cell();
public:
    Unit *getWarrior() const;
    void setWarrior(Unit *war);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    Coordinate getCrd() const;
    void print() const;
};
class BattleField {
private:
    Cell **field;
    int size;
public:
    BattleField(int amount);
    ~BattleField();
public:
    int getSize() const;
    Cell **getField() const;
    Cell getCell(int x, int y) const;
    Cell getCell(Coordinate crd) const;
    void print() const;
};

#endif // BATTLEFIELD_HPP_INCLUDED
