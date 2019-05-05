QT += qml quick
QT += core
QT += quick
CONFIG += c++11
QT += quickcontrols2
TEMPLATE = app
TARGET  = PASALogger
QT          += widgets network
QT += network
INCLUDEPATH += "src/C++code/Server/Server/" \
               "src/C++code/Setting/" \
               "src/C++code/Server/Client/Clients/" \
               "src/C++code/Server/Client/Workers/Worker/" \
               "src/C++code/Server/Client/Workers/ModelServise/" \
               "src/C++code/Server/Client/Workers/ParserService/" \
               "src/C++code/Server/Client/Workers/ProxiModel/" \
               "src/C++code/Server/Client/Workers/DataLoaderServise/"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/C++code/Server/Client/Clients/clientbase.cpp \
    src/C++code/Server/Client/Clients/clientudp.cpp \
    src/C++code/Server/Client/Workers/DataLoaderServise/dataloaderbaseclass.cpp \
    src/C++code/Server/Client/Workers/DataLoaderServise/dateloaderudp.cpp \
    src/C++code/Server/Client/Workers/ModelServise/modelservisebaseclass.cpp \
    src/C++code/Server/Client/Workers/ModelServise/modelserviseudp.cpp \
    src/C++code/Server/Client/Workers/ParserService/parseservicebaseclass.cpp \
    src/C++code/Server/Client/Workers/ParserService/parseserviceudp.cpp \
    src/C++code/Server/Client/Workers/Worker/workerbaseclass.cpp \
    src/C++code/Server/Client/Workers/Worker/workerudp.cpp \
    src/C++code/Setting/setting.cpp \
    src/C++code/Setting/settingmap.cpp \
    src/C++code/Server/Server/Server.cpp \
    src/C++code/Server/Client/Clients/clienttext.cpp \
    src/C++code/Server/Client/Workers/Worker/workertext.cpp \
    src/C++code/Server/Client/Workers/DataLoaderServise/dateloadertext.cpp \
    src/C++code/Server/Client/Workers/ParserService/parseservicetext.cpp \
    src/C++code/Server/Client/Workers/ModelServise/modelservisetext.cpp \
    src/C++code/Server/Client/Workers/ProxiModel/proximodelservisebaseclass.cpp \
    src/C++code/Server/Client/Workers/ProxiModel/proximodelserviseudp.cpp


RESOURCES += qml.qrc
INCLUDEPATH +=$$PWD/src
# Additional import path used to resolve QML modules in Qt Creator's code model

#RC_FILE = PASALogger.rc icon

OTHER_FILES += \
    main.qml \
    src/Setting/SettingData.qml \
#designer/Backend/*.qml - can do it man
#MenuBar
    src/MenuBar/MenuBar.qml \
    src/MenuBar/MenuBarBasic.qml \
    src/ContextMenu/CheckIndicator.qml \
#Actions
    src/Action/Actions.qml \
#Context menu
    src/ContextMenu/ContextMenuBase.qml \
    src/ContextMenu/TabContextMenu/TabContextMenu.qml \
    src/ContextMenu/ContextMenuSeparator.qml \
    src/ContextMenu/TableViewContexMenu/HeaderContexMenu/HeaderContexMenu.qml \
    src/ContextMenu/TableViewContexMenu/ItemContexMenu/ItemContexMenu.qml \
    src/ContextMenu/MenuBarContextMenu/SettingContexMenu/SettingContexMenu.qml \
    src/ContextMenu/MenuBarContextMenu/ConnectContexMenu/ConnectContexMenu.qml \
    src/ContextMenu/MenuBarContextMenu/FileContexMenu/FileContexMenu.qml \
    src/ContextMenu/MenuBarContextMenu/TableContexMenu/TableContexMenu.qml \
#TabView
    src/TabView/TabView.qml \
    src/TabView/Style/TabViewStyle.qml \
    src/TabView/Tab/MouseEvent.qml \
    src/TabView/Style/Tab/OneTabBaseStyle.qml \
#TableView
    src/TableView/ItemDelegat/ItemDelegate/ItemDelegate.qml \
    src/TableView/ItemDelegat/HeaderDelegate/HeaderDelegate.qml \
    src/TableView/TableWithHeader.qml \
    src/TableView/ItemDelegat/Loaders/HeaderLoader.qml \
    src/TableView/ItemDelegat/RowDelegat/RowDelegat.qml \
    src/TableView/TableView/BaseTableView.qml \
    src/TableView/TableView/TableUDPBaseTable.qml \
    src/TableView/TableView/TableUDP.qml \
    src/TableView/TableView/TableText.qml \
    src/TableView/FilterDailog/FilterDialog.qml \
#ToolBar
    src/ToolBar/ToolBar.qml \
    src/ToolBar/CustomComboBox/CustomComboBox.qml \
    src/ToolBar/CustomToolButton/CustomToolButtonIconText.qml \
    src/ToolBar/CustomToolButton/CustomToolButtonIcon.qml \
    src/ToolBar/CustomToolButton/CustomToolButtonText.qml \
    src/ToolBar/CustomToolButton/ToolButtonLoader.qml \
    src/ToolBar/CustomToolButton/CustomToolButton.qml \
#ChoiceItem
    src/ChoiceItem/ChoiceItemBase.qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
    src/images/TableViewIcon/filter.png \
    src/images/TableViewIcon/filterAdd.png \
    src/images/TableViewIcon/filterDelete.png \
    src/images/TableViewIcon/search.png \
    src/images/TableViewIcon/sort_ascending.png \
    src/images/TableViewIcon/sort_descending.png \
    src/images/ToolBarIcon/rename.jpg \
    src/images/ToolBarIcon/explorer.png \




#   src/images/ToolBarIcon/qt-logo.png \

HEADERS += \
    src/C++code/Server/Client/Clients/clientbase.h \
    src/C++code/Server/Client/Clients/clientudp.h \
    src/C++code/Server/Client/Workers/DataLoaderServise/dataloaderbaseclass.h \
    src/C++code/Server/Client/Workers/DataLoaderServise/dateloaderudp.h \
    src/C++code/Server/Client/Workers/ModelServise/modelservisebaseclass.h \
    src/C++code/Server/Client/Workers/ModelServise/modelserviseudp.h \
    src/C++code/Server/Client/Workers/ParserService/parseservicebaseclass.h \
    src/C++code/Server/Client/Workers/ParserService/parseserviceudp.h \
    src/C++code/Server/Client/Workers/ParserService/parseservicebaseclass.h \
    src/C++code/Server/Client/Workers/ParserService/parseserviceudp.h \
    src/C++code/Server/Client/Workers/Worker/workerbaseclass.h \
    src/C++code/Server/Client/Workers/Worker/workerudp.h \
    src/C++code/Setting/setting.h \
    src/C++code/Setting/settingmap.h \
    src/C++code/Server/Server/Server.h \
    src/C++code/Server/Client/Clients/clienttext.h \
    src/C++code/Server/Client/Workers/Worker/workertext.h \
    src/C++code/Server/Client/Workers/DataLoaderServise/dateloadertext.h \
    src/C++code/Server/Client/Workers/ParserService/parseservicetext.h \
    src/C++code/Server/Client/Workers/ModelServise/modelservisetext.h \
    src/C++code/Server/Client/Workers/ProxiModel/proximodelservisebaseclass.h \
    src/C++code/Server/Client/Workers/ProxiModel/proximodelserviseudp.h





