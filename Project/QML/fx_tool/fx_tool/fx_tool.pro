QT += qml quick core quickcontrols2

CONFIG += c++11

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
        main.cpp \
        src/C++/QMLCustomClasses/BorderRadiusWidget/borderradiuswidget.cpp
HEADERS += \
    src/C++/QMLCustomClasses/BorderRadiusWidget/borderradiuswidget.h

RESOURCES += qml.qrc

TRANSLATIONS += \
    fx_tool_ru_RU.ts



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

INCLUDEPATH +=$$PWD/src \
               $$PWD/src/C++/QMLCustomClasses/BorderRadiusWidget

# Additional import path used to resolve QML modules just for Qt Quick Designer

OTHER_FILES += \
    main.qml \
#Actions
    src/qml/Action/Actions.qml \
#ToolBar
    src/qml/ToolBar/T_toolbar.qml \
    src/qml/ToolBar/CustomComboBox/CustomComboBox.qml \
    src/qml/ToolBar/CustomToolButton/CustomToolButtonIconText.qml \
    src/qml/ToolBar/CustomToolButton/CustomToolButtonIcon.qml \
    src/qml/ToolBar/CustomToolButton/CustomToolButtonText.qml \
    src/qml/ToolBar/CustomToolButton/ToolButtonLoader.qml \
    src/qml/ToolBar/CustomToolButton/CustomToolButton.qml \
#MenuBar
    src/qml/Menu/HeaderMenuBar/T_menu_bar.qml \
    src/qml/Menu/HeaderMenuBar/MenuBarBasic.qml \
    src/qml/Menu/ContextMenuBase.qml \
    src/qml/Menu/ContextMenuSeparator.qml \
    src/qml/Menu/CheckIndicator.qml \
    src/qml/Menu/MenuBarContextMenu/FileContexMenu/FileContexMenu.qml \
#TabView
    src/qml/TabView/T_tab_view.qml \
    src/qml/TabView/Style/TabViewStyle.qml \
    src/qml/TabView/Style/OneTabBaseStyle.qml \
#TabView_menu
    src/qml/TabView/Tab/MouseEvent.qml \
    src/qml/Menu/TabContextMenu/TabContextMenu.qml \
#TableView
    src/qml/TableView/BaseTableView.qml \
#TableView Item Delegats
    src/qml/TableView/ItemDelegate/ItemDelegate/EditableLable.qml \

DISTFILES += \
    src/images/ToolBarIcon/editcopy.png \
    src/images/ToolBarIcon/editcopy.png \
    src/images/ToolBarIcon/editcut.png \
    src/images/ToolBarIcon/editpaste.png \
    src/images/ToolBarIcon/editredo.png \
    src/images/ToolBarIcon/editundo.png \
    src/images/ToolBarIcon/exportpdf.png \
    src/images/ToolBarIcon/filenew.png \
    src/images/ToolBarIcon/fileopen.png \
    src/images/ToolBarIcon/fileprint.png \
    src/images/ToolBarIcon/filesave.png \
    src/images/ToolBarIcon/qt-logo.png \
    src/images/ToolBarIcon/textbold.png \
    src/images/ToolBarIcon/textcenter.png \
    src/images/ToolBarIcon/textitalic.png \
    src/images/ToolBarIcon/textjustify.png \
    src/images/ToolBarIcon/textleft.png \
    src/images/ToolBarIcon/textright.png \
    src/images/ToolBarIcon/textunder.png \
    src/images/ToolBarIcon/zoomin.png \
    src/images/ToolBarIcon/zoomout.png \
    src/images/ToolBarIcon/setting.png \
    src/images/ToolBarIcon/sony.png \
    src/images/ToolBarIcon/marker.png \
    src/images/ToolBarIcon/close.png \
    src/images/ToolBarIcon/plus.png \
    src/images/TableViewIcon/filter.png \
    src/images/TableViewIcon/filterAdd.png \
    src/images/TableViewIcon/filterDelete.png \
    src/images/TableViewIcon/search.png \
    src/images/TableViewIcon/sort_ascending.png \
    src/images/TableViewIcon/sort_descending.png \
    src/images/ToolBarIcon/rename.jpg \
    src/images/ToolBarIcon/explorer.png \




QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
