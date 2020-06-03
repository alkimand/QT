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

    property string test:  "test tab_view_Style" //--

    tab: OneTabBaseStyle {}

    tabBar : Rectangle {
        gradient: Gradient.PerfectBlue
        border.width : 1
        border.color : "black"
    }
}