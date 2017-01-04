#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Ticket.h"

class Customer
{
private:
    Ticket* m_ticket;
    /* 顾客持有的小票,默认为NULL*/
public:

    int business;
    /* 顾客需要办理的业务id */

    Customer();
    /* 顾客的构造函数 */

    Customer(int businessId);
    /* 顾客的构造函数
     * businessId: 顾客需要办理的业务id
    */

    Ticket* ticket();
    /* 获取顾客的小票 */

    void setTicket(Ticket* t);
    /* 配置顾客的小票 */
};
#endif /* CUSTOMER_H */
 
