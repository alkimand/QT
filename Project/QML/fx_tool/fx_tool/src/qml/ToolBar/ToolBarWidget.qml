import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

import Actions 1.0
import "./CustomToolButton"

ToolBar {
    id: control
    width: parent.width
    property int current_id: -1
    //implicitHeight: grid_view_.height
    height: 30
    focusReason : Qt.MouseFocusReason
    background: Rectangle  {
        anchors.fill:parent
        color: "white"
    }

    signal pushTollBar(real item_id)
    signal pushTollBarRightButon(real item_id)

    onPushTollBar: {
        main_root.onTolBarButtonPush(item_id)
    }

    onPushTollBarRightButon: {
        main_root.onTolBarButtonPush(item_id)
    }

    //ListView {
    GridView {
        id:tool_bar_grid_
        width: parent.width;
        cellHeight : 30
        cellWidth : 30
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

    Component.onCompleted: {
        //console.log("toolBar Completed count= " + app_data.model.rowCount())
    }
}

