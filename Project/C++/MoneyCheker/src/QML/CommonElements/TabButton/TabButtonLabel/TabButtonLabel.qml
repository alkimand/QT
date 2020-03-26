import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "../../../Action"

Item {

    id:root
    property Action activeAction
    property Action disactiveAction
    property color activeColor
    property color disactiveColor
    property color activeFontColor
    property color disactiveFontColor
    property bool isActive
    property int marginTop
    property int iconTextMargin
    property int fontSize
    property int iconSize
    property string  fontFamily
    property int  type

    anchors.fill:parent
    //Component.onCompleted: console.log("Button:" + root.action.text)
    Button
    {
        id: control
        width: root.width
        height: root.height
        contentItem: Rectangle
        {
            id: buttonReact
            color: root.isActive?root.activeColor:root.disactiveColor
            anchors.fill: parent
            Image
            {
                id: image
                height:  root.iconSize
                width: root.iconSize
                source: root.isActive? root.activeAction.icon.source: root.disactiveAction.icon.source
                fillMode: Image.PreserveAspectFit
                anchors.top: parent.top
                anchors.topMargin: root.marginTop
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text
            {
                id: text
                anchors.top: image.bottom
                anchors.horizontalCenter: buttonReact.horizontalCenter
                text: root.isActive?root.activeAction.text: root.disactiveAction.text
                font.family : root.fontFamily
                font.pointSize:  root.fontSize
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.bold :true
                color: root.isActive?root.activeFontColor : root.disactiveFontColor
                anchors.topMargin: root.iconTextMargin
                horizontalAlignment : Text.AlignHCenter
                renderType: Text.NativeRendering // Rendering type (optional)
            }
        }
    }
}
