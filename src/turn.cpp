#include <iostream>
#include <cstdio>
#include <cmath>
#include ".\lists.cpp"
using namespace std;
class Game
{
protected:
    List *firstOpponent;
    List *secondOpponent;
    int turn;
public:
    Game() {
        firstOpponent = new List(1);
        secondOpponent = new List(2);
        turn = 0;
    }
    virtual ~Game() {
        delete firstOpponent;
        delete secondOpponent;
    }
public:
    List *getFirstOpponent() {
        return firstOpponent;
    }
    List *getSecondOpponent() {
        return secondOpponent;
    }
    int getTurn() {
        return turn;
    }
    virtual void armyChoose(int amount, List *army) {
        int coordinate;
        if (army->getArmyNum() == 1) {
            coordinate = 0;
        } else {
            coordinate = xmax - 1;
        }
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
            if (coordinate == xmax) {
                coord2 = ymax - (i + genAm);
            }
            Unit *arch = new Archer(army->getArmyNum(), coordinate, coord2);
            army->addNodeTail(*arch);
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
            if (coordinate == xmax) {
                d = ymax - (i + genAm);
            }
            Unit *kn = new Knight(army->getArmyNum(), coordinate, d);
            army->addNodeTail(*kn);
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
            Unit *mag = new Mage(army->getArmyNum(), coordinate, i + genAm);
            army->addNodeTail(*mag);
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
            Unit *horse = new Horseman(army->getArmyNum(), coordinate, i + genAm);
            army->addNodeTail(*horse);
        }
        genAm += horseAm;
    }
    bool turnIsOver (List *team) {
        for (int i = 0; i < team->getSize(); i++) {
            if (team->getNodePos(i)->getWarrior().getAction() == false) {
                return false;
            }
        }
        return true;
    }
    int gameEnd() {
        if (firstOpponent->isEmpty()||firstOpponent->getSize() == 0) {
            return 2;
        } else if (secondOpponent->isEmpty() || secondOpponent->getSize() == 0) {
            return 1;
        }
        return 0;
    }
    ListNode **enemiesInRange(Unit &obj) {
        ListNode *cur = firstOpponent->getStart();
        int size = firstOpponent->getSize();
        if (obj.getArmy() == 1) {
            cur = secondOpponent->getStart();
            size = secondOpponent->getSize();

        }
        ListNode **enemies = new ListNode*[size];
        int k = 0;
        while (cur){
            int xRange = abs(obj.getX() - cur->getWarrior().getX());
            int yRange = abs(obj.getY() - cur->getWarrior().getY());
            if (xRange <= obj.getRange() && yRange <= obj.getRange() && cur->getWarrior().getHealth() > 0 && cur->getWarrior().getArmy() != obj.getArmy()) {
                enemies[k] = cur;
                k++;
            }
            cur = cur->getNext();
        }
        if (k == 0) {
            delete[] enemies;
            return NULL;
        }
        return enemies;
    }
    bool isReserved(Coordinate xy) {
        int size = firstOpponent->getSize();
        for (int i = 0; i < size; i++) {
            if (firstOpponent->getNodePos(i)->getWarrior().getX() == xy.getX() && firstOpponent->getNodePos(i)->getWarrior().getY() == xy.getY()) {
                cout << endl;
                return true;
            }
        }
        size = secondOpponent->getSize();
        for (int i = 0; i < size; i++) {
            if (secondOpponent->getNodePos(i)->getWarrior().getX() == xy.getX() && secondOpponent->getNodePos(i)->getWarrior().getY() == xy.getY()) {
                cout << endl;
                return true;
            }
        }
        cout << endl;
        return false;
    }



    void makeDamage(Unit &obj) {
        if (obj.getAction() == true) {
            cout << "This unit has already done his action" << endl;
            return;
        }
        cout << "Enemies to attack:" << endl;
        ListNode **enemies = enemiesInRange(obj);
        if (!enemies) {
            cout << "No units to atack" << endl;
            return;
        }
        int enSize = 0;
        while (enemies[enSize]) {
            enSize++;
        }
        for (int j = 0; j < enSize; j++) {
            cout << j + 1 << ") ";
            cout << enemies[j]->getWarrior().getX() << " ";
            cout << enemies[j]->getWarrior().getY() << endl;
        }
        cout << endl;
        cout << "Choose: ";
        int target;
        cin >> target;
        target--;
        if (target >= enSize) {

            cout << "No target selected" << endl;
            delete[] enemies;
            return;
        }
        obj.makeDamage(enemies[target]->getWarrior());
        if (obj.getArmy() == 1) {
            buryDead(secondOpponent);
        } else {
            buryDead(firstOpponent);
        }
        delete[] enemies;
    }
    void walkto(Unit &obj) {
        if (obj.getAction() == true) {
            cout << "This unit has already done his action" << endl;
            return;
        }
        cout << "coordinates: ";
        int x, y;
        cin >> x >> y;
        Coordinate tmp;
        tmp.setX(x);
        tmp.setY(y);
        if (isReserved(tmp) == true) {
            cout << "This coordinate already contains a unit" << endl;
            return;
        }
        obj.walkto(tmp);
        if (enemiesInRange(obj) && obj.getAction() == true) {
            obj.setAction(false);
            makeDamage(obj);
        }

    }
    void oneUnitAction(Unit &obj) {
        while (obj.getAction() == false) {
            obj.print();
            int marker;
            cout << "Warrior actions:" << endl;
            cout << "1) Walk" << endl;
            cout << "2) Attack" << endl;
            cout << "3) Skip" << endl;
            cout << "4) Back" << endl;
            cout << "Choose: ";
            cin >> marker;
            if (marker == 1) {
                walkto(obj);
                if (obj.getAction() == false) {
                    continue;
                }
            } else if (marker == 2) {
                makeDamage(obj);
                if (obj.getAction() == false) {
                    continue;
                }
            } else if (marker == 3) {
                if (obj.getAction() == false) {
                    obj.setAction(true);
                    continue;
                }
            } else if (marker == 4) {
                return;
            } else {
                cout << "Action not chosen" << endl;
                continue;
            }
        }
        printMap();
    }
    void turnFinish(List *team) {
        int i = 0;
        while (team->getNodePos(i)) {
            team->getNodePos(i)->getWarrior().setAction(false);
            Unit *potentialMage = &team->getNodePos(i)->getWarrior();
            Mage* mag = dynamic_cast<Mage*>(potentialMage);
           	if (mag) {
                mag->manaPlus();
                if (mag->getMana() > 20) {
                    mag->setMana(20);
                }
            }
            i++;
        }
    }
    void buryDead(List *team) {
        int i = 0;
        while (team->getNodePos(i)) {
            if (team->getNodePos(i)->getWarrior().getHealth() <= 0) {
                team->removeNodePos(i);
                i--;
            }
            i++;
        }
    }
    void teamAction(List *team) {
        team->printList();
        printMap();
        while (turnIsOver(team) == false) {
            cout << "Choose unit: ";
            int num;
            cin >> num;
            num --;
            cout << endl;
            if (num >= team->getSize()) {
                cout << "Warrior not chosen" << endl;
                continue;
            }
            ListNode *cur = team->getStart();
            for (int i = 0; i < num; i++) {
                cur = cur->getNext();
            }
            oneUnitAction(cur->getWarrior());
        }
        if (gameEnd()) {
            return;
        }
        cout << "Pass the device to your opponent" << endl;
        turnFinish(team);
    }
    void printSoldierOnMap(Coordinate xy) {
        Unit *res = NULL;
        int i = 0;
        while (firstOpponent->getNodePos(i)) {
            Unit *war = &firstOpponent->getNodePos(i)->getWarrior();
            if (war->getX() == xy.getX() && war->getY() == xy.getY()) {
                res = war;
            }
            i++;
        }
        if (!res) {
            i = 0;
            while (secondOpponent->getNodePos(i)) {
                Unit *war = &secondOpponent->getNodePos(i)->getWarrior();
                if (war->getX() == xy.getX() && war->getY() == xy.getY()) {
                    res = war;
                }
                i++;
            }
        }
        if (res) {
            Archer* ar = dynamic_cast<Archer*>(res);
            Knight* kn = dynamic_cast<Knight*>(res);
            Mage* ma = dynamic_cast<Mage*>(res);
            Horseman* ho = dynamic_cast<Horseman*>(res);
            if (ar && !kn && !ma && !ho) {
                if (res->getArmy() == 1) {
                    cout << "A ";
                } else if (res->getArmy() == 2){
                    cout << "a ";
                }
            } else if (kn && !ar && !ma && !ho) {
                if (res->getArmy() == 1) {
                    cout << "K ";
                } else if (res->getArmy() == 2) {
                    cout << "k ";
                }
            } else if (ma && !kn && !ar && !ho) {
                if (res->getArmy() == 1) {
                    cout << "M ";
                } else if (res->getArmy() == 2) {
                    cout << "m ";
                }
            } else if (ho && !kn && !ma && !ar) {
                if (res->getArmy() == 1) {
                    cout << "H ";
                } else if (res->getArmy() == 2) {
                    cout << "h ";
                }
            } else {
                cout << "_ ";
            }
        } else {
            cout << "_ ";
        }
    }
    void printMap() {
        for (int i = -1; i < ymax; i++) {
            if (i == -1) {
                cout << "  ";
            }
            else {
                cout << i % 10 << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < ymax; i++) {
            for (int j = 0; j < xmax; j++) {
                if (j == 0) {
                    cout << i % 10 << " ";
                }
                Coordinate tmp(j, i);
                printSoldierOnMap(tmp);
            }
            cout << endl;
        }
        cout << endl;
    }
    virtual void gameProcess() {
        int amount;
        cout << "Troop's amount: ";
        cin >> amount;
        while (amount > ymax) {
            cout << "too many troops" << endl;
            cout << "maximal amount is " << ymax << endl;
            cin >> amount;
        }
        armyChoose(amount, firstOpponent);
        armyChoose(amount, secondOpponent);
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
            teamAction(secondOpponent);
        }
        int winner = gameEnd();
        cout << "Congratulations, team " << winner << " wins the battle in " << turn << " turns!" << endl;
        cout << "The end." << endl << "Made by Paul Ilyushin on 12.07.18" << endl;
    }

};
