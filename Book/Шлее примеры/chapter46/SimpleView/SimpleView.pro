

QT += widgets
QT       += core gui
QT += gui

QT       += core network
CONFIG += c++11 console
CONFIG -= app_bundle

QT += webengine
TEMPLATE     = app
QT          += widgets webkitwidgets
SOURCES	     = main.cpp 
windows:TARGET = ../SimpleView

