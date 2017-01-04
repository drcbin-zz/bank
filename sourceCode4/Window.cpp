
#include "Window.h"
Window::Window(QWidget *qwidget,
               int id,
               Queue<Customer*>* customerQueue,
               Queue<Ticket*>* oldTicQueue,
               condition_variable* workCond,
               condition_variable* recCond,
               mutex* customerQueueMutex,
               mutex* oldTicQueueMutex):QTextBrowser(qwidget){
    //初始化信息
    this->m_workCond = workCond;
    this->m_customerQueue = customerQueue;
    this->m_oldTicQueue = oldTicQueue;
    this->m_id = id;
    this->m_recCond = recCond;
    this->m_customerQueueMutex = customerQueueMutex;
    this->m_oldTicQueueMutex = oldTicQueueMutex;


    //初始化成员变量
    this->isBusy = false;
    this->timeOut = 3;
    this->m_customer = NULL;
    cout << "成功构建窗口:" << m_id << endl;
}

void Window::execute(){
    // unique_lock<mutex> L(lock);
    int sec=5;
    unique_lock<mutex> locker(*m_customerQueueMutex, defer_lock);
    while(true){
        cout << "wait" << endl;
        locker.lock();
        if(m_customerQueue->isEmpty()){
            cout << "Window " << m_id << " sleeping .." << endl;
            m_workCond->wait(locker);
        }
        m_customer = m_customerQueue->pop();
        locker.unlock();
        // while(true){
        // cout << "now in operator" << endl;
            // locker.lock();
            // cout << "is tmpty?:" << m_customerQueue->isEmpty() << endl;
            // if(!m_customerQueue->isEmpty()){
                // m_customer = m_customerQueue->pop();
                // locker.unlock();
            // }else{
                // locker.unlock();
                // break;
            // }
        this->isBusy = true;
        switch (m_customer->ticket()->businessId()) {
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
        // this_thread::sleep_for(std::chrono::seconds(sec));
        for(int i = sec; i >=0; i--){
            cout << "Window " << m_id << " now is execute ... " << i << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }


        //业务受理完成,填写受理信息
        m_customer->ticket()->windowId = this->m_id;
        m_customer->ticket()->statusCode = 1;


        //将小票放入废旧小票队列(m_oldTicQueue)
        m_oldTicQueue->push(m_customer->ticket());

        //执行完毕后唤醒小票处理线程来做收尾工作
        m_recCond->notify_one();

        //办理完成后直接释放顾客对象
        delete m_customer;
        this->m_customer = NULL;


        //更改空闲状态
        this->isBusy = false;
        cout << "办理成功:" << m_id << endl;
    }
    // }
}
// void Window::operator()(){
    // while(true){
        // mutex mu;
        // unique_lock<mutex> locker(mu);
        // m_workCond->wait(locker);
        // // execute();
        // locker.unlock();
    // }
// }

void Window::result(){
    this->append("call result");
}

