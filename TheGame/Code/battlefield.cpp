
#include <iostream>
#include "battlefield.hpp"
using namespace std;
Cell::Cell(Coordinate coordinate, Unit *war = NULL) {
    crd = coordinate;
    warrior = war;
}
Cell::Cell() {
    warrior = NULL;
}
Cell::Cell(int x, int y, Unit *war = NULL) {
    crd.setX(x);
    crd.setY(y);
    warrior = war;
}
Cell::~Cell() {
    if (warrior) {
        delete warrior;
    }
}
Unit *Cell::getWarrior() const {
    return warrior;
}
void Cell::setWarrior(Unit *war) {
    warrior = war;
}
int Cell::getX() const {
    return crd.getX();
}
void Cell::setX(int newX) {
    crd.setX(newX);
}
int Cell::getY() const {
    return crd.getY();
}
void Cell::setY(int newY) {
    crd.setY(newY);
}
Coordinate Cell::getCrd() const {
    return crd;
}
void Cell::print() const {
    crd.print();
    if (warrior) {
        warrior->print();
    } else {
        cout << "empty cell" << endl;
    }
}
BattleField::BattleField(int amount = 16) {
    size = amount;
    field = new Cell *[size];
    for (int i = 0; i < size; i++) {
        field[i] = new Cell[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            Coordinate tmp(j, i);
            Cell *tmpCell = new Cell(tmp);
            field[i][j] = *tmpCell;
        }
    }
}
BattleField::~BattleField() {
    for (int i = 0; i < size; i++) {
        delete[] field[i];
    }
    delete[] field;
    cout << "field deleted" << endl;
}
int BattleField::getSize() const {
    return size;
}
Cell **BattleField::getField() const {
    return field;
}
Cell BattleField::getCell(int x, int y) const {
    return field[y][x];
}
Cell BattleField::getCell(Coordinate crd) const {
    return field[crd.getY()][crd.getX()];
}
void BattleField::print() const {
    for (int i = -1; i < size; i++) {
        if (i == -1) {
            cout << "  ";
        } else {
            cout << i << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == 0) {
                cout << i << " ";
            }
            if (field[i][j].getWarrior()) {
                cout << "W ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}
