
QT += widgets
QT -= gui
QT       += core network
CONFIG += c++11 console
CONFIG -= app_bundle

QT += core








TEMPLATE      = app
QT           += network
HEADERS       = clientsocket.h \
                tripserver.h
SOURCES       = clientsocket.cpp \
                main.cpp \
                tripserver.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
