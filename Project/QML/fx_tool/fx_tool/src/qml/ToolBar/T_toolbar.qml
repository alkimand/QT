import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

import Actions 1.0
import "./CustomToolButton"

ToolBar
{
    id: control
    width: parent.width
    implicitHeight: 55
    //height: 25
    focusReason : Qt.MouseFocusReason
    background: Rectangle  {
        anchors.fill:parent
        color: "white"
    }

    Row {
        property int button_type : 1
        spacing: 0
        CustomToolButton {action: Actions.addAction}
        CustomToolButton {action: Actions.fileOpenAction}
        CustomToolButton {action: Actions.fileSaveAction}
        CustomToolButton {action: Actions.fileSaveAsAction}
        CustomToolButton {action: Actions.closeAction}

//        Rectangle {
//            color: "#77a9ef"
//            width: parent.width
//            height: 1
//            anchors.bottom: parent.bottom
//        }

    }
//    Rectangle {
//        color: "#77a9ef"
//        width: parent.width
//        height: 1
//        anchors.bottom: parent.bottom
//    }

}

