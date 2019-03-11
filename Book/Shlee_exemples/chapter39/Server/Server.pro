
QT -= gui
QT       += core network
CONFIG += c++11 console
CONFIG -= app_bundle







TEMPLATE     = app
SOURCES	     = main.cpp \
               MyServer.cpp
QT          += widgets network
HEADERS      = MyServer.h
windows:TARGET = ../Server
