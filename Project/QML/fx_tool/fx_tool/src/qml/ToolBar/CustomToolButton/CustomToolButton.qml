import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQml 2.12
import "."
ToolButton {

    id: control
    text:""
    implicitHeight: tool_bar_grid_.cellHeight//mainToolBar.toolButtonImplicitHeight
    implicitWidth: tool_bar_grid_.cellWidth
     //mainToolBar.toolButtonImplicitWidth
    property int textHeight: 10//mainToolBar.toolButtonTextHeight
    property string textFont: "Arial Narrow"
    property string sourceIconPath: "qt-logo.png"
    property string  textFirstLine: "QT"
    property color buttonBackColor: "white"
    property int button_type :      1//parent.button_type
    property int table_id    :      ID
    contentItem: ToolButtonLoader{}

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        propagateComposedEvents: true
        preventStealing: true

        onEntered: {
            control.buttonBackColor = "#77a9ef"
        }

        onExited: {
            control.buttonBackColor = "white"
        }

        onClicked: {
            tool_bar_.pushTollBar(control.table_id)
            //control.action.triggered(control.table_id)
            //control.buttonBackColor = settingData.children[3].toolBarButtonIsNotSelectedColorSetting
        }
    }
    Component.onCompleted: {
        //console.log("ID=" + ID)
       // console.log("sourceIconPath = " + sourceIconPath)
    }
}
