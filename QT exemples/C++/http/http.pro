




QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = http
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


QT += network widgets

HEADERS += httpwindow.h
SOURCES += httpwindow.cpp \
           main.cpp
FORMS += authenticationdialog.ui

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/http
INSTALLS += target

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
