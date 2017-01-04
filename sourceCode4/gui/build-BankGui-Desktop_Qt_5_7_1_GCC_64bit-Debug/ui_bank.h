/********************************************************************************
** Form generated from reading UI file 'bank.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANK_H
#define UI_BANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <thread>
#include "../../TicMachine.h"
#include "../../Window.h"
#include "../../Customer.h"
#include "../../Queue.cpp"

QT_BEGIN_NAMESPACE

class Ui_Bank
{
public:

    //from Bank.h
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

    //银行有四个窗口
    Window *m_windowOne, *m_windowTwo, *m_windowThree, *m_windowFour;

    /********** 银行私有成员结束 **********/


    QAction *actionStart;
    QAction *actionStop;
    QAction *actionAbout;
    QWidget *centralWidget;
    Window *w1, *w2, *w3, *w4;
    QPushButton *randCreatePersonButton;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_5;
    QTextBrowser *processWindow;
    QPushButton *addPersonButton;
    QSpinBox *businessIdBox;
    QSpinBox *personNumBox;
    QLabel *businessIdLabel;
    QLabel *personNumLabel;
    QLabel *businessIdWaringBox;
    QLabel *window_1StatusLabel;
    QLabel *window_2StatusLabel;
    QLabel *window_3StatusLabel;
    QLabel *window_5StatusLabel;
    QLabel *window_1Status;
    QLabel *window_2Status;
    QLabel *window_3Status;
    QLabel *window_4Status;
    QLabel *serverNumLabel;
    QLabel *stayTimeLabel;
    QFrame *line_4;
    QLabel *informationLabel;
    QLabel *remainTimeLabel;
    QLabel *remainTime;
    QLabel *stayTime;
    QLabel *serverNum;
    QMenuBar *menuBar;
    QMenu *menuChoose;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Bank)
    {
        if (Bank->objectName().isEmpty())
            Bank->setObjectName(QStringLiteral("Bank"));
        Bank->resize(926, 518);
        actionStart = new QAction(Bank);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStop = new QAction(Bank);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionAbout = new QAction(Bank);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(Bank);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        w1 = new Window(centralWidget, 1,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
        w1->setObjectName(QStringLiteral("w1"));
        w1->setGeometry(QRect(44, 48, 191, 211));
        randCreatePersonButton = new QPushButton(centralWidget);
        randCreatePersonButton->setObjectName(QStringLiteral("randCreatePersonButton"));
        randCreatePersonButton->setGeometry(QRect(700, 378, 201, 71));
        randCreatePersonButton->setStyleSheet(QStringLiteral("font: 14pt \"Sans Serif\";"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(60, 268, 811, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(240, 58, 20, 201));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(674, 58, 20, 201));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(457, 58, 20, 201));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        w2 = new Window(centralWidget, 2,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
        w2->setObjectName(QStringLiteral("w2"));
        w2->setGeometry(QRect(265, 48, 191, 211));
        w3 = new Window(centralWidget, 3, m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
        w3->setObjectName(QStringLiteral("w3"));
        w3->setGeometry(QRect(479, 48, 191, 211));
        w4 = new Window(centralWidget, 4,m_lineQueue,m_oldTicQueue,&workCond,&recCond, &customerQueueMutex, &oldTicQueueMutex);
        w4->setObjectName(QStringLiteral("w4"));
        w4->setGeometry(QRect(699, 48, 191, 211));
        processWindow = new QTextBrowser(centralWidget);
        processWindow->setObjectName(QStringLiteral("processWindow"));
        processWindow->setGeometry(QRect(40, 288, 451, 181));
        addPersonButton = new QPushButton(centralWidget);
        addPersonButton->setObjectName(QStringLiteral("addPersonButton"));
        addPersonButton->setGeometry(QRect(810, 308, 91, 61));
        addPersonButton->setStyleSheet(QStringLiteral("font: 20pt \"Sans Serif\";"));
        businessIdBox = new QSpinBox(centralWidget);
        businessIdBox->setObjectName(QStringLiteral("businessIdBox"));
        businessIdBox->setGeometry(QRect(755, 311, 47, 23));
        personNumBox = new QSpinBox(centralWidget);
        personNumBox->setObjectName(QStringLiteral("personNumBox"));
        personNumBox->setGeometry(QRect(755, 341, 47, 23));
        businessIdLabel = new QLabel(centralWidget);
        businessIdLabel->setObjectName(QStringLiteral("businessIdLabel"));
        businessIdLabel->setGeometry(QRect(677, 305, 81, 31));
        businessIdLabel->setStyleSheet(QLatin1String("\n"
"font: 13pt \"Sans Serif\";"));
        personNumLabel = new QLabel(centralWidget);
        personNumLabel->setObjectName(QStringLiteral("personNumLabel"));
        personNumLabel->setGeometry(QRect(711, 335, 51, 31));
        personNumLabel->setStyleSheet(QLatin1String("\n"
"font: 13pt \"Sans Serif\";"));
        businessIdWaringBox = new QLabel(centralWidget);
        businessIdWaringBox->setObjectName(QStringLiteral("businessIdWaringBox"));
        businessIdWaringBox->setGeometry(QRect(690, 288, 101, 20));
        businessIdWaringBox->setStyleSheet(QStringLiteral("font: 9pt \"Sans Serif\";"));
        window_1StatusLabel = new QLabel(centralWidget);
        window_1StatusLabel->setObjectName(QStringLiteral("window_1StatusLabel"));
        window_1StatusLabel->setGeometry(QRect(60, 8, 81, 41));
        window_1StatusLabel->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        window_2StatusLabel = new QLabel(centralWidget);
        window_2StatusLabel->setObjectName(QStringLiteral("window_2StatusLabel"));
        window_2StatusLabel->setGeometry(QRect(280, 8, 81, 41));
        window_2StatusLabel->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        window_3StatusLabel = new QLabel(centralWidget);
        window_3StatusLabel->setObjectName(QStringLiteral("window_3StatusLabel"));
        window_3StatusLabel->setGeometry(QRect(490, 8, 81, 41));
        window_3StatusLabel->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        window_5StatusLabel = new QLabel(centralWidget);
        window_5StatusLabel->setObjectName(QStringLiteral("window_5StatusLabel"));
        window_5StatusLabel->setGeometry(QRect(710, 8, 81, 41));
        window_5StatusLabel->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        window_1Status = new QLabel(centralWidget);
        window_1Status->setObjectName(QStringLiteral("window_1Status"));
        window_1Status->setGeometry(QRect(132, 12, 61, 31));
        window_1Status->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        window_2Status = new QLabel(centralWidget);
        window_2Status->setObjectName(QStringLiteral("window_2Status"));
        window_2Status->setGeometry(QRect(352, 13, 61, 31));
        window_2Status->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        window_3Status = new QLabel(centralWidget);
        window_3Status->setObjectName(QStringLiteral("window_3Status"));
        window_3Status->setGeometry(QRect(563, 12, 61, 31));
        window_3Status->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        window_4Status = new QLabel(centralWidget);
        window_4Status->setObjectName(QStringLiteral("window_4Status"));
        window_4Status->setGeometry(QRect(782, 12, 61, 31));
        window_4Status->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        serverNumLabel = new QLabel(centralWidget);
        serverNumLabel->setObjectName(QStringLiteral("serverNumLabel"));
        serverNumLabel->setGeometry(QRect(511, 370, 81, 31));
        stayTimeLabel = new QLabel(centralWidget);
        stayTimeLabel->setObjectName(QStringLiteral("stayTimeLabel"));
        stayTimeLabel->setGeometry(QRect(500, 387, 91, 41));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(640, 300, 20, 161));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        informationLabel = new QLabel(centralWidget);
        informationLabel->setObjectName(QStringLiteral("informationLabel"));
        informationLabel->setGeometry(QRect(530, 310, 101, 41));
        informationLabel->setStyleSheet(QStringLiteral("font: 20pt \"Sans Serif\";"));
        remainTimeLabel = new QLabel(centralWidget);
        remainTimeLabel->setObjectName(QStringLiteral("remainTimeLabel"));
        remainTimeLabel->setGeometry(QRect(523, 420, 61, 21));
        remainTime = new QLabel(centralWidget);
        remainTime->setObjectName(QStringLiteral("remainTime"));
        remainTime->setGeometry(QRect(580, 426, 59, 14));
        stayTime = new QLabel(centralWidget);
        stayTime->setObjectName(QStringLiteral("stayTime"));
        stayTime->setGeometry(QRect(581, 403, 59, 14));
        serverNum = new QLabel(centralWidget);
        serverNum->setObjectName(QStringLiteral("serverNum"));
        serverNum->setGeometry(QRect(581, 380, 59, 14));
        Bank->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Bank);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 926, 19));
        menuChoose = new QMenu(menuBar);
        menuChoose->setObjectName(QStringLiteral("menuChoose"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Bank->setMenuBar(menuBar);
        statusBar = new QStatusBar(Bank);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Bank->setStatusBar(statusBar);

        menuBar->addAction(menuChoose->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuChoose->addAction(actionStart);
        menuChoose->addAction(actionStop);
        menuHelp->addAction(actionAbout);

        retranslateUi(Bank);

        QMetaObject::connectSlotsByName(Bank);
    } // setupUi

    void retranslateUi(QMainWindow *Bank)
    {
        Bank->setWindowTitle(QApplication::translate("Bank", "Bank", Q_NULLPTR));
        actionStart->setText(QApplication::translate("Bank", "start", Q_NULLPTR));
        actionStop->setText(QApplication::translate("Bank", "stop", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("Bank", "about", Q_NULLPTR));
        randCreatePersonButton->setText(QApplication::translate("Bank", "\351\232\217\346\234\272\344\272\247\347\224\23710\344\270\252\344\272\272", Q_NULLPTR));
        addPersonButton->setText(QApplication::translate("Bank", "\346\267\273\345\212\240", Q_NULLPTR));
        businessIdLabel->setText(QApplication::translate("Bank", "\344\270\232\345\212\241\347\274\226\345\217\267:", Q_NULLPTR));
        personNumLabel->setText(QApplication::translate("Bank", "\344\272\272\346\225\260:", Q_NULLPTR));
        businessIdWaringBox->setText(QApplication::translate("Bank", "\344\270\232\345\212\241\347\274\226\345\217\267\350\214\203\345\233\264:1-8", Q_NULLPTR));
        window_1StatusLabel->setText(QApplication::translate("Bank", "\347\252\227\345\217\243\344\270\200:", Q_NULLPTR));
        window_2StatusLabel->setText(QApplication::translate("Bank", "\347\252\227\345\217\243\344\272\214:", Q_NULLPTR));
        window_3StatusLabel->setText(QApplication::translate("Bank", "\347\252\227\345\217\243\344\270\211:", Q_NULLPTR));
        window_5StatusLabel->setText(QApplication::translate("Bank", "\347\252\227\345\217\243\345\233\233:", Q_NULLPTR));
        window_1Status->setText(QApplication::translate("Bank", "\345\277\231\347\242\214", Q_NULLPTR));
        window_2Status->setText(QApplication::translate("Bank", "\345\277\231\347\242\214", Q_NULLPTR));
        window_3Status->setText(QApplication::translate("Bank", "\345\277\231\347\242\214", Q_NULLPTR));
        window_4Status->setText(QApplication::translate("Bank", "\345\277\231\347\242\214", Q_NULLPTR));
        serverNumLabel->setText(QApplication::translate("Bank", "\345\267\262\346\234\215\345\212\241\344\272\272\346\225\260:", Q_NULLPTR));
        stayTimeLabel->setText(QApplication::translate("Bank", "\344\272\272\345\235\207\351\200\227\347\225\231\346\227\266\351\227\264:", Q_NULLPTR));
        informationLabel->setText(QApplication::translate("Bank", "\344\277\241\346\201\257\346\240\217", Q_NULLPTR));
        remainTimeLabel->setText(QApplication::translate("Bank", "\350\220\245\344\270\232\346\227\266\351\227\264:", Q_NULLPTR));
        remainTime->setText(QApplication::translate("Bank", "0", Q_NULLPTR));
        stayTime->setText(QApplication::translate("Bank", "0", Q_NULLPTR));
        serverNum->setText(QApplication::translate("Bank", "0", Q_NULLPTR));
        menuChoose->setTitle(QApplication::translate("Bank", "choose", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("Bank", "help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Bank: public Ui_Bank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANK_H
