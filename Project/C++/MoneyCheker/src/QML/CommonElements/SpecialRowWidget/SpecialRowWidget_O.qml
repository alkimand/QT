import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import"../../Setting"
import BorderRadiusWidget.qml 1.0
import "../OneRowItem/RowElements"
import "../OneRowItem/MoneyCheker"
import "../OneRowItem/RowLogic.js" as RowLogic



Item {
    id:root

    property int borderRadius : settingData.appContentWidgetSettings.borderRadius;
    property color topActiveColor:settingData.buttonSettings.buttonIsNotSelectedColorSetting;
    property color backgroundColor:settingData.appContentWidgetSettings.disactiveFontColor;
    property color activeButtonColor:"red"
    property color backgroundFontColor:"yellow"
    height: settingData.appContentWidgetSettings.buttonHeight

    //common
    //    property Item centerCustomWidget : Item{
    //        Rectangle{
    //            //anchors.fill: parent
    //            color:"red"
    //            height:10
    //            width:10
    //        }
    //    }

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
        id:home_prise_row
        anchors.top:topLeftRadius.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        //anchors.fill: parent
        rowItemHeight:settingData.appContentWidgetSettings.buttonHeight - settingData.appContentWidgetSettings.borderRadius;
        backgroundColor: root.topActiveColor;
       // paddingRight:settingData.elementsMortagePage.paddingRight;
        labelРighlightingFontColor:"black";
        value: 1210010
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//SettingData.DataType.CURRENCY_DATA_TYPE;
        textSecondLineType: RowLogic.DataType.STRING_DATA_TYPE;
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_TEXT_RIGHT_ALIGNEMENT;
        textFirstLine: "Monthly payment"
        textSecondLine: (RowLogic.valueToUserText ("test", RowLogic.DataType.STRING_DATA_TYPE))
    }

}





