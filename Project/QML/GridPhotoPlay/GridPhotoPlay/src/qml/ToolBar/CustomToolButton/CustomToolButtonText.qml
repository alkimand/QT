import QtQuick 2.0
//import QtQuick.Controls 1.4
//import QtQuick.Controls 2.4

Rectangle
{
    //property string sourcePath: "../../images/ToolBarIcon/fileopen.png"
    property string sourceIconPath: parent.sourceIconPathLoader
    property string textFirstLine: parent.textFirstLineLoader
    property int textHeight: parent.textHeightLoader
    property string textFont: parent.textFontLoader
    color:control.buttonBackColor
    anchors.fill: parent
    Text
    {
        id: text
        text: parent.textFirstLine
        //anchors.top: image.bottom // Placing text in bottom
        font.family:textFont
        font.pointSize: textHeight
        //anchors.top: 2
        anchors.margins: 2 // Leaving space between text and borders  (optional)
        anchors.horizontalCenter: parent.horizontalCenter // Centering text
        renderType: Text.NativeRendering // Rendering type (optional)
    }
}
