
QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


TEMPLATE      = app
HEADERS       = booleanmodel.h \
                booleanparser.h \
                booleanwindow.h \
                node.h
SOURCES       = booleanmodel.cpp \
                booleanparser.cpp \
                booleanwindow.cpp \
                main.cpp \
                node.cpp


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
