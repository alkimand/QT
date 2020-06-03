import QtQuick 2.12
//import QtQuick.Window 2.11
//import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.12
//import QtQuick.Controls.Styles 1.4
//import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import Actions 1.0

import "./CustomToolButton"
//import "./CustomComboBox"

ToolBar
{
    id: control
    width: parent.width
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
    }

}

