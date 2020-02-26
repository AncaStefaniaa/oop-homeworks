//
// Created by Anca Ilicea on 4/23/2019.
//

#ifndef TEMA2_POO_ITEM_H
#define TEMA2_POO_ITEM_H

#include "mapp.h"
#include "robot.h"

using namespace std;

class Item {
        protected:
        pair<int, int> position;

        public:
        friend class Robot;

        Item(int i, int j){
            position.first = i;
            position.second = j;
        }

        virtual void effect(Robot &A) = 0;

        pair<int, int> getPosition() const {
            return position;
        }

        void setMapPosition(pair<int, int> P, mapp &World);

        ifstream &read(ifstream &input, mapp &world);
};


class pheonixFeather : public Item {

public:
    pheonixFeather(int x = 0, int y = 0) : Item(x, y) {}
    void effect(Robot &A);

};


class Fly : public Item {

    Ninja *A;
public:
    Fly(int x = 0, int y = 0) : Item(x, y) {}
    void effect(Robot &A);

};


class omnioculars : public Item {

public:
    omnioculars(int x = 0, int y = 0) : Item(x, y) {}
    void effect(Robot &A);

};


class gobstone: public Item{

public:
    gobstone(int x=0,int y=0):Item(x,y){}
    void effect(Robot &A);

};


#endif //TEMA2_POO_ITEM_H
