import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: 640
    height: 480

    TableView {
        anchors.fill: parent

        model: someModel

        TableViewColumn {
            role: "check"
            title: "Check"
            delegate: CheckBox {
                checked: styleData.value
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        someModel.setRowChecked(styleData.row, !styleData.value)
                    }
                }
            }
        }
        TableViewColumn {
            role: "description"
            title: "Description"
        }
        TableViewColumn {
            role: "value"
            title: "Value"
        }

        headerDelegate: Item {
            height: textItem.implicitHeight

            Text {
                id: textItem
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: styleData.textAlignment
                text: styleData.value
            }
            CheckBox {
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 3
                property bool isPressed: styleData.pressed
                visible: styleData.column === 0
                onIsPressedChanged: {
                    if (isPressed) {
                        checked  = !checked
                        someModel.setAllChecked(checked)
                    }
                }
            }
        }
    }
}
