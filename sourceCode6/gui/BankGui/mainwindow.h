#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <Bank.h>
using namespace  std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(Bank *bank,QWidget *parent = 0);
    void sayHello(QString& s);
    ~MainWindow();

private slots:
    void on_addPersonButton_clicked();
//    void setWindowStatus(int, bool);
//    void addWindowProcess(int, string);
//    void addBankProcess(string);

    void on_createPersonButton_clicked();

private:
    Ui::MainWindow *ui;
    int randNumber;
    Bank *m_bank;
};

#endif // MAINWINDOW_H
