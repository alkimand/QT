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
    width: 800
    height: 800
    title: qsTr("GridPhotoPlay")

//    TableView {
//        anchors.fill: parent
//        columnSpacing: 1
//        rowSpacing: 1
//        clip: true

//        model:  app_data.getModelByID(0);

//        delegate: Rectangle {
//            implicitWidth: 30
//            implicitHeight: 30
//            Text {
//                text: display
//            }
//        }

//    }
//    Image {
//        width: 150;
//        height: 150
//        id: img
//        source: "image://pixmap_id/1_1"
//        visible: true
//    }

    GridViewWidget {
       anchors.fill: parent
        //width: 320;
        //height: 480
       //model: app_data.getModelByID(0);
        columns:5
       // model:  app_data.getModelByID(0);
       //number of rows you the the grid to have
        rows: 5
        cellWidth: main_root.width/5;
        cellHeight: main_root.height/5;
        cell_field_size: 0//15
    }
}
