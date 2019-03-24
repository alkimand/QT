import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import "../"
import "../../Action/"


ContextMenuBase
{
    id:control
    Component.onCompleted:
    {
       control.insertAction(0, actions.fileSaveAction)
       control.insertAction(1, actions.fileSaveAsAction)
       control.insertAction(2, actions.closeAction)
       control.insertAction(3, actions.closeAllButThisAction)
       control.insertAction(4, actions.openInExplorerAction)
       control.insertAction(5, actions.openDesktopServicesAction)
       control.insertAction(6, actions.renameTabAction)
    }
}
