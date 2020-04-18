import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Settings 1.0

import BorderRadiusWidget.qml 1.0

Item {
    id:root

    property int borderRadius
    property color topActiveColor
    property color backgroundColor

    height: root.borderRadius
    anchors.left:parent.left
    anchors.right:parent.right

    BorderRadiusWidget {
        id:borromLeftRadius
        anchors.left:parent.left
        anchors.leftMargin: root.borderRadius
        anchors.top:parent.top
        radius: root.borderRadius
        activeButtonColor:  topActiveColor
        height: root.borderRadius
        width: root.borderRadius

        transform: Rotation {
            origin.x: 0;
            origin.y: 0;
            angle: 270
        }
        z:2
    }

    Rectangle{
        id:bottomLeftRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        anchors.left:parent.left
        anchors.bottom:parent.bottom
        z:1
        color: root.backgroundColor
    }


    Rectangle{
        id:centerBottomRect
        anchors.top:parent.top
        anchors.left:bottomLeftRadiusReact.right
        anchors.right: bottomRightRadius.left
        height:root.borderRadius
        color: root.topActiveColor
    }


    BorderRadiusWidget {
        id:bottomRightRadius
        anchors.right:parent.right
        anchors.bottom:parent.bottom
        anchors.bottomMargin: root.borderRadius
        anchors.rightMargin: root.borderRadius
        radius: root.borderRadius
        activeButtonColor:  root.topActiveColor
        transform: Rotation {
            origin.x: 0;
            origin.y: 0;
            angle: 180
        }
        z:2
    }

    Rectangle{
        id:bottomRightRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        anchors.right:parent.right
        anchors.bottom:parent.bottom
        z:1
        color: root.backgroundColor
    }
}






