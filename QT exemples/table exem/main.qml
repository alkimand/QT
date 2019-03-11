import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 1000
    height: 800
    title: qsTr("Demo_Logger_01")

        TableView {
            id : tableView
            anchors.fill: parent
            model: myModel
//                    TableViewColumn {
//                        role: "date"    // Эти роли совпадают с названиями ролей в C++ модели
//                        title: "Date"
//                        horizontalAlignment :Text.AlignRight
//                    }
            focus: true



            MyColumn
            {
                id: date
                role: "date"  // Эти роли совпадают с названиями ролей в C++ модели
                title:"1"
                ident:1
            }
            MyColumn
            {
                id:time
                role: "time"  // Эти роли совпадают с названиями ролей в C++ модели
                title:"2"
            }
            MyColumn
            {
                id:random
                role: "random"  // Эти роли совпадают с названиями ролей в C++ модели
                title:"3"
            }
            MyColumn
            {
                id:message
                role: "message"  // Эти роли совпадают с названиями ролей в C++ модели
                title:"4"
            }

            //Component.onCompleted: console.log("1")

//            itemDelegate: Item {
//                //Rectangle{
//                Text {
//                    anchors.verticalCenter: parent.verticalCenter
//                    color: styleData.textColor
//                    elide: styleData.elideMode
//                    text: (styleData.column===0)?styleData.value:""
//                    Component.onCompleted: console.log("styleData.column= " + styleData.column)
//                    //lineHeight:2
//                }
//            //}
//            }

////                TableViewColumn {
////                    role: "time"    // Эти роли совпадают с названиями ролей в C++ модели
////                    title: "Time"
////                    horizontalAlignment :Text.AlignRight
////                }
//            }


    //        TableViewColumn {
    //            role: "random"  // Эти роли совпадают с названиями ролей в C++ модели
    //            title: "Random"
    //            horizontalAlignment :Text.AlignRight
    //        }

    //        TableViewColumn {
    //            role: "message" // Эти роли совпадают с названиями ролей в C++ модели
    //            title: "Message"
    //            horizontalAlignment :Text.AlignRight
    //        }


    //MyColumn{}
    //property var za : 1500
    //readonly property int modelRow2:60
    //rowDelegate:  RowDelegat{}

    //        function myQmlFunction(msg) {
    //            console.log("Got message:", msg);
    //            return "some return value"
    //            //loginPage.visible = false;
    //        }

    //tableView.onLoginOk:0
    //     function setRowHeight(x)
    //    {
    //          tableView.rowDelegate = Rectangle
    //          {

    //               height = x
    //SystemPalette {
    //id: myPalette;
    //colorGroup: SystemPalette.Active
    //}
    //          }

    //           rowDelegate: Rectangle {

    //               height: 80
    //               SystemPalette {
    //                  id: myPalette;
    //                  colorGroup: SystemPalette.Active
    //             }

    //               color: {
    //                  var baseColor = styleData.alternate?myPalette.alternateBase:myPalette.base
    //                  return styleData.selected?myPalette.highlight:baseColor
    //               }
    //  }
    //       }
    //        rowDelegate: Rectangle {
    //          // height: 80
    //           SystemPalette {
    //              id: myPalette;
    //              colorGroup: SystemPalette.Active
    //           }

    //           color: {
    //              var baseColor = styleData.alternate?myPalette.alternateBase:myPalette.base
    //              return styleData.selected?myPalette.highlight:baseColor
    //           }
    //       }
    // Устанавливаем модель в TableView

    // }

//    Rectangle {
//        width: 360
//        height: 360

//        ListModel {
//            id: dataModel

//            ListElement {
//                color: "orange"
//                text: "first"
//            }
//            ListElement {
//                color: "lightgreen"
//                text: "second"
//            }
//            ListElement {
//                color: "orchid"
//                text: "third"
//            }
//            ListElement {
//                color: "tomato"
//                text: "fourth"
//            }
//        }

//        ListView {
//            id: view
//            //ListModel   {}
//            anchors.margins: 10
//            anchors.fill: parent
//            spacing: 10
//            // model: dataModel
//            model: ListModel
//            clip: true

//            highlight: Rectangle {
//                color: "skyblue"
//            }
//            highlightFollowsCurrentItem: true

//            delegate: Item {
//                id: listDelegate

//                property var view: ListView.view
//                property var isCurrent: ListView.isCurrentItem

//                width: view.width
//                height: 40

//                Rectangle {
//                    anchors.margins: 5
//                    anchors.fill: parent
//                    radius: height / 2
//                    color: model.color
//                    border {
//                        color: "black"
//                        width: 1
//                    }

//                    Text {
//                        anchors.centerIn: parent
//                        renderType: Text.NativeRendering
//                        text: "%1%2".arg(model.text).arg(isCurrent ? " *" : "")
//                    }

//                    MouseArea {
//                        anchors.fill: parent
//                        onClicked: view.currentIndex = model.index
//                    }
//                }
//            }
//        }
//    }


}

}
