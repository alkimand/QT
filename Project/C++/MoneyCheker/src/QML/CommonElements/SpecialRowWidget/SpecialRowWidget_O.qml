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
    anchors.fill:parent
    property int borderRadius : 15
    property color backgroundColor:"blue"
    property color activeButtonColor:"red"
    property color backgroundFontColor:"yellow"

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
        activeButtonColor:  root.backgroundColor
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
        color: root.backgroundFontColor
    }


//    Rectangle{
//        id:rect
//        anchors.top:parent.top
//        anchors.left:parent.left
//        anchors.right: parent.right
//        height:100
//        //width:100
//        color:"red"
//       // weidth:100

//    }

    OneRowItem_S {
        id:home_prise_row
        anchors.top:topLeftRadius.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        //anchors.fill: parent
        value: 1210010
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//SettingData.DataType.CURRENCY_DATA_TYPE;
        textSecondLineType: RowLogic.DataType.STRING_DATA_TYPE;
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_TEXT_RIGHT_ALIGNEMENT;
        textFirstLine: "Monthly payment"
        textSecondLine: (RowLogic.valueToUserText ("test", RowLogic.DataType.STRING_DATA_TYPE))
    }








}





