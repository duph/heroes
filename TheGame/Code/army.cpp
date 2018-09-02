#include <iostream>
#include "army.hpp"
using namespace std;
Node::Node(Unit &war, Node *nex = NULL, Node *pre = NULL) : warrior(war){
    prev = pre;
    next = nex;
}
Node &Node::operator=(Node &other) {
    this->next = other.next;
    this->prev = other.prev;
    this->warrior = other.warrior;
    return *this;
}
Node::~Node() {
    delete &warrior;
}
Unit &Node::getWarrior() const {
    return warrior;
}
void Node::setWarrior(Unit &war) {
    warrior = war;
}
Node *Node::getNext() const {
    return next;
}
void Node::setNext(Node *nex) {
    next = nex;
}
Node *Node::getPrev() const {
    return prev;
}
void Node::setPrev(Node *pre) {
    prev = pre;
}
void Node::print() {
    warrior.print();
}









Army::Army(int num) {
    armyNum = num;
    size = 0;
    start = NULL;
}
Army::~Army() {
    Node *cur = start;
    while (cur) {
        Node *tmp = cur;
        cur = cur->getNext();
        delete tmp;
    }
}
Node *Army::operator[](int pos) const {
    if (size == 0 || pos >= size) {
        return NULL;
    }
    Node *cur = start;
    for (int i = 0; i < pos; i++) {
        cur = cur->getNext();
    }
    return cur;

}
int Army::getArmyNum() {
    return armyNum;
}
void Army::setArmyNum(int num) {
    armyNum = num;
}
int Army::getSize() const {
    return size;
}
Node *Army::getStart() {
    return start;
}
void Army::setStart(Node *cur) {
    start = cur;
}
bool Army::isEmpty() const {
    return size == 0;
}
/*Node *Army::addNodeTail(int width, int height) {
    Unit war(armyNum, width, height);
    Node *newNode = new Node(war);
    if (isEmpty() == true) {
        start = newNode;
    } else {
        Node *cur = start;
        while (cur->getNext()) {
            cur = cur->getNext();
        }
        newNode->setPrev(cur);
        cur->setNext(newNode);
    }
    size++;
    return newNode;
}*/
Node *Army::addNodeTail(Unit &war) {
    Node *newNode = new Node(war);
    if (isEmpty() == true) {
        start = newNode;
    } else {
        Node *cur = start;
        while (cur->getNext()) {
            cur = cur->getNext();
        }
        newNode->setPrev(cur);
        cur->setNext(newNode);
    }
    size++;
    return newNode;
}
/*Node *Army::addNodeHead(int width, int height){
    Unit war(armyNum, width, height);
    Node *newNode = new Node(war);
    newNode->setNext(start);
    start = newNode;
    if (size > 0) {
        newNode->getNext()->setPrev(newNode);
    }
    size++;
    return newNode;
}*/
/*Node *Army::addNodePos(int width, int height, int pos = 0) {
    Unit war(armyNum, width, height);
    Node *newNode;
    if (pos < 0 || pos > size) {
        cout << "inserted position doesn't exist" << endl;
        return NULL;
    } else {
        newNode = new Node(war);
        Node *cur = start;
        Node *prev = NULL;
        for (int i = 0; i < pos; i++) {
            prev = cur;
            cur = cur->getNext();
        }
        newNode->setNext(cur);
        newNode->setPrev(prev);
        if (prev) {
            prev->setNext(newNode);
        } else {
            start = newNode;
        }
        if (cur) {
            cur->setPrev(newNode);
        }
        size++;
    }
    return newNode;
}*/
void Army::removeNodeHead() {
    if (isEmpty()) {
        return;
    }
    Node *cur = start;
    start = cur->getNext();
    if (start) {
        start->setPrev(NULL);
    }
    delete cur;
    size--;
}
void Army::removeNodeTail() {
    if (size <= 1) {
        removeNodeHead();
        return;
    }
    Node *cur = start;
    while (cur->getNext()) {
        cur = cur->getNext();
    }
    cur->getPrev()->setNext(NULL);
    delete cur;
    size--;
}
void Army::removeNodePos(int pos = 0) {
    if (pos == 0) {
        removeNodeHead();
        return;
    }
    if (pos < 0 || pos >= size) {
        cout << "inserted position doesn't exist" << endl;
    } else {
        Node *cur = start;
        for (int i = 0; i < pos; i++) {
            cur = cur->getNext();
        }
        Node *pr = cur->getPrev();
        Node *nx = cur->getNext();
        if (pr) {
            pr->setNext(nx);
        }
        if (nx) {
            nx->setPrev(pr);
        }
        delete cur;
        size--;
    }
}
void Army::printArmy() const {
    cout << "Army~" << armyNum << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Units: " << size << endl << endl;
    if (isEmpty() == true) {
        cout << "Empty army" << endl;
        return;
    }
    Node *cur = start;
    while (cur) {
        cur->print();
        cur = cur->getNext();
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
Node *Army::getNodeTail() const {
    return getNodePos(size - 1);
}
Node *Army::getNodeHead() const {
    return getNodePos(0);
}
Node *Army::getNodePos(int pos) const {
    if (pos < 0 || pos >= size) {
        return NULL;
    }
    Node *cur = start;
    for (int i = 0; i < pos; i++) {
        cur = cur->getNext();
    }
    return cur;
}
