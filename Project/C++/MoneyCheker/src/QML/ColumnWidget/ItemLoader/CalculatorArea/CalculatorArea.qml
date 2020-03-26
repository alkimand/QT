import QtQuick 2.12
import QtQuick.Controls 2.12

//import "ButtonTemplate.qml"
import "../../../Action"
import "../../../CommonElements/TabButton"
import "../../../Setting"



Item {
    id:root
    property Actions actions : parent.actions

    Connections {
        target: button_1
        onActivateButton: {
            //console.log("button_1 Connections+")
            button_1.isActive=true;
            button_2.isActive=false;
            root.update();
        }
    }

    Connections {
        target: button_2
        onActivateButton: {
            //console.log("button_2 Connections+")
            button_1.isActive=false;
            button_2.isActive=true;
            root.update();
        }
    }

    TabButton{
        id:button_1
        anchors.left:parent.left
        anchors.top: parent.top
        width: settingData.appContentWidgetSettings.contentCalculatoButtonWidth;
        height:settingData.appContentWidgetSettings.buttonHeight;
        radius:settingData.appContentWidgetSettings.borderRadius
        activeColor: settingData.buttonSettings.buttonIsSelectedColorSetting
        disactiveColor: settingData.buttonSettings.buttonIsNotSelectedColorSetting
        backgroundColor:settingData.columnSettings.columnFreeSpaceColor
        buttonTupe: SettingData.ButtonType.FIRST_BUTTON_TYPE
        // isActive:true
    }

    TabButton{
        id:button_2
        anchors.left:button_1.right
        anchors.top: parent.top
        width: settingData.appContentWidgetSettings.contentCalculatoButtonWidth;
        height:settingData.appContentWidgetSettings.buttonHeight;
        radius:settingData.appContentWidgetSettings.borderRadius
        activeColor: settingData.buttonSettings.buttonIsSelectedColorSetting
        disactiveColor: settingData.buttonSettings.buttonIsNotSelectedColorSetting
        backgroundColor:settingData.columnSettings.columnFreeSpaceColor
        buttonTupe: SettingData.ButtonType.LAST_BUTTON_TYPE

        //isActive:false
    }

    function update(){
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



