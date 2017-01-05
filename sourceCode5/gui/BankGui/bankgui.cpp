#include "bankgui.h"
#include "ui_bankgui.h"

BankGui::BankGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BankGui)
{
    ui->setupUi(this);
}

BankGui::~BankGui()
{
    delete ui;
}

void BankGui::on_pushButton_clicked()
{
    ui->textBrowser->showSin();
}
