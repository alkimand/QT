//modules
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

//files
import "src/QML/Setting"
import "./src/QML/Action"
import "src/QML/ToolBar"
import "src/QML/ColumnWidget"



ApplicationWindow {
    id:mainwindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Working Money Cheker")
    //property var  actions: actions



    //singleton object for all app
    SettingData{id: settingData}
    property Actions actions : Actions{}

    ColumnWidget {
        id: column_1
        anchors.left: mainwindow.left
        title:""
        columnWidgetType: SettingData.ColumnWidgetType.EMPTY_SPACE
        //columnWidth:50
        width: 25;
        actions: mainwindow.actions
    }


    ColumnWidget {
        id:column_2
        anchors.left: column_1.right
        title:qsTr("")
        columnWidgetType: SettingData.ColumnWidgetType.BUTTON_SPACE
        //columnWidth:100
        width: 100;
        actions: mainwindow.actions
    }


//    Rectangle {
//        id: rect1;
//        color: "red"
//        width: 200; height: 80
//    }

//    Rectangle {
//        id: rect2;
//        anchors.left: rect1.right; anchors.leftMargin: 5;
//        color: "steelblue"
//        y: 100; width: 80; height: 80
//    }

    ColumnWidget {
        id:column_3
        anchors.left: column_2.right
        title:""
        columnWidgetType: SettingData.ColumnWidgetType.EMPTY_SPACE
        //columnWidth:50
        width: 50;
        actions: mainwindow.actions
    }


    //menuBar: MenuBar{id:mainMenuBar}
    //header: ToolBar {id:mainToolBar}
}
