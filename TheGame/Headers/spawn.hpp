#ifndef SPAWN_HPP_INCLUDED
#define SPAWN_HPP_INCLUDED
#include "army.hpp"
#include "infantry.hpp"
#include "archer.hpp"
#include "cavalry.hpp"
#include "mages.hpp"
class Citadel {
private:
    Army forces;
public:
    Citadel(Army arm);
    ~Citadel();
public:
    Army getForces();
    void setForces();
    Node *spawnWizard();
    Node *spawnPriest();
    Node *spawnCrossbowman();
    Node *spawnRifleman();
    Node *spawnDriver();
    Node *spawnHorseman();
    Node *spawnSwordman();
    Node *spawnSpearman();


};


#endif // SPAWN_HPP_INCLUDED

