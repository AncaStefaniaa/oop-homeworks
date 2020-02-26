#include <iostream>
#include "Queue.h"
using namespace std;



int main() {

    Queue Q1,Q2;
    cin >> Q1;
    Q2.push(1);
    Q2.push(2);
    Q2.push(3);
    Q2.push(5);
    cout<<endl<<"------------Display Q2------------";
    cout<<endl;
    Q2.display();
    cout<<Q1.isEmpty()<<endl;
    cout<<Q1.Len()<<endl;
    cout<<endl<<"------------Display Q1------------";
    cout<<endl;
    cout<<Q1;
    cout<<endl;
    cout<<Q1.getFront();
    Q1.Rev();
    Q1.display();



    return 0;
}