import QtQuick 2.12
import QtQuick.Controls 2.12
import BorderRadiusWidget.qml 1.0
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
    property bool isActive:true
    // anchors.right:parent.right
    //anchors.top: parent.top

    //Actions{id: actions}
    Rectangle {
        id:parentReact
        color:root.backgroundColor
        anchors.fill: parent
       // z:0
        BorderRadiusWidget {
            id:leftRadius
            anchors.left:parent.left
            anchors.leftMargin: root.radius
            anchors.topMargin: root.radius
            anchors.top:parent.top
            radius:root.radius
            activeButtonColor:(root.isActive==true)?root.activeColor:root.disactiveColor


            z:2


        }

        Rectangle{
            id:leftRadiusReact
            color: (root.isActive==true)?root.backgroundColor:root.disactiveColor
            width:root.radius
            height:root.radius
            anchors.left:parent.left
            anchors.top:parent.top
            //anchors.bottomMargin: root.radius
            z:1
        }

        Rectangle {
            id:leftReact
            color:(root.isActive==true)?root.activeColor:root.disactiveColor
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
            activeButtonColor:(root.isActive==true)?root.activeColor:root.disactiveColor
            transform: Rotation { origin.x: parentReact.x; origin.y: parentReact.y; angle: 270}
            z:2
        }

//        Rectangle{
//            id:bottomLeftRadiusReact
//            color:root.activeColor
//            width:root.radius
//            height:root.radius
//            anchors.left:parent.left
//            anchors.bottom:parent.bottom
//            //anchors.bottomMargin: root.radius
//            z:1
//        }

//        Rectangle {
//            id:centerReact
//            width: (root.width - root.radius * 2);
//            anchors.left:leftRadius.left
//            color:(root.isActive===true)?root.activeColor:root.disactiveColor
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//        }

//        BorderRadiusWidget {
//            id:rightRadius
//            anchors.right:parent.right
//            anchors.rightMargin: root.radius
//            anchors.topMargin: root.radius
//            anchors.top:parent.top
//            radius:root.radius
//            activeButtonColor:(root.isActive===true)?root.activeColor:root.disactiveColor
//            transform: Rotation { origin.x: parentReact.x; origin.y: parentReact.y; angle: 90}
//            z:2
//        }

//        Rectangle{
//            id:rightRadiusReact
//            color:(root.isActive===true)?root.disactiveColor:root.activeColor
//            width:root.radius
//            height:root.radius
//            anchors.right:parent.right
//            anchors.top:parent.top
//            z:1
//        }
//        Rectangle {
//            id:rightReact
//            width: root.radius
//            color:(root.isActive===true)?root.activeColor:root.disactiveColor
//            anchors.right:parent.right
//            anchors.top: rightRadius.bottom
//            anchors.bottom: bottomRightRadius.top

//        }

//        BorderRadiusWidget {
//            id:bottomRightRadius
//            anchors.right:parent.right
//            anchors.bottomMargin: root.radius
//            anchors.rightMargin: root.radius
//            anchors.bottom:parent.bottom
//            radius:root.radius
//            activeButtonColor:(root.isActive===true)?root.activeColor:root.disactiveColor
//            transform: Rotation { origin.x: parentReact.x; origin.y: parentReact.y; angle: 180}
//            z:2
//        }

        MouseArea{
            anchors.fill:parent
            onClicked: {
                if( !root.isActive){

                }
                root.isActive?root.isActive = false:root.isActive = true;
                console.log(root.isActive);
            }
        }
    }



}
