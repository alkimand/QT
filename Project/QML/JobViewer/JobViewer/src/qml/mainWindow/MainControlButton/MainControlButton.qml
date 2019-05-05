import QtQuick 2.12
import "../../Button"

Column {
    spacing: 20; anchors { bottom: parent.bottom; right: parent.right; rightMargin: 20; bottomMargin: 20 }

   UserButton {
        id: newButton; label: qsTr("Add"); rotation: 3
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            mainWindow.editMode = false
            photosModel.append( { tag: "" } )
            albumView.positionViewAtIndex(albumView.count - 1, GridView.Contain)
        }
    }
    UserButton {
        id: deleteButton; label: qsTr("Edit"); rotation: 1;
        onClicked: mainWindow.editMode = !mainWindow.editMode
        anchors.horizontalCenter: parent.horizontalCenter
    }
    UserButton {
        id: quitButton; label: qsTr("Quit"); rotation: -2;
        onClicked: Qt.quit()
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
