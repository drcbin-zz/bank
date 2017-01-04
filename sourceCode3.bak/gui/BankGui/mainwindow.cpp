#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Bank *bank,QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    m_bank = bank;
    ui->setupUi(this);
    //ui->pushButton->setText("New Windown你好");
    ui->businessIdBoxWaringLabel->setVisible(false);
    this->randNumber = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sayHello(QString& s){
//    QString qs = QString::fromStdString(s);
    ui->runingText->setText(s);
}

//clicked the addPersonButton
void MainWindow::on_addPersonButton_clicked()
{
    int num = ui->personNumBox->value();
    int businessId = ui->businessIdBox->value();
    QString s = QString::number(businessId)+" added "+QString::number(num)+ " persons.";
    ui->runingText->append(s);
    ui->personNumBox->setValue(0);
    ui->businessIdBox->setValue(0);
    m_bank->createCustomer(businessId, num);
}

void MainWindow::on_createPersonButton_clicked()
{
    randNumber += 4*3+2;
    if(randNumber > 1000){
        randNumber = 1;
    }
    int businessId = randNumber%8;
    m_bank->createCustomer(businessId, 10);
}
