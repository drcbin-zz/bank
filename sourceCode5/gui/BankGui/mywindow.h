#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QTextBrowser>
#include <iostream>
#include <thread>
#include <condition_variable>
#include "../../Customer.h"
#include "../../Ticket.h"
#include "../../Queue.cpp"
using namespace std;

class MyWindow: public QTextBrowser
{
    Q_OBJECT
public:
    MyWindow(QWidget*,int, Queue<Customer*>* customerQueue, Queue<Ticket*>* lodTicQueue, condition_variable* workCond, condition_variable* recCond, mutex *customerQueueMutex, mutex* oldTicQueueMutex);
    ~MyWindow();
private slots:
    void Slot();
signals:
    void Sin();

public:
    void showSin();
};
#endif // MYWINDOW_H
