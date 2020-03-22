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
import "../StackView/Pages"


Item{
    id:root

    StackView {
        id: stack
        initialItem: mainView

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
       // Component.onCompleted: stack.push(mainView_)

    }
    CalkPage{id:mainView }
    //CalkPage{id:mainView_ }

}
