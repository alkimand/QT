import QtQuick 2.12
import QtQuick.Controls 2.12

//import "ButtonTemplate.qml"
import "../../../Action"
import "../../../CommonElements/TabButton"



Item {
    id:root
    property Actions actions : parent.actions
   //
   // anchors.fill:parent
//    Column
//    {
//ButtonTemplate { action: root.actions.mainButtonCalculate;}
//    Rectangle{
//       // anchors.left:parent.left
//        //anchors.right:parent.right
//        //anchors.top: parent.top
//        color:"red"
//        height:40
//        weight:10

//    }

//    }

  //  Column
   // {
//
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
        isActive:true
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
        isActive:false
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



