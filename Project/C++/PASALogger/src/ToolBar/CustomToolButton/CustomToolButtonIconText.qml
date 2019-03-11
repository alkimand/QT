import QtQuick 2.12
import QtQuick.Layouts 1.3
Rectangle
{
    id:control
    property string sourceIconPath: parent.sourceIconPathLoader
    property string textFirstLine: parent.textFirstLineLoader
    property int textHeight: parent.textHeightLoader
    property string textFont: parent.textFontLoader
    property color buttonBackColor: parent.buttonBackColorLoader
    color:control.buttonBackColor
    anchors.fill:parent

    Image
    {
        id: image
        anchors.topMargin: 10
        height:  mainToolBar.toolButtonIconHeight
        width: mainToolBar.toolButtonIconHeight
        source: sourceIconPath //"../../images/ToolBarIcon/" + parent.parent.sourceIconPath
        fillMode: Image.PreserveAspectFit // For not stretching image (optional)
        anchors.horizontalCenter: control.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Text
    {
        id: text
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: control.horizontalCenter
        text: textFirstLine//parent.parent.textFirstLine
        font.family :textFont
        font.pointSize:  control.textHeight
        Layout.fillHeight: true
        Layout.fillWidth: true
        horizontalAlignment : Text.AlignHCenter
        renderType: Text.NativeRendering // Rendering type (optional)
    }
}
