#include "Ticket.h"
 
Ticket::Ticket(string id, int businessId, int waitCount){
    this->m_id = id;
    this->m_business = businessId;
    this->m_waitCount = waitCount;
    time_t now = time(0);
    this->m_arriveTime = localtime(&now);
    this->m_banliTime = NULL;
    this->windowId = 0;
    this->statusCode = false;
//    cout << "arrive time:" << m_arriveTime->tm_min << ":" << m_arriveTime->tm_sec << endl;
}

tm* Ticket::arriveTime(){
    return new tm(*m_arriveTime); //防止被修改
}
void Ticket::setBanliTime(tm* banliTime){
    this->m_banliTime = banliTime;


}

tm* Ticket::banliTime(){
//     cout << "m_banli time:" << m_banliTime->tm_min << ":" << m_banliTime->tm_sec << endl;
    return m_banliTime; //防止被修改
}

int Ticket::waitCount(){
    return this->m_waitCount;
}

int Ticket::businessId(){
    return this->m_business;
}

string Ticket::id(){
    return this->m_id;
}
