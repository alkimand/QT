TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "gtest-1.7.0/include"
INCLUDEPATH += "gtest-1.7.0/"
INCLUDEPATH +="../../"

SOURCES += \
        main.cpp \
    ../../function.cpp \
    gtest-1.7.0/src/gtest.cc \
    gtest-1.7.0/src/gtest-all.cc \
    gtest-1.7.0/src/gtest-death-test.cc \
    gtest-1.7.0/src/gtest-filepath.cc \
    gtest-1.7.0/src/gtest-port.cc \
    gtest-1.7.0/src/gtest-printers.cc \
    gtest-1.7.0/src/gtest-test-part.cc \
    gtest-1.7.0/src/gtest-typed-test.cc

HEADERS += \
    ../../function.h \
    gtest-1.7.0/src/gtest-internal-inl.h
