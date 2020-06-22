import QtQuick 2.12
import QtQuick.Controls 2.4
import "../../"
import Actions 1.0

ContextMenuBase {
    id:control
    Component.onCompleted: {
        control.insertAction(0, Actions.removeRowAction)
        control.insertAction(1, Actions.addRowAction)
        control.insertAction(2, Actions.copyRowAction)
    }
}
