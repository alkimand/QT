import QtQuick 2.12
import QtQuick.Controls 2.12

import "../../../Action"
import "../../../CommonElements/TabButton/MoneyCheker"
import "../../../Setting"
import "../../../CommonElements/OneRowItem/MoneyCheker"
import "../../../CommonElements/OneRowItem/RowLogic.js" as RowLogic


Item {
    id:root
    property Actions actions : parent.actions
    //property int radius : parent.actions
    Connections {
        target: button_1
        onActivateButton: {
            //console.log("button_1 Connections+")
            button_1.isActive=true;
            button_2.isActive=false;
            root.updateTabButton();
        }
    }

    Connections {
        target: button_2
        onActivateButton: {
            //console.log("button_2 Connections+")
            button_1.isActive=false;
            button_2.isActive=true;
            root.updateTabButton();
        }
    }

    TabButton_S {
        id:button_1;
        anchors.left: parent.left;
        anchors.top: parent.top;
        activeAction: parent.actions.tabButtonMortageActivate;
        disactiveAction:parent.actions.mainButtonFavorite;
        buttonTupe: SettingData.ButtonType.FIRST_BUTTON_TYPE;
    }


    TabButton_S {
        id:button_2;
        anchors.left:button_1.right;
        anchors.top: parent.top;
        activeAction: parent.actions.tabButtonMortageActivate;
        disactiveAction:parent.actions.mainButtonFavorite;
        buttonTupe: SettingData.ButtonType.LAST_BUTTON_TYPE;
    }

    //Rows
    Component {
        id:itemBorder
        Rectangle {

            height:settingData.oneRowItemSettings.oneRowItemBorderHeigh;
            color: settingData.columnSettings.columnFreeSpaceColor;
        }
    }

    OneRowItem_S {
        id:home_prise_row
        anchors.top:button_1.bottom
        anchors.left:button_1.left
        anchors.right:button_2.right
        value: 1210010
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//SettingData.DataType.CURRENCY_DATA_TYPE;
        textSecondLineType: RowLogic.DataType.PERSENT_DATA_TYPE;
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textFirstLine: "Home prise"

    }




    Loader {
        id:border_1
        sourceComponent: itemBorder
        anchors.top:home_prise_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:downpayment_row
        anchors.top:border_1.bottom
        anchors.left:parent.left
        //anchors.right:parent.right
        value: 20
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType: RowLogic.DataType.PERSENT_DATA_TYPE;
        textFirstLine: "Downpayment"
        textSecondLine: "2 297 22"
    }

    Loader {
        id:border_2
        sourceComponent: itemBorder
        anchors.top:downpayment_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:rate_row
        anchors.top:border_2.bottom
        anchors.left:parent.left
        value: 4.5
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:RowLogic.DataType.PERSENT_DATA_TYPE;
        textFirstLine: "Rate"
    }

    Loader {
        id:border_3
        sourceComponent: itemBorder
        anchors.top:rate_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:term_row
        anchors.top:border_3.bottom
        anchors.left:parent.left
        value: 100
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:RowLogic.DataType.YERS_DATA_TYPE;
        textFirstLine: "Term"
    }

    Loader {
        id:border_4
        sourceComponent: itemBorder
        anchors.top:term_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:taxes_row
        anchors.top:border_4.bottom
        anchors.left:parent.left
        value: 6911
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:RowLogic.DataType.CURRENCY_DATA_TYPE;
        textSecondLineType: RowLogic.DataType.PERSENT_DATA_TYPE
        textFirstLine: "Taxes"
        textSecondLine: "0.060"
    }

    Loader {
        id:border_5
        sourceComponent: itemBorder
        anchors.top:taxes_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:insurance_row
        anchors.top:border_5.bottom
        anchors.left:parent.left
        value: 126152
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:RowLogic.DataType.CURRENCY_DATA_TYPE;
        textFirstLine: "Insurance"
    }

    Loader {
        id:border_6
        sourceComponent: itemBorder
        anchors.top:insurance_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:omi_row
        anchors.top:border_6.bottom
        anchors.left:parent.left
        value: 0.1
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:RowLogic.DataType.PERSENT_DATA_TYPE;
        textFirstLine: "PMI"
    }
    //--border_1
    Loader {
        id:border_7
        sourceComponent: itemBorder
        anchors.top:omi_row.bottom//area_7
        anchors.left:parent.left
        anchors.right:parent.right
    }

//    OneRowItem_S {
//        id:start_date_row
//       anchors.top:border_7.bottom//border_7
//       // anchors.top:button_1.bottom
//        anchors.left:parent.left
//        value:1//{ return new Date().toLocaleDateString(Qt.locale("de_DE"),"dd.MM.yyyy")}
//        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT;
//        textType:RowLogic.DataType.DATE_DATA_TYPE;
//        textFirstLine: "Start date"
//    }

//    Loader {
//        id:border_8
//        sourceComponent: itemBorder
//        anchors.top:start_date_row.bottom
//        anchors.left:parent.left
//        anchors.right:parent.right
//    }

    OneRowItem_S {
        id:amortization_row
        anchors.top:border_7.bottom//border_8
       // anchors.top:button_1.bottom
        anchors.left:parent.left
        value: 1
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT;
        textType: RowLogic.DataType.YERS_DATA_TYPE;
        textFirstLine: "Amortization"
        hasBorder: SettingData.HasBorder.BOTTOM_BORDER

    }


    //Update TabButton
    function updateTabButton(){
        button_1.update();
        //console.log("button_1.update()");
        button_2.update();
        //console.log("button_2.update()");
    }


}



