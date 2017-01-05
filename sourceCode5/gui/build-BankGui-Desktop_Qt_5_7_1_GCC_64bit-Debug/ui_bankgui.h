/********************************************************************************
** Form generated from reading UI file 'bankgui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKGUI_H
#define UI_BANKGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mywindow.h"
#include <thread>
#include "../../TicMachine.h"
#include "../../Customer.h"
#include "../../Queue.cpp"

QT_BEGIN_NAMESPACE

class Ui_BankGui
{
public:
    /***********以下为银行类私有成员**********/
       // 三个条件变量, 一个唤醒入队线程取票入队,一个唤醒窗口办理业务,一个唤醒回收小票
       condition_variable workCond, recCond, joinLineCond;

       //三把把锁, 两个排队队列锁,一个小票锁
       mutex customerQueueMutex, oldTicQueueMutex, lineQueueLock;

       //三个队列, 一个待取票, 一个待办理, 一个旧小票
       Queue<Customer*> *m_customerQueue, *m_lineQueue;
       Queue<Ticket*> *m_oldTicQueue;

       //银行有一台打票机
       TicMachine *m_ticMachine;
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    MyWindow *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BankGui)
    {
        if (BankGui->objectName().isEmpty())
            BankGui->setObjectName(QStringLiteral("BankGui"));
        BankGui->resize(400, 300);
        centralWidget = new QWidget(BankGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 130, 80, 22));
        textBrowser = new MyWindow(centralWidget, 4,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(90, 10, 151, 101));
        BankGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BankGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        BankGui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BankGui);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BankGui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BankGui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BankGui->setStatusBar(statusBar);

        retranslateUi(BankGui);

        QMetaObject::connectSlotsByName(BankGui);
    } // setupUi

    void retranslateUi(QMainWindow *BankGui)
    {
        BankGui->setWindowTitle(QApplication::translate("BankGui", "BankGui", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BankGui", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BankGui: public Ui_BankGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKGUI_H
