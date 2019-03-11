#-------------------------------------------------
#
# Project created by QtCreator 2018-09-28T22:33:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConfData
TEMPLATE = app
QT += widgets
QT += core


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    toolwidget.cpp \
    firstwidget.cpp \
    generaltoolwidget.cpp \
    generalproduct.cpp \
    product_ktp.cpp \
    ktp_2_widget.cpp \
    controlwidget.cpp

HEADERS += \
        mainwindow.h \
    toolwidget.h \
    firstwidget.h \
    constantlist.h \
    generaltoolwidget.h \
    generalproduct.h \
    product_ktp.h \
    ktp_2_widget.h \
    controlwidget.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sourse.qrc

DISTFILES += \
    sourse/1.txt \
    sourse/1.txt
