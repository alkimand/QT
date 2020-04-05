//modules
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import BorderRadiusWidget.qml 1.0
//files
import "src/QML/Setting"
import "./src/QML/Action"
import "src/QML/ToolBar"
import "src/QML/ColumnWidget"
import "src/QML/StackView"

ApplicationWindow {
    id:mainwindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Working Money Cheker")
    //property var  actions: actions



    //singleton object for all app
    SettingData{
        id: settingData
    }
    property Actions actions : Actions{}

    ColumnWidget {
        id: column_1
        anchors.left: mainwindow.left
        title:""
        columnWidgetType: SettingData.ColumnWidgetType.EMPTY_SPACE
        //columnWidth:50
        width: 20;
        actions: mainwindow.actions
    }

    ColumnWidget {
        id:column_2
        anchors.left: column_1.right
        title:""
        columnWidgetType: SettingData.ColumnWidgetType.BUTTON_SPACE
        width: settingData.buttonSettings.buttonWidth;
        actions: mainwindow.actions
    }

    ColumnWidget {
        id:column_3
        anchors.left: column_2.right
        title:""
        columnWidgetType: SettingData.ColumnWidgetType.EMPTY_SPACE
        //columnWidth:50
        width: 40;
        actions: mainwindow.actions
    }

    //all pages
    AppContentBox {
        id:appContentBox
        anchors.left: column_3.right
        anchors.right: parent.right
       // anchors.right: mainwindow.right

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        //anchors.right: column_3.left
    }

//    Rectangle {
//        id: rootReact
//        color: "red"
//       // anchors.top: mainwindow.top
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
//        width: 25
//       // anchors.top: mainViewItem.top
//       // anchors.bottom: mainViewItem.bottom
//        height:10
//        border.color: "yellow"
//        border.width: 1
//    }


    //menuBar: MenuBar{id:mainMenuBar}
    //header: ToolBar {id:mainToolBar}
}
