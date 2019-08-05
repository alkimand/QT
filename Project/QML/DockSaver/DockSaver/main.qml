import QtQuick 2.13
import QtQuick.Window 2.13

import QtQuick.Controls 2.12
//import QtQml.Models 2.1
import QtQml.Models 2.13

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")
//}

//ApplicationWindow {
Window {
    id: mainWindow

    visible: true

    Rectangle {
        focus: true

        Keys.onBackPressed: {
            event.accepted = true
            backButton.clicked()
        }
    }

    property real downloadProgress: 0
    property bool imageLoading: false
    property bool editMode: false

    width: 800; height: 480; color: "#d5d6d8"

    ListModel {
        id: photosModel
        ListElement { tag: "Flowers" }
        ListElement { tag: "Wildlife" }
        ListElement { tag: "Prague" }
    }

}
