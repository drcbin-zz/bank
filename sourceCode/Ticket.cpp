#include "Ticket.h"

Ticket::Ticket(string id,  int business, int waitCount){
        //set id
        this->m_id = id;

        // set arrive time
        time_t now = time(0);
        m_arriveTime = localtime( &now);


        //set windowId
        this->windowId = 0;

        // set business
        this->m_business = business;

        // set wait count
        this->m_waitCount = waitCount;

        //set default status
        this->statusCode = false;
}

//获取打票时间
tm* Ticket::arriveTime(){
    return  new tm(*m_arriveTime);   //返回arriveTime的复制,防止在外界被更改
}


//获取打票时等待人数
int Ticket::waitCount(){
    return this->m_waitCount;
}

//获取单号
string Ticket::id(){
    return this->m_id;
}

//获取业务类型
int Ticket::business(){
    return this->m_business;
}

