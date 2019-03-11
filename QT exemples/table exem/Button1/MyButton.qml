import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item
{
    //anchors.fill: parent
    Button
    {
        //anchors.fill: parent
        style: ButtonStyle
        {
            background: Rectangle
            {
                color: control.pressed ? "green" : "blue"
                border.color: control.pressed ? "black" : "green"
                border.width: 2
                radius: 5
                implicitWidth: 100
                implicitHeight: 25
                //gradient: Gradient
                //border.color: "#888"
                //{
                 //   GradientStop { color: control.pressed ? "#808000" : "#FF4500" }
                    //GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
               // }

            }
        }
        //onClicked: console.log("Button pressed")
        //onClicked: console.info("Button is: ", button1.)
    }

}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
