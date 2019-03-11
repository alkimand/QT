import QtQuick 2.0
import QtQuick.Controls 1.4
//https://stackoverflow.com/questions/5021350/how-do-you-assign-a-qml-item-to-a-component-property-in-qml-and-then-use-that-ob
//https://evileg.com/ru/forum/topic/466/
//Item {
   // anchors.fill: parent

    TableViewColumn {
        property int ident
        property int dat
        role: (ident===1)?"time":"date"   // Эти роли совпадают с названиями ролей в C++ модели
        title: (ident===1)?"Time":"Date"
        horizontalAlignment :Text.AlignRight
        dat:1

       // delegate: Text {

         //text:(ident===1)?"time":"date"

     //   }

//             color: "transparent"
//             anchors.fill: parent
//             Rectangle {
//                 anchors.verticalCenter: parent.verticalCenter
//                 height: 100
//                 width: 450
//                 //color: "white"
//             }




}
        //delegate:Delegat{}








//    TableViewColumn {
//        role: "time"    // Эти роли совпадают с названиями ролей в C++ модели
//        title: "Time"
//        horizontalAlignment :Text.AlignRight
//    }


//    TableViewColumn {
//        role: "random"  // Эти роли совпадают с названиями ролей в C++ модели
//        title: "Random"
//        horizontalAlignment :Text.AlignRight
//    }

//    TableViewColumn {
//        role: "message" // Эти роли совпадают с названиями ролей в C++ модели
//        title: "Message"
//        horizontalAlignment :Text.AlignRight
//    }

//}
