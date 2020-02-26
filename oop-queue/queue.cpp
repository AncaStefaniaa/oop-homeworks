//
// Created by Anca Ilicea on 3/21/2019.
//
#include "Queue.h"
#include <iostream>

using namespace std;


void Queue::display() {   //afiseaza stiva
    if (front == NULL) {  //verific initial daca coada este goala
        cout << "Underflow." << endl;
        return;
    }
    Node *temp = front;
    //voi avansa in stiva pana cand voi intalnii NULL si afisez valoarea fiecarui Node
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}


Queue::~Queue() { //destructor

    while (front != NULL) {  //cat timp coada nu este goala avansez si sterg din memorie nodurile
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    back = NULL; //la final elementul din coada cozii va devenii NULL
}

Queue::Queue() {   //constructor

    front = back = NULL;  //setez primul si ultimul element ca fiind nule
    qSize = 0; //setez dimensiunea cozii la 0
    cout << "Queue was set" << endl;
}

Queue::Queue(Node *rearIn, Node *frontIn, int sizeIn) {  //constructor cu parametrii

    back = rearIn; //initalizez coada cozii cu valoarea parametrului rearIn
    qSize = sizeIn; //initalizez dimensiunea cozii cu valoarea parametrului sizeIn
    front = frontIn; //initalizez varful cozii cu valoarea parametrului rearIn

    cout << "Queue was set" << endl;
}

void Queue::push(int x) {


    if (front == NULL) { //verific initial daca stiva este goala


        front = back = new Node; //daca da atunci aloc memorie pentru front si back
        front->value = back->value = x; //va fi un singur element in coada deci back s front for fi egale
        back->next = NULL; //initializez valoarea next cu NULL deoarece nu mai urmeaza niciun element


    } else {

        Node *p = new Node; //daca nu este goala atunci aloc memorie pentru un nou nod
        p->value = x; //valoarea noului nod va devenii egala cu x
        p->next = NULL;  //p va fi ultimul element din coada
        back->next = p;  //coada cozii va devenii nodul adaugat anterior
        back = p;

    }


}

int Queue::getFront() {


    if (front == NULL) //verific daca coada este goala
        return -1;  //daca da returnez -1
    return front->value;  //daca nu returnez elementul din varf


}

int Queue::getBack(){

    if (front == NULL) //verific daca coada este goala
        return -1;  //daca da returnez -1
    return back->value;  //daca nu returnez elementul din coada

}


void Queue::pop() {


    if (front == NULL)  //verific initial daca coada este nula
        return; //daca da atunci nu sterg nimic si termn executia
    Node *p = front; //daca nu este nula atunci aloc memorie pentru nodul ce va devenii varful cozii
    front = front->next;  //setez varful cozii ca fiind urmatorul element dupa cel sters
    delete p;  //sterg nodul care fusese anterior in varful cozii


}

bool Queue::isEmpty() {

    if (front == NULL &&
        back == NULL) //daca front si back sunt nule atunci inseamna ca stiva este goala si returnez true
        return true;
    return false;

}

int Queue::Len() {

    Node *aux = front;  //voi folosi o variabila ajutatoare de tip nod pentru a parcurge coada pe care o initializez cu primul element
    qSize = 0;  //initializez lungimea cozii cu 0


    while (aux != NULL) {   //cat timp exista variabila, adica nu am ajuns la capatul cozii

        qSize++;  //creste lungimea cozii
        aux = aux->next;  //trec la uratorul element din coada

    }
    return qSize;
}

//todo copiere, supraincarcare <<,>>,==,>,< si reverse

ostream &operator<<(ostream &out, const Queue &Q) {  //functia pentru supraincarearea operatorului <<


    Node *aux = Q.front;  //folosesc o variabila ajutatoare de tip nod care va lua valoarea varfului cozii
    while (aux != NULL) {  //cat timp nu am ajuns la final
        out << aux->value << " ";  //afisez valoarea
        aux = aux->next;  //trec la urmatorul nod
    }
    out << endl;
    return out;


}

istream &operator>>(istream &in, Queue &Q) {  //functia pentru supraincarea operatorului >>


    int n, value;  //n reprezinta numarul de elemente pe care vreau sa le citesc
    cin >> n;
    int i = 0;

    while (i < n) {  //cat timp nu am ajuns la ultimul element a carui valoare vreau sa o citesc

        in >> value;  //citesc valoarea
        Q.push(value);  //introduc valoarea in coada
        i++;  //trec la urmatoarea valoare
    }

    return in;


}

//todo reverse, copiere, ==,<,>

bool Queue::operator<(Queue q2) {  //comparam obiectul in sine cu operandul(argumentul functiei)


    Node *p = front;  //varful obiectului in sine
    Node *q = q2.front;  //varful operandului

    //int i=qSize;  //dimensiunea primei cozi
    //int j=q2.qSize;  //dimensiunea cozii cu care vreau sa o compar
    //if (i!=j) return false;  //compar initial dimensiunile si daca nu sunt egale atunci returnez false fara sa mai continui



    while (p != NULL && q != NULL) {  //cat timp nu am ajuns la finalul uneia dintre cozi

        /**compar pe rand valorile cu aceeasi indexi din ambele cozi iar in momentul in care am gasit o valoare care
          *nu corespunde, o valoare mai mica in coada operand atunci inseamna ca prima coada este mai mare si returnez fals*/
        if (p->value > q->value)
            return false;

        p = p->next;  //daca nu am gasit un element care nu corespunde avansez in ambele cozi cu un pas
        q = q->next;


    }


    return !(p && !q); /**in cazul acesta se ajunge atunci cand ambele cozi sunt egale pana la terminarea uneia dintre ele,
                          asadar vreau sa vad care s-a terminat prima
                          daca p va iesii cu valoarea NULL inseamna ca ea este mai mica, q va iesii cu o valoare diferita de NULL
                          dar negat va fi NULL, ambele negate inca o data vor devenii true deci prima coada este mai mica
                          daca q va fi NULL inseamna ca prima coada este mai mare, p va fi o valoare diferita de NULL
                          se va returna false
                          */

}


bool Queue::operator>(Queue q2) {  //analog functiei anterioare


    Node *p = front;
    Node *q = q2.front;

    while (p != NULL && q != NULL) {


        if (p->value < q->value)
            return false;

        //else
        p = p->next;
        q = q->next;


    }
    return !(q && !p);


}


bool Queue::operator==(Queue q2) {  //functia va verifica daca coada initiala este egala cu coada operand


    Node *p = front;
    Node *q = q2.front;

    while (p != NULL && q != NULL) {  //parcurg cozile pana cand gasesc 2 valori cu aceeasi indexi care nu sunt egale

        if (p->value != q->value)
            return false;  //cand am gasit returnez false

        //else
        p = p->next;
        q = q->next;

    }
    return true;  //daca am ajuns la final inseamna ca nu am gasit elemente diferite deci returnez true
}


//todo reverse, copy operator


void Queue::Rev() {  //functia va rasuci coada



    Node *prev = front, *curr = prev->next, *next = curr->next;  //initializez 3 pointeri prev curr si next cu care voi avansa pe rand in coada

    back = front;  //coada cozii va devenii acum varful

    while (next) {  //cat timp nu am ajuns pe penultimul element schimb directia catre care pointreaza fiecare nod

        curr->next = prev;  //schimbarea efectiva a directiei in care pointeaza nodul curent
        prev = curr;  //avansez in coada cu fiecare dintre cei 3 pointeri
        curr = next;
        next = next->next;

    }
    //am ajuns cu ultimul element pe pozitia curenta
    curr->next = prev;  //actualizez si directia in care pointeaza ultimul nod
    front = curr;  //varful cozii devine elementul curent, adica
    back->next = NULL;  //coada cozii va pointa acum catre NULL



}


Queue &Queue::operator=(const Queue &newQueue) {  //copy constructor


    if (this == &newQueue) return *this;  //daca obiectul este identic

    if (this != &newQueue) {  //daca este un obiect nou

        front = NULL;  //initializez varful si coada cozii
        back = NULL;
        qSize = 0;  //initializez lungimea noului obiect



        Node *aux = new Node;  //folosesc un pointer ajutator pentru a parcurge coada pe care doresc sa o copiez
        aux = newQueue.front; //pointerul aux se va duce pe varf

        if (aux != NULL) {  //daca nu este primul


            qSize++;  //cresc dimensiunea obiectului nou de tip coada
            front = new Node;  //setez varful
            back = new Node;  //setez coada
            front->value = aux->value;  //varful va lua valoarea lui aux deoarece este prima
            back->next = NULL;  //setez coada cozii sa pointeze catre NULL
            aux = aux->next;  //trec la urmatorul element



        }


        while (aux != NULL) {  //incep sa copiez restul nodurilor pana la NULL setat anterior



            Node *aux2 = new Node;  // aloc memorie pentru un nou pointer ce va tine elementele din coada noua
            aux2->value = aux->value;  //copiez valoarea din coada initiala in noua coada
            aux2->next = NULL;  //aux2 va pointa catre NULL deoarece va devenii noua coada a cozii
            back->next = aux2;  //coada anterioara va pointa acum catre aux2 cara va devenii noua coada
            back = aux2;  //aux2 devine noua coada a cozii
            qSize++;  //creste lungimea
            aux = aux->next;  //trec la urmatorul element


        }

    }
    return *this;

}














