#include <QApplication>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel label( QLabel::tr("Hello, qt!") );
    label.show();
    return 0;
}
