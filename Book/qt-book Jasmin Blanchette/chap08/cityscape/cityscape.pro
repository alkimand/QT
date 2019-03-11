
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cityscape
TEMPLATE = app

QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

TEMPLATE      = app
HEADERS       = annotation.h \
                cityblock.h \
                cityscape.h \
                cityview.h
SOURCES       = annotation.cpp \
                cityblock.cpp \
                cityscape.cpp \
                cityview.cpp \
                main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
