#ifndef CAVALRY_HPP_INCLUDED
#define CAVALRY_HPP_INCLUDED
#include "unit.hpp"
using namespace std;
class Cavalry : public Unit {
protected:
    string warType;
public:
    Cavalry();
    ~Cavalry();
    void print() const ;
    void printInfo() const ;
};

class Driver : public Cavalry {
public:
    Driver();
    ~Driver();
};

class Horseman : public Cavalry {
public:
    Horseman();
    ~Horseman();
};
#endif // CAVALRY_HPP_INCLUDED
