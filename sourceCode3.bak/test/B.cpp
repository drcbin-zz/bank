#include "B.h"
#include <iostream>
using namespace std;
B::B(){
    this->a = new A(110);
}
B::~B(){}
void B::display(){
    cout << "call B:" << "    A->display():" ;
    a->display();
}
