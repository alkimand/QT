import QtQuick 2.12
import "./"
import QtQuick.Controls 2.4
//import "../ContextMenu/TableViewContexMenu/ItemContexMenu"
import "../ContextMenu/MenuBarContextMenu/FileContexMenu"
import "../ContextMenu/MenuBarContextMenu/SettingContexMenu"
import "../ContextMenu/MenuBarContextMenu/ConnectContexMenu"
import "../ContextMenu/MenuBarContextMenu/TableContexMenu"

MenuBarBasic
{
    FileContexMenu{title: qsTr("File")}
    ConnectContexMenu{title: qsTr("Connect")}
    TableContexMenu{title: qsTr("Table")}
    SettingContexMenu{title: qsTr("Seting")}
}

