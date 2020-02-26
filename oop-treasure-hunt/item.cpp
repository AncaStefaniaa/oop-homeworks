//
// Created by Anca Ilicea on 4/23/2019.
//

#include "item.h"

//todo nu am putut sa definesc constructorul aici pentru ca imi aparea urmatoarea eroare si nu stiu de ce
//todo  error: addition of default argument on redeclaration makes this constructor a default constructor
//todo am inteles ca este din vina compilatorului meu

/*Item::Item(int i = 0, int j = 0) {
 *  position.first = i;
 *  position.second = j;
}*/

void Item::setMapPosition(pair<int, int> P, mapp &World) {
    World.Matrix[P.first][P.second]=I;  //setez pozitia itemului pe harta
}

ifstream &Item::read(ifstream &input, mapp &world) {
    input >> position.first;  //citesc coordonatele itemului pe harta
    input >> position.second;
    world.Matrix[position.first][position.second] = I;  //setez pe harta locul ite,ului cu I
    return input;
}

void pheonixFeather::effect(Robot &A) {
    A.increaseResistance(1);
}

void Fly::effect(Robot &A){
    A.changeAttribute(true);
}

void omnioculars::effect(Robot &A) {
    A.changeAttribute(true);
}

void gobstone::effect(Robot &A) {
    A.increaseResistance(2);
}


