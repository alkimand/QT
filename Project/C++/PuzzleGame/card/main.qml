import QtQuick
import QtQuick.Window
import QtQuick3D
//https://evileg.com/ru/post/280/ scaled
Window {
    id:root
    width: 250
    height: 250
    visible: true
    title: qsTr("mini card")
    property  int start_z :173
    property  int cursor_x_pasition :0
    property  int cursor_y_pasition :0
    property  double temp : 0
    property int previousX
    property int previousY
    property int minimum_rotate_delta:1
    property int x_max_rotation_angle: 45
    property int y_max_rotation_angle: 30
    property bool isAnimating:false

    Item{
        id:hover
        anchors.fill: parent
        MouseArea{
            id:mouse
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            hoverEnabled: true
            onClicked: {
                console.log("onClicked hover");
               //if (mouse.button === Qt.RightButton)
                console.log(" before = " + image_node.sceneRotation);
                 if(mouse.button & Qt.RightButton){
                     console.log("Qt.RightButton");
                    image_node.rotate(-10,Qt.vector3d(1,0,0),Node.ParentSpace)
                 }
//                    root.temp = root.temp - 0.1;
                else{
                     console.log("Qt.LeftButton");
                    image_node.rotate(10,Qt.vector3d(1,0,0),Node.ParentSpace)
                 }
//                    root.temp = root.temp + 0.1;

               // console.log("temp = " + root.temp);

              //  image_node.rotate(45,Qt.vector3d(0,250, 0),0)
                //image_node.position = Qt.vector3d(0, 150, 0)

                //image_node.position = Qt.vector3d(0,250, 0)
               // var ald_x = camera.eulerRotation.x - 0.1
               // camera.eulerRotation.x = ald_x;
               // start_z = start_z - 10
                //camera.position =  Qt.vector3d(0, 0, start_z)
               // console.log("start_z = " + start_z);
               // console.log(" = " + image_node.sceneRotation);

                //image_node.rotate(-10,Qt.vector3d(0,1,0),Node.ParentSpace)
                console.log(" after = " + image_node.sceneRotation);


            }
            onEntered: {
                //root.width = 400
               // root.height = 400

            }
            onExited: {
                //root.width = 200
                //root.height = 200
                var x_delta = mouseX - root.width/2;
                var y_delta = mouseY - root.height/2;
                var  x_rotation = x_delta / (root.width/2) * x_max_rotation_angle;
                var  y_rotation = y_delta / (root.height/2) * y_max_rotation_angle;
                //console.log('x_rotation = ',x_rotation)
                //if (minimum_rotate_delta > minimum_rotate_delta)
                    //image_node.sceneRotation = Qt.vector3d(0,1,0)
                  // image_node.rotate(x_rotation,Qt.vector3d(0,1,0),0)
              //  var curent_angle = 	parseInt(Math.acos(image_node.sceneRotation.y)* (180 / Math.PI))
                var curent_angle = 	(90 - Math.round(Math.acos(image_node.sceneRotation.y)* (180 / Math.PI))) * 2
                image_node.rotate(-curent_angle,Qt.vector3d(0,1,0),Node.ParentSpace)


            }
//            onMouseXChanged: {
//               console.log("onMouseXChanged " + mouseX);
//                var dx = mouseX - previousX
//                root.setX(root.x + dx)
//                root.setWidth(root.width - dx)
//            }

//            onPressed: {
//                previousX = mouseX
//            }
            onPositionChanged: {
                //console.log('mouse area 2 onPositionChanged');
                //console.log('Moved', mouseX, mouseY)
                //if ((mouseX - previousX) > minimum_rotate_delta){
                //previousX = mouseX
                //previousY = mouseY
                var x_delta = mouseX - root.width/2;
                var y_delta = mouseY - root.height/2;
                var  x_rotation = x_delta / (root.width/2) * x_max_rotation_angle;
                var  y_rotation = y_delta / (root.height/2) * y_max_rotation_angle;
                //console.log('y_rotation = ',y_rotation)
                //if (minimum_rotate_delta > minimum_rotate_delta)
                    //image_node.sceneRotation = Qt.vector3d(0,1,0)
                  // image_node.rotate(x_rotation,Qt.vector3d(0,1,0),0)
              //  var curent_angle = 	parseInt(Math.acos(image_node.sceneRotation.y)* (180 / Math.PI))
                var curent_x_angle = 	(90 - Math.round(Math.acos(image_node.sceneRotation.y)* (180 / Math.PI))) * 2
                var angle_dif = x_rotation - curent_x_angle
                if (Math.abs(angle_dif) > minimum_rotate_delta)
                    image_node.rotate(angle_dif,Qt.vector3d(0,1,0),Node.ParentSpace)
                //console.log('curent_x_angle = ',curent_x_angle)
            }


        }
    }
    View3D {
        id:view
        anchors.fill: parent
        environment: SceneEnvironment {
            clearColor: "#808080"
            backgroundMode: SceneEnvironment.Color
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

//        Model {
//            source: "#Rectangle"
//            z: -600
//            scale: Qt.vector3d(12, 1, 1)
//            materials: DefaultMaterial {
//                diffuseColor: Qt.rgba(0.8, 0.8, 0.6, 1.0)
//            }
//        }

        PerspectiveCamera {
            id: camera
            //property real cameraAnimation: 1
            //            SequentialAnimation on cameraAnimation {
            //                loops: Animation.Infinite
            //                NumberAnimation {
            //                    to: -1
            //                    duration: 5000
            //                    easing.type: Easing.InOutQuad
            //                }
            //                NumberAnimation {
            //                    to: 1
            //                    duration: 5000
            //                    easing.type: Easing.InOutQuad
            //                }
            //            }
            //position: Qt.vector3d(200 * cameraAnimation, 300, 500)
            position: Qt.vector3d(000, 000, start_z)//start_z)
            eulerRotation.x: 0//-20
            eulerRotation.y: 0//20*temp

        }
//        MouseArea{
//            anchors.fill: parent
//            onClicked: {
//                console.log("onClicked");
//            }
//        }

        //        MouseArea{
        //           anchors.fill: parent
        //            onClicked: {

        //                if (start_z > 0){
        //                var new_z = start_z - 100;
        //                console.log("onClicked z=" + new_z);
        //                start_z = new_z;
        //                }
        //                else
        //                   console.log("onClicked z<0");
        //            }
        //        }
        DirectionalLight {
            eulerRotation: Qt.vector3d(-135, -110, 0)
            brightness: 1
        }

        Node {
            id:image_node
            position: Qt.vector3d(0, 0, 0)//root.x/2
//            Rectangle {
//                anchors.fill: parent
//                opacity: 0.4
//                color: "#202020"
//                radius: 10
//                border.width: 2
//                border.color: "red"
//            }
            Item {

                id:image_root
               // anchors.fill: parent
                anchors.centerIn: parent
//visible: false
                //width: root.width//200
                 //width: {root.width}
                width: 200
                //root.width
                //height: root.height//200
                 //height: {root.height}
               height: 200
                //                Rectangle {
                //                    anchors.fill: parent
                //                    opacity: 0.4
                //                    color: "#202020"
                //                    radius: 10
                //                    border.width: 2
                //                    border.color: "#f0f0f0"
                //                }
                //                Text {
                //                    anchors.top: parent.top
                //                    anchors.topMargin: 10
                //                    anchors.horizontalCenter: parent.horizontalCenter
                //                    font.pixelSize: 20
                //                    color: "#e0e0e0"
                //                    style: Text.Raised
                //                    text: qsTr("Background Item")
                //                }
                Image {
                    id:image
                    anchors.fill: parent
                    anchors.centerIn: parent
                    //fillMode: Image.PreserveAspectFit
                    source:"Built_with_Qt_RGB_logo_vertical"


                }
                //                MouseArea{
                //                    anchors.fill: parent
                //                    onClicked: {

                //                        if (start_z > 0){
                //                            var new_z = start_z - 100;
                //                            console.log("onClicked z=" + new_z);
                //                            start_z = new_z;
                //                        }
                //                        else
                //                            console.log("onClicked z<0");
                //                    }
                //                }
            }
        }
        //! [background item]

        //! [circles item]
        //        Node {
        //            position: Qt.vector3d(0, 150, 100)
        //            SequentialAnimation on x {
        //                loops: Animation.Infinite
        //                NumberAnimation {
        //                    to: -200
        //                    duration: 1500
        //                    easing.type: Easing.InOutQuad
        //                }
        //                NumberAnimation {
        //                    to: 200
        //                    duration: 1500
        //                    easing.type: Easing.InOutQuad
        //                }
        //            }
        //            NumberAnimation on eulerRotation.z {
        //                loops: Animation.Infinite
        //                from: 0
        //                to: 360
        //                duration: 4000
        //                easing.type: Easing.InOutBack
        //            }
        //            Item {
        //                width: 400
        //                height: 400
        //                anchors.centerIn: parent
        //                // This allows rendering into offscreen surface and caching it.
        //                layer.enabled: true
        //                Rectangle {
        //                    x: 150
        //                    y: 100
        //                    width: 100
        //                    height: 100
        //                    radius: 50
        //                    color: "#80808020"
        //                    border.color: "black"
        //                    border.width: 2
        //                }
        //                Rectangle {
        //                    x: 90
        //                    y: 200
        //                    width: 100
        //                    height: 100
        //                    radius: 50
        //                    color: "#80808020"
        //                    border.color: "black"
        //                    border.width: 2
        //                }
        //                Rectangle {
        //                    x: 210
        //                    y: 200
        //                    width: 100
        //                    height: 100
        //                    radius: 50
        //                    color: "#80808020"
        //                    border.color: "black"
        //                    border.width: 2
        //                }
        //            }
        //        }
        //! [circles item]

        //! [text item]
        //        Node {
        //            position: Qt.vector3d(0, 80, 250)
        //            Text {
        //                anchors.centerIn: parent
        //                width: 300
        //                wrapMode: Text.WordWrap
        //                horizontalAlignment: Text.AlignJustify
        //                font.pixelSize: 14
        //                color: "#e0e0e0"
        //                style: Text.Raised
        //                text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod " +
        //                      "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim " +
        //                      "veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea " +
        //                      "commodo consequat."
        //                SequentialAnimation on opacity {
        //                    loops: Animation.Infinite
        //                    NumberAnimation {
        //                        to: 0
        //                        duration: 1500
        //                        easing.type: Easing.InOutQuad
        //                    }
        //                    NumberAnimation {
        //                        to: 1
        //                        duration: 1500
        //                        easing.type: Easing.InOutQuad
        //                    }
        //                }
        //            }
        //        }
        //! [text item]

        //! [wrecking ball model]
        //        Node {
        //            position: Qt.vector3d(0, 800, 0)
        //            SequentialAnimation on eulerRotation.x {
        //                loops: Animation.Infinite
        //                NumberAnimation {
        //                    to: 20
        //                    duration: 3500
        //                    easing.type: Easing.InOutQuad
        //                }
        //                NumberAnimation {
        //                    to: -20
        //                    duration: 3500
        //                    easing.type: Easing.InOutQuad
        //                }
        //            }
        //            Model {
        //                source: "#Cylinder"
        //                y: -300
        //                scale: Qt.vector3d(0.1, 6.1, 0.1)
        //                materials: DefaultMaterial {
        //                    diffuseColor: Qt.rgba(0.9, 0.9, 0.9, 1.0)
        //                }
        //            }
        //            Model {
        //                source: "#Sphere"
        //                y: -700
        //                scale: Qt.vector3d(2, 2, 2)
        //                materials: DefaultMaterial {
        //                    diffuseColor: Qt.rgba(0.4, 0.4, 0.4, 1.0)
        //                }
        //            }
        //        }
        //! [wrecking ball model]
    }

}
