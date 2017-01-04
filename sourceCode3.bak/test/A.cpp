#include "A.h"
A::A(int data){
    this->m_data = data;
}

void A::display(){
    cout  << "call display():" << this->m_data << endl;
}
