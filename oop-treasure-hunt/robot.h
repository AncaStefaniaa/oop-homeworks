//
// Created by Anca Ilicea on 4/24/2019.
//

#ifndef TEMA2_POO_ROBOT_H
#define TEMA2_POO_ROBOT_H

#include <string>
#include <vector>
#include <iostream>
#include "mapp.h"

using namespace std;

class Robot {  //clasa abstracta, memoreaza pozitia si itemele acceptate de robot

protected:
    pair<int, int> position;
    int resistance;
    vector<string> itemsAccepted;

public:
    friend class game;

    Robot();

    Robot(int i, int j);

    void setMapPosition(pair<int, int> p, mapp &world);  //pune robotul pe harta

    virtual ~Robot();

    virtual bool round(mapp &world) = 0;

    virtual void increaseResistance(int x);

    virtual void decreaseResistance(int x);

    int getResistance() const;

    pair<int, int> getPosition() const {
        return position;
    }

    void setPosition(int mR, int mC) {

        position.first = mR;
        position.second = mC;

    }

    virtual void changeAttribute(bool x) = 0;

};


class Ninja : public Robot {

    bool agility;
public:
    Ninja();

    Ninja(int i, int j);

    bool round(mapp &world);

    void changeAttribute(bool x) {};

};

class Warrior : public Robot {
public:
    Warrior(int i, int j);

    Warrior() {};

    bool round(mapp &world);

    void changeAttribute(bool x) {};
};

class HarryPotter : public Robot {
    bool invi;
    int rightC, leftC, upR, downR, move;
    int countGobstone;  //daca harry potter gaseste un item invincibil atunci el va avea capabilitatea de a ke evita pe toate
public:
    HarryPotter() {

        //int rightC,leftC,upR,downR,move;
        rightC = leftC = upR = downR = 0;
        move = 0;
    };

    HarryPotter(int x, int y);

    bool round(mapp &world);

    void changeAttribute(bool x);

};


#endif //TEMA2_POO_ROBOT_H
