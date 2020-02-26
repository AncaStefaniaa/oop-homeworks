//
// Created by Anca Ilicea on 4/24/2019.
//
#include "robot.h"
#include "trap.h"

Robot::Robot() {  //pozitionarea initiala
    position.first = 0;
    position.second = 0;
    resistance = 0;  //setarea rezistentei initiale
}

Robot::Robot(int i, int j) {  //pozitionarea efecttiva
    position.first = i;
    position.second = j;
    resistance = 0;  //setarea rezistentei initiale
}

void Robot::setMapPosition(pair<int, int> p, mapp &world) {
    world.Matrix[position.first][position.second] = R;  //pozitionez simbolul robotului pe harta
}

//urmeaza impementarea functiilor pentru rezistenta

int Robot::getResistance() const {  //returnez rezistenra robotului in momentul curent
    return resistance;
}

void Robot::increaseResistance(int x) {  //cresc rezistenta cu elementul din input
    resistance = resistance + x;
}

void Robot::decreaseResistance(int x) {  //scad rezistenra cu elementul din x
    resistance = resistance - x;
}

//destructor
Robot::~Robot() {

    cout << "robo a fost apelat" << endl;
    int i = 0;
    while (i < itemsAccepted.size()) {
        itemsAccepted[i].clear();
        i++;
    }
    itemsAccepted.clear();

}

//primul tip de robo

Ninja::Ninja() : Robot() {}


//setez itemele acceptate de fiecare robot

Ninja::Ninja(int i, int j) : Robot(i, j) {  //setez itemele ajutatoare compatibile cu acest tip de robo
    agility = false;
    itemsAccepted.push_back("pheonixFeather");
    itemsAccepted.push_back("Fly");
}

Warrior::Warrior(int i, int j) : Robot(i, j) {
    resistance = 3;
    itemsAccepted.push_back("pheonixFeather");
    itemsAccepted.push_back("omniocular");

}

HarryPotter::HarryPotter(int i, int j) : Robot(i, j) {
    countGobstone = 0;
    invi = false;
    itemsAccepted.push_back("pheonixFeather");
    itemsAccepted.push_back("gobstone");
}

void HarryPotter::changeAttribute(
        bool x) {  //harry potter devine invincibil in cazul in care colecteaza mai mult de 3 gobstoneuri
    if (countGobstone >= 3)
        invi = true;
}


//world reprezinta mapa unde se fa desfasura actiunea
//returnam adevarat daca robotelul gaseste comoara, daca nu atunci returnam fals

bool Ninja::round(mapp &world) {


    pair<int, int> prevPoz = getPosition();  //pastrez pozitia precedenta
    int i = getPosition().first;
    int j = getPosition().second;
    int xF = world.treasurePosition.first;  //coordonatele finishului
    int yF = world.treasurePosition.second;

    if (world.getTreasurePosition() == make_pair(j, i))  //verific initial daca am ajuns la finish
        return true;  //daca da, atunci termin si returnez da

    else {  //cazul in care nu am ajuns la finish



        //aici verific daca finishul este in apropiere
        if (abs(xF - i) <= 4 && abs(yF - j) <= 4) {
            //verific pentru prima coordonata daca comoara se afla sus sau jos fata de robot
            if (xF < i)
                setPosition(i - 1, j);  //daca se afla la sus ma mut un pas in jos
            else if (xF > i)
                setPosition(i + 1, j);  //daca se afla la jos ma mut un pas in sus

            //verific pentru coordonata 2 daca comoara se afla in stanga sau in dreapta
            if (yF < j)   //daca se afla la dreapta ma mut cu un pas la staga
                setPosition(i, j - 1);
            else if (yF > j)  //daca se afla in stanga ma mut cu un pas la dreapta
                setPosition(i, j + 1);


            //acum setez pozitiile gasite pe harta
            setMapPosition(getPosition(), world);

            //verific acum daca pasul pe  care am ajuns este o  capcana
            if (world.isTrap((getPosition()))) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);  //atunci robotul va primii insusirile respectivului trap
            }


        } else {



            //in cazul in care finishul nu este prin apropiere robotul se va muta linie cu linie
            setMapPosition(getPosition(), world);
            if ((getPosition().second == world.getWidth() - 1 && i % 2 == 0) ||
                (getPosition().second == 0 && i % 2 == 1)) {  //cazul in care ies din matrice la stanga sau la dreapta

                setPosition(i + 1, j);  //trec pe urmatorul rand
                setMapPosition(getPosition(), world);
                return 0;
            }

            //ma pozitionez acum pe linii
            if (i % 2 == 0)
                setPosition(i, j + 1);
            else
                setPosition(i, j - 1);
            setMapPosition(getPosition(), world);  //si setez acum pozitia pe harta


            //verific in continuare daca pe coordonatele pe care am ajuns exita o capcana
            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
                if (resistance ==
                    0) {  //daca rezistenta robtului e mai mare decat 0 atunci acesta fva fi afectat,daca nu, nu se va muta
                    setPosition(prevPoz.first, prevPoz.second);
                    setMapPosition(prevPoz, world);
                }
            }
            return 0;
        }
    }
    return false;
}


//se desfasoara analog rundei robotului ninja doar ca in loc sa se plimbe pe linie, acesta se
//plimba pe coloana
bool Warrior::round(mapp &world) {


    pair<int, int> prevPoz = getPosition();
    int i = getPosition().first;
    int j = getPosition().second;
    int xF = world.treasurePosition.first;
    int yF = world.treasurePosition.second;


    // verific daca am ajuns pe pozitia finala
    if (world.getTreasurePosition() == make_pair(j, i)) {
        return true; //daca da returnez adevarat
    } else {

        if (abs(xF - i) <= 4 && abs(yF - j) <= 4) {
            if (xF < i)
                setPosition(i - 1, j);
            else if (xF > i)
                setPosition(i + 1, j);
            if (yF < j)
                setPosition(i, j - 1);
            else if (yF > j)
                setPosition(i, j + 1);
            setMapPosition(getPosition(), world);


            //verific pozitia capcanei
            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
            }


        } else {
            //robotelul se va muta coloana cu coloana
            setMapPosition(getPosition(), world);
            if ((getPosition().first == world.getHeight() - 1 && j % 2 == 0) ||
                (getPosition().first == 0 && j % 2 == 1)) {
                setPosition(i, j + 1);
                setMapPosition(getPosition(), world);
                return 0;
            }


            if (j % 2 == 0) setPosition(i + 1, j);
            else setPosition(i - 1, j);
            setMapPosition(getPosition(), world);


            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
                if (resistance == 0) {

                    //daca rezistenta robtului e mai mare decat 0 atunci acesta fva fi afectat,daca nu, nu se va muta
                    setPosition(prevPoz.first, prevPoz.second);
                    setMapPosition(prevPoz, world);
                }
            }
        }
    }
    return false;
}


bool HarryPotter::round(mapp &world) {


    //setez pozitiile analog functiilor anterioare
    pair<int, int> prevPoz = getPosition();
    int i = getPosition().first;
    int j = getPosition().second;
    int xF = world.treasurePosition.first;
    int yF = world.treasurePosition.second;


    if (world.getTreasurePosition() == make_pair(j, i))  //verific initial daca am ajuns la finish
        return true;  //daca da, atunci termin si returnez da

    else {  //cazul in care nu am ajuns la finish



        //aici verific daca finishul este in apropiere
        if (abs(xF - i) <= 4 && abs(yF - j) <= 4) {
            //verific pentru prima coordonata daca comoara se afla sus sau jos fata de robot
            if (xF < i)
                setPosition(i - 1, j);  //daca se afla la sus ma mut un pas in jos
            else if (xF > i)
                setPosition(i + 1, j);  //daca se afla la jos ma mut un pas in sus

            //verific pentru coordonata 2 daca comoara se afla in stanga sau in dreapta
            if (yF < j)   //daca se afla la dreapta ma mut cu un pas la staga
                setPosition(i, j - 1);
            else if (yF > j)  //daca se afla in stanga ma mut cu un pas la dreapta
                setPosition(i, j + 1);


            //acum setez pozitiile gasite pe harta
            setMapPosition(getPosition(), world);

            //verific acum daca pasul pe  care am ajuns este o  capcana
            if (world.isTrap((getPosition()))) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);  //atunci robotul va primii insusirile respectivului trap
            }


        } else {
            //harry potter se va muta in spirala
            setMapPosition(getPosition(), world);
            if (move % 4 == 0) { // verific in ce directie se ma muta harry potter
                if (j == world.getWidth() - 1 - rightC) {
                    setPosition(i + 1, j);
                    move++;
                    upR++;
                } else setPosition(i, j + 1);
            } else if (move % 4 == 1) {
                if (i == world.getHeight() - 1 - downR) {
                    setPosition(i, j - 1);
                    move++;
                    rightC++;
                } else setPosition(i + 1, j);
            } else if (move % 4 == 2) {
                if (j == 0 + leftC) {
                    setPosition(i - 1, j);
                    move++;
                    downR++;
                } else setPosition(i, j - 1);
            } else if (move % 4 == 3) {
                if (i == 0 + upR) {
                    setPosition(i, j + 1);
                    move++;
                    leftC++;
                } else setPosition(i + 1, j);
            }

            //verific in continuare daca pe coordonatele pe care am ajuns exita o capcana
            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
                if (resistance == 0) {

                    //daca rezistenta robtului e mai mare decat 0 atunci acesta fva fi afectat,daca nu, nu se va muta
                    setPosition(prevPoz.first, prevPoz.second);
                    setMapPosition(prevPoz, world);
                }
            }


            return 0;
        }

    }

    return false;
}
