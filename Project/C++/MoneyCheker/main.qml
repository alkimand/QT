//modules
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

//files
import "src/QML/Setting"
import "./src/QML/Action"
import "src/QML/ToolBar"



ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Working Money Cheker")



    //singleton object for all app
    SettingData{id: settingData}
    Actions{id:actions}

    //menuBar: MenuBar{id:mainMenuBar}
    //header: ToolBar {id:mainToolBar}
}
