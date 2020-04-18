import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Settings 1.0

Rectangle
{
    id:root
    property color activMainButtonColor
    property color activBackgroundButtonColor
    property color pressedMainButtonColor
    property color pressedBackgroundButtonColor
    property color hoveredButtonColor
    property int buttonSize// = 2*radius
    property int crossSize
    property int checkerSize
    property int checkerHeigh
    property int checkerMargin
    property int buttonBorderWidth
    property int oneRowItemBorderHeigh
    property int paddingRight
    property int type

    color:root.activBackgroundButtonColor
    anchors.topMargin: (root.height - root.buttonSize)/2
    anchors.bottomMargin: (root.height - root.buttonSize)/2
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.right: parent.right
    anchors.rightMargin: root.paddingRight

    width: root.buttonSize
    radius:root.buttonSize/2
    border.color: root.activMainButtonColor
    border.width:root.buttonBorderWidth
    property color dashColor: root.pressedBackgroundButtonColor

    Component{
        id:dash
        Rectangle{
            id:oneDash
            color:root.dashColor
            width: root.crossSize
            height: root.oneRowItemBorderHeigh
        }

    }

    Loader {
        id:dash_horizontal
        visible:false
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        sourceComponent: dash
    }

    Loader {
        id:dash_vertical
        visible:false
        sourceComponent: dash
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        transform: Rotation { origin.x: root.crossSize/2 ; origin.y: root.oneRowItemBorderHeigh/2; angle: 90}
    }

    Loader {
        id:dash_cross_left
        visible:false
        sourceComponent: dash
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: root.checkerSize
        height: root.checkerHeigh
        transform: Rotation { origin.x: root.checkerSize/2 - root.checkerHeigh/2 - (4 - root.checkerHeigh)  - root.checkerMargin;
            origin.y: root.checkerHeigh - 6 //6 = 0;
            angle: 45 }
    }

    Loader {
        id:dash_cross_right
        visible:false
        sourceComponent: dash
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: root.checkerSize
        height: root.checkerHeigh
        transform: Rotation { origin.x: root.checkerSize/2 + root.checkerHeigh/2 - (root.checkerHeigh - 4) + root.checkerMargin; //(root.checkerHeigh % 2);
            origin.y: root.checkerHeigh - 6//6=0
            angle: -45 }
    }


    states: [
        //        State {
        //            name: "s_clicked"
        //            PropertyChanges {
        //                target: root;
        //                color: root.activMainButtonColor;
        //            }
        //        },

        State {
            name: "s_pressed"
            PropertyChanges {
                target: root;
                color: root.activMainButtonColor;
                dashColor: root.pressedMainButtonColor;
            }
        },

        State {
            name: "s_hovered"
            PropertyChanges {
                target: root;
                border.color: root.hoveredButtonColor
                dashColor: root.hoveredButtonColor;
            }
        },

        State {
            name: "s_dashPressed"
            PropertyChanges {
                target: root;
                color: root.activBackgroundButtonColor;
                dashColor: root.pressedBackgroundButtonColor;
            }
        },

        State {
            name: "s_notActive"
            PropertyChanges {
                target: root;
                dashColor: root.pressedBackgroundButtonColor;
                border.color: root.activMainButtonColor
                color: root.activBackgroundButtonColor;
            }
        }

    ]

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        pressAndHoldInterval:100
        onPressed: {
            //console.log("+onPressed");
            switch (root.type)   {
            case Settings.BlueButtonType.PLUS :
            case Settings.BlueButtonType.MINUS :
                root.state = 's_pressed'
                break;
            case Settings.BlueButtonType.CHECK :
                root.state = 's_dashPressed'
            }
            //console.log("-onPressed");
            //
        }
        onReleased: {
        //console.log("+onReleased");
            root.state = 's_notActive'
            //send signal to finish
        }
        onExited: {
            root.state = 's_notActive'
        }
        onEntered: {
            root.state = 's_hovered'
        }
        onPressAndHold:{
             //console.log("+onPressAndHold");
            switch (root.type)   {
            case Settings.BlueButtonType.PLUS :
            case Settings.BlueButtonType.MINUS :
                root.state = 's_pressed'
                break;
            case Settings.BlueButtonType.CHECK :
                root.state = 's_dashPressed'
            }
        }
    }
//121334Settings.oneRowItemSettings.oneRowItemBorderHeigh


    Component.onCompleted: {
        switch (root.type)   {
        case Settings.BlueButtonType.PLUS :
            dash_horizontal.visible = true;
            dash_vertical.visible = true;
            break

        case Settings.BlueButtonType.MINUS :
            dash_horizontal.visible = true;
            break;

        case Settings.BlueButtonType.CHECK :
            dash_cross_left.visible = true;
            dash_cross_right.visible = true;
            break;

        }
    }

}


