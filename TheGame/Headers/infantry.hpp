#ifndef INFANTRY_HPP_INCLUDED
#define INFANTRY_HPP_INCLUDED
#include "unit.hpp"
using namespace std;
class Infantry : public Unit {
protected:
    string warType;
public:
    Infantry();
    ~Infantry();
public:
    void print();
    void printInfo();
};


class Swordman : public Infantry {
public:
    Swordman();
    ~Swordman();
};


class Spearman : public Infantry {
public:
    Spearman();
    ~Spearman();
};
#endif // INFANTRY_HPP_INCLUDED
