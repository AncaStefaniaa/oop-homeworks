//
// Created by Anca Ilicea on 4/24/2019.
//

#ifndef TEMA2_POO_GAME_H
#define TEMA2_POO_GAME_H

#include "mapp.h"
#include "robot.h"
#include "item.h"
#include "trap.h"
#include <fstream>

using namespace std;

class Game {

    int nr;//nr de runde
    vector<Item *> items;  //vector de iteme
    vector<Trap *> traps;  //vector de capcane
    int nrItems;  //nr iteme
    int nrTraps;  //nr capcane
    Robot *robo;  //robotul nostru
    mapp world;  //harta pe care se va desfasura actiunea


public:
    void setRobo(Robot *a) {
        robo = a;
    }

    friend class Robot;

    friend class Item;

    friend class Trap;

    friend class Fly;


    Game() : world(1, 1) {
        nr = 0;
        nrItems = 0;
        nrTraps = 0;

    }

    ~Game();

    friend ifstream &operator>>(ifstream &input, Game &game);

    void setRobotPosition(int x, int y);

    ofstream &playGame(ofstream &output);
};


#endif //TEMA2_POO_GAME_H
