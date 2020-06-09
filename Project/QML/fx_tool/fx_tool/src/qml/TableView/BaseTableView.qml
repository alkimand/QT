import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import ItemModelBase 1.0
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
    property  int data_type_: 1

    property ListModel model_test : ListModel {
        id: model_
        ListElement {
            type1: "feature1"
            type2: "feature3"
            type3: "feature3"
        }
        ListElement {
            type1: "feature1"
            type2: "feature3"
            type3: "feature3"
        }
        ListElement {
            type1: "feature1"
            type2: "feature3"
            type3: "feature3"
        }

    }

    ItemModelBase {
        id:myModel
    }

    model:  myModel//model_test
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
        EditableLable{
            //leftPadding :20
            placeholderText:  display_
             //  display//feature//modelData.feature
        }
//        EditableLable{
//            leftPadding :20
//            placeholderText: display//name//modelData.feature
//        }
//        EditableLable{
//            leftPadding :20
//            placeholderText: display//is_active
//            text: is_active//modelData.feature
//        }
//        bottomPadding :20
   // }


       // EditableLable { }
//    delegate: ItemDelegate {
//        text: index.row===0? feature : name
//        width: parent.width
//        onClicked: console.log("clicked:", modelData)
//    }

        //EditableLable { }
}
