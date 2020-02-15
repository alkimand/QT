TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../../ \
               $$PWD/../../libcurl-vc-x64-release-dll-ipv6-sspi-winssl/include

SOURCES += main.cpp \
    ../../src/api.cpp \
    ../../src/attachment.cpp \
    ../../src/messages.cpp


HEADERS += \
    ../../src/json.hpp \
    ../../src/api.h \
    ../../src/attachment.h \
    ../../src/messages.h

LIBS += -lcurl
