#include <iostream>
#include "spawn.hpp"
using namespace std;
Citadel::Citadel(Army arm) : forces(arm){

}
Citadel::~Citadel() {
    //cout << "Citadel destructed";
}
Node *Citadel::spawnWizard() {
    Unit *newOne = new Wizard;
    forces.addNodeTail(*newOne);
    cout << "Wizard spawned" << endl;
    return forces[forces.getSize()];
}
Node *Citadel::spawnPriest() {
    Unit *newOne = new Priest;
    forces.addNodeTail(*newOne);
    cout << "Priest spawned";
    return forces[forces.getSize()];
}
Node *Citadel::spawnCrossbowman() {
    Unit *newOne = new Crossbowman;
    forces.addNodeTail(*newOne);
    cout << "Crossbowman spawned";
    return forces[forces.getSize()];
}
Node *Citadel::spawnRifleman() {
    Unit *newOne = new Rifleman;
    forces.addNodeTail(*newOne);
    cout << "Rifleman spawned";
    return forces[forces.getSize()];
}
Node *Citadel::spawnDriver() {
    Unit *newOne = new Driver;
    forces.addNodeTail(*newOne);
    cout << "Driver spawned";
    return forces[forces.getSize()];
}
Node *Citadel::spawnHorseman() {
    Unit *newOne = new Horseman;
    forces.addNodeTail(*newOne);
    cout << "Horseman spawned";
    return forces[forces.getSize()];
}
Node *Citadel::spawnSwordman() {
    Unit *newOne = new Swordman;
    forces.addNodeTail(*newOne);
    cout << "Swordman spawned";
    return forces[forces.getSize()];
}
Node *Citadel::spawnSpearman() {
    Unit *newOne = new Spearman;
    forces.addNodeTail(*newOne);
    cout << "Spearman spawned";
    return forces[forces.getSize()];
}
