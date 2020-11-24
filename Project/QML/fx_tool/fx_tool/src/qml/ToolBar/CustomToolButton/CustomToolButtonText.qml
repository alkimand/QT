import QtQuick 2.0

Rectangle
{
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
        anchors.margins: 2 // Leaving space between text and borders  (optional)
        anchors.horizontalCenter: parent.horizontalCenter // Centering text
        renderType: Text.NativeRendering // Rendering type (optional)
    }
}
