#http://itnotesblog.ru/note.php?id=3

PROJECT_ROOT_PATH = $${PWD}/
win32: OS_SUFFIX = win32
linux-g++: OS_SUFFIX = linux

QT += qml quick core quickcontrols2 widgets concurrent opengl
CONFIG += c++11

#CONFIG(debug, debug|release) {
CONFIG(debug) {
    BUILD_FLAG = debug
    LIB_SUFFIX = d
} else {
    BUILD_FLAG = release
}

LIBS_PATH = $${PROJECT_ROOT_PATH}/lib/$${OS_SUFFIX}/
INC_PATH = $${PROJECT_ROOT_PATH}/include/
IMPORT_PATH = $${PROJECT_ROOT_PATH}/import/
BIN_PATH = $${PROJECT_ROOT_PATH}/bin/$${BUILD_FLAG}/

#IMAGES_PATH = $${PROJECT_ROOT_PATH}/src/images/ToolBarIcon/

BUILD_PATH = $${PROJECT_ROOT_PATH}/build/$${BUILD_FLAG}/$${TARGET}/
#RCC_DIR = $${BUILD_PATH}/rcc/

#UI_DIR = $${BUILD_PATH}/ui/
#MOC_DIR = $${BUILD_PATH}/moc/
#OBJECTS_DIR = $${BUILD_PATH}/obj/
LIBS += -L$${LIBS_PATH}/

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS

#INCLUDEPATH += $${INC_PATH}/
#INCLUDEPATH += $${IMPORT_PATH}/

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QML_CUSTOM_CLASSES = $${PROJECT_ROOT_PATH}/src/C++/QMLCustomClasses/
C_SOURSE_MODEL_PATH = $${PROJECT_ROOT_PATH}/src/C++/Models/
C_SOURSE_CONTROLLERS_PATH = $${PROJECT_ROOT_PATH}/src/C++/Controllers/
C_SOURSE_UTILS_PATH = $${PROJECT_ROOT_PATH}/src/C++/utilities/
SOURCES += \
        main.cpp \
        #$${C_SOURSE_CONTROLLERS_PATH}/AppDataProvider/AppDataProvider.cpp 
HEADERS += 
        #$${C_SOURSE_CONTROLLERS_PATH}/AppDataProvider/AppDataProvider.h \

QRC_DIR_PATH = $${PROJECT_ROOT_PATH}/src/resources \

RESOURCES += $${QRC_DIR_PATH}/qml.qrc 
             #$${QRC_DIR_PATH}/Icons.qrc

TRANSLATIONS += \
             $${QRC_DIR_PATH}/translations/fx_tool_ru_RU.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

INCLUDEPATH += $${PROJECT_ROOT_PATH}/src 
               #$${IMPORT_PATH}/ \
               #$${INC_PATH}/

               # $${QML_CUSTOM_CLASSES}/BorderRadiusWidget

# Additional import path used to resolve QML modules just for Qt Quick Designer

#defines other files
QML_SOURSE_PATH = $${PROJECT_ROOT_PATH}/src/qml/
    QML_SOURSE_TOOL_BAR_PATH =    $${QML_SOURSE_PATH}/ToolBar
    QML_SOURSE_MENU_BAR_PATH =    $${QML_SOURSE_PATH}/Menu
    QML_SOURSE_TAB_VIEW_PATH =    $${QML_SOURSE_PATH}/TabView
    QML_SOURSE_TABLE_VIEW_PATH =  $${QML_SOURSE_PATH}/TableView
    QML_SOURSE_FILE_DIALOG_PATH = $${QML_SOURSE_PATH}/FileDialog
OTHER_FILES += \
    main.qml \

RC_FILE = $${PROJECT_ROOT_PATH}/src/images/AppIcon/AppIcon.rc

DISTFILES += 


QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
