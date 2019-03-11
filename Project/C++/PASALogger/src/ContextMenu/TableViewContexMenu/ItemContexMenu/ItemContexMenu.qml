import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import "../../"
ContextMenuBase
{
    id:control
//    Action { text: qsTr("Test tool Bar"); checkable: false }
//    Action { text: qsTr("Test tool Bar"); checkable: false }
//    Action { text: qsTr("Test tool Bar"); checkable: false }
//    //Action { text: qsTr("Tool Bar"); checkable: true }
//    Action { text: qsTr("Side Bar"); checkable: true; checked: true }

    Component.onCompleted:
    {
        control.insertAction(0, actions.fileOpenAction)
        control.insertAction(1, actions.searchAction)

    }



}
