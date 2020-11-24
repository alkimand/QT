import QtQuick 2.12

import Actions 1.0

import "../"

ContextMenuBase {
    id:control
    Component.onCompleted:{
       control.insertAction(0, Actions.deleteFileAction)
    }
}
