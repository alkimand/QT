import QtQuick 2.12
import QtQuick.Controls 2.12

//import "ButtonTemplate.qml"
import "../../Action"
import "../../CommonElements/TabButton"
import "../../Setting"
import "../../CommonElements/OneRowItem"


Item {
    id:root
    property Actions actions : parent.actions

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

    TabButton{
        id:button_1;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: settingData.appContentWidgetSettings.contentCalculatoButtonWidth;
        height: settingData.appContentWidgetSettings.buttonHeight;
        radius: settingData.appContentWidgetSettings.borderRadius;
        activeAction: parent.actions.tabButtonMortageActivate;
        disactiveAction:parent.actions.mainButtonFavorite;
        activeColor: settingData.buttonSettings.buttonIsSelectedColorSetting;
        disactiveColor: settingData.buttonSettings.buttonIsNotSelectedColorSetting;
        activeFontColor: settingData.appContentWidgetSettings.activeFontColor;
        disactiveFontColor:settingData.appContentWidgetSettings.disactiveFontColor;
        tabIconTextMargin: settingData.appContentWidgetSettings.iconMarginTop;
        iconTextMargin:settingData.appContentWidgetSettings.tabiconTextMargin;
        fontSize:settingData.appContentWidgetSettings.fontSize;
        iconSize:settingData.appContentWidgetSettings.iconSize;
        fontFamily:settingData.appContentWidgetSettings.tabFontFamily;
        backgroundColor:settingData.columnSettings.columnFreeSpaceColor;
        buttonTupe: SettingData.ButtonType.FIRST_BUTTON_TYPE;
        // isActive:true
    }

    TabButton{
        id:button_2;
        anchors.left:button_1.right;
        anchors.top: parent.top;
        width: settingData.appContentWidgetSettings.contentCalculatoButtonWidth;
        height: settingData.appContentWidgetSettings.buttonHeight;
        radius: settingData.appContentWidgetSettings.borderRadius;
        activeAction: parent.actions.tabButtonMortageActivate;
        disactiveAction:parent.actions.mainButtonFavorite;
        activeColor: settingData.buttonSettings.buttonIsSelectedColorSetting;
        disactiveColor: settingData.buttonSettings.buttonIsNotSelectedColorSetting;
        activeFontColor: settingData.appContentWidgetSettings.activeFontColor;
        disactiveFontColor:settingData.appContentWidgetSettings.disactiveFontColor;
        tabIconTextMargin: settingData.appContentWidgetSettings.iconMarginTop;
        iconTextMargin:settingData.appContentWidgetSettings.tabiconTextMargin;
        fontSize:settingData.appContentWidgetSettings.fontSize;
        iconSize:settingData.appContentWidgetSettings.iconSize;
        fontFamily:settingData.appContentWidgetSettings.tabFontFamily;
        backgroundColor:settingData.columnSettings.columnFreeSpaceColor;
        buttonTupe: SettingData.ButtonType.LAST_BUTTON_TYPE;
    }



    OneRowItem {
        id:areaItem

        //anchors
        anchors.top:button_1.bottom
        anchors.left:parent.left
        //anchors.right:parent.right

        //common
        commonFontFamily: settingData.oneRowItemSettings.commonFontFamily;
        backgroundColor: settingData.oneRowItemSettings.backgroundColor;
        rowItemWidth: settingData.appContentWidgetSettings.contentCalculatorPageWidth;
        rowItemHeight:settingData.oneRowItemSettings.rowItemHeight;
        rowMargin:settingData.oneRowItemSettings.rowMargin;
        paddingLeft:settingData.oneRowItemSettings.paddingLeft;
        paddingRight:settingData.oneRowItemSettings.paddingRight;
        type:SettingData.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT
        textRowSpacing: settingData.oneRowItemSettings.textRowSpacing;

        //textLine
        textBlockWidth:settingData.oneRowItemSettings.textBlockWidth;
        textFirstLineFontColor:settingData.oneRowItemSettings.textFirstLineFontColor;
        textSecondLineFontColor: settingData.oneRowItemSettings.textSecondLineFontColor;
        textFirstLineTopMargin: settingData.oneRowItemSettings.textFirstLineTopMargin;
        textFirstLineFontSize:settingData.oneRowItemSettings.textFirstLineFontSize;
        textSecondLineFontSize:settingData.oneRowItemSettings.textSecondLineFontSize;
        textFirstLine:"Home prise"
        textSecondLine:""

        //Label

        labelFontColor:settingData.oneRowItemSettings.labelFontColor;
        labelРighlightingFontColor:settingData.oneRowItemSettings.labelРighlightingFontColor;
        labelFontSize:settingData.oneRowItemSettings.labelFontSize;
        labelBorderColorWidth:settingData.oneRowItemSettings.labelBorderColorWidth;
        labelLeftPadding:settingData.oneRowItemSettings.labelLeftPadding;
        labelMargins:settingData.oneRowItemSettings.labelMargins;


        //Button
        activMainButtonColor:settingData.oneRowItemSettings.activMainButtonColor;
        activBackgroundButtonColor:settingData.oneRowItemSettings.activBackgroundButtonColor;
        pressedMainButtonColor:settingData.oneRowItemSettings.pressedMainButtonColor;
        pressedBackgroundButtonColor:settingData.oneRowItemSettings.pressedBackgroundButtonColor;
        buttonSize:settingData.oneRowItemSettings.buttonSize;// = 2*radius
        crossSize:settingData.oneRowItemSettings.crossSize;
        checkerSize:settingData.oneRowItemSettings.checkerSize;
        checkerMargin:settingData.oneRowItemSettings.checkerMargin;
        buttonBorderWidth:settingData.oneRowItemSettings.buttonBorderWidth;
        oneRowItemBorderHeigh:settingData.oneRowItemSettings.oneRowItemBorderHeigh;
        checkerHeigh:settingData.oneRowItemSettings.checkerHeigh;
    }

    Rectangle {
        id: border_1
        width:settingData.appContentWidgetSettings.contentCalculatorPageWidth;
        height:settingData.oneRowItemSettings.oneRowItemBorderHeigh;
        color:settingData.columnSettings.columnFreeSpaceColor;
        anchors.left:areaItem.left
        anchors.top:areaItem.bottom
    }









    //UPDATE TabButton
    function updateTabButton(){
        button_1.update();
        //console.log("button_1.update()");
        button_2.update();
        //console.log("button_2.update()");
    }


    //    TabButton{
    //        anchors.left:button_1.right
    //        anchors.top: parent.top
    //       activeColor: "red"
    //    }


    //    Rectangle{
    //        id:qw
    //                anchors.left:button_1.right
    //                //anchors.right:parent.right
    //                anchors.top: parent.top
    //                color:"red"
    //                height:40

    //                width:200

    //            }

    //    Rectangle{
    //                anchors.left:qw.right
    //                //anchors.right:parent.right
    //                anchors.top: parent.top
    //                color:"blue"
    //                height:40

    //                width:200

    //            }


    //       spacing: settingData.columnSettings.spaceBetweenButton

    //       ButtonTemplate { action: root.actions.mainButtonCalculate;}
    //       ButtonTemplate { action: root.actions.mainButtonFavorite;}
    //       ButtonTemplate { action: root.actions.mainButtonPercent;}
    //       ButtonTemplate { action: root.actions.mainButtonSetting;}
    // ButtonTemplate { actions: actions.buttonSettings;}


    // ButtonTemplate { actions: actions.fileOpenAction}
    //ButtonTemplate { actions: actions.downloadAction}
    // ButtonTemplate{actions: root.actions}
    //        CustomToolButton{action: actions.downloadAction}

    // }


    // Component.onCompleted: console.log(parent.test)
    //Component.onCompleted: console.log("Button_1:" + root.actions.fileOpenAction.text)
    // Component.onCompleted: console.log(actions.fileOpenAction.text)

    // test
}



