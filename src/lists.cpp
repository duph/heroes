#ifndef _LISTS_CPP_
#define _LISTS_CPP_

#include <iostream>
#include "listnode.cpp"
using namespace std;
class List {
private:
    int armyNum;
    int size;
    ListNode *start;
public:
    List(int num) {
        armyNum = num;
        size = 0;
        start = NULL;
    }
    ~List() {
        ListNode *cur = start;
        while (cur) {
            ListNode *tmp = cur;
            cur = cur->getNext();
            delete tmp;
        }
    }
    ListNode *operator[](int pos) const {
        if (size == 0 || pos >= size) {
            return NULL;
        }
        ListNode *cur = start;
        for (int i = 0; i < pos; i++) {
            cur = cur->getNext();
        }
        return cur;

    }
public:
    int getArmyNum() {
        return armyNum;
    }
    void setArmyNum(int num) {
        armyNum = num;
    }
    int getSize() const {
        return size;
    }
    ListNode *getStart() {
        return start;
    }
    void setStart(ListNode *cur) {
        start = cur;
    }
    bool isEmpty() const {
        return size == 0;
    }
    ListNode *addNodeTail(int width, int height) {
        Unit war(armyNum, width, height);
        ListNode *newNode = new ListNode(war);
        if (isEmpty() == true) {
            start = newNode;
        } else {
            ListNode *cur = start;
            while (cur->getNext()) {
                cur = cur->getNext();
            }
            newNode->setPrev(cur);
            cur->setNext(newNode);
        }
        size++;
        return newNode;
    }
    ListNode *addNodeTail(Unit &war) {
        ListNode *newNode = new ListNode(war);
        if (isEmpty() == true) {
            start = newNode;
        } else {
            ListNode *cur = start;
            while (cur->getNext()) {
                cur = cur->getNext();
            }
            newNode->setPrev(cur);
            cur->setNext(newNode);
        }
        size++;
        return newNode;
    }
    ListNode *addNodeHead(int width, int height){
        Unit war(armyNum, width, height);
        ListNode *newNode = new ListNode(war);
        newNode->setNext(start);
        start = newNode;
        if (size > 0) {
            newNode->getNext()->setPrev(newNode);
        }
        size++;
        return newNode;
    }
    ListNode *addNodePos(int width, int height, int pos = 0) {
        Unit war(armyNum, width, height);
        ListNode *newNode;
        if (pos < 0 || pos > size) {
            cout << "inserted position doesn't exist" << endl;
            return NULL;
        } else {
            newNode = new ListNode(war);
            ListNode *cur = start;
            ListNode *prev = NULL;
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
    }
    void removeNodeHead() {
        if (isEmpty()) {
            return;
        }
        ListNode *cur = start;
        start = cur->getNext();
        if (start) {
            start->setPrev(NULL);
        }
        delete cur;
        size--;
    }
    void removeNodeTail() {
        if (size <= 1) {
            removeNodeHead();
            return;
        }
        ListNode *cur = start;
        while (cur->getNext()) {
            cur = cur->getNext();
        }
        cur->getPrev()->setNext(NULL);
        delete cur;
        size--;
    }
    void removeNodePos(int pos = 0) {
        if (pos == 0) {
            removeNodeHead();
            return;
        }
        if (pos < 0 || pos >= size) {
            cout << "inserted position doesn't exist" << endl;
        } else {
            ListNode *cur = start;
            for (int i = 0; i < pos; i++) {
                cur = cur->getNext();
            }
            ListNode *pr = cur->getPrev();
            ListNode *nx = cur->getNext();
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
    void printList() const {
        cout << "Army~" << armyNum << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Units: " << size << endl << endl;
        if (isEmpty() == true) {
            cout << "Empty list" << endl;
            return;
        }
        ListNode *cur = start;
        while (cur) {
            cur->print();
            cur = cur->getNext();
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    ListNode *getNodeTail() const {
        return getNodePos(size - 1);
    }
    ListNode *getNodeHead() const {
        return getNodePos(0);
    }
    ListNode *getNodePos(int pos) const {
        if (pos < 0 || pos >= size) {
            return NULL;
        }
        ListNode *cur = start;
        for (int i = 0; i < pos; i++) {
            cur = cur->getNext();
        }
        return cur;
    }
};
#endif // _LISTS_CPP_
