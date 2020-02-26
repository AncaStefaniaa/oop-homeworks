//
// Created by Anca Ilicea on 4/24/2019.
//

#include "game.h"
#include <bits/stdc++.h>
#include <algorithm>


void Game::setRobotPosition(int x, int y) {
    robo->setPosition(x,y);
}


ifstream &operator>>(ifstream &input, Game &game) {
    int x, y;
    input >> game.nr; //citesc numarul de randuri
    input >> x >> y;  //citesc coordonatele
    mapp A(x, y);
    input >> x >> y;
    A.setTreasurePosition(make_pair(x, y));
    input >> game.nrItems >> game.nrTraps;
    for (int i = 0; i < game.nr; i++) {
        //sets the type of robot and items
        string type;
        Item *currentItem;
        input >> type;
        if (type == "pheonixFeather") {
            pheonixFeather pH;
            pH.read(input, A);
            currentItem = &pH;
        } else if (type == "Fly") {
            Fly fly;
            fly.read(input, A);
            currentItem = &fly;
        } else if (type == "gobstone") {
            gobstone gob;
            gob.read(input, A);
            currentItem = &gob;
        } else {
            omnioculars omni;
            omni.read(input, A);
            currentItem = &omni;
        }
        game.items.push_back(currentItem);
    }

for (int i = 0; i < game.nr; i++) {
Trap *currentTrap = new Trap();
(*currentTrap).read(input, A);
game.traps.push_back(currentTrap);
}
game.world = A;
return input;
}

Game::~Game(){
    items.clear();
    traps.clear();
}

ofstream &Game::playGame(ofstream &output) {
    int it = 0;
    output << world;

    int i, j;
    //plays rounds until the treasure is not found
    while(robo->round(world)==0) {
        output << "Round:" << it << "\n";
        if (world.isItem(robo->getPosition())) {
            for (auto h: items) {
                if (h->getPosition() == robo->getPosition()) {
                    if (dynamic_cast<Ninja *>(robo) != nullptr) { // verifies if the item
                        if (dynamic_cast<pheonixFeather *>(h) != nullptr || dynamic_cast<Fly *>(h) != nullptr)
                            h->effect(*robo);
                    }else if(dynamic_cast<Warrior *>(robo) != nullptr){
                        if (dynamic_cast<pheonixFeather *>(h) != nullptr || dynamic_cast<gobstone *>(h) != nullptr)
                            h->effect(*robo);
                    }else if(dynamic_cast<HarryPotter*>(robo) != nullptr){
                        if (dynamic_cast<pheonixFeather *>(h) != nullptr || dynamic_cast<omnioculars *>(h) != nullptr)
                            h->effect(*robo);
                    }
                }
            }
        }
        output << world;
        it++;
        if (it == nr) exit(0);
    }
    return output;
}
