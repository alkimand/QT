import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.12

//import AppDataController 1.0
import ItemModelBase 1.0

import "./ItemDelegate/Loaders"

//import "../ItemDelegat/HeaderDelegate"
//import "../ItemDelegat/RowDelegat"
//import "../../ContextMenu/TableViewContexMenu/HeaderContexMenu"
//import "../../ContextMenu/TableViewContexMenu/ItemContexMenu"
//import "../"
//import "../ItemDelegat/HeaderDelegate"

import "./ItemDelegate/ItemDelegate"
Item {
    id: root
    property int model_id:0
    property string selectedTileId: '0'
    //property alias model : table.model
    signal cliked(string tile_id,real mouseX, real mouseY);

    Connections {
        target: root
        onCliked: {
            app_data.getModelByID(root.model_id).onClick(tile_id, mouseX, mouseY);
        }
    }
    Connections {
        target: app_data.getModelByID(root.model_id)
        onSelectTile:{
            //console.log("signal from Iem data"+tile_id);
            selectedTileId = tile_id;

        }
    }

    TableView {
        id: table
        anchors.fill: parent
        //visible:false
        //property  string current_id_: parent.current_id_
        // property  int view_id_: parent.view_id_
        // anchors.fill: parent
        // height:600
        //width:800
        //ItemSelectionModel:app_data.getModelByID(root.model_id);
        columnSpacing: 0
        model:  app_data.getModelByID(root.model_id);
        rowSpacing: 0
        clip: true
        // cellWidth: root.width/5
        //cellHeight: root.height/5
        // highlightRangeMode: ListView.StrictlyEnforceRange
        //  leftMargin:0
        //  rightMargin:0
        // topMargin:10
        // bottomMargin: 5
        // contentWidth : main_root.width
        // implicitHeight:600
        //implicitWidth:800
        flickableDirection  :   Qt.Vertical
        // property var columnWidths: [80, 300, 40]
        //  columnWidthProvider: function (column) { return getWith(column) }
        // rowHeightProvider :  function (row) { return 35}
        signal refreshModel()
        // atYBeginning: false
        //flickDeceleration :5
        //contentY :100
        //horizontalOvershoot :40
        //boundsBehavior  : Flickable.OvershootBounds
        //boundsMovement : Flickable.DragAndOvershootBounds
        //verticalOvershoot :10
        // model: app_data.getModelByID(current_id_)

        reuseItems : true
        //z:1
        //    onWidthChanged: {
        //        table_view.forceLayout()
        //        table_view.x=0
        //    }
        delegate: DropArea {
            id: delegateRoot
            onXChanged: {
                // console.log("onXChanged= "+delegateRoot.x);
            }

            // width: 150//root.cellWidth;
            //height: 150//root.cellHeight;
            onEntered: {
                console.log("onEntered DropArea")
            }





            Rectangle {
                id: tile_container
                property int visualIndex: 0
                color: "#00000000"
                //color: "red"
                // anchors.fill: parent
                property  int originX: origin_x;
                property  int originY: origin_y;
                property  string originID: ID;
                property bool isSetuped:false
                onXChanged: {
                    if (tile_container.isSetuped === true){
                        // console.log("tile_container.isSetuped= "+ tile_container.isSetuped);
                        selectedTileId = tile_container.originID
                        console.log("onXChanged= "+ tile_container.x);
                    }
                }
                Image {
                    property int visualIndex: 0
                    id: icon
                    anchors.centerIn: parent
                    source: image_source//model.image_source
                    anchors {
                        horizontalCenter: parent.horizontalCenter;
                        verticalCenter: parent.verticalCenter
                    }
                    z:0
                    MouseArea{
                        onEntered: {
                            console.log("onEntered icon")
                        }
                    }
                }

                Image {
                    id:border
                    //id: icon
                    anchors.centerIn: parent
                    source: border_source//model.border_source
                    anchors {
                        horizontalCenter: parent.horizontalCenter;
                        verticalCenter: parent.verticalCenter
                    }

                    visible:(root.selectedTileId==tile_container.originID)?true:false;// tapHandler.pressed ? 1 : 0
                    MouseArea{
                        onEntered: {
                            console.log("onEntered border")
                        }
                    }
                    //z:1
                }


                //                DragHandler {
                //                    id: dragHandler
                //                    // xAxis.maximum : 250
                //                    //  xAxis.minimum : 140
                //                }



                Drag.active: {
                    id:drag
                    //console.log("dragHandler.active")
                    mouse_area.drag.active
                    // dragHandler.active
                }
                Drag.source: tile_container
                Drag.hotSpot.x: 36
                Drag.hotSpot.y: 36

                DropArea {
                    id: drop_area
                    anchors.fill: parent
                    //                    Rectangle {
                    //                        id: dropRectangle
                    //                        anchors.fill: parent
                    //                        z:-1

                    states: [
                        State {
                            when: delegateRoot.containsDrag
                            // when: drop_area.containsDrag
                            //                            PropertyChanges {
                            //                                target: dropRectangle
                            //                                color: "grey"
                            //                            }

                            PropertyChanges {
                                target: icon
                                opacity: 0.0
                            }


                        }
                    ]
                    //}
                    onEntered :{
                        //console.log("originX " + originX)
                        console.log("onEntered index=" + tile_container.originID)
                    }

                }

                Component.onCompleted: {
                    tile_container.width = icon.paintedWidth
                    tile_container.height = icon.paintedHeight
                }

                MouseArea {
                    id: mouse_area
                    anchors.fill: parent
                    drag.target: tile_container
                    hoverEnabled:true
                    propagateComposedEvents : true
                   // preventStealing: true

                    onClicked: {
                        console.log("onClicked index=" + tile_container.originID)
                        //tile_container.isSelected =  !tile_container.isSelected
                        //if(app_data.getModelByID(root.model_id).isPointInsideTile( tile_container.originID, mouse_area.mouseX, mouse_area.mouseY)){
                        //mouse_area.propagateComposedEvents = false;
                        //console.log("PointInsideTile")
                        //}
                        root.cliked(tile_container.originID,mouse_area.mouseX, mouse_area.mouseY);
                        // else
                        //console.log("PointOutsideTile")
                        // curentIndex = 2;
                        //if (tile_container.z ===1)
                        //     tile_container.z = 0;
                        //  else
                        //     tile_container.z = 1;

                    }
                    onEntered: {
                        root.cliked(tile_container.originID,mouse_area.mouseX, mouse_area.mouseY);
                        console.log("onEntered mouse_area index=" + tile_container.originID)
                    }

                    onReleased:{
                        //tile_container.z =0;
                        console.log("onReleased index=" + tile_container.originID)
                        tile_container.Drag.target !== null ? tile_container.Drag.target : root
                    }

                }
            }
            Component.onCompleted: {
                //console.log("icon-rectangle change parent Completed");
                tile_container.parent = root;
                tile_container.x = tile_container.originX-000;
                tile_container.y = tile_container.originY;
                //tile_container.parent = table;
                tile_container.isSetuped = true;

                curentIndex = 1;

            }
        }

        Component.onCompleted: {
            //  console.log("onCompleted");
        }
        MouseArea {
            onEntered: {
                console.log("onEntered i" )
            }
        }
    }
    //ColumnProvider {
    //        placeholderText_L:  { return typeof display_ !== "undefined" ? display_:""}
    //    }
    /* EditableLable {
        placeholderText:  display_
    }*/

    //    Connections {
    //        target: table_view
    //        onRefreshModel: {
    //            console.log("onRefreshModel");
    //            //table_view.test()
    //        }
    //    }

    //    function getWith(column) {
    //        var width
    //        var part
    //        if (column === 0) {
    //            part = 0.25
    //            width = (main_root.width - 50)* part
    //        }
    //        else if (column === 1) {
    //            part = 0.75
    //            width = (main_root.width - 50)* part
    //        }
    //        else width = 40
    //        //console.log("column = " + column +  " width =" + width)
    //        return width
    //    }

    //    function modelReset() {
    //        //console.log("modelReset");
    //       table_view.model.modelReset();// = app_data.getModelByID(current_id_)
    //    }

    //    function removeRow(item_row) {
    //       // table_view.model.removeRow(item_row);
    //      //  table_view.model.modelReset();
    //    }

    //    function addRow(item_row) {
    //       // table_view.model.addRow(item_row);
    //      //  table_view.model.modelReset();
    //    }

    //    function copyRow(item_row) {
    //        //table_view.model.copyRow(item_row);
    //        //table_view.model.modelReset();
    //    }
}


