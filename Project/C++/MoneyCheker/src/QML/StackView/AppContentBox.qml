import QtQuick 2.12
import QtQuick.Controls 2.12

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
//import "ItemLoader/ButtonRow"
//import "..ItemLoader/ButtonRow"
//import "../Action"

import "../ColumnWidget"
import "../Setting"
import "../Action"


Item{
    id:root

    anchors.top: parent.top
    anchors.bottom: parent.bottom

    StackView {
        id: stack
        initialItem: mainView
        anchors.left: parent.left
        anchors.top: root.top
        anchors.bottom: root.bottom

    }

    Component {
        id: mainView

        Item {
            id:mainViewItem
            anchors.fill: parent
            //anchors.left: stack.left

            ColumnWidget {

                id:column_1
                //anchors.left: mainViewItem.left
                width:100
                //anchors.left: column_1.right
                title:qsTr("Calculator")
                columnWidgetType: SettingData.ColumnWidgetType.BUTTON_SPACE
                //columnWidth:100
                //width: settingData.appContentWidgetSettings.contentCalculatorPageWidth;
                // rootReactClr:"red"
                actions: mainwindow.actions
               // Component.onCompleted: console.log(column_1.rootReactClr)
            }

//            ColumnWidget {
//                id: column_2
//                anchors.left: column_1.left
//                title:""
//                columnWidgetType: SettingData.ColumnWidgetType.EMPTY_SPACE
//                //columnWidth:50
//                width: 10;
//                rootReactClr:"red"
//                actions: mainwindow.actions
//            }

            Rectangle {
                id: rootReact
                color: "red"
               // anchors.top: mainViewItem.top
                anchors.left: column_2.left
                //anchors.bottom: mainViewItem.bottom
                width: 25
                height:10
                border.color: "yellow"
                border.width: 1
            }
        }
    }

}
