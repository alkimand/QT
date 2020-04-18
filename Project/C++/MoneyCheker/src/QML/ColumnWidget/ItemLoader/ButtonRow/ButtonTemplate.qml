import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12

import "../../../Action"
import Settings 1.0

Item {

    id:root
    property Action action
    //anchors.leftMargin: 5
    width:Settings.buttonSettings.buttonWidth
    height:Settings.buttonSettings.buttonHeight //border
    //Component.onCompleted: console.log("Button:" + root.action.text)

    Button
    {


        id: control
        // Layout.columnSpan: 1
        //Layout.rowSpan: 1
        //anchors.margins: 1
        //  anchors.topMargin: 10
        //        text:""
        //property color buttonBackColor: Settings.buttonSettings.buttonIsNotSelectedColorSetting
        //implicitHeight: 100//Settings.buttonSettings.buttonHeight
        //implicitWidth: 100//Settings.buttonSettings.buttonWidth
        width: root.width
        height: root.height
        //color:Settings.buttonSettings.buttonIsNotSelectedColorSetting
        //        property int textHeight: mainToolBar.toolButtonTextHeight
        //        property string textFont: mainToolBar.toolButtonTextFont
        //        property string sourceIconPath: "qt-logo.png"
        //        property string  textFirstLine: "QT"
        //Settings.children[3].toolBarButtonIsNotSelectedColorSetting

        palette {
            button: Settings.columnSettings.columnFreeSpaceColor
        }

        contentItem: Rectangle
        {
            id:buttonReact
            color:Settings.buttonSettings.buttonIsNotSelectedColorSetting
            anchors.fill:parent
            //border.width: 1
            radius: Settings.buttonSettings.buttonRadius
            //anchors.margins: 1

            //property string sourceIconPath: parent.sourceIconPathLoader
            Image
            {
                id: image
                source: root.action.icon.source
                fillMode: Image.PreserveAspectFit // For not stretching image (optional)
                // fillMode: Image.Stretch
                anchors.top: parent.top
                anchors.fill: parent
                anchors.margins: Settings.buttonSettings.buttonMargin // Leaving space between image and borders (optional)
            }
        }

        MouseArea
        {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            propagateComposedEvents: true
            preventStealing: true

            onEntered:
            {
                buttonReact.color  = Settings.buttonSettings.buttonIsSelectedColorSetting
            }

            onExited:
            {
                buttonReact.color = Settings.buttonSettings.buttonIsNotSelectedColorSetting
            }

            onClicked:
            {
                //control.action.triggered()
                buttonReact.color = Settings.buttonSettings.buttonIsSelectedColorSetting
                action.trigger()
                //console.log("Button cliked")
            }
        }



    }
}
