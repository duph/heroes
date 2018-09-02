#ifndef _BATTLEFIELD_CPP_
#define _BATTLEFIELD_CPP_

#include <iostream>
#include "lists.cpp"
using namespace std;

class Cell {
private:
    Unit *warrior;
    Coordinate crd;
public:
    Cell(Coordinate coordinate, Unit *war = NULL) {
        crd = coordinate;
        warrior = war;
    }
    Cell() {
        warrior = NULL;
    }
    Cell(int x, int y, Unit *war = NULL) {
        crd.setX(x);
        crd.setY(y);
        warrior = war;
    }
    ~Cell() {
        if (warrior) {
            delete warrior;
        }
    }
public:
    Unit *getWarrior() {
        return warrior;
    }
    void setWarrior(Unit *war) {
        warrior = war;
    }
    int getX() {
        return crd.getX();
    }
    void setX(int newX) {
        crd.setX(newX);
    }
    int getY() {
        return crd.getY();
    }
    void setY(int newY) {
        crd.setY(newY);
    }
    Coordinate getCrd() {
        return crd;
    }
    void print() {
        crd.print();
        if (warrior) {
            warrior->print();
        } else {
            cout << "empty cell" << endl;
        }
    }
};
class BattleField {
private:
    Cell **field;
    int size;
public:
    BattleField(int amount = 16) {
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
    ~BattleField() {
        for (int i = 0; i < size; i++) {
            delete[] field[i];
        }
        delete[] field;
        cout << "field deleted" << endl;
    }
public:
    int getSize() {
        return size;
    }
    Cell **getField() {
        return field;
    }
    Cell getCell(int x, int y) {
        return field[y][x];
    }
    Cell getCell(Coordinate crd) {
        return field[crd.getY()][crd.getX()];
    }
    void walkto(Unit *obj, Coordinate newOne) {
        if (obj->getAction() == true) {
            return;
        }
        Coordinate first = getCell(obj->getCrd()).getCrd();
        Coordinate second = obj->walkto(newOne);
        getCell(first).setWarrior(NULL);
        getCell(second).setWarrior(obj);
    }
    void makeDamage(Unit &obj, ListNode **enemies) {
        if (obj.getAction() == true) {
            return;
        }
        cout << "Enemies to attack:" << endl;
        int enSize = 0;
        while (enemies[enSize]) {
            enSize++;
        }
        for (int j = 0; j < enSize; j++) {
            cout << j + 1 << ") ";
            enemies[j]->getWarrior().getCrd().print();
        }
        cout << endl;
        cout << "Choose: ";
        int target;
        cin >> target;
        target--;
        if (target >= enSize) {

            cout << "No target selected" << endl;
            delete[] enemies;
            return;
        }
        Unit final = *getCell(enemies[target]->getWarrior().getCrd()).getWarrior();
        obj.makeDamage(final);
    }
    void print() {
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
};
#endif // _BATTLEFIELD_CPP_
