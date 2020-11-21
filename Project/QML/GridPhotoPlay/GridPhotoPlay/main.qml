import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Dialogs 1.2
//import QtQuick.Controls.Stylles 1.4

//import "src/qml/GridView"

import "src/qml/Scene"

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
//    Canvas{
//        id:canvas
//        anchors.fill: parent
//      //  width: parent.width
//          height: 200
//          onPaint: {
//              var ctx = getContext("2d");
//              ctx.fillStyle = Qt.rgba(1, 0, 0, 1);
//              ctx.fillRect(0, 0, width, height);
//          }

Column{
    id:column
    //anchors.left: parent.left
    //anchors.right: parent.right
    anchors.horizontalCenter: parent.horizontalCenter;

    property int screen_width: app_data.getScreenWidth();
    property int screen_height: app_data.getScreenHeight()
    width:screen_width +400
    DropWidget {
        id: drop_widget
        model_id:0
        anchors.horizontalCenter: parent.horizontalCenter;
        width: 1000//column.screen_width;
        height:1000//column.screen_height;
    }
    DraggedWidget{
        id: drag_widget
        model_id:0
        anchors.horizontalCenter: parent.horizontalCenter;
        width: 1000
        height:1000
    }

//    BaseTableView{
//        id: screen2
//        model_id:0
//        anchors.left: parent.left
//        anchors.right: parent.right
//        anchors.top: screen.bottom

//      //   anchors.fill: parent

//    }
}




//    GridViewWidget {
//       anchors.fill: parent
//       id:grid
//        //width: 320;
//        //height: 480
//       //model: app_data.getModelByID(0);
//       // columns:5
//       // model:  app_data.getModelByID(0);
//       //number of rows you the the grid to have
//        //rows: 5
//        cellWidth: main_root.width/5;
//        cellHeight: main_root.height/5;
//        cell_field_size: 0//15
//        Component.onCompleted: {
//            for (var i = 0 ;i < grid.count;++i) {
//                var gr = grid;
//                 var item_id = grid.itemAtIndex(i);
//                 var item_ = grid.itemAtIndex(0).item;
//                 var item3_ = grid.itemAtIndex(0);
//                //console.log("tab_view.current_id_="+ item_id)
//               // if (item_id == tool_bar_.current_id) {
//                  // console.log("removeTab i="+i)
//                   // tab_view.removeTab(i)
//              //  }
//              //  item_id.parent = canvas;//data(1).parent = = canvas
//               // item_id.

//                //if (tab_view.count > 0)
//            }
//        }
//    }

   // }
}
