#ifndef BANK_H
#define BANK_H

#include <QMainWindow>

namespace Ui {
class Bank;
}

class Bank : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bank(QWidget *parent = 0);
    ~Bank();

private slots:


    void on_pushButton_clicked();

private:
    Ui::Bank *ui;
};

#endif // BANK_H
