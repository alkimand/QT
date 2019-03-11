
QT += widgets
QT -= gui
QT       += core network
CONFIG += c++11 console
CONFIG -= app_bundle




TEMPLATE      = app
QT           += network
HEADERS       = tripplanner.h
SOURCES       = main.cpp \
                tripplanner.cpp
FORMS         = tripplanner.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
