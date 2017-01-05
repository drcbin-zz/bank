#include "bank.h"
#include <QApplication>
#include <thread>

int showPrinter(QApplication* a,GuiBank *b){
    b->show();
    return a->exec();
}

//void runBank(Ui::GuiBank* b){
////    b->run();
//}

int main(int argc, char *argv[])
{
    QApplication *a = new QApplication(argc, argv);
    GuiBank *b = new GuiBank;
//    GuiBank w;
//    w.show();
//    return a.exec();
//    thread t(&GuiBank::run, ref(b));
    showPrinter(a,b);
//    t.join();
}


