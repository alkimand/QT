import QtQuick 2.12
import QtQuick.Controls 2.12
//import "ButtonTemplate.qml"
import "../../../Action"




Item {
    id:root
    //Actions{id: actions} //toDo -> move as singleton
    property Actions actions : parent.actions
    //Actions{id: actions}

    Column
    {


       spacing: settingData.columnSettings.spaceBetweenButton

       ButtonTemplate { action: root.actions.mainButtonCalculate;}
       ButtonTemplate { action: root.actions.mainButtonFavorite;}
       ButtonTemplate { action: root.actions.mainButtonPercent;}
       ButtonTemplate { action: root.actions.mainButtonSetting;}
    }

   // Component.onCompleted: console.log(parent.test)
    //Component.onCompleted: console.log("Button_1:" + root.actions.fileOpenAction.text)
   // Component.onCompleted: console.log(actions.fileOpenAction.text)

   // test
}



