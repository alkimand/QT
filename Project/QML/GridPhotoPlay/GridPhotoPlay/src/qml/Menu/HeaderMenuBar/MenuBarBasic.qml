import QtQuick 2.12
import QtQuick.Controls 2.12

MenuBar {

    delegate: MenuBarItem {
        id: menuBarItem

        contentItem: Text {
            text: menuBarItem.text
            font: menuBarItem.font
            opacity: enabled ? 1.0 : 0.3
            //color:  "black" //menuBarItem.highlighted ? "#ffffff" : "black"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
            //font.bold: enabled ? true : false
        }

        background: Rectangle{
            implicitWidth: 40
            implicitHeight: 32
            opacity: enabled ? 1 : 0.3
            color: menuBarItem.highlighted ? "#77a9ef" : "transparent"
        }
    }

    background: Rectangle {
        implicitWidth: 40
        implicitHeight: 32
        color: "#ffffff"

        Rectangle {
            color: "#77a9ef"
            width: parent.width
            height: 1
            anchors.bottom: parent.bottom
        }
    }
}

