#ifndef ARMY_HPP_INCLUDED
#define ARMY_HPP_INCLUDED
#include <iostream>
#include "infantry.hpp"
#include "mages.hpp"
#include "cavalry.hpp"
#include "archer.hpp"
using namespace std;
class Node {
private:
    Unit &warrior;
    Node *next;
    Node *prev;
public:
    Node(Unit &war, Node *nex, Node *pre);
    Node &operator=(Node &other);
    ~Node();
public:
    Unit &getWarrior() const;
    void setWarrior(Unit &war);
    Node *getNext() const;
    void setNext(Node *nex);
    Node *getPrev() const;
    void setPrev(Node *pre);
public:
    void print();
};
class Army {
private:
    int armyNum;
    int size;
    Node *start;
public:
    Army(int num);
    ~Army();
    Node *operator[](int pos) const;
public:
    int getArmyNum();
    void setArmyNum(int num);
    int getSize() const;
    Node *getStart();
    void setStart(Node *cur);
    bool isEmpty() const;
//    Node *addNodeTail(int width, int height);
    Node *addNodeTail(Unit &war);
 //   Node *addNodeHead(int width, int height);
//    Node *addNodePos(int width, int height, int pos = 0);
    void removeNodeHead();
    void removeNodeTail();
    void removeNodePos(int pos);
    void printArmy() const;
    Node *getNodeTail() const;
    Node *getNodeHead() const;
    Node *getNodePos(int pos) const;
};

#endif // ARMY_HPP_INCLUDED
