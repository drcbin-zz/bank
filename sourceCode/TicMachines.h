#ifndef TICMACHINES_H
#define TICMACHINES_H
#include "Business.cpp"
#include "Ticket.h"
#include "Queue.h"
class TicMachine
{
private:
    tm* m_startTime, *m_closingTime;
    int m_wholeNum;
    int m_everyNum[8];
    int m_waitCount;
    int m_evertWaitCount[8];
    int m_lastRecoverId;
    string m_preID;
    mutex m_countLock;

public:
    TicMachine();
    Ticket* createTicket(int);    //放票方法
    bool isStillWork();    //判断是否是营业时间
    void recover();    //回收办理的票
    int getNum();    //获取所有服务的人数
    int getNum(int);    //获取所有服务的人数
    int getWaitCount();    //获取总的等待人数
    int getWaitCount(int);
};
#endif /* TICMACHINES_H */
