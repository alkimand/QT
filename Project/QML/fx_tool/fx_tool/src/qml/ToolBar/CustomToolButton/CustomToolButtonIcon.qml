import QtQuick 2.0

Rectangle {
    color: control.buttonBackColor
    anchors.fill: parent
    property string sourceIconPath: parent.sourceIconPathLoader
    Image {
        id: image
        source: sourceIconPath
        fillMode: Image.PreserveAspectFit // For not stretching image (optional)
        anchors.top: parent.top
        anchors.fill: parent
        anchors.margins: 2 // Leaving space between image and borders (optional)
    }
}
