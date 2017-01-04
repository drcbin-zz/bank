#include "Customer.h"
Customer::Customer(){
    this->m_ticket = NULL;
}
Customer::Customer(int b){
    this->m_ticket = NULL;
    this->business = b;
}
Ticket* Customer::ticket(){
    return this->m_ticket;
}

void Customer::setTicket(Ticket* t){
    this->m_ticket = t;
} 
