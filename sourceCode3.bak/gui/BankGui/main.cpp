#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include "Bank.h"


void runBank(Bank &b){
    b.run();
    cout << "Hello, not world" << endl;
}

int runPrinter(QApplication& a, Bank* b){
    MainWindow w(b);
    w.show();
    return a.exec();
}

int main(int argc, char *argv[])
{
    Bank bank(argc,argv);
//    thread t(&Bank::run, &b);
    QApplication a(argc, argv);

    thread t(&runBank, ref(bank));
    runPrinter(a, &bank);

    t.join();

    return 0;
}
