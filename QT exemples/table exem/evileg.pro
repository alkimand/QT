TEMPLATE = app
QT += quick
CONFIG += c++11

TARGET = evileg

QT += qml quick widgets sql

SOURCES += main.cpp \
    database.cpp \
    model.cpp

HEADERS += \
    database.h \
   model.h



RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

H

DISTFILES += \
    Delegat.qml
