import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
//import ItemModelBase 1.0
import Qt.labs.qmlmodels 1.0

import AppDataProvider 1.0

//https://stackoverflow.com/questions/43423981/qt-quick-controls-2-and-tableview

//https://github.com/qt/qtquickcontrols2/tree/dev/examples/quickcontrols2/contactlist


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
    topMargin:5

    property  int data_type_:  1
    property  int current_id_: parent.current_id_

    model:  app_data.model//model_test
   // delegate:EditableLable { }

//    TableViewColumn {
//        role: "type1"
//        title: "Kunde"
//        width: 100

//        delegate: Text {
//            text: display  // accessing the property
//        }
////    }

    //AppDataProvider{}

    delegate: //Row {
        EditableLable {
            //leftPadding :20
            placeholderText:  display_
             //  display//feature//modelData.feature
        }
    Component.onCompleted: {
        //        setColumnWidth(0,100);
        //        setColumnWidth(1,150);
        //        setColumnWidth(3,350);
    }

}
