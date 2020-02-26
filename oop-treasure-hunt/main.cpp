#include <iostream>
#include "game.h"

using namespace std;
ifstream input("..\\thewalk.in");
ofstream output("..\\thewalk.out");

int main() {

    Game theWalk;

    input >> theWalk;
    string type;
    input >> type;
    Robot *a;
    if (type == "Ninja") {
        a=new Ninja();
    } else if (type == "Warrior") {
        a=new Warrior();

    } else {
        a=new HarryPotter();

    }
    theWalk.setRobo(a);
    theWalk.playGame(output);

    return 0;
}