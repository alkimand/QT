

QT       += core gui
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = settingsviewer
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS





TEMPLATE      = app
HEADERS       = settingsviewer.h
SOURCES       = main.cpp \
                settingsviewer.cpp
