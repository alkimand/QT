QT -= gui
QT       += core network
CONFIG += c++11 console
CONFIG -= app_bundle

TARGET = EchoServer
//CONFIG += console
CONFIG -= app_bundle

TEMPLATE     = app
QT          += widgets network
SOURCES	     = main.cpp \
               MyClient.cpp
HEADERS      = MyClient.h
windows:TARGET = ../Client


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
