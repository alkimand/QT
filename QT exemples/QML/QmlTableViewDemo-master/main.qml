import QtQuick 2.7
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4 as C1
import QtQuick.Window 2.2
import TableModel 0.1




Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    C1.TableView {
        anchors.fill: parent
        onClicked: {
            console.log("row: "+row);
        }

        //columnSpacing: 1
        //rowSpacing: 1
        C1.TableViewColumn
        {
            role: "name"
            title: "Name"
            width: 200

            horizontalAlignment: Text.AlignHCenter

        }
        C1.TableViewColumn
        {
            role: "age"
            title: "Age"
            width: 200
            horizontalAlignment : Text.AlignHCenter
            delegate : Component
            {
                Rectangle {
                    color: "red"
                    height: 100
                }

            }
        }
        rowDelegate: Rectangle
        {
            height: 70
            SystemPalette {
                id: myPalette
                colorGroup: SystemPalette.Active
                //height: 50
            }
            color:
            {
                var baseColor = styleData.alternate ?
                            myPalette.alternateBase
                          :myPalette.base;
                return styleData.selected ?
                            myPalette.highlight
                          :baseColor;
            }
        }

    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
