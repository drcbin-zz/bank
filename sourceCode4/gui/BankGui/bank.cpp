#include "bank.h"
#include "ui_bank.h"

Bank::Bank(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bank)
{
    ui->setupUi(this);
}

Bank::~Bank()
{
    delete ui;
}



void Bank::on_pushButton_clicked()
{
    ui->w1->append("asd");
//    ui->w1->result();
}
