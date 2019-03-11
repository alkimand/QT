import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item
{
    id: item1
    //id: item
    width: 640
    height: 480
    property alias item1: item1
    anchors.fill: parent
    anchors.centerIn: parent
    //property alias rowlayot: rowlayot
    //property alias button1: button1
    //property alias button2: button2
    RowLayout
    {
        anchors.bottomMargin: 0
        transformOrigin: Item.Center
        anchors.leftMargin: 0
        anchors.top: parent.verticalCenter
        anchors.right: parent.right
        anchors.left: parent.horizontalCenter
        anchors.topMargin: 0
        anchors.bottom: parent.verticalCenter
        //id: rowlayot
        //
        //Item { Layout.fillWidth: true }
        Item { Layout.fillWidth: true }
        Button
        {
            id:button1

        }
        Button
        {
            //x:button1.width + 200
            //id:button2
        }

        //anchors.centerIn: parent
        //anchors.verticalCenter : AnchorLine
        //        Button
        //        {
        //            id:button2
        //        }
    }

}
