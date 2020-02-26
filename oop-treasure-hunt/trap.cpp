//
// Created by Anca Ilicea on 4/23/2019.
//


#include "trap.h"

Trap::Trap(int i, int j, mapp &world) {

    world.Matrix[i][j] = T;  //notez pe harta cu T locul in care se afla capcana
    position.first = i;  //setez coordonatele
    position.second = j;

}

Trap::Trap() {  //constructorul cu care setez coord init

    position.first = -1;
    position.second = -1;

}

void Trap::read(ifstream &input, mapp &world) {  //citesc si repozitionez capcana in functie de input

    input >> position.first;
    input >> position.second;
    world.Matrix[position.first][position.second];

}

void Trap::effect(Robot *robo) {

    if (robo->getResistance() > 0)
        robo->decreaseResistance(1);
    if (robo->getResistance() == 0);

}

void Trap::setPosition(pair<int, int> p, mapp &world) {

    world.Matrix[p.first][p.second]=T;

}
