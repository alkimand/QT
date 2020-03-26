import QtQuick 2.12
import QtQuick.Controls 2.12
import BorderRadiusWidget.qml 1.0
import QtQml.StateMachine 1.12
//import "ButtonTemplate.qml"
import "../../Action"
import"../../Setting"




Item {
    id:root
    //Actions{id: actions} //toDo -> move as singleton
    property Actions actions : parent.actions
    property color activeColor
    property color disactiveColor
    property color backgroundColor
    property int radius
    property bool isActive: false
    property int buttonTupe: SettingData.ButtonType.FIRST_BUTTON_TYPE

    // anchors.right:parent.right
    //anchors.top: parent.top


    signal activateButton()
    signal disableButton()

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
            //color: (root.isActive==true)?root.backgroundColor:root.disactiveColor
            width:root.radius
            height:root.radius
            anchors.left:parent.left
            anchors.top:parent.top
            //anchors.bottomMargin: root.radius
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
            //activeButtonColor:(root.isActive==true)?root.activeColor:root.disactiveColor
            transform: Rotation { origin.x: parentReact.x; origin.y: parentReact.y; angle: 270}
            z:2
        }

        Rectangle{
            id:bottomLeftRadiusReact
            //color:root.activeColor
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
            //color:(root.isActive===true)?root.activeColor:root.disactiveColor
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }

        BorderRadiusWidget {
            id:rightRadius
            anchors.right:parent.right
            anchors.rightMargin: root.radius
            anchors.topMargin: root.radius
            anchors.top:parent.top
            radius:root.radius
            //activeButtonColor:(root.isActive===true)?root.activeColor:root.disactiveColor
            transform: Rotation { origin.x: parentReact.x; origin.y: parentReact.y; angle: 90}
            z:2
        }

        Rectangle{
            id:rightRadiusReact
            //color:(root.isActive===true)?root.disactiveColor:root.activeColor
            width:root.radius
            height:root.radius
            anchors.right:parent.right
            anchors.top:parent.top
            z:1
        }
        Rectangle {
            id:rightReact
            width: root.radius
            //color:(root.isActive===true)?root.activeColor:root.disactiveColor
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
            //activeButtonColor:(root.isActive===true)?root.activeColor:root.disactiveColor
            transform: Rotation { origin.x: parentReact.x; origin.y: parentReact.y; angle: 180}
            z:2
        }

        Rectangle{
            id:bottomRightRadiusReact
            //color:(root.isActive===true)?root.disactiveColor:root.activeColor
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
                initialState: disableFirstButton
                SignalTransition {
                    targetState: disableFirstButton
                    signal: root.disable
                }
                onEntered: {
                    //console.log("activeFirstButton onEntered")
                    leftRadius.activeButtonColor=root.activeColor;
                    leftRadiusReact.color=root.backgroundColor;
                    leftReact.color=root.activeColor;
                    bottomLeftRadius.activeButtonColor=root.activeColor;
                    bottomLeftRadiusReact.color=root.activeColor;
                    centerReact.color=root.activeColor;
                    rightRadius.activeButtonColor=root.activeColor;
                    rightRadiusReact.color=root.disactiveColor;
                    rightReact.color=root.activeColor;
                    bottomRightRadius.activeButtonColor=root.activeColor;
                    bottomRightRadiusReact.color=root.activeColor;
                    isActive = true;
                }
                // onExited: console.log("activeFirstButton onExited")
            }

            State {
                id: disableFirstButton
                initialState: activeFirstButton
                SignalTransition {
                    targetState: activeFirstButton
                    signal: root.activate

                }

                onEntered: {
                    //console.log("disableFirstButton onEntered")
                    leftRadius.activeButtonColor=root.disactiveColor;
                    leftRadiusReact.color=root.backgroundColor;
                    leftReact.color=root.disactiveColor;
                    bottomLeftRadius.activeButtonColor=root.disactiveColor;
                    bottomLeftRadiusReact.color=root.disactiveColor;
                    centerReact.color=root.disactiveColor;
                    rightRadius.activeButtonColor=root.disactiveColor;
                    rightRadiusReact.color=root.disactiveColor;
                    rightReact.color=root.disactiveColor;
                    bottomRightRadius.activeButtonColor=root.disactiveColor;
                    bottomRightRadiusReact.color=root.activeColor;
                    isActive = false;
                }
                // onExited: console.log("disableFirstButton exited")
            }

            State {
                id: activeLastButton
                initialState: disableLastButton
                SignalTransition {
                    targetState: disableLastButton
                    signal: root.disable
                }
                onEntered: {
                    //console.log("activeLastButton onEntered")
                    leftRadius.activeButtonColor=root.activeColor;
                    leftRadiusReact.color=root.disactiveColor;
                    leftReact.color=root.activeColor;
                    bottomLeftRadius.activeButtonColor=root.activeColor;
                    bottomLeftRadiusReact.color=root.activeColor;
                    centerReact.color=root.activeColor;
                    rightRadius.activeButtonColor=root.activeColor;
                    rightRadiusReact.color=root.backgroundColor;
                    rightReact.color=root.activeColor;
                    bottomRightRadius.activeButtonColor=root.activeColor;
                    bottomRightRadiusReact.color=root.activeColor;
                    isActive = true;
                }
                // onExited: console.log("activeFirstButton onExited")
            }

            State {
                id: disableLastButton
                initialState: activeLastButton
                SignalTransition {
                    targetState: activeLastButton
                    signal: root.activate//mouseArea.clicked //root.activateButton
                }
                onEntered: {
                    //console.log("disableLastButton onEntered")
                    leftRadius.activeButtonColor=root.disactiveColor;
                    leftRadiusReact.color=root.disactiveColor;
                    leftReact.color=root.disactiveColor;
                    bottomLeftRadius.activeButtonColor=root.disactiveColor;
                    bottomLeftRadiusReact.color=root.activeColor;
                    centerReact.color=root.disactiveColor;
                    rightRadius.activeButtonColor=root.disactiveColor;
                    rightRadiusReact.color=root.backgroundColor;
                    rightReact.color=root.disactiveColor;
                    bottomRightRadius.activeButtonColor=root.disactiveColor;
                    bottomRightRadiusReact.color=root.disactiveColor;
                    isActive = false;
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
                    stateMachine.initialState = activeFirstButton;
                    break;
//                case SettingData.ButtonType.MIDLE_BUTTON_TYPE:
//                    stateMachine.initialState = disableMidleButton;
//                    break;
                case SettingData.ButtonType.LAST_BUTTON_TYPE:
                    stateMachine.initialState = disableLastButton;
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
                }
               // else{}
                  //console.log("MouseArea isActive already");
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
                 console.log("update disableFirstButton");
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

}
