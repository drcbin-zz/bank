#include "guibank.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiBank w;
    w.show();

    return a.exec();
}
