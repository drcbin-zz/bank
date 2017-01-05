#ifndef GUIBANK_H
#define GUIBANK_H

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

    void on_addPersonButton_clicked();

    void on_randCreatePersonButton_clicked();

private:
    Ui::GuiBank *ui;
};

#endif // GUIBANK_H
