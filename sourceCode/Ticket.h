#ifndef TICKET_H
#define TICKET_H

#include "Business.cpp"
// c++中对时间的操作
// time_t t = time(0);    //获取相对于当前时间的时间对象
// tm* dtm = gmtime(&t);    //把time_t 对象转换成 tm 结构体,格林时区
// chat *dt = ctime(&t);    //把time_t对象转换成字符串
// dt = asctime(dtm);    //把tm 结构提转换陈字符串

class Ticket
{
private:
    string m_id;
    int  m_business;
    int m_waitCount;
    tm *m_arriveTime;
public:
    bool statusCode;
    int windowId;
    Ticket(string, int , int);
    tm* arriveTime();
    int waitCount();
    string id();
    int  business();
};

#endif /* TICKET_H */
