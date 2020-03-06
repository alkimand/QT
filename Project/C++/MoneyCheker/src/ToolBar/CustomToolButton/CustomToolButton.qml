import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQml 2.12
import "."
//https://stackoverflow.com/questions/22752201/qml-timer-not-triggered-in-the-right-interval
ToolButton
{

    id: control
    // Layout.columnSpan: 1
    // Layout.rowSpan: 1
    //anchors.margins: 1
    // anchors.topMargin: 10
    text:""
    implicitHeight: mainToolBar.toolButtonImplicitHeight
    implicitWidth: mainToolBar.toolButtonImplicitWidth
    property int textHeight: mainToolBar.toolButtonTextHeight
    property string textFont: mainToolBar.toolButtonTextFont
    property string sourceIconPath: "qt-logo.png"
    property string  textFirstLine: "QT"
    property color buttonBackColor: settingData.children[3].toolBarButtonIsNotSelectedColorSetting
    contentItem:ToolButtonLoader{}

    MouseArea
    {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        propagateComposedEvents: true
        preventStealing: true

        onEntered:
        {
            control.buttonBackColor = settingData.children[3].toolBarButtonIsSelectedColorSetting
        }

        onExited:
        {
            control.buttonBackColor = settingData.children[3].toolBarButtonIsNotSelectedColorSetting
        }

        onClicked:
        {
            control.action.triggered()
            //control.buttonBackColor = settingData.children[3].toolBarButtonIsNotSelectedColorSetting
        }
    }



}
