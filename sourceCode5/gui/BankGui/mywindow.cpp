#include "mywindow.h"
MyWindow::MyWindow(QWidget* parent,
                   int id,
                   Queue<Customer*>* customerQueue,
                   Queue<Ticket*>* lodTicQueue,
                   condition_variable* workCond,
                   condition_variable* recCond,
                   mutex *customerQueueMutex,
                   mutex* oldTicQueueMutex):QTextBrowser(parent){
    connect(this,SIGNAL(Sin()),this,SLOT(Slot()));
};
MyWindow::~MyWindow(){};
void MyWindow::Slot(){
    cout << "Hello, qt!" << endl;
};
void MyWindow::showSin(){
    emit Sin();
}
