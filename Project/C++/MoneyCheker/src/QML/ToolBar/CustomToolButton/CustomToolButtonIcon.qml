import QtQuick 2.0
//import QtQuick.Controls 1.4
//import QtQuick.Controls 2.4

Rectangle
{
    color:control.buttonBackColor
    anchors.fill:paren
    //property string sourceIconPath: parent.sourceIconPathLoader
    Image
    {
        id: image
        source: "../../images/ToolBarIcon/" + parent.sourceIconPath
        fillMode: Image.PreserveAspectFit // For not stretching image (optional)
        // fillMode: Image.Stretch
        anchors.top: parent.top
        anchors.fill: parent
        anchors.margins: 2 // Leaving space between image and borders (optional)
    }
}
