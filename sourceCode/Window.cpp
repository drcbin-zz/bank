
#include "Business.cpp"
#include "Window.h"
Window::Window(int id){

//    //设置窗口id
//    this->m_id = id;
//
//    //初始化成员变量
//    this->isBusy = false;
//    this->timeOut = 3;
//    this->m_customer = NULL;
}

void Window::execute(){

    unique_lock<mutex> locker(lineQueueLock);
    lineCond.wait(locker, []{return !lineQueue->isEmpty();});
    int sec=0;
    if(m_customer){
        this->isBusy = true;
        switch (m_customer->getTicket()->business()) {
            case 0:
                sec = 3;
                break;
            case 1:
                sec = 5;
                break;
            case 2:
                sec = 7;
                break;
            case 3:
                sec = 4;
                break;
            case 4:
                sec = 2;
                break;
            case 5:
                sec = 3;
                break;
            case 6:
                sec = 4;
                break;
            case 7:
                sec = 6;
                break;
        }
        //可以加个繁忙剩余时间,并输出
        this_thread::sleep_for(std::chrono::seconds(sec));


        //业务受理完成,填写受理信息
        m_customer->getTicket()->windowId = this->m_id;
        m_customer->getTicket()->statusCode = 1;


        //将小票放入废旧小票队列(m_oldTicQueue)
        unique_lock<mutex> ticLocker(recQueueLock);
        oldTicQueue->push(m_customer->getTicket());
        ticLocker.unlock();

        //执行完毕后唤醒小票处理线程来做收尾工作
        recCond.notify_one();

        //办理完成后直接释放顾客对象
        delete m_customer;
        this->m_customer = NULL;


        //更改空闲状态
        this->isBusy = false;
    }
}

Customer* Window::callFrom(Queue<Customer*> *q){
    return q->isEmpty() ? NULL : q->pop();
}

void Window::result(){
}


