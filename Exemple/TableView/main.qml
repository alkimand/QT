import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    C1.TabView{
        anchors.fill: parent
        C1.Tab
        {
            id: tab1
            title: "Tab_1"
            Rectangle
            {
                width: tab1.width
                height: tab1.height
                color: "red"
            }
        }
        C1.Tab
        {
            id: tab2
            title: "Tab_2"
            Rectangle
            {
                width: tab2.width
                height: tab2.height
                color: "blue"
            }
        }
        C1.Tab
        {
            id: tab3
            title: "Tab_3"
            Rectangle
            {
                width: tab3.width
                height: tab3.height
                color: "green"
            }
        }
    }
}
