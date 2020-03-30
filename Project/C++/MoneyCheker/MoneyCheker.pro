QT += quick

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


INCLUDEPATH += "src/C++code/QMLCustomClasses/BorderRadiusWidget/" \



SOURCES += \
        main.cpp \
        src/C++code/QMLCustomClasses/BorderRadiusWidget/borderradiuswidget.cpp

RESOURCES += \
    resources.qrc


OTHER_FILES += \
    main.qml \
#Setting
    src/QML/Setting/SettingData.qml \
#Actions
    src/QML/Action/Actions.qml \
#ToolBar
    src/QML/ToolBar/ToolBar.qml \
    src/QML/ToolBar/CustomComboBox/CustomComboBox.qml \
    src/QML/ToolBar/CustomToolButton/CustomToolButtonIconText.qml \
    src/QML/ToolBar/CustomToolButton/CustomToolButtonIcon.qml \
    src/QML/ToolBar/CustomToolButton/CustomToolButtonText.qml \
    src/QML/ToolBar/CustomToolButton/ToolButtonLoader.qml \
    src/QML/ToolBar/CustomToolButton/CustomToolButton.qml \
#ColumnWidget
    src/QML/ColumnWidget/ColumnWidget.qml \
    src/QML/ColumnWidget/CalculatorArea/CalculatorArea.qml\
#ButtonRow
    src/QML/ColumnWidget/ItemLoader/ButtonRow/ButtonRow.qml\
    src/QML/ColumnWidget/ItemLoader/ButtonRow/ButtonTemplate.qml\
#StackView
    src/QML/StackView/AppContentBox.qml\
    src/QML/StackView/Pages/CalkPage.qml\
#CommonElements
    src/QML/CommonElements/TabButton/TabButton.qml\
    src/QML/CommonElements/TabButton/TabButtonLabel/TabButtonLabel.qml\
    src/QML/CommonElements/OneRowItem/OneRowItem.qml\
    src/QML/CommonElements/SmallCrossChekerButton/SmallCrossChekerButton_O.qml\
    src/QML/CommonElements/SmallCrossChekerButton/MoneyCheker/SmallCrossChekerButton_S.qml\

DISTFILES += \
    src/QML/StackView/AppContentBox.qml \
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
    src/images/AppButton/calculator.png \
    src/images/AppButton/percent.png \
    src/images/AppButton/setting.png \
    src/images/AppButton/star_favorite.png \
    src/images/AppButton/home_blue.png \




# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/C++code/QMLCustomClasses/BorderRadiusWidget/borderradiuswidget.h
