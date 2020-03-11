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
Item{

    StackView {
        id: stack
        initialItem: mainView
        anchors.fill: parent

    }

    Component {
        id: mainView

        Row {
            spacing: 10

            Button {
                text: "Push"
                onClicked: stack.push(mainView)
            }
            Button {
                text: "Pop"
                enabled: stack.depth > 1
                onClicked: stack.pop()

            }
            Text {
                text: stack.depth
            }
        }
    }
}
