#include "guibank.h"
#include "ui_guibank.h"

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



void GuiBank::on_addPersonButton_clicked()
{
    int id, count;
    id = ui->businessIdBox->value();
    if(id > 8 || id <= 0){
        ui->businessIdWaringBox->setVisible(true);
        return;
    }
    ui->businessIdWaringBox->setVisible(false);
    count = ui->personNumBox->value();
    if(count <= 0){
        return;
    }
    ui->createCustomer(id, count);
}

void GuiBank::on_randCreatePersonButton_clicked()
{
    time_t now = time(0);
    tm* tm_now = localtime(&now);
    int randNum = tm_now->tm_sec;
    cout << tm_now->tm_sec << endl;
    for(int i = 0; i < 10; i++){
        randNum = randNum*2 -3*4 + 5;
        if(randNum > 1000 || randNum < 0){
            randNum = 32;
        }
        cout << randNum << endl;
        ui->createCustomer(randNum%8 + 1, 1);
    }
}
