/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.12
import QtQml.Models 2.12

GridView {
    id: root

    // width: 320;
    //height: 480
    //cellWidth: 80;
    //cellHeight: 80
    property int columns
    property int rows
    property int cell_field_size
    //property int itemsPerPage: columns * rows
    //property int page_width_:0
    //property int page_height_:0
    //  Component {

    //        Image {
    //            id: img
    //            source: "image://pixmap_id_0/2"
    //            visible: false
    //        }
    // }
    displaced: Transition {
        NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }//OutQuad Linear
    }
    //            delegate: Rectangle {
    //                implicitWidth: 30
    //                implicitHeight: 30
    //                Text {
    //                    text: display
    //                }
    //            }

    //! [0]
    model: DelegateModel {
        //Component.onCompleted: console.log("model  "+model.rowCount + columnCount )
        //! [0]
        id: visualModel
        //model: app_data.getModelByID(0);

        model: ListModel {
            id: colorModel
            ListElement { image_source: "image://pixmap_id/0_0" }
            ListElement { image_source: "image://pixmap_id/0_1" }
            ListElement { image_source: "image://pixmap_id/0_2" }
            ListElement { image_source: "image://pixmap_id/0_3" }
            ListElement { image_source: "image://pixmap_id/0_4" }
            ListElement { image_source: "image://pixmap_id/1_0" }
            ListElement { image_source: "image://pixmap_id/1_1" }
            ListElement { image_source: "image://pixmap_id/1_2" }
            ListElement { image_source: "image://pixmap_id/1_3" }
            ListElement { image_source: "image://pixmap_id/1_4" }
            ListElement { image_source: "image://pixmap_id/2_0" }
            ListElement { image_source: "image://pixmap_id/2_1" }
            ListElement { image_source: "image://pixmap_id/2_2" }
            ListElement { image_source: "image://pixmap_id/2_3" }
            ListElement { image_source: "image://pixmap_id/2_4" }
            ListElement { image_source: "image://pixmap_id/3_0" }
            ListElement { image_source: "image://pixmap_id/3_1" }
            ListElement { image_source: "image://pixmap_id/3_2" }
            ListElement { image_source: "image://pixmap_id/3_3" }
            ListElement { image_source: "image://pixmap_id/3_4" }
            //ListElement { Loader { sourceComponent: img } }
            // }

            //ListElement {color: "blue"}
            //ListElement { color: "blue" }
            //                  ListElement { color: "green" }
            //                    ListElement { color: "red" }
            //                    ListElement { color: "yellow" }
            //                    ListElement { color: "orange" }
            //                    ListElement { color: "purple" }
            //                    ListElement { color: "cyan" }
            //                    ListElement { color: "magenta" }
            //                    ListElement { color: "chartreuse" }
            //                    ListElement { color: "aquamarine" }
            //                    ListElement { color: "indigo" }
            //                    ListElement { color: "black" }
            //                    ListElement { color: "lightsteelblue" }
            //                    ListElement { color: "violet" }
            //                    ListElement { color: "grey" }
            //                    ListElement { color: "springgreen" }
            //                                ListElement { color: "salmon" }
            //                                ListElement { color: "blanchedalmond" }
            //                                ListElement { color: "forestgreen" }
            //                                ListElement { color: "pink" }
            //                                ListElement { color: "navy" }
            //                                ListElement { color: "goldenrod" }
            //                                ListElement { color: "crimson" }
            //                                ListElement { color: "teal" }
        }
        //! [1]
        delegate: DropArea {
            id: delegateRoot

            width: root.cellWidth;
            height: root.cellHeight;

//            onEntered: {
//                console.log("onEntered")

//                var on = drag.source.visualIndex;
//                var to = icon.visualIndex;
//                if (on!==to){
//                    console.log("drag.source.visualIndex= "+drag.source.visualIndex);
//                    console.log("icon.visualIndex= "+icon.visualIndex);
//                    switch (root.getOrientation(on,to, columns, rows)) {
//                    case 0:
//                        visualModel.items.move(on, to);
//                        visualModel.items.move(to + 1, on);
//                        break;
//                    case 1:
//                        visualModel.items.move(on, to);
//                        break;
//                    case 2:
//                        visualModel.items.move(on, to);
//                        visualModel.items.move(to - 1, on);
//                        break;
//                    case 3:
//                        visualModel.items.move(to, on);
//                        break;
//                    default:
//                        break;
//                    }
//                    //visualModel.items.move(on, to)
//                    //visualModel.items.move(to+1, on)
//                }
//                //visualModel.items.move(icon.visualIndex, drag.source.visualIndex)
//            }
            property int visualIndex: DelegateModel.itemsIndex
            Binding { target: icon; property: "visualIndex"; value: visualIndex }


                        Rectangle {
                            id: icon
                            property int visualIndex: 0
                            color: "#00000000"
             width: root.width - 8;
             height: root.height - 8;
            //                anchors {
            //                    horizontalCenter: parent.horizontalCenter;
            //                    verticalCenter: parent.verticalCenter
            //                }
            //                radius: 0//3
            //                // color: model.color

            ////                Text {
            ////                    anchors.centerIn: parent
            ////                    // color: "white"
            ////                    //text: display
            ////                    //parent.visualIndex
            ////                }
            Image {
                property int visualIndex: 0
                //id: icon
                anchors.centerIn: parent
                source: model.image_source
                //width: root.width - 8;
               // height: root.height - 8;
                anchors {
                    horizontalCenter: parent.horizontalCenter;
                    verticalCenter: parent.verticalCenter
                }
            }


                DragHandler {
                    id: dragHandler
                    // xAxis.maximum : 250
                    //  xAxis.minimum : 140
                }

                Drag.active: {
                    // console.log("dragHandler.active")
                    dragHandler.active
                }
                Drag.source: icon
                Drag.hotSpot.x: 36
                Drag.hotSpot.y: 36

                states: [
                    State {
                        when: icon.Drag.active
                        ParentChange {
                            target: icon
                            parent: root
                        }

                        AnchorChanges {
                            target: icon
                            anchors.horizontalCenter: undefined
                            anchors.verticalCenter: undefined
                        }
                    }
                ]
                Component.onCompleted: {
                    icon.width = root.cellWidth - root.cell_field_size;
                    icon.height = root.cellHeight - root.cell_field_size;
                }
            }

        }
        //! [1]
    }
    function getOrientation (on, to, max_colum, max_height){

        var orientation = 0;

        switch (on - to ){
        case max_colum:
            orientation = 0;
            break;
        case -1 :
            orientation = 1;
            break;
        case -max_colum :
            orientation = 2;
            break;
        case 1 :
            orientation = 3;
            break;
        default:
            break;
        }
        console.log("getOrientation = "+orientation);
        return orientation;
    }
}
