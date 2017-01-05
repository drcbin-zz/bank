#include "bank.h"
#include "ui_bank.h"

GuiBank::GuiBank(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiBank)
{
    ui->setupUi(this);
}

GuiBank::~GuiBank()
{
    delete ui;
}

//void GuiBank::on_randCreatePersonButton_clicked()
//{
////    for(int i = 0; i < 10; i++){
////        if(m_randNumber > 1000){
////            m_randNumber = 0;
////        }
////        m_randNumber += 4+3*4;
//        ui->createCustomer(3,2);
////    }
//}

//void GuiBank::on_addPersonButton_clicked()
//{

//    ui->createCustomer(ui->businessIdBox->value(), ui->personNumBox->value());
//}

