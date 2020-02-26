//
// Created by Anca Ilicea on 3/21/2019.
//

#ifndef TEMA1_QUEUE_H
#define TEMA1_QUEUE_H

#include <iostream>
using namespace std;

struct Node {

    int value;
    Node *next;

};


class Queue {

    Node *front, *back;
    int qSize;

public:

    Queue();  //constructor
    Queue(Node *, Node *, int); //constructor cu parametrii
    ~Queue();  //destructor
    Queue &operator=(const Queue &object);  //copy constructor

    //todo supraincarcarea operatorilor

    void push(int);  //functia pentru inserarea unui element
    void pop();  //functia pentru eliminarea unui element
    int getFront(); //returneaza elementul din varful cozii
    bool isEmpty();  //verifica daca este goala coada
    void display();  //afiseaza coada
    int Len();  //afiseaza dimensiunea cozii
    void Rev();  //functie pentru inversarea unei cozi
    int getBack();  //returneaza ultimul element

    //supraincarcarea pentru citire si scriere
    friend istream &operator >>(istream &in, Queue &Q);
    friend ostream &operator <<(ostream &out, const Queue &Q);


    //supraincarcarea operatorilor de comparare
    bool operator ==(Queue);
    bool operator <(Queue);
    bool operator >(Queue);


};


#endif //TEMA1_QUEUE_H
