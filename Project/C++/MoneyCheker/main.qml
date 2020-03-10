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
        title:"Calculator"
        //title:""
        columnWidth:100
        actions: mainwindow.actions

    }

    //menuBar: MenuBar{id:mainMenuBar}
    //header: ToolBar {id:mainToolBar}
}
