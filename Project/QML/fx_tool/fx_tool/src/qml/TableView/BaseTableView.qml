import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

import ItemModelBase 1.0
import AppDataProvider 1.0


//import "../ItemDelegat/ItemDelegate"
//import "../ItemDelegat/HeaderDelegate"
//import "../ItemDelegat/RowDelegat"
//import "../../ContextMenu/TableViewContexMenu/HeaderContexMenu"
//import "../../ContextMenu/TableViewContexMenu/ItemContexMenu"
//import "../"
//import "../ItemDelegat/HeaderDelegate"

import "./ItemDelegate/ItemDelegate"

TableView {
    id:table_view
    anchors.fill: parent
    columnSpacing: 0
    rowSpacing: 0
    clip: true
    leftMargin:5
    rightMargin:5
    topMargin:10
    property var columnWidths: [80, 300, 40]
    columnWidthProvider: function (column) { return getWith(column) }
    property  string current_id_: parent.current_id_
    model: app_data.getModelByID(current_id_)
    reuseItems : true

    delegate: EditableLable {
        placeholderText:  display_
    }

    Component.onCompleted: {
    }

    function getWith(column) {
        var width
        if (column ===1){
            width = main_root.width - 130
        }
        else width = table_view.columnWidths[column]
        console.log("column = " + column +  " width =" + width)
        return width
    }
}

