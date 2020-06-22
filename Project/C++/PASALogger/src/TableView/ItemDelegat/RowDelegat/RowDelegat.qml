import QtQuick 2.12
//https://www.qtcentre.org/threads/62320-qml-animated-height-in-tableview-row
Rectangle
{
    property int sizeOpen: 50
    property int sizeClosed: 30//tableView.heightSetting

    id: rowDelegate
    color:  "white"//:"red"//styleData.alternate ? "#7dade7" : "#1066cd"
    height: getSize() // styleData.selected? sizeOpen : sizeClosed
    border.width : (tableView.selectRow === styleData.row)? 2 : 0
    border.color: "white"//(tableView.selectRow === styleData.row) ? "red" : "black"
    function getSize()
    {
        if(!tableView.selection.contains(styleData.row))
        {
            doClose.start();
            return sizeClosed;
        }

        return sizeOpen;
    }

    MouseArea
    {
        id:rowDelegatMouseArea
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: sizeClosed
        propagateComposedEvents: true//false//
        preventStealing: true//false//
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked:
        {
            if (mouse.button === Qt.LeftButton)
            {
                if(rowDelegate.sizeOpen == rowDelegate.height)
                {
                    tableView.selection.deselect(styleData.row);
                    doClose.start()
                    if (styleData.row > -1)tableView.selectRow = styleData.row;
                }
                else
                {
                    tableView.selection.clear();
                    tableView.selection.select(styleData.row);
                    doOpen.start();
                    if (styleData.row > -1)tableView.selectRow = styleData.row;
                }
            }
            else   {
                itemContexMenu.popup()
            }
        }
        /*        onDoubleClicked:
            {
                //searchTextArea.moveCursorSelection(searchTextArea.positionAt(areaX, areaY),TextEdit.SelectCharacters)
                //textItemDelegate.forceActiveFocus()
                //console.debug("positionAt_" + rowDelegatMouseArea.mouseX+ "_" + rowDelegatMouseArea.mouseY )
                //console.debug("height:"+ rowDelegate.childAt(rowDelegatMouseArea.mouseX, rowDelegatMouseArea.mouseY).height)
                //console.debug("styleData.row:"+ rowDelegate.childAt(rowDelegatMouseArea.mouseX, rowDelegatMouseArea.mouseY).rowIndex)
                //console.debug("width:"+ rowDelegate.childAt(rowDelegatMouseArea.mouseX, rowDelegatMouseArea.mouseY).width)
            }*///tableView
    }

    ParallelAnimation
    {
        id: doOpen
        running: false
        NumberAnimation { target: rowDelegate; easing.type: Easing.OutSine; property: "height"; to: sizeOpen; duration: 100 }
    }
    ParallelAnimation
    {
        id: doClose
        running: false
        NumberAnimation { target: rowDelegate; easing.type: Easing.OutSine; property: "height"; to: sizeClosed; duration: 100; }
    }
}
