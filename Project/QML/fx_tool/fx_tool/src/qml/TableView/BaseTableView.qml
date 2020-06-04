import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import Qt.labs.qmlmodels 1.0
//import "../ItemDelegat/ItemDelegate"
//import "../ItemDelegat/HeaderDelegate"
//import "../ItemDelegat/RowDelegat"
//import "../../ContextMenu/TableViewContexMenu/HeaderContexMenu"
//import "../../ContextMenu/TableViewContexMenu/ItemContexMenu"
//import "../"
//import "../ItemDelegat/HeaderDelegate"

import "./ItemDelegate/ItemDelegate"

TableView {
    anchors.fill: parent
    columnSpacing: 0
    rowSpacing: 0
    clip: true
    leftMargin:5
    rightMargin:5
    topMargin:5
    property  int data_type_: 1

    property ListModel model_test : ListModel {
        id: model_
        ListElement { type: "feature1"}
        ListElement { type: "feature2" }
        ListElement { type: "feature3" }

    }

    model:  model_test
    delegate: EditableLable { }
}
