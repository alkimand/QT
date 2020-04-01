import QtQuick 2.12
import QtQuick.Controls 2.12

import "../../Action"
import "../../CommonElements/TabButton/MoneyCheker"
import "../../Setting"
import "../../CommonElements/OneRowItem/MoneyCheker"

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

    //Rows
    TabButton_S {
        id:button_2;
        anchors.left:button_1.right;
        anchors.top: parent.top;
        activeAction: parent.actions.tabButtonMortageActivate;
        disactiveAction:parent.actions.mainButtonFavorite;
        buttonTupe: SettingData.ButtonType.LAST_BUTTON_TYPE;
    }

    OneRowItem_S {
        id:area_1
        anchors.top:button_1.bottom
        anchors.left:parent.left
        value: 130
        textType:SettingData.DataType.CURRENCY_DATA_TYPE;
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textFirstLine: "Home prise"

    }


    Component {
        id:itemBorder
        Rectangle {

            height:settingData.oneRowItemSettings.oneRowItemBorderHeigh;
            color: settingData.columnSettings.columnFreeSpaceColor;
        }
    }

    Loader {
        id:border_1
        sourceComponent: itemBorder
        anchors.top:area_1.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_2
        anchors.top:border_1.bottom
        anchors.left:parent.left
        value: 20
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:SettingData.DataType.PERSENT_DATA_TYPE
        textFirstLine: "Downpayment"
        textSecondLine: "2 297 22"
    }

    Loader {
        id:border_2
        sourceComponent: itemBorder
        anchors.top:area_2.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_3
        anchors.top:border_2.bottom
        anchors.left:parent.left
        value: 4.5
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:SettingData.DataType.PERSENT_DATA_TYPE
        textFirstLine: "Rate"
    }

    Loader {
        id:border_3
        sourceComponent: itemBorder
        anchors.top:area_3.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_4
        anchors.top:border_3.bottom
        anchors.left:parent.left
        value: 100
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:SettingData.DataType.YERS_DATA_TYPE
        textFirstLine: "Term"
    }

    Loader {
        id:border_4
        sourceComponent: itemBorder
        anchors.top:area_4.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_5
        anchors.top:border_4.bottom
        anchors.left:parent.left
        value: 6911
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:SettingData.DataType.CURRENCY_DATA_TYPE
        textSecondLineType: SettingData.DataType.PERSENT_DATA_TYPE;
        textFirstLine: "Taxes"
        textSecondLine: "0.060"
    }

    Loader {
        id:border_5
        sourceComponent: itemBorder
        anchors.top:area_5.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_6
        anchors.top:border_5.bottom
        anchors.left:parent.left
        value: 126152
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:SettingData.DataType.CURRENCY_DATA_TYPE
        textFirstLine: "Insurance"
    }

    Loader {
        id:border_6
        sourceComponent: itemBorder
        anchors.top:area_6.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_7
        anchors.top:border_6.bottom
        anchors.left:parent.left
        value: 0.1
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
        textType:SettingData.DataType.PERSENT_DATA_TYPE
        textFirstLine: "PMI"
    }
    //--border_1
    Loader {
        id:border_7
        sourceComponent: itemBorder
        anchors.top:area_7.bottom//area_7
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_8
        anchors.top:border_7.bottom//border_7
        anchors.left:parent.left
        value: "07.2020"
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_LABEL_ONLY_LEFT_LABEL_ALIGNEMENT;
        textType:SettingData.DataType.DATE_DATA_TYPE
        textFirstLine: "Start date"
    }

    Loader {
        id:border_8
        sourceComponent: itemBorder
        anchors.top:area_8.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id:area_9
        anchors.top:border_8.bottom//border_8
        anchors.left:parent.left
        value: 1
        type: SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT;
        textType:SettingData.DataType.YERS_DATA_TYPE
        textFirstLine: "Amortization"
        hasBorder:SettingData.HasBorder.BOTTOM_BORDER
    }


    //UPDATE TabButton
    function updateTabButton(){
        button_1.update();
        //console.log("button_1.update()");
        button_2.update();
        //console.log("button_2.update()");
    }


}



