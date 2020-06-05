import QtQuick 2.12
import QtQuick.Controls.Styles 1.4
//import QtQuick.Controls 1.4
//import QtQuick.Layouts 1.3
//import QtGraphicalEffects 1.0

//import "../Style"

TabViewStyle {
    //id:tab_view_Style
    tabOverlap:0
    tabsMovable :true

    //property string test:  "test tab_view_Style" //--

    tab: OneTabBaseStyle {}


    tabBar : Rectangle {
       // gradient: Gradient.PerfectBlue
        //border.width : 1
        //border.color : "red"
        color: "#dee1e6"
        z:0

        Rectangle {
            color: "#77a9ef"
            width: parent.width
            height: 1
            anchors.top: parent.top
            z:1
        }
          //  "black"

//        Rectangle {
//            color: "#dee1e6"
//            width: parent.width
//            height: 8
//            anchors.top: parent.top
//        }

        Rectangle {
            color: "white"
            width: parent.width
            height: 3
            anchors.bottom: parent.bottom
            z:1
        }


    }

//    Rectangle {
//        color: "blue"//"#77a9ef"
//        width: parent.width
//        height: 2
//        anchors.bottom: parent.top
//        z:1
//    }
}
