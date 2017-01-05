#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QTextBrowser>
#include <QLabel>
#include <iostream>
#include <thread>
#include <condition_variable>
#include "../../Customer.h"
#include "../../Ticket.h"
#include "../../Queue.cpp"
using namespace std;

#define BUSY 0
#define FREE 1
#define WAIT 2

class MyLabel:public QLabel{
    Q_OBJECT
signals:
    void changeTextSignal(const QString &text);
private slots:
    void acceptChangeTextSignal(const QString &text);

public :
    MyLabel(QWidget*);
    void changeText(const QString &text);
};

class ProcessWindow:public QTextBrowser
{

    Q_OBJECT
        //signals
    signals:
        void processWindowAppendSignal(const QString& text);

        //slots
    private slots:
        void acceptProcessWindowAppendSignal(const QString& text);

    public:
        ProcessWindow(QWidget*);
        ~ProcessWindow();
        void processWindowAppend(const QString& text);
        void processWindowAppend(const string& text);
};
class MyWindow: public QTextBrowser
{
    Q_OBJECT

private slots:
    void Slot(const QString&);
signals:
    void Sin(const QString&);


public:
    // 窗口的id
       int m_id;

       int m_busnessId;

       //当前窗口的状态
       int m_status;

        QLabel* m_statusWindow;

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




       //public function
       //初始化函数
       MyWindow(QWidget*,
                QLabel*,
                int,
                Queue<Customer*>* customerQueue,
                Queue<Ticket*>* lodTicQueue,
                condition_variable* workCond,
                condition_variable* recCond,
                mutex *customerQueueMutex,
                mutex* oldTicQueueMutex);
       ~MyWindow();
       //呼叫客户方法
       Customer *callFrom(Queue<Customer*>*);

       //办理业务方法
       void execute(ProcessWindow*&);

       //业务办理完成后的后续处理
       void result();

       // show sigain
       void Append(const QString&);



       void changeStatus(int);


};
#endif // MYWINDOW_H
