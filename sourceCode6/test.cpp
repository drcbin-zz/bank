// #include "TicMachine.h"
// #include "Queue.cpp"
// #include "Window.h"
// #include "Bank.h"
// #include "Customer.h"
// #include <thread>
// #include <string>
// #include <iostream>
// using namespace std;

// ***** test function for thread and TicMachine.*  *****
// void joinLine(Queue<Customer*>*& qc, Queue<Customer*>*& newQc, TicMachine*& ticMachine, condition_variable& joinLineCond, condition_variable &workCond){
    // int count = 0;
    // while(true){
        // mutex mu;
        // unique_lock<mutex> locker(mu);
        // joinLineCond.wait(locker);
        // locker.unlock();
        // while(!qc->isEmpty()){
            // count++;
            // cout << "正在放入第" << count  << "个" << endl;
            // Customer* c = qc->pop();
            // c->setTicket(ticMachine->createTicket(c->business));
            // newQc->push(c);
            // this_thread::sleep_for(chrono::seconds(1));
            // cout << "第" << count  << "个成功" << endl;
            // cout << "正在唤醒窗口" << endl;
            // workCond.notify_one();
            // cout << "窗口唤醒成功" << endl;

        // }
    // }
// }


// void createCustomer(Queue<Customer*> *qc, condition_variable& joinLineCond){
    // while(true){
        // cout << "出入人数,办理的业务编号:";
        // int count, id;
        // cin >> count >> id;
        // for(int i = 0; i < count; i++){
            // qc->push(new Customer(id));
            // joinLineCond.notify_one();
            // this_thread::sleep_for(chrono::milliseconds(100));
        // }
    // }
// }

// int main()
// {
    // Queue<Customer*> *q = new Queue<Customer*>;
    // Queue<Ticket*> *p = new Queue<Ticket*>;
    // Customer* c = new Customer();
    // c->setTicket(new Ticket("10086", 1, 12));
    // q->push(c);
    // Ticket *t = new Ticket("10086", 1, 1);
    // p->push(t);
    // cout << q->pop()->ticket()->id() << endl;
    // cout << p->pop()->id() << endl;
    /***** Ticket.* and Customer.*  test code, sussess ****/





    // TicMachine* ticMachine = new TicMachine;
    // Queue<Customer*> *qc = new Queue<Customer*>;
    // Queue<Customer*> *newQc = new Queue<Customer*>;
    // Queue<Ticket*> *qt = new Queue<Ticket*>;
    // condition_variable workCond, recCond;
    // for(int i = 0; i < 5; i++){
        // cout << "creat the " << i << "Customer" << endl;
        // qc->push(new Customer(4));
    // }
    // thread t1(line, ref(qc), ref(newQc), ref(ticMachine));
    // this_thread::sleep_for(chrono::seconds(8));
    // while(!newQc->isEmpty()){
        // Customer* c = newQc->pop();
        // cout << c->ticket()->id() << endl;
    // }
    // t1.join();
    /**** TicMachine.* and thread test code, success ******/



    // condition_variable workCond, recCond, joinLineCond;
    // mutex customerQueueMutex, oldTicQueueMutex, lock;
    // Queue<Customer*> *qc = new Queue<Customer*>;
    // Queue<Customer*> *newQc = new Queue<Customer*>;
    // Queue<Ticket*> *qt = new Queue<Ticket*>;
    // TicMachine* ticMachine = new TicMachine(qt, &recCond);
    // Window *w1 = new Window(1,newQc,qt,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex); 
    // Window *w2 = new Window(2,newQc,qt,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex); 
    // Window *w3 = new Window(3,newQc,qt,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex); 
    // Window *w4 = new Window(4,newQc,qt,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
    // for(int i = 0; i < 5; i++){
        // cout << "creat the " << i << "Customer" << endl;
        // qc->push(new Customer(4));
    // }
    // this_thread::sleep_for(chrono::seconds(8));
    // while(!newQc->isEmpty()){
        // Customer* c = newQc->pop();
        // cout << c->ticket()->id() << endl;
    // }
    // t1.join();

    // thread createThread(createCustomer,ref(qc), ref(joinLineCond));
    // thread t1(joinLine, ref(qc), ref(newQc), ref(ticMachine), ref(joinLineCond), ref(workCond));
    // thread w1Thread(*w1);
    // thread w1Thread(&Window::execute, &(*w1));
    // thread w2Thread(&Window::execute, &(*w2));
    // thread w3Thread(&Window::execute, &(*w3));
    // thread w3Thread(*w3);
    // thread w4Thread(&Window::execute, &(*w4));
    // thread recThread(&TicMachine::recover, &(*ticMachine));

    // createThread.join();
    // t1.join();
    // w1Thread.join();
    // w2Thread.join();
    // w3Thread.join();
    // w4Thread.join();
    // recThread.join();
    /**********  Ticket.* TicMachine.* Customer.* and thread test code, success ********/


    // Bank b;
    // b.run();
    // return 0;
// }
