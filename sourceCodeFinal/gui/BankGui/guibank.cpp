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
