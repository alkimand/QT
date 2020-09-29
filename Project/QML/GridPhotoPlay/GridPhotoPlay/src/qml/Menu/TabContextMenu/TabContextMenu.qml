import QtQuick 2.12

import Actions 1.0

import "../"

ContextMenuBase {
    id:control
    Component.onCompleted:{
       control.insertAction(0, Actions.fileSaveAction)
       control.insertAction(1, Actions.fileSaveAsAction)
       control.insertAction(2, Actions.closeTabAction)
       control.insertAction(3, Actions.closeAllButThisAction)
       control.insertAction(4, Actions.refreshAction)
     //  control.insertAction(4, Actions.openInExplorerAction)
     //  control.insertAction(5, Actions.openDesktopServicesAction)
     //  control.insertAction(6, Actions.renameTabAction)
    }
}
