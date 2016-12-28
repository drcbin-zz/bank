#include "Bank.h"

Bank::Bank(){

    // 构造打票机
    this->m_ticMachine = new TicMachine();

    //构造4个窗口
    this->m_windowOne = new Window(001);
    this->m_windowTwo = new Window(002);
    this->m_windowThree = new Window(003);
    this->m_windowFour = new Window(004);


    //创建4个窗口线程,并进入工作状态
    thread windowOneThread(&Window::execute, m_windowOne);
    thread windowTwoThread(&Window::execute, m_windowOne);
    thread windowThreeThread(&Window::execute, m_windowOne);
    thread windowFourThread(&Window::execute, m_windowOne);
    windowOneThread.join();
    windowTwoThread.join();
    windowOneThread.join();
    windowFourThread.join();

    //创建打票机线程
    thread ticMachineThread(&TicMachine::createTicket, m_ticMachine);
    ticMachineThread.join();

    //创建小票回收线程
    thread recoverThread(&TicMachine::recover, m_ticMachine);
    recoverThread.join();

    //创建对外接口线程

    thread runThread(bind(&Bank::run, this));
    runThread.join();

    //创建取票线程
    thread joinLineThread(bind(&Bank::joinLine, this));
}

//银行开始工作
void Bank::run(){
    unique_lock<mutex> locker(personQueueLock);
    personQueue->push(new Customer(1));
    locker.unlock();
    personCond.notify_one();
}

void Bank::joinLine(){
    unique_lock<mutex> locker(personQueueLock);
    personCond.wait(locker);
    Customer *temp = personQueue->pop();
    temp->setTicket(m_ticMachine->createTicket(temp->business));
    unique_lock<mutex> lineQueueLocker(lineQueueLock);
    lineQueue->push(temp);
    lineQueueLocker.unlock();
    lineCond.notify_one();
    locker.unlock();
}
