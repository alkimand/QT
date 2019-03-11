#-------------------------------------------------
#
# Project created by QtCreator 2018-07-05T08:14:00
#
#-------------------------------------------------

QT       += core gui
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pr
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
QT += axcontainer
QT           += sql
SOURCES += main.cpp\
    mainform.cpp \
    MainDelegate.cpp \
    ContactsDelegate.cpp \
    Setting.cpp \
    ContactsCheckboxDelegate.cpp \
    ComboboxDelegate.cpp \
    QlineEditDelegate.cpp \
    stylehelper.cpp \
    VisitsDelegate.cpp

CONFIG += c++11

HEADERS  += \
    mainform.h \
    mainform2.h \
    MainDelegate.h \
    ContactsDelegate.h \
    ContactsCheckboxDelegate.h \
    ComboboxDelegate.h \
    QlineEditDelegate.h \
    stylehelper.h \
    VisitsDelegat.h

RESOURCES += \
    qrc.qrc
