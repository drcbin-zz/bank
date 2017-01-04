#ifndef BANK_H
#define BANK_H
  
#include <thread>
#include "TicMachine.h"
#include "Window.h"
#include "Customer.h"
#include "Queue.cpp"
class Bank{
private:
    /***********以下为银行类私有成员**********/
    // 三个条件变量, 一个唤醒入队线程取票入队,一个唤醒窗口办理业务,一个唤醒回收小票
    condition_variable workCond, recCond, joinLineCond;

    //三把把锁, 两个排队队列锁,一个小票锁
    mutex customerQueueMutex, oldTicQueueMutex, lineQueueLock;

    //三个队列, 一个待取票, 一个待办理, 一个旧小票
    Queue<Customer*> *m_customerQueue, *m_lineQueue;
    Queue<Ticket*> *m_oldTicQueue;

    //银行有一台打票机
    TicMachine *m_ticMachine;

    //银行有四个窗口
    Window *m_windowOne, *m_windowTwo, *m_windowThree, *m_windowFour;

    /********** 银行私有成员结束 **********/
public:
    
    //构造,析构函数
    Bank();

    /*********** 开始运行(run()) ********/
    /**  银行与外界交互的唯一接口
     * 有点类似于银行的大门,有人能进来
     * 向外提供的录入信息的接口
     * 因为是模拟,所以选择在内部自己构造顾客(Customer)对象
     * 并将构造出来的对象放进等待取票队列(personQueue)
     * 然后通知打票即开始打票
     */
    void run();

    /********** 入队方法(joinLine()) ********
     * 有点类似与银行的接待前台,带领着你取号,然后让你去排队
     * 从等待取票队列(personQueuq)呼叫一个人出队
     * 唤醒打票机(ticMachine)工作放票
     * 把票给顾客
     * 带领顾客去排队  (lineQueue 入队)
     * 然后唤醒窗口工作
     */
    void joinLine();



    /******* 产人方法 ********/
    void createCustomer();
};

#endif /* BANK_H */
