#ifndef BANKGUI_H
#define BANKGUI_H

#include <QMainWindow>

namespace Ui {
class BankGui;
}

class BankGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit BankGui(QWidget *parent = 0);
    ~BankGui();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BankGui *ui;
};

#endif // BANKGUI_H
