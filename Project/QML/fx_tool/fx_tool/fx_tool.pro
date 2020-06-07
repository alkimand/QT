#http://itnotesblog.ru/note.php?id=3

PROJECT_ROOT_PATH = $${PWD}/
win32: OS_SUFFIX = win32
linux-g++: OS_SUFFIX = linux

QT += qml quick core quickcontrols2

CONFIG += c++11

CONFIG(debug, debug|release) {
    BUILD_FLAG = debug
    LIB_SUFFIX = d
} else {
    BUILD_FLAG = release
}

LIBS_PATH = $${PROJECT_ROOT_PATH}/lib/$${OS_SUFFIX}/
INC_PATH = $${PROJECT_ROOT_PATH}/include/
IMPORT_PATH = $${PROJECT_ROOT_PATH}/import/
BIN_PATH = $${PROJECT_ROOT_PATH}/bin/$${BUILD_FLAG}/

IMAGES_PATH = $${PROJECT_ROOT_PATH}/src/images/ToolBarIcon/

BUILD_PATH = $${PROJECT_ROOT_PATH}/build/$${BUILD_FLAG}/$${TARGET}/
RCC_DIR = $${BUILD_PATH}/rcc/
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

SOURCES += \
        main.cpp \
        $${QML_CUSTOM_CLASSES}/BorderRadiusWidget/borderradiuswidget.cpp
HEADERS += \
        $${QML_CUSTOM_CLASSES}/BorderRadiusWidget/borderradiuswidget.h

RESOURCES += qml.qrc
TRANSLATIONS += \
    fx_tool_ru_RU.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

INCLUDEPATH += $${PROJECT_ROOT_PATH}/src \
               $${QML_CUSTOM_CLASSES}/BorderRadiusWidget/ \
               $${IMPORT_PATH}/
               $${INC_PATH}/

               # $${QML_CUSTOM_CLASSES}/BorderRadiusWidget

# Additional import path used to resolve QML modules just for Qt Quick Designer

#defines other files
QML_SOURSE_PATH = $${PROJECT_ROOT_PATH}/src/qml/
    QML_SOURSE_TOOL_BAR_PATH =  $${QML_SOURSE_PATH}/ToolBar
    QML_SOURSE_MENU_BAR_PATH =  $${QML_SOURSE_PATH}/Menu
    QML_SOURSE_TAB_VIEW_PATH =  $${QML_SOURSE_PATH}/TabView
    QML_SOURSE_TABLE_VIEW_PATH =  $${QML_SOURSE_PATH}/TableView

OTHER_FILES += \
    main.qml \
#Actions
    $${PROJECT_ROOT_PATH}/src/qml/Action/Actions.qml \
#ToolBar
    $${QML_SOURSE_TOOL_BAR_PATH}/T_toolbar.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomComboBox/CustomComboBox.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButtonIconText.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButtonIcon.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButtonText.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/ToolButtonLoader.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButton.qml \
#MenuBar
    $${QML_SOURSE_MENU_BAR_PATH}/HeaderMenuBar/T_menu_bar.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/HeaderMenuBar/MenuBarBasic.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/ContextMenuBase.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/ContextMenuSeparator.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/CheckIndicator.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/MenuBarContextMenu/FileContexMenu/FileContexMenu.qml \
#TabView
    $${QML_SOURSE_TAB_VIEW_PATH}/T_tab_view.qml \
    $${QML_SOURSE_TAB_VIEW_PATH}/Style/TabViewStyle.qml \
    $${QML_SOURSE_TAB_VIEW_PATH}/Style/OneTabBaseStyle.qml \
#TabView_menu
    $${QML_SOURSE_TAB_VIEW_PATH}/Tab/MouseEvent.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/TabContextMenu/TabContextMenu.qml \
#TableView
    $${QML_SOURSE_TABLE_VIEW_PATH}/BaseTableView.qml \
#
    #TableView Item Delegats
    $${QML_SOURSE_TABLE_VIEW_PATH}/ItemDelegate/ItemDelegate/EditableLable.qml \

DISTFILES += \
    $${IMAGES_PATH}/filenew.png \
    $${IMAGES_PATH}/fileopen.png \
    $${IMAGES_PATH}/filesave.png \
    $${IMAGES_PATH}/qt-logo.png \
    $${IMAGES_PATH}/close.png \
    $${IMAGES_PATH}/plus.png



QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
