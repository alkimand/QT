import QtQuick 2.12
import QtQuick.Controls 2.4

Item
{
    id: itemSecond
    anchors.fill: parent
    clip: true
    Rectangle
    {
        id:itemDelegateRect
        anchors.fill: parent
        border.width:1
        border.color:"black"//(styleData.row===tableView.selectRow)?"#e200ff":"black"
        color :getRowColor() //(styleData.row % 2===0 && styleData.)?"#77a9ef":"white"//"#00ff17"
        Text
        {
            id:textItemDelegate
            //anchors.top: parent.top
            anchors.fill: parent
            //anchors.left: parent.left
            //anchors.right: parent.right
            anchors.leftMargin: 7
            text: styleData.value
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            //color: (styleData.row===tableView.selectRow)? "black" : "red"
            //color: (styleData.row % 2===0)? "black" : "#ebef77"
            color: "black"
            font.pointSize:(styleData.row===tableView.selectRow)? 12 : 8
        }
        MouseArea
        {
            acceptedButtons: Qt.RightButton | Qt.LeftButton
            propagateComposedEvents: true
            preventStealing: true//false
            anchors.fill: parent
            hoverEnabled: true
            //            onClicked:
            //            {
            //                if (mouse.button === Qt.RightButton)
            //                {
            //                console.debug("onClicked: ")
            //                //textItemDelegate.forceActiveFocus()
            //                //itemContexMenu.popup()

            //                }
            //            }
            onDoubleClicked:
            {
                //console.debug("Text : onDoubleClicked: "+item.row)
                //console.debug("styleData.row "+ styleData.row)
                //console.debug("tableView.selectRow "+ tableView.selectRow)
            }

        }
    }

    function getRowColor()
    {
        if (styleData.selected)
            return "#00C919";
        /// settingData.children[4].setting.tableViewhRowDelegatSelectColorSetting
        if (styleData.row % 2===0 )
            return "#77a9ef";
        else
            return "white";
    }
}
