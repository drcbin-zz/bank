#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Ticket.h"
 
class Customer
{
private:
    Ticket* m_ticket;
public:
    int business;
    Customer();
    Customer(int);
    Ticket* ticket();
    void setTicket(Ticket* t);
};
#endif /* CUSTOMER_H */

