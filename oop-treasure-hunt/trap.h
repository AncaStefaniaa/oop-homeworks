//
// Created by Anca Ilicea on 4/23/2019.
//

#ifndef TEMA2_POO_TRAP_H
#define TEMA2_POO_TRAP_H

#include "Robot.h"
#include "mapp.h"

using namespace std;

class Trap {
    pair<int, int> position;

public:
    friend class Robot;

    friend class Ninja;

    Trap(int i, int j, mapp &world);

    Trap();

    void effect(Robot *A);

    void read(ifstream &input, mapp &world);

    void setPosition(pair<int, int> p, mapp &world);

};

#endif //TEMA2_POO_TRAP_H
