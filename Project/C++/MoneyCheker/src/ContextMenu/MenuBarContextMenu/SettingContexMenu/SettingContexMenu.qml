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
        control.insertAction(0, actions.settingAction)
    }
}
