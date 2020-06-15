import QtQuick 2.0

Rectangle {
    color: control.buttonBackColor
    anchors.fill: parent
    property string sourceIconPath: parent.sourceIconPathLoader
    Image {
        id: image
        source: "../../../images/ToolBarIcon/" + sourceIconPath
        fillMode: Image.PreserveAspectFit // For not stretching image (optional)
        anchors.top: parent.top
        anchors.fill: parent
        anchors.margins: 3 // Leaving space between image and borders (optional)
    }
}
