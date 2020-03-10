import QtQuick 2.12
//import QtQuick.Controls 1.4 as C1
//import"../TableView/TableView"
//import QtQuick.Controls 2.4
//https://stackoverflow.com/questions/34410260/trouble-setting-activefocus-to-item-in-a-qml-tabview
//https://switch-case.ru/61977594 -selection
//import TableModel 1.0
//import "../TableView/"
//import "../TabView/Style"
//import "../TabView/Style/Tab"
//import "../TableView/ItemDelegat/HeaderDelegate"
//import "../TableView/TableView" as MyTable
import "ItemLoader/ButtonRow"
//import "..ItemLoader/ButtonRow"
import "../Action"

Item {

    id:root
    property string title//:text_.text
    property int columnWidth//:text_.text
    //property int titleBlockHeight :200//:text_.text
    property Actions actions

    anchors.top:parent.top
    anchors.bottom:parent.bottom
    Rectangle{

        color: settingData.columnSettings.columnFreeSpaceColor
        anchors.top:parent.top
        anchors.bottom:parent.bottom

       // anchors.bottom:parent.bottom
        //width: childrenRect.width
        //height: childrenRect.height


        width: columnWidth
        //height: text_.height + loader_.height
        //color: "red"
        border.color: "black"
        border.width: 2
        //radius: 0
        //width: 240

        Text {
            id:text_
            anchors.top:parent.top
            //text: ""
            height: settingData.columnSettings.titleBlockHeight
            font.family: "Helvetica"
            font.pointSize: 20
            color: "black"
            text:title
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }


//        Item {
//            id:root_
//            //Actions{id: actions} //toDo -> move as singleton
//            property Actions actions
//            //Actions{id: actions}

//            Column
//            {


//               spacing: settingData.columnSettings.spaceBetweenButton

//               ButtonTemplate { action: root.actions.fileOpenAction;}
//              // ButtonTemplate { actions: actions.buttonSettings;}


//              // ButtonTemplate { actions: actions.fileOpenAction}
//               //ButtonTemplate { actions: actions.downloadAction}
//               // ButtonTemplate{actions: root.actions}
//        //        CustomToolButton{action: actions.downloadAction}

//            }
//        }







        Loader
        {
            id: loader_
            //anchors.margins: 4
            //height: calc(parent.height - text_.height)
            anchors.top: text_.bottom
            anchors.bottom:parent.bottom
            property Actions actions: root.actions
            //property int test:10
            //actions: root.actions
            source:"../ColumnWidget/ItemLoader/ButtonRow/ButtonRow.qml"
            //visible: false

            //Component.onCompleted: console.log("loader_:" + loader_.actions.fileOpenAction.text)













            property string type: "NONE"
            //Component.onCompleted: console.log(loader_.height)

            function setTable(name)
            {

                loader.source = ""
                //console.log("name:" + name)
                switch (name)
                {
                case "UDP logger" :
                    console.log("UDP logger")
                    source= "../TableView/TableView/TableUDP.qml"

                    break
                case "Text logger" :
                    console.log("Text logger")
                    source= "../TableView/TableView/TableText.qml"

                    break
                }
                //  tabView.getTab(contexMenuIndex).title = tabView.getTab(contexMenuIndex).title + ".txt"
            }
        }

    }
}
