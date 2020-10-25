import QtQuick 2.12

Onegamecontroller {
    implicitWidth: 40
    implicitHeight: 40
    Rectangle {
        width: 26
        height: 26
        anchors.centerIn: parent
        visible: menuItem.checkable
        border.color: "black"//"#21be2b"
        radius: 3
        Rectangle {
            width: 14
            height: 14
            anchors.centerIn: parent
            visible: menuItem.checked
            color: itemBorderColor
            radius: 2
        }
    }
}
