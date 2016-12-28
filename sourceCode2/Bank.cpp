#include "Bank.h"
 
Bank::Bank(){

    //构造队列
    m_customerQueue = new Queue<Customer*>;
    m_lineQueue = new Queue<Customer*>;
    m_oldTicQueue = new Queue<Ticket*>;


    // 构造打票机
    this->m_ticMachine = new TicMachine(m_oldTicQueue, &recCond);
    /******** 一定要先构造完上述的成员, 才能构造下面的窗口 ********/


    //构造4个窗口
    cout << "构建窗口" << endl;
    this->m_windowOne = new Window(1,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex); 
    this->m_windowTwo = new Window(2,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex); 
    this->m_windowThree = new Window(3,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
    this->m_windowFour = new Window(4,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
    cout << "窗口构建成功" << endl;

}


void Bank::createCustomer(){
    while(true){
        cout << "出入人数,办理的业务编号:";
        int count, id;
        cin >> count >> id;
        for(int i = 0; i < count; i++){
            m_customerQueue->push(new Customer(id));
            joinLineCond.notify_one();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
}


void Bank::joinLine(){
    int count = 0;
    while(true){
        unique_lock<mutex> locker(lineQueueLock);
        joinLineCond.wait(locker);
        locker.unlock();
        while(!m_customerQueue->isEmpty()){
            count++;
            cout << "正在放入第" << count  << "个" << endl;
            Customer* c = m_customerQueue->pop();
            c->setTicket(m_ticMachine->createTicket(c->business));
            m_lineQueue->push(c);
            this_thread::sleep_for(chrono::seconds(1));
            cout << "第" << count  << "个成功" << endl;
            cout << "正在唤醒窗口" << endl;
            workCond.notify_one();
            cout << "窗口唤醒成功" << endl;
        }
    }
}


void Bank::run(){
    thread createThread(bind(&Bank::createCustomer, this));
    thread joinLineThread(bind(&Bank::joinLine, this));
    thread w1Thread(&Window::execute, &(*m_windowOne));
    thread w2Thread(&Window::execute, &(*m_windowTwo));
    thread w3Thread(&Window::execute, &(*m_windowThree));
    thread w4Thread(&Window::execute, &(*m_windowFour));
    thread recThread(&TicMachine::recover, &(*m_ticMachine));

    createThread.join();
    joinLineThread.join();
    w1Thread.join();
    w2Thread.join();
    w3Thread.join();
    w4Thread.join();
    recThread.join();
}
