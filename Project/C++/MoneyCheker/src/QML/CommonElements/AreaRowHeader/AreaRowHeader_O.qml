import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Settings 1.0
import BorderRadiusWidget.qml 1.0
import "../RoundRowPillow"
import "../OneRowItem/MoneyCheker"
import "../OneRowItem/RowLogic.js" as RowLogic

Item {
    id:root

    property int borderRadius //: Settings.appContentWidgetSettings.borderRadius;
    property color topActiveColor:Settings.buttonSettings.buttonIsNotSelectedColorSetting;
    property color backgroundColor: Settings.appContentWidgetSettings.disactiveFontColor;
    property color activeButtonColor:"red"
    property color backgroundFontColor:"yellow"
    property int rowTextBlockWidth
    property bool hasbottomBorder //: 4;
    property int itemBorderHeight : Settings.oneRowItemSettings.oneRowItemBorderHeigh;
    property bool isOpen : true
    property bool isAnimationInProgress : false

    property alias  value: header_row.value

    property alias  textFirstLine: header_row.textFirstLine

    //property int upperAnimationMargin : Settings.oneRowItemSettings.oneRowItemBorderHeigh;
    property int animationTime : 400
    //height: root.hasbottomBorder * Settings.oneRowItemSettings.rowItemHeight + Settings.appContentWidgetSettings.buttonHeight + (root.hasbottomBorder)* Settings.oneRowItemSettings.oneRowItemBorderHeigh + root.borderRadius;
    height: Settings.appContentWidgetSettings.buttonHeight
    //property ListModel userObjectModel

    signal dataChaned_Area(int type_, variant value_)

    Connections {
        target: root
        onDataChaned_Area: {
            //console.log("onDataChanged")
                header_row.value = root.value;
                header_row.textFirstLine=root.textFirstLine;
                header_row.dataChaned_Row(type_, value_);
           // console.log("root.value="+root.value)
            //}
        }
    }

    BorderRadiusWidget {
        id:topLeftRadius
        anchors.left:parent.left
        anchors.top:parent.top
        anchors.topMargin:root.borderRadius
        anchors.leftMargin: root.borderRadius
        radius: root.borderRadius
        activeButtonColor:  root.topActiveColor
        transform: Rotation {
            origin.x: 0;
            origin.y:0;
            angle: 0
        }
        z:2
    }

    Rectangle{
        id:topLeftRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        anchors.left:parent.left
        anchors.top:parent.top
        z:1
        color: root.backgroundColor
    }


    Rectangle{
        id:centerRect
        anchors.top:parent.top
        anchors.left:topLeftRadiusReact.right
        anchors.right: topRightRadiusReact.left
        height:root.borderRadius
        color: root.topActiveColor
    }


    BorderRadiusWidget {
        id:topRightRadius
        anchors.right:parent.right
        anchors.top:parent.top
        anchors.topMargin:root.borderRadius
        anchors.rightMargin: root.borderRadius
        radius: root.borderRadius
        activeButtonColor:  root.topActiveColor
        transform: Rotation {
            origin.x: root.x;
            origin.y: root.y;
            angle: 90}

        z:2
    }

    Rectangle{
        id:topRightRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        anchors.right:parent.right
        anchors.top:parent.top
        z:1
        color: root.backgroundColor
    }

    OneRowItem_S {
        id:header_row
        anchors.top:topLeftRadius.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        //anchors.fill: parent
        rowItemHeight:Settings.appContentWidgetSettings.buttonHeight - Settings.appContentWidgetSettings.borderRadius-root.itemBorderHeight;
        textBlockWidth: root.rowTextBlockWidth
        backgroundColor: root.topActiveColor;
        // paddingRight:Settings.elementsMortagePage.paddingRight;
        labelРighlightingFontColor:"black";
        //value: 99
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
        textSecondLineType: RowLogic.DataType.STRING_DATA_TYPE;
        type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_TEXT_RIGHT_ALIGNEMENT;
        //textFirstLine: root.textFirstLine
        textSecondLine: (RowLogic.valueToUserText ("test", RowLogic.DataType.STRING_DATA_TYPE))
    }

    Loader {
        id:border_1
        anchors.top:header_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    Component.onCompleted: {
        if (root.hasbottomBorder)
            border_1.sourceComponent = betwinRowItem
        else
            header_row.rowItemHeight = Settings.appContentWidgetSettings.buttonHeight - Settings.appContentWidgetSettings.borderRadius;
    }
}





