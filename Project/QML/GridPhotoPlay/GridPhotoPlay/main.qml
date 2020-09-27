import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

import "src/qml/GridView"

ApplicationWindow {
    id: main_root
    visible: true
    width: 500
    height: 800
    title: qsTr("GridPhotoPlay")

    GridViewWidget {
       anchors.fill: parent
        //width: 320;
        //height: 480
        columns: 4
       //number of rows you the the grid to have
        rows: 4
        cellWidth: main_root.width/4;
        cellHeight: main_root.height/4;
        cell_field_size: 15
    }
}
