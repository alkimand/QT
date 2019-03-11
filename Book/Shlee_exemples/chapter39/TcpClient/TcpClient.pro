

QT += widgets
QT -= gui
QT       += core network
CONFIG += c++11 console
CONFIG -= app_bundle




TEMPLATE     = app
SOURCES	     = main.cpp 
QT          += network
CONFIG       += console

TEMPLATE = app

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





