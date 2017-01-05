#ifndef BANK_H
#define BANK_H

#include <QMainWindow>

namespace Ui {
class GuiBank;
}

class GuiBank : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuiBank(QWidget *parent = 0);
    ~GuiBank();


private slots:
//    void on_randCreatePersonButton_clicked();
//    void on_addPersonButton_clicked();

private:
    Ui::GuiBank *ui;
};

#endif // BANK_H
