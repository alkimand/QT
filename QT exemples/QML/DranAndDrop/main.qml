import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 400
    title: qsTr("Hello World")

    Rectangle
    {
        width: 400
        height: 400
        color: "#000000"

        Component
        {
            id: dndDelegate

            Item
            {
                id: wrapper
                width: dndGrid.cellWidth
                height: dndGrid.cellHeight
                Image
                {
                    id: itemImage
                    source: imagePath
                    anchors.centerIn: parent
                    width: 90
                    height: 90
                    smooth: true
                    fillMode: Image.PreserveAspectFit
                    states: [
                        State
                        {
                            name: "inDrag"
                            when: index == dndGrid.draggedItemIndex
                            PropertyChanges { target: itemImage; parent: dndContainer }
                            PropertyChanges { target: itemImage; anchors.centerIn: undefined }
                            PropertyChanges { target: itemImage; x: coords.mouseX - itemImage.width / 2 }
                            PropertyChanges { target: itemImage; y: coords.mouseY - itemImage.height / 2 }
                        }
                    ]

                }
            }
        }

        ListModel
        {
            id: dndModel
            ListElement { imagePath: "images/1.jpg" }
            ListElement { imagePath: "images/2.jpg" }
            ListElement { imagePath: "images/3.jpg" }

            ListElement { imagePath: "images/4.jpg" }
            ListElement { imagePath: "images/5.jpg" }
            ListElement { imagePath: "images/6.jpg" }

            ListElement { imagePath: "images/7.jpg" }
            ListElement { imagePath: "images/8.jpg" }
            ListElement { imagePath: "images/9.jpg" }
            //Еще 15 картинок
        }

        GridView
        {
            id: dndGrid
            property int draggedItemIndex: -1
            interactive: false
            anchors.fill: parent
            anchors.margins: 9
            cellWidth: 120
            cellHeight: 120
            model: dndModel
            delegate: dndDelegate
            Item
            {
                id: dndContainer
                anchors.fill: parent
            }

            MouseArea
            {
                id: coords
                anchors.fill: parent
                onReleased:
                {
                    if (dndGrid.draggedItemIndex != -1)
                    {
                        var draggedIndex = dndGrid.draggedItemIndex
                        dndGrid.draggedItemIndex = -1
                        dndModel.move(draggedIndex,dndGrid.indexAt(mouseX, mouseY),1)
                    }
                }
                onPressed:
                {
                    dndGrid.draggedItemIndex = dndGrid.indexAt(mouseX, mouseY)
                }
            }
        }
    }

}
