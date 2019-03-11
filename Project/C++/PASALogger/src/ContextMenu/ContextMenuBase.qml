import QtQuick 2.12
//import QtQuick.Controls 1.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
//https://doc.qt.io/QT-5/qtquickcontrols2-customize.html#customizing-menu
import "./TabContextMenu"
Menu
{
    id:contextMenuBase
    //property color borderMoveAreaColor: settingData.children[5].tableViewhHederDelegatBorderMoveAreaColorSetting
   // property int itemImplicitWidth: settingData.children[7].contextMenuBaseImplicitWidthSetting
   // property int itemImplicitHeight: settingData.children[7].contextMenuBaseImplicitHeightSetting
    property color itemBorderColor:settingData.children[7].contextMenuBaseBorderColorSetting
    property string itemFontMenu:settingData.children[7].contextMenuBaseTextFontSetting
    property int itemFontSizeMenu:settingData.children[7].contextMenuBaseTextSizeSetting
    property int itemIconSize:settingData.children[7].contextMenuBaseIconSizeSetting
    property bool hasArrow: false
    property bool hasIndicator: false
    //title:"123"

    topPadding: 2
    bottomPadding: 2
    leftPadding: 2
    rightPadding: 2

    delegate: MenuItem
    {
        id: menuItem
        implicitWidth:settingData.children[7].contextMenuBaseImplicitWidthSetting
        implicitHeight: settingData.children[7].contextMenuBaseImplicitHeightSetting
        //font.pixelSize:itemFontSizeMenu
        arrow: Canvas
        {
            x: parent.width - width
            // implicitWidth: 40
            //implicitHeight: 40 see MenuItem.qml
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
            Item
        {
            id: indicator
            visible: true// false//--
            // anchors.centerIn: menuItem
            implicitWidth: menuItem.implicitHeight
            implicitHeight: menuItem.implicitHeight
            //anchors.leftMargin: 20
            Rectangle
            {
                anchors.fill: parent
                anchors.leftMargin: 5
                anchors.centerIn: parent
                color: menuItem.highlighted ?settingData.children[7].contextMenuBaseBorderColorSetting: settingData.children[7].contextMenuBaseItemColorSetting
                Image
                {
                    id: image
                    anchors.centerIn: parent
                    height: settingData.children[7].contextMenuBaseIconSizeSetting
                    width: settingData.children[7].contextMenuBaseIconSizeSetting
                    source: menuItem.icon.source
                    fillMode: Image.PreserveAspectFit // For not stretching image (optional)
                }
            }
        }

        contentItem: Rectangle
        {

            anchors.leftMargin: (menuItem.checkable)?menuItem.indicator.width:5
            anchors.rightMargin:(hasIndicator)?menuItem.arrow.width:0
            color: menuItem.highlighted ?settingData.children[7].contextMenuBaseBorderColorSetting: settingData.children[7].contextMenuBaseItemColorSetting
            //rightPadding:(hasIndicator)?menuItem.arrow.width:0

            Text
            {
                id:text
                anchors.top: parent.top
                anchors.left: parent.left//image.left
                anchors.bottom: parent.bottom
                anchors.leftMargin:(image.width>0)? indicator.implicitWidth  + 0 : 5 //ToDo

                // leftPadding: (menuItem.checkable)?menuItem.indicator.width:5
                // rightPadding:(hasIndicator)?menuItem.arrow.width:0
                text: menuItem.text
                font: settingData.children[7].contextMenuBaseTextFontSetting
                //font.pointSize:15 //?
                opacity: enabled ? 1.0 : 0.3
                color: menuItem.highlighted ? settingData.children[7].contextMenuBaseTextHighlightedColorSetting : settingData.children[7].contextMenuBaseTextNoHighlightedColorSetting
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
        }

        background: Rectangle
        {
            implicitWidth: 200
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            color: menuItem.highlighted ? settingData.children[7].contextMenuBaseBorderColorSetting: settingData.children[7].contextMenuBaseItemColorSetting
            //border.width:2
        }
    }

    background: Rectangle
    {
        implicitWidth: settingData.children[7].contextMenuBaseImplicitWidthSetting
        implicitHeight: settingData.children[7].contextMenuBaseImplicitHeightSetting
        color:settingData.children[7].contextMenuBorderColorSetting
        border.color: settingData.children[7].contextMenuBaseBorderColorSetting
        //radius: 2
    }
}
