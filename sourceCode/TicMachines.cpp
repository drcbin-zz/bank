#include "TicMachines.h"
TicMachine::TicMachine(){
    //初始化开始营业时间,开始营业
    time_t now = time(0);
    m_startTime = localtime(&now);

    //设置结束营业时间
    m_closingTime = new tm(*m_startTime);
    m_closingTime->tm_min += 8;    //营业8分钟

    //初始化总服务人数
    this->m_wholeNum = 0;
    for(int i = 0; i < 8; i++){m_everyNum[i] = 0;}

    //初始化排队人数
    this->m_waitCount = 0;
    for(int i = 0; i < 8; i++){m_evertWaitCount[i] = 0;}

    //初始化最后一次回收id:m_lastRecoverId
    m_lastRecoverId = 0;


    //初始化id前置编号
    m_preID = to_string(m_startTime->tm_year) + to_string(m_startTime->tm_mon) + to_string(m_startTime->tm_mday);
}

Ticket* TicMachine::createTicket(int b){
    unique_lock<mutex> locker(m_countLock);
    personCond.wait(locker);
    m_wholeNum++;
    m_everyNum[b]++;
    m_waitCount++;
    m_evertWaitCount[b]++;
    locker.unlock();
    return new Ticket(m_preID + to_string(m_wholeNum), b, m_waitCount);
}


//获取各种统计数据
int TicMachine::getNum(){
    return m_wholeNum;
}
int TicMachine::getNum(int b){
    return m_everyNum[b];
}
int TicMachine::getWaitCount(){
    return m_waitCount;
}
int TicMachine::getWaitCount(int b){
    return m_evertWaitCount[b];
}


//是否还是营业时间
bool TicMachine::isStillWork(){
    time_t now = time(0);
    tm* tm_now = localtime(&now);
    if(tm_now->tm_hour > m_closingTime->tm_hour || tm_now->tm_min > m_closingTime->tm_min || tm_now->tm_sec > m_closingTime->tm_sec ){
        return false;
    }
    return true;
}


//回收小票
void TicMachine::recover(){

    //加锁取旧小票操作
    unique_lock<mutex> recLocker(recQueueLock);


    //线程休眠等待唤醒
    recCond.wait(recLocker, []{return !oldTicQueue->isEmpty();});
    Ticket *oldTic = oldTicQueue->isEmpty()?oldTicQueue->pop():NULL;
    recLocker.unlock();

    //加锁修改数据操作
    unique_lock<mutex> locker(m_countLock);
    if(oldTic){
        this->m_waitCount--;
        this->m_evertWaitCount[oldTic->business()]--;
    }
    locker.unlock();
}
