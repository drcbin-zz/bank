#-------------------------------------------------
#
# Project created by QtCreator 2017-01-03T16:08:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankGui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Bank.cpp \
    Customer.cpp \
    Queue.cpp \
    test.cpp \
    Ticket.cpp \
    TicMachine.cpp \
    Window.cpp \
    ../build-BankGui-Desktop_Qt_5_7_1_GCC_64bit-Debug/moc_mainwindow.cpp

HEADERS  += mainwindow.h \
    Bank.h \
    Customer.h \
    Ticket.h \
    TicMachine.h \
    Window.h \
    ../build-BankGui-Desktop_Qt_5_7_1_GCC_64bit-Debug/ui_mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    BankGui.pro.user
