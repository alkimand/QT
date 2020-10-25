import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Menu {
    id: root
    property color itemBorderColor: "#77a9ef"
    property string itemFontMenu: "Cambria Math"
    property int itemFontSize: 12
    property int itemIconSize: 25
    property int itemImplicitWidth: 150
    property int itemImplicitHeight: 40
    property bool hasArrow: false
    property bool hasIndicator: false

    topPadding: 2
    bottomPadding: 2
    leftPadding: 2
    rightPadding: 2

    delegate: MenuItem {
        id: menuItem
        implicitWidth: root.itemImplicitWidth
        implicitHeight: root.itemImplicitHeight
        arrow: Canvas {
            x: parent.width - width
            visible: menuItem.subMenu
            onPaint:
            {
                var ctx = getContext("2d")
                ctx.fillStyle = menuItem.highlighted ? "#ffffff" : "#568fe9"
                ctx.moveTo(15, 15)
                ctx.lineTo(width - 15, height / 2)
                ctx.lineTo(15, height - 15)
                ctx.closePath()
                ctx.fill()
            }
        }

        indicator:
            Onegamecontroller {
            id: indicator
            visible: true
            implicitWidth: menuItem.implicitHeight
            implicitHeight: menuItem.implicitHeight
            //anchors.leftMargin: 20
            Rectangle {
                anchors.fill: parent
                anchors.leftMargin: 5
                anchors.centerIn: parent
                color: menuItem.highlighted ?"#77a9ef":"#deeef9"
                Image {
                    id: image
                    anchors.centerIn: parent
                    height: root.itemIconSize
                    width: root.itemIconSize
                    source: menuItem.icon.source
                    fillMode: Image.PreserveAspectFit // For not stretching image (optional)
                }
            }
        }

        contentItem: Rectangle {
            anchors.leftMargin: (menuItem.checkable)?menuItem.indicator.width:5
            anchors.rightMargin:(hasIndicator)?menuItem.arrow.width:0
            color: menuItem.highlighted ?"#77a9ef": "#deeef9"
            //rightPadding:(hasIndicator)?menuItem.arrow.width:0
            Text {
                id:text
                anchors.top: parent.top
                anchors.left: parent.left//image.left
                anchors.bottom: parent.bottom
                anchors.leftMargin:(image.width>0)? indicator.implicitWidth  + 0 : 5 //ToDo
                text: menuItem.text
                font.family: "Times"
                font.pixelSize: root.itemFontSize //works
                //font.pointSize:15 //? does not work
                opacity: enabled ? 1.0 : 0.3
                color: menuItem.highlighted ? "#ffffff" : "black"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
        }

        background: Rectangle {
            implicitWidth: 200
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            color: menuItem.highlighted ? "#77a9ef": "#deeef9"
            //border.width:2
        }
    }

    background: Rectangle {
        implicitWidth: root.itemImplicitWidth
        implicitHeight: root.itemImplicitHeight
        color:"#ffffff"
        border.color: "#77a9ef"
        //radius: 2
    }
}
