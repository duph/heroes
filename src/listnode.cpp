#include <iostream>
#include ".\unitTypes.cpp"
//#include "/sdcard/CppDroid/projects/HeroesOfMightAndMagic/workfiles/unit.cpp"

using namespace std;
class ListNode {
private:
    Unit &warrior;
    ListNode *next;
    ListNode *prev;
public:
    ListNode(Unit &war, ListNode *nex = NULL, ListNode *pre = NULL) : warrior(war){
        prev = pre;
        next = nex;
    }
    ListNode &operator=(ListNode &other) {
        this->next = other.next;
        this->prev = other.prev;
        this->warrior = other.warrior;
        return *this;
    }
    ~ListNode() {
        delete &warrior;
    }
public:
    Unit &getWarrior() const {
        return warrior;
    }
    void setWarrior(Unit &war) {
        warrior = war;
    }
    ListNode *getNext() const {
        return next;
    }
    void setNext(ListNode *nex) {
        next = nex;
    }
    ListNode *getPrev() const {
        return prev;
    }
    void setPrev(ListNode *pre) {
        prev = pre;
    }
public:
    void print() {
        warrior.print();
    }
};