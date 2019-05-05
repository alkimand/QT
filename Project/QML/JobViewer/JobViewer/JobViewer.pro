

QT += qml quick
QT += quick
QT += core
QT += quickcontrols2

CONFIG += c++11

TEMPLATE = app

#TARGET  = JobViewer


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp
RESOURCES += qml.qrc
 #   src/qrc/resource.qrc
INCLUDEPATH +=$$PWD/src
#INCLUDEPATH += "src/qml/Button/"

#Add QML Files Here
OTHER_FILES += \
#ApplicationWindow
   main.qml \
#Button
   src/qml/Button/UserButton.qml \
   src/qml/mainWindow/MainControlButton/MainControlButton.qml



# Additional import path used to resolve QML modules in Qt Creator's code model


# Additional import path used to resolve QML modules just for Qt Quick Designer

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
     src/qrc/images/Button/box-shadow.png \
     src/qrc/images/Button/busy.png \
    src/qrc/images/Button/cardboard.png
