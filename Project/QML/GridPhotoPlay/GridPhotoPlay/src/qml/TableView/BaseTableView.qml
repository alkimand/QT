import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

import AbstractTableItemData 1.0
import AppDataProvider 1.0


import "./ItemDelegate/Loaders"

//import "../ItemDelegat/HeaderDelegate"
//import "../ItemDelegat/RowDelegat"
//import "../../ContextMenu/TableViewContexMenu/HeaderContexMenu"
//import "../../ContextMenu/TableViewContexMenu/ItemContexMenu"
//import "../"
//import "../ItemDelegat/HeaderDelegate"

import "./ItemDelegate/ItemDelegate"

TableView {
    id:table_view
    property  string current_id_: parent.current_id_
    property  int view_id_: parent.view_id_
    anchors.fill: parent
    columnSpacing: 0
    rowSpacing: 0
    clip: true
   // highlightRangeMode: ListView.StrictlyEnforceRange
    leftMargin:0
    rightMargin:0
    topMargin:10
    bottomMargin: 5
    contentWidth : main_root.width
    flickableDirection  :   Qt.Vertical
    property var columnWidths: [80, 300, 40]
    columnWidthProvider: function (column) { return getWith(column) }
    rowHeightProvider :  function (row) { return 35}
    signal refreshModel()
   // atYBeginning: false
    //flickDeceleration :5
    //contentY :100
    //horizontalOvershoot :40
    //boundsBehavior  : Flickable.OvershootBounds
  //boundsMovement : Flickable.DragAndOvershootBounds
    //verticalOvershoot :10
    model: app_data.getModelByID(current_id_)

    reuseItems : true
    z:1
    onWidthChanged: {
        table_view.forceLayout()
        table_view.x=0
    }
    delegate: ColumnProvider {
        placeholderText_L:  { return typeof display_ !== "undefined" ? display_:""}
    }
        /* EditableLable {
        placeholderText:  display_
    }*/

    Connections {
        target: table_view
        onRefreshModel: {
            console.log("onRefreshModel");
            //table_view.test()
        }
    }

    function getWith(column) {
        var width
        var part
        if (column === 0) {
            part = 0.25
            width = (main_root.width - 50)* part
        }
        else if (column === 1) {
            part = 0.75
            width = (main_root.width - 50)* part
        }
        else width = 40
        //console.log("column = " + column +  " width =" + width)
        return width
    }

    function modelReset() {
        //console.log("modelReset");
       table_view.model.modelReset();// = app_data.getModelByID(current_id_)
    }

    function removeRow(item_row) {
        table_view.model.removeRow(item_row);
        table_view.model.modelReset();
    }

    function addRow(item_row) {
        table_view.model.addRow(item_row);
        table_view.model.modelReset();
    }

    function copyRow(item_row) {
        table_view.model.copyRow(item_row);
        table_view.model.modelReset();
    }
}

