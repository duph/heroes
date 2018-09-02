#ifndef ARCHER_HPP_INCLUDED
#define ARCHER_HPP_INCLUDED
#include "unit.hpp"
using namespace std;
class Archer : public Unit {
protected:
    string warType;
public:
    Archer();
    ~Archer();
public:
    void print() const ;
    void printInfo() const ;
};


class Crossbowman : public Archer {
public:
    Crossbowman();
    ~Crossbowman();
};


class Rifleman : public Archer {
public:
    Rifleman();
    ~Rifleman();
};

#endif // ARCHER_HPP_INCLUDED
