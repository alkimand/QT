import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

import Actions 1.0
import "./CustomToolButton"

ToolBar
{
    id: control
    width: parent.width
    //implicitHeight: grid_view_.height
    //height: 400
    focusReason : Qt.MouseFocusReason
    background: Rectangle  {
        anchors.fill:parent
        color: "white"
    }


    signal pushTollBar(real item_id)
//    Connections {
//        target: CustomToolButton
//        onPush: {
//           // tab_view.onTolBarButtonPush()
//    }

    onPushTollBar: {
        main_root.onTolBarButtonPush(item_id)
    }

    //ListView {
    GridView {
        id:tool_bar_grid_
        width: parent.width;
        cellHeight : 25
        cellWidth : 25
        //parent.height;
        //orientation : ListView.Horizontal
        model: app_data.model//100
        //snapMode:ListView.SnapOneItem
        delegate  :  CustomToolButton {
            property int button_type : 1
            action: Actions.pushTolBarButton
            table_id : ID
            sourceIconPath : icon_
        }
    }
//    Flow {
//        id:grid_view_
//        width: parent.width;
//
       //model:2

//        CustomToolButton {
//            action: Actions.fileOpenAction
//            table_id:1
//        }
      // CustomToolButton {action: Actions.fileSaveAction}
//        CustomToolButton {action: Actions.fileSaveAsAction}
//        CustomToolButton {action: Actions.closeAllAction}
       // CustomToolButton {action: Actions.addAction}
//        CustomToolButton {action: Actions.fileOpenAction}
//        CustomToolButton {action: Actions.fileSaveAction}
//        CustomToolButton {action: Actions.fileSaveAsAction}
//        CustomToolButton {action: Actions.closeAllAction}
//        CustomToolButton {action: Actions.addAction}
//        CustomToolButton {action: Actions.fileOpenAction}
//        CustomToolButton {action: Actions.fileSaveAction}
//        CustomToolButton {action: Actions.fileSaveAsAction}
//        CustomToolButton {action: Actions.closeAllAction}
//        CustomToolButton {action: Actions.addAction}
//        CustomToolButton {action: Actions.fileOpenAction}
//        CustomToolButton {action: Actions.fileSaveAction}
//        CustomToolButton {action: Actions.fileSaveAsAction}
//        CustomToolButton {action: Actions.closeAllAction}
        //}
        //        Rectangle {
        //            color: "#77a9ef"
        //            width: parent.width
        //            height: 1
        //            anchors.bottom: parent.bottom
        //        }


  //  }
    //    Rectangle {
    //        color: "#77a9ef"
    //        width: parent.width
    //        height: 1
    //        anchors.bottom: parent.bottom
    //    }

    Component.onCompleted: {
        //console.log("toolBar Completed count= " + app_data.model.rowCount())
    }
}

