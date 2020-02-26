//
// Created by Anca Ilicea on 4/23/2019.
//

#ifndef TEMA2_POO_HARTA_H
#define TEMA2_POO_HARTA_H

#include <utility>
#include <vector>
#include <fstream>

#define R 1
#define T -1
#define C 3
#define I 2

using namespace std;

class mapp {

    int width;  //inaltimea si latimea hartii
    int height;
    pair<int, int> treasurePosition;  //pozitia la care trebuie sa ajunga robotul pe harta
    vector<vector<int>> Matrix;

    friend class Item;

    friend class Robot;

    friend class Ninja;

    friend class Warrior;

    friend class HarryPotter;

    friend class Trap;

    friend class Game;
public:
    mapp() : width(1), height(1) { //pseudoconstructor pentru mapa
        Matrix.resize(1);
        Matrix[1].resize(1);
    }

    //constructori
    mapp(int n, int m);

    mapp(mapp &Matrix);

    ~mapp();  //destructor

    int getHeight() const {  //functia returneaza inaltimea mapei, nu modifica obiectul
        return height;
    }

    int getWidth() const {  //analog getHeight, doar ca pentru latime
        return width;
    }

    pair<int, int> getTreasurePosition(){  //returneaza pozitia la care trb sa ajung
        return treasurePosition;
    }

    void setTreasurePosition(pair <int,int> p){  //pozitionez comorile pe harta si le notez cu C
        treasurePosition.first=p.first;     // setez coordonatele
        treasurePosition.second=p.second;
        Matrix[p.first][p.second]=C;  //se face notatia
    }

    bool isItem(pair <int,int> p) const; //verific daca o pozitie pe harta este item
    bool isTrap(pair<int,int> p) const;  //verific daca o pozitie pe harta este capcana

    mapp &operator=(const mapp &A);

    friend ofstream &operator<<(ofstream &fout,mapp &world);



};


#endif //TEMA2_POO_HARTA_H
