import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

import Actions 1.0
import "./CustomToolButton"

ToolBar
{
    id: control
    width: parent.width
    //implicitHeight: grid_view_.height
    //height: 400
    focusReason : Qt.MouseFocusReason
    background: Rectangle  {
        anchors.fill:parent
        color: "white"
    }


    Flow {
        id:grid_view_
        width: parent.width;
        property int button_type : 1
        CustomToolButton {action: Actions.addAction}
        CustomToolButton {action: Actions.fileOpenAction}
        CustomToolButton {action: Actions.fileSaveAction}
        CustomToolButton {action: Actions.fileSaveAsAction}
        CustomToolButton {action: Actions.closeAllAction}
        CustomToolButton {action: Actions.addAction}
        CustomToolButton {action: Actions.fileOpenAction}
        CustomToolButton {action: Actions.fileSaveAction}
        CustomToolButton {action: Actions.fileSaveAsAction}
        CustomToolButton {action: Actions.closeAllAction}
        CustomToolButton {action: Actions.addAction}
        CustomToolButton {action: Actions.fileOpenAction}
        CustomToolButton {action: Actions.fileSaveAction}
        CustomToolButton {action: Actions.fileSaveAsAction}
        CustomToolButton {action: Actions.closeAllAction}
        CustomToolButton {action: Actions.addAction}
        CustomToolButton {action: Actions.fileOpenAction}
        CustomToolButton {action: Actions.fileSaveAction}
        CustomToolButton {action: Actions.fileSaveAsAction}
        CustomToolButton {action: Actions.closeAllAction}
        //}
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

