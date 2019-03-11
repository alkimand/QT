lessThan(QT_MAJOR_VERSION, 5): error(This project requires Qt 5 or later)

# Needed for C++11 support.
CONFIG += c++11

TEMPLATE = app
TARGET = qmlc++
QT += qml quick widgets
HEADERS += KeyGenerator.h
SOURCES += main.cpp KeyGenerator.cpp
OTHER_FILES += main.qml
