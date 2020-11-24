import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ItemDelegate {
    id:root
    property string placeholderText: placeholderText_L
    Rectangle {
        id: rect
        anchors.fill:parent
        border.width: 1
        border.color: "#4385ef"
        color:"white"
        CheckBox {
            id: control
            checked: (display_==="1")?true:false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.fill:parent

            indicator: Rectangle {
                implicitWidth: 26
                implicitHeight: 26
                x: control.leftPadding
                y: parent.height / 2 - height / 2
                radius: 3
                border.color:"#4385ef"

                Rectangle {
                    width: 14
                    height: 14
                    x: 6
                    y: 6
                    radius: 2
                    color: "#4385ef"
                    visible: control.checked
                }
            }
            onClicked : {
                var value = display_
                if (value==="1")
                    value = "0"
                else
                    value = "1"
                edite = value
            }
        }
    }
}
