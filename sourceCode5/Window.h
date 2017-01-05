#ifndef WINDOW_H
#define WINDOW_H

#include <QTextBrowser>
#include <thread>
#include <iostream>
#include <condition_variable>
#include "Customer.h"
#include "Ticket.h"
#include "Queue.cpp"
using namespace std;

/********** 窗口对象(class Window) ********
* 银行的窗口,办理业务的地方
* 能从排队队列中呼叫排队的顾客(lineQueue)出队
* 然后办理客户的业务
* 析构客户:因为客户对模拟系统的影响不大,为了方便,当客户办理完业务之后就将其释放,重新办理的重新取号
* 将办理过的小票放到旧票回收队列(oldTicQueue)
* 同时唤醒小票处理线程来对小票做最后的处理
*/

class Window:public QTextBrowser
{
    Q_OBJECT
private:

    // 窗口的id
    int m_id;

    //当前窗口的状态
    bool isBusy;

    //呼叫客户的最长时间,超过时间没有呼叫到,就作废
    int timeOut;

    //呼叫到的客户对象
    Customer *m_customer;

    //工作条件变量
    condition_variable* m_workCond, *m_recCond;

    //line queue
    Queue<Customer*>* m_customerQueue;

    //old ticket queue
    Queue<Ticket*>* m_oldTicQueue;

    //Cusrom Queue lock
    mutex* m_customerQueueMutex, *m_oldTicQueueMutex;
public:

    //初始化函数
    explicit Window(int, Queue<Customer*>* customerQueue, Queue<Ticket*>* lodTicQueue, condition_variable* workCond, condition_variable* recCond, mutex *customerQueueMutex, mutex* oldTicQueueMutex);
    ~Window();
    //呼叫客户方法
    Customer *callFrom(Queue<Customer*>*);

    //办理业务方法
    void execute();

    //业务办理完成后的后续处理
    void result();

    //执行函数
    // void operator()();
};

#endif
/* WINDOW_H */
