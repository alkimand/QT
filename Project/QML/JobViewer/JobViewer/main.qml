//import QtQuick 2.0
import QtQuick 2.12

import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQml.Models 2.12
import QtQml.Models 2.12


//import "./src/qml/Button"
import "./src/qml/mainWindow/MainControlButton"

ApplicationWindow {
    id:mainWindow

    visible: true
    property real downloadProgress: 0
    property bool imageLoading: false
    property bool editMode: false

    width: 800; height: 480; color: "#CCFFCC"

    title: qsTr("JobViewer")


//toDo
    ListModel {
        id: photosModel
        ListElement { tag: "Flowers" }
        ListElement { tag: "Wildlife" }
        ListElement { tag: "Prague" }
    }







//Block of Control ButtonGroup
MainControlButton{}

}
