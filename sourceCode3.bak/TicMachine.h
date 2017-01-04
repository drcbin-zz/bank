#ifndef TICMACHINES_H
#define TICMACHINES_H
#include <condition_variable>
#include <mutex>
#include <string>
#include <iostream>
#include "Queue.cpp"
#include "Ticket.h"
using namespace std;
class TicMachine
{
private:
    tm* m_startTime, *m_closingTime;
    int m_serviceNum;
    int m_eachServiceNum[8];
    int m_waitNum;
    int m_eachWaitNum[8];
    string m_preID;
    mutex m_countLock;
    Queue<Ticket*> *m_oldTicQueue;
    condition_variable *m_recCond;
    // condition_variable& m_countCond;

public:
    TicMachine(Queue<Ticket*> *oldTicQueue, condition_variable* recCond);
    /*构造方法*/

    Ticket* createTicket(int businessId);
    /* 放票方法
     * businessId:int 型,需要办理的业务id
     */

    bool isStillWork();
    /* 判断是否是营业时间 */


    void recover();
    /*回收办理完成的票
     * oldTicQueue: Queue<>* 类型, 存放废旧小票的队列
     * recCond:condition_variable 类型, 线程唤醒的条件变量
     */
    int serviceNum();    //获取所有服务的人数
    int serviceNum(int);    //获取所有服务的人数
    int waitCount();    //获取总的等待人数
    int waitCount(int);
};
#endif /* TICMACHINES_H */
