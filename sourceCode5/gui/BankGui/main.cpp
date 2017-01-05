#include "bankgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BankGui w;
    w.show();

    return a.exec();
}
