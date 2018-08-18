#include ".\turn.cpp"
#include <cmath>
#include <iostream>
using namespace std;
class AIGame : public Game {
public:
    AIGame() : Game(){

    }
    ~AIGame() {

    }
    void AIWalk(Unit& obj) {
        if (obj.getAction() == true) {
            return;
        }
        List *foe = firstOpponent;
        if (obj.getArmy() == 1) {
            foe = secondOpponent;
        }
        int minDist = 33;
        Unit nearestFoe = foe->getNodeHead()->getWarrior();
        for (int i = 0; i < foe->getSize(); i++) {
            int distance = abs(foe->getNodePos(i)->getWarrior().getX() - obj.getX()) + abs(foe->getNodePos(i)->getWarrior().getY() - obj.getY());
            if (distance < minDist) {
                minDist = distance;
                nearestFoe = foe->getNodePos(i)->getWarrior();
            }
        }
        Coordinate NF;
        NF.setX(nearestFoe.getX());
        NF.setY(nearestFoe.getY());

        Coordinate final(-1, -1);


        for (int i = -obj.getStamina(); i < obj.getStamina(); i++) {
            Coordinate tmp;
            for (int j = -(obj.getStamina() - abs(i)); j <= obj.getStamina() - abs(i); j++) {
                tmp.setY(obj.getY() + i);
                tmp.setX(obj.getX() + j);
                int distance = abs(NF.getX() -tmp.getX()) + abs(NF.getY() - tmp.getY());
                if (distance < minDist && !isReserved(tmp)) {
                    minDist = distance;
                    final.setX(tmp.getX());
                    final.setY(tmp.getY());
                    if (distance <= obj.getRange()) {
                        break;
                    }
                }
            }
        }
        obj.walkto(final);
        cout << "Moved to " << obj.getX() << " " << obj.getY() << endl;
        ListNode **enemies = enemiesInRange(obj);
        if (enemies) {
            obj.setAction(false);
            AIDmg(obj);
            delete[] enemies;
        }
    }




    void AIDmg(Unit& obj) {
        ListNode **enemies = enemiesInRange(obj);
        if (obj.getAction() == true || !enemies) {
            return;
        }
        int i = 0;
        int chosen = 0;
        int minHealth = enemies[chosen]->getWarrior().getHealth();
        while (enemies[i]) {
            if (enemies[i]->getWarrior().getHealth() < minHealth) {
                chosen = i;
                minHealth = enemies[chosen]->getWarrior().getHealth();
            }
            i++;
        }
        obj.makeDamage(enemies[chosen]->getWarrior());
        if (obj.getArmy() == 1) {
            buryDead(secondOpponent);
        } else {
            buryDead(firstOpponent);
        }
        cout << endl << "Unit with ";
        obj.crdt();
        cout << "Attacked unit ";
        enemies[chosen]->getWarrior().crdt();
        cout << endl;
        delete[] enemies;
    }
    void AIOneUnitAction(Unit& obj) {
        AIDmg(obj);
        AIWalk(obj);
        obj.setAction(true);
    }
    void AITeamAction(List *army) {
        for (int i = 0; i < army->getSize(); i++) {
            AIOneUnitAction(army->getNodePos(i)->getWarrior());
        }
        turnFinish(army);
    }




    void armyChoose(int amount) {
        int archAm = 0, knightAm = 0, mageAm = 0, horseAm = 0, genAm = 0;
        cout << "Choose your " << amount << " troops:" << endl;

        cout << "Archers(a): ";
        cin >> archAm;
        if (genAm + archAm > amount) {
            archAm = amount - genAm;
            cout << "too many troops. added " << archAm << " archers instead" << endl;
        }

        for (int i = 0; i < archAm; i++) {
            int coord2 = i + genAm;
            Unit *arch = new Archer(1, 0, coord2);
            firstOpponent->addNodeTail(*arch);
            Unit *AIarch = new Archer(2, xmax - 1, coord2);
            secondOpponent->addNodeTail(*AIarch);
        }
        genAm += archAm;
        if (genAm == amount) {
            return;
        }
        cout << genAm << "/" << amount << endl;
        cout << "Knights(k): ";
        cin >> knightAm;
        if (genAm + knightAm > amount) {
            knightAm = amount - genAm;
            cout << "too many troops. added " << knightAm << " knights instead" << endl;
        }

        for (int i = 0; i < knightAm; i++) {
            int d = i + genAm;
            Unit *kn = new Knight(1, 0, d);
            firstOpponent->addNodeTail(*kn);
            Unit *AIkn = new Knight(2, xmax - 1, d);
            secondOpponent->addNodeTail(*AIkn);
        }
        genAm += knightAm;
        if (genAm == amount) {
            return;
        }
        cout << genAm << "/" << amount << endl;
        cout << "Mages(m): ";
        cin >> mageAm;
        if (genAm + mageAm > amount) {
            mageAm = amount - genAm;
            cout << "too many troops. added " << mageAm << " mages instead" << endl;
        }
        for (int i = 0; i < mageAm; i++) {
            Unit *mag = new Mage(1, 0, i + genAm);
            firstOpponent->addNodeTail(*mag);
            Unit *AImag = new Mage(2, xmax - 1, i + genAm);
            secondOpponent->addNodeTail(*AImag);
        }
        genAm += mageAm;
        if (genAm == amount) {
            return;
        }
        cout << genAm << "/" << amount << endl;

        cout << "Horsemen(h): ";
        cin >> horseAm;
        if (genAm + horseAm > amount) {
            horseAm = amount - genAm;
            cout << "too many troops. added " << horseAm << " horsemen instead" << endl;
        }

        for (int i = 0; i < horseAm; i++) {
            Unit *horse = new Horseman(1, 0, i + genAm);
            firstOpponent->addNodeTail(*horse);
            Unit *AIhorse = new Horseman(2, xmax - 1, i + genAm);
            secondOpponent->addNodeTail(*AIhorse);
        }
        genAm += horseAm;
    }
    void gameProcess() {
        int amount;
        cout << "Troop's amount: ";
        cin >> amount;
        while (amount > ymax) {
            cout << "too many troops" << endl;
            cout << "maximal amount is " << ymax << endl;
            cin >> amount;
        }
        armyChoose(amount);
        firstOpponent->printList();
        secondOpponent->printList();
        printMap();
        while (gameEnd() == 0) {
            turn++;
            cout << "##########TURN " << turn << "##########" << endl;
            if (gameEnd() != 0) {
                break;
            }
            teamAction(firstOpponent);
            if (gameEnd() != 0) {
                break;
            }
            AITeamAction(secondOpponent);
        }
    }
};
