#include "mywindow.h"


//for MyLabel
MyLabel::MyLabel(QWidget *parent):QLabel(parent){
     connect(this,SIGNAL(changeTextSignal(QString)),this,SLOT(acceptChangeTextSignal(QString)));
}
void MyLabel::changeText(const QString &text){
    emit changeTextSignal(text);
}
void MyLabel::acceptChangeTextSignal(const QString &text){
    this->setText(text);
}



// for ProcessWindow
ProcessWindow::ProcessWindow(QWidget* parent):QTextBrowser(parent)
{
    connect(this,SIGNAL(processWindowAppendSignal(QString)),this,SLOT(acceptProcessWindowAppendSignal(QString)));
}
ProcessWindow::~ProcessWindow(){};
void ProcessWindow::acceptProcessWindowAppendSignal(const QString &text){
    this->append(text);
}
void ProcessWindow::processWindowAppend(const QString &text){
    emit processWindowAppendSignal(text);
}
void ProcessWindow::processWindowAppend(const string &text){
    QString qText = QString::fromStdString(text);
    emit processWindowAppendSignal(qText);
}




// for MyWindow
MyWindow::MyWindow(QWidget* parent,
                   QLabel* statusWindow,
                   int id,
                   Queue<Customer*>* customerQueue,
                   Queue<Ticket*>* oldTicQueue,
                   condition_variable* workCond,
                   condition_variable* recCond,
                   mutex *customerQueueMutex,
                   mutex* oldTicQueueMutex):QTextBrowser(parent){
    connect(this,SIGNAL(Sin(QString)),this,SLOT(Slot(QString)));
    //初始化信息
    m_statusWindow = statusWindow;
    this->m_workCond = workCond;
    this->m_customerQueue = customerQueue;
    this->m_oldTicQueue = oldTicQueue;
    this->m_id = id;
    this->m_recCond = recCond;
    this->m_customerQueueMutex = customerQueueMutex;
    this->m_oldTicQueueMutex = oldTicQueueMutex;


    //初始化成员变量
    this->m_status = "free";
    this->timeOut = 3;
    this->m_customer = NULL;

};
MyWindow::~MyWindow(){};
void MyWindow::Slot(const QString& text){
//    cout << "Hello, qt!" << endl;
    this->append(text);
};
void MyWindow::Append(const QString& text){
    emit Sin(text);
}


void MyWindow::execute(ProcessWindow*& processWind){
    // unique_lock<mutex> L(lock);
    QString s;
    int sec=5;
    unique_lock<mutex> locker(*m_customerQueueMutex, defer_lock);
    while(true){
        s = "正在呼叫......";
        this->Append(s);
        m_status = "wait" ;
        this_thread::sleep_for(std::chrono::seconds(1));
//        m_statusWindow->setText(m_status);
        locker.lock();
        if(m_customerQueue->isEmpty()){

             s =  "没有顾客,等待中......";
                        this->Append(s);
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
        m_busnessId = m_customer->ticket()->businessId();
        this->m_status = "free";
        switch (m_busnessId) {
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
        s = QString::number(m_id) + "号窗口正在办理业务.";
        processWind->processWindowAppend(s);
        for(int i = sec; i >=0; i--){
            s ="正在办理" + QString::number(m_busnessId) + "号业务:" + QString::number(i);
            this->Append(s);
            this_thread::sleep_for(chrono::seconds(1));
        }


        //业务受理完成,填写受理信息
        m_customer->ticket()->windowId = this->m_id;
        m_customer->ticket()->statusCode = 1;


        //将小票放入废旧小票队列(m_oldTicQueue)
        m_oldTicQueue->push(m_customer->ticket());
        s = QString::number(m_id) + "号窗口办理完成.";
        processWind->processWindowAppend(s);
        //执行完毕后唤醒小票处理线程来做收尾工作
        m_recCond->notify_one();
        //办理完成后直接释放顾客对象
        delete m_customer;
        this->m_customer = NULL;


        //更改空闲状态
        this->m_status = "free";
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

void MyWindow::result(){
}
