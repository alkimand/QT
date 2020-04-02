import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12

import "../../../Action"

Item {

    id:root
    property Action action
    //anchors.leftMargin: 5
    width:settingData.buttonSettings.buttonWidth
    height:settingData.buttonSettings.buttonHeight //border
    //Component.onCompleted: console.log("Button:" + root.action.text)

    Button
    {


        id: control
        // Layout.columnSpan: 1
        //Layout.rowSpan: 1
        //anchors.margins: 1
        //  anchors.topMargin: 10
        //        text:""
        //property color buttonBackColor: settingData.buttonSettings.buttonIsNotSelectedColorSetting
        //implicitHeight: 100//settingData.buttonSettings.buttonHeight
        //implicitWidth: 100//settingData.buttonSettings.buttonWidth
        width: root.width
        height: root.height
        //color:settingData.buttonSettings.buttonIsNotSelectedColorSetting
        //        property int textHeight: mainToolBar.toolButtonTextHeight
        //        property string textFont: mainToolBar.toolButtonTextFont
        //        property string sourceIconPath: "qt-logo.png"
        //        property string  textFirstLine: "QT"
        //settingData.children[3].toolBarButtonIsNotSelectedColorSetting

        palette {
            button: settingData.columnSettings.columnFreeSpaceColor
        }

        contentItem: Rectangle
        {
            id:buttonReact
            color:settingData.buttonSettings.buttonIsNotSelectedColorSetting
            anchors.fill:parent
            //border.width: 1
            radius: settingData.buttonSettings.buttonRadius
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
                anchors.margins: settingData.buttonSettings.buttonMargin // Leaving space between image and borders (optional)
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
                buttonReact.color  = settingData.buttonSettings.buttonIsSelectedColorSetting
            }

            onExited:
            {
                buttonReact.color = settingData.buttonSettings.buttonIsNotSelectedColorSetting
            }

            onClicked:
            {
                //control.action.triggered()
                buttonReact.color = settingData.buttonSettings.buttonIsSelectedColorSetting
                action.trigger()
                //console.log("Button cliked")
            }
        }



    }
}
