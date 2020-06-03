import QtQuick 2.12

import "../MenuBarContextMenu/FileContexMenu"
//import "../ContextMenu/MenuBarContextMenu/SettingContexMenu"
//import "../ContextMenu/MenuBarContextMenu/ConnectContexMenu"
//import "../ContextMenu/MenuBarContextMenu/TableContexMenu"

MenuBarBasic {
    FileContexMenu {title: qsTr("File")}
    FileContexMenu {title: qsTr("File")}
    //ConnectContexMenu{title: qsTr("Connect")}
    //TableContexMenu{title: qsTr("Table")}
    //SettingContexMenu{title: qsTr("Seting")}
}

