import QtQuick 2.12

import Actions 1.0

import "../"

ContextMenuBase {
    id:control
    Component.onCompleted:{
       control.insertAction(0, Actions.deleteFileAction)

     //  control.insertAction(4, Actions.openInExplorerAction)
     //  control.insertAction(5, Actions.openDesktopServicesAction)
     //  control.insertAction(6, Actions.renameTabAction)
    }
}
