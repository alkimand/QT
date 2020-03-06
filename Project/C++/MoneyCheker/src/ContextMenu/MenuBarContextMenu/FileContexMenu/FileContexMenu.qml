import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import "../../"
import "../../../Action"

ContextMenuBase
{
    id:control
    Component.onCompleted:
    {
        control.insertAction(0, actions.fileOpenAction)
        control.insertAction(1, actions.fileSaveAction)
        control.insertAction(2, actions.fileSaveAsAction)
        control.insertAction(3, actions.downloadSaveAction)
        control.insertAction(4, actions.addAction)
        control.insertAction(5, actions.closeAction)
    }
}
