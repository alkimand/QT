import QtQuick 2.12

import "../../"
import Actions 1.0

ContextMenuBase {
    id:control
    Component.onCompleted: {
        control.insertAction(0, Actions.fileOpenAction)
        control.insertAction(1, Actions.fileSaveAction)
        control.insertAction(2, Actions.fileSaveAsAction)
      //  control.insertAction(3, Actions.closeAppAction)
    }
}
