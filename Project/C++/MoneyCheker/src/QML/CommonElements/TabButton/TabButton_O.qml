import QtQuick 2.12
import QtQuick.Controls 2.12
import BorderRadiusWidget.qml 1.0
import QtQml.StateMachine 1.12

import "../../Action"
import"../../Setting"
import "./TabButtonLabel"




Item {
    id:root
    //property Actions actions : parent.actions
    property Action activeAction
    property Action disactiveAction
    property color activeColor
    property color disactiveColor
    property color backgroundColor
    property color activeFontColor
    property color disactiveFontColor
    property int tabIconTextMargin
    property int iconTextMargin
    property int fontSize
    property int iconSize
    property string fontFamily
    property int  type
    property int radius
    property bool isActive: false
    property int buttonTupe: SettingData.ButtonType.FIRST_BUTTON_TYPE

    //to transfer up
    signal activateButton()
    signal disableButton()

    //use in this  class
    signal activate()
    signal disable()

    Rectangle {
        id:parentReact
        anchors.fill: parent
        // z:0
        BorderRadiusWidget {
            id:leftRadius
            anchors.left:parent.left
            anchors.leftMargin: root.radius
            anchors.topMargin: root.radius
            anchors.top:parent.top
            radius:root.radius
            activeButtonColor:root.activeColor
            z:2
        }

        Rectangle{
            id:leftRadiusReact
            width:root.radius
            height:root.radius
            anchors.left:parent.left
            anchors.top:parent.top
            z:1
        }

        Rectangle {
            id:leftReact

            anchors.right:leftRadius.right
            anchors.left:parent.left
            anchors.top: leftRadius.bottom
            anchors.bottom: bottomLeftRadius.bottom

        }

        BorderRadiusWidget {
            id:bottomLeftRadius
            anchors.left:parent.left
            anchors.leftMargin: root.radius
            anchors.bottomMargin: root.radius
            anchors.bottom:parent.bottom
            radius:root.radius
            transform: Rotation {
                origin.x: parentReact.x;
                origin.y: parentReact.y;
                angle: 270}
            z:2
        }

        Rectangle{
            id:bottomLeftRadiusReact
            width:root.radius
            height:root.radius
            anchors.left:parent.left
            anchors.bottom:parent.bottom
            z:1
        }

        Rectangle {
            id:centerReact
            width: (root.width - root.radius * 2);
            anchors.left:leftRadius.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            TabButtonLabel_O {
                activeAction:root.activeAction;
                disactiveAction:root.disactiveAction;//root.actions.mainButtonFavorite;
                activeColor: root.activeColor
                disactiveColor:root.disactiveColor
                activeFontColor:root.activeFontColor
                disactiveFontColor:root.disactiveFontColor
                marginTop:root.tabIconTextMargin
                iconTextMargin:root.iconTextMargin
                isActive:root.isActive
                fontSize:root.fontSize
                iconSize:root.iconSize
            }
        }

        BorderRadiusWidget {
            id:rightRadius
            anchors.right:parent.right
            anchors.rightMargin: root.radius
            anchors.topMargin: root.radius
            anchors.top:parent.top
            radius:root.radius
            transform: Rotation {
                origin.x: parentReact.x;
                origin.y: parentReact.y;
                angle: 90}
            z:2
        }

        Rectangle{
            id:rightRadiusReact
            width:root.radius
            height:root.radius
            anchors.right:parent.right
            anchors.top:parent.top
            z:1
        }
        Rectangle {
            id:rightReact
            width: root.radius
            anchors.right:parent.right
            anchors.top: rightRadius.bottom
            anchors.bottom: bottomRightRadius.top

        }

        BorderRadiusWidget {
            id:bottomRightRadius
            anchors.right:parent.right
            anchors.bottomMargin: root.radius
            anchors.rightMargin: root.radius
            anchors.bottom:parent.bottom
            radius:root.radius
            transform: Rotation {
                origin.x: parentReact.x;
                origin.y: parentReact.y;
                angle: 180
            }
            z:2
        }

        Rectangle{
            id:bottomRightRadiusReact
            width:root.radius
            height:root.radius
            anchors.right:parent.right
            anchors.bottom:parent.bottom
            z:1
        }

        StateMachine {
            id: stateMachine
            initialState: activeFirstButton
            running: true

            State {
                id: activeFirstButton
                SignalTransition {
                    targetState: disableFirstButton
                    signal: root.disable
                }
                onEntered: {
                    //console.log("activeFirstButton onEntered")
                    root.toActiveteState();
                    leftRadiusReact.color=root.backgroundColor;
                    bottomLeftRadiusReact.color=root.activeColor;
                    rightRadiusReact.color=root.disactiveColor;
                }
                // onExited: console.log("activeFirstButton onExited")
            }

            State {
                id: disableFirstButton
                SignalTransition {
                    targetState: activeFirstButton
                    signal: root.activate
                }

                onEntered: {
                    //console.log("disableFirstButton onEntered")
                    root.toDisableState();
                    leftRadiusReact.color=root.backgroundColor;
                    bottomLeftRadiusReact.color=root.disactiveColor;
                    rightRadiusReact.color=root.disactiveColor;
                    bottomRightRadius.activeButtonColor=root.disactiveColor;
                }
                // onExited: console.log("disableFirstButton exited")
            }

            State {
                id: activeLastButton
                SignalTransition {
                    targetState: disableLastButton
                    signal: root.disable
                }
                onEntered: {
                    //console.log("activeLastButton onEntered")
                    root.toActiveteState();
                    leftRadiusReact.color=root.disactiveColor;
                    bottomLeftRadiusReact.color=root.activeColor;
                    rightRadiusReact.color=root.backgroundColor;
                }
                // onExited: console.log("activeFirstButton onExited")
            }

            State {
                id: disableLastButton
                SignalTransition {
                    targetState: activeLastButton
                    signal: root.activate
                }
                onEntered: {
                    //console.log("disableLastButton onEntered")
                    root.toDisableState();
                    leftRadiusReact.color=root.disactiveColor;
                    bottomLeftRadiusReact.color=root.activeColor;
                    rightRadiusReact.color=root.backgroundColor;
                    bottomRightRadiusReact.color=root.disactiveColor;
                }
            }

            //            State {
            //                id: disableMidleButton
            //                initialState: activeLastButton//+-
            //                SignalTransition {
            //                    targetState: activeLastButton//+-
            //                    signal: mouseArea.clicked
            //                }
            //                onEntered: {
            //                    console.log("disableLastButton onEntered")
            //                    leftRadius.activeButtonColor=root.disactiveColor;
            //                    leftRadiusReact.color=root.backgroundColor;
            //                    leftReact.color=root.disactiveColor;
            //                    bottomLeftRadius.activeButtonColor=root.disactiveColor;
            //                    bottomLeftRadiusReact.color=root.disactiveColor;
            //                    centerReact.color=root.disactiveColor;
            //                    rightRadius.activeButtonColor=root.disactiveColor;
            //                    rightRadiusReact.color=root.disactiveColor;
            //                    rightReact.color=root.disactiveColor;
            //                    bottomRightRadius.activeButtonColor=root.disactiveColor;
            //                    bottomRightRadiusReact.color=root.activeColor;
            //                }
            //            }


            Component.onCompleted: {
                switch  (root.buttonTupe){
                case SettingData.ButtonType.FIRST_BUTTON_TYPE:
                    root.activateButton();
                    break;
                    //                case SettingData.ButtonType.MIDLE_BUTTON_TYPE:
                    //                    break;
                case SettingData.ButtonType.LAST_BUTTON_TYPE:
                    stateMachine.initialState = disableLastButton;
                    //root.disable();
                    break;

                default:
                    break;
                }
            }
        }
        MouseArea{
            id:mouseArea
            anchors.fill:parent
            onClicked: {
                //console.log("isActive="+root.isActive);
                if( !root.isActive) {
                    isActive = true;
                    //console.log("root.activateButton()");
                    root.activateButton() ;
                    root.forceActiveFocus()
                }
                // else { isActive = false;
                //console.log("MouseArea isActive already"); }
            }
        }
    }

    function update(){
        //console.log("in update()"+ root.buttonTupe);
        switch  (root.buttonTupe){
        case SettingData.ButtonType.FIRST_BUTTON_TYPE:
            if(root.isActive){
                root.activate();
            }
            else{
                //console.log("update disableFirstButton");
                root.disable();
            }
            break;
        case SettingData.ButtonType.MIDLE_BUTTON_TYPE:
            break;
        case SettingData.ButtonType.LAST_BUTTON_TYPE:
            if(root.isActive){
                root.activate();
            }
            else{
                root.disable();
            }
            break;

        default:
            break;
        }
    }

    function toDisableState(){
        leftRadius.activeButtonColor=root.disactiveColor;
        leftReact.color=root.disactiveColor;
        bottomLeftRadius.activeButtonColor=root.disactiveColor;
        centerReact.color=root.disactiveColor;
        rightRadius.activeButtonColor=root.disactiveColor;
        rightReact.color=root.disactiveColor;
        bottomRightRadius.activeButtonColor=root.disactiveColor;
        isActive = false;
    }

    function toActiveteState(){
        leftRadius.activeButtonColor=root.activeColor;
        leftReact.color=root.activeColor;
        bottomLeftRadius.activeButtonColor=root.activeColor;
        centerReact.color=root.activeColor;
        rightRadius.activeButtonColor=root.activeColor;
        rightReact.color=root.activeColor;
        bottomRightRadius.activeButtonColor=root.activeColor;
        bottomRightRadiusReact.color=root.activeColor;
        isActive = true;
    }

}
