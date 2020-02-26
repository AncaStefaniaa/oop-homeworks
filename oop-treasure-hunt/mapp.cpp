//
// Created by Anca Ilicea on 4/23/2019.
//
#include "mapp.h"

using namespace std;


mapp::mapp(int n, int m) {  //initializez harta setand latimea si inatimea


    height = n;
    width = m;
    Matrix.resize(n);
    for (int i = 0; i < n; i++)
        Matrix[i].resize(m);
    Matrix[0][0] = R;  //pun robotul pe pozitia 00 in matrice


}


mapp::~mapp() {

    Matrix.erase(Matrix.begin(), Matrix.end()); //dezaloc memoria

}


mapp::mapp(mapp &obj) {


    height = obj.height;
    width = obj.width;
    Matrix.resize(height);


    for (int i = 0; i < height; i++)
        Matrix[i].resize(width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            Matrix[i][j] = obj.Matrix[i][j];


}

bool mapp::isItem(pair<int, int> p) const {


    if (Matrix[p.first][p.second] == I) {
        return true;
    }
    return false;


}

bool mapp::isTrap(pair<int, int> p) const {


    if (Matrix[p.first][p.second] == T) {
        return true;
    }
    return false;


}


mapp &mapp::operator=(const mapp &A) {
    if (this != &A) {
        height = A.height;
        width = A.width;
        treasurePosition.first = A.treasurePosition.first;
        treasurePosition.second = A.treasurePosition.second;

        Matrix.resize(height);
        for (int i = 0; i < height; i++)
            Matrix[i].resize(width);
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                Matrix[i][j] = A.Matrix[i][j];
    }
    return *this;
}

ofstream &operator << (ofstream &output, mapp & world) {
    int i, j;
    for (i = 0; i < world.height; i++) {
        for (j = 0; j < world.width; j++) {
            output << world.Matrix[i][j] << " ";
        }
        output << "\n";
    }
    return output;
}