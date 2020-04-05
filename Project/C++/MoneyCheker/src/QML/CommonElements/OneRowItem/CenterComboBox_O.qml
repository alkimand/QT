import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//import"../../Setting"

import "../SmallCrossChekerButton/MoneyCheker"
import "RowLogic.js" as Logic
import "../../Setting"

Component{
    //  id:root
    // property int labelMargins
    Item{
        id:root
        //Component.onCompleted: {console.log("value="+value);}

        property color labelFontColor:labelFontColor_L //white
        property color labelРighlightingFontColor:labelРighlightingFontColor_L //blue

        property color activMainButtonColor : activMainButtonColor_L //blue
        property color activBackgroundButtonColor : activBackgroundButtonColor_L//white

        property color pressedMainButtonColor :      pressedMainButtonColor_L
        property color pressedBackgroundButtonColor: pressedBackgroundButtonColor_L

        property color hoveredButtonColor: hoveredButtonColor_L

        property string commonFontFamily:commonFontFamily_L
        property int labelFontSize:labelFontSize_L
        property int labelBorderColorWidth:labelBorderColorWidth_L
        property int labelLeftPadding:labelLeftPadding_L
        property int labelMargins :labelMargins_L

        property var value : value_L
        property int type : type_L
        property int textBlockWidth:textBlockWidth_L

        //toDo
        property int checkerSize:8
        property int checkerHeigh:2
        property int checkerMargin:15
        property var valueArr : valueArr_L

        //alias

        //textLabel
        property alias  textLabelColor: textLabel.color
        property alias  textAreaRectColor: textAreaRect.color
        property alias  leftMarginRectColor: leftTextMargin.color



        property alias  viewReactVisible: viewReact.visible

        //dash
        property alias  dashRectColor: dashChecker.color
        property alias  dashColor: root.dashColor
        property color dashColor: root.labelРighlightingFontColor

        anchors.fill:parent
        Rectangle {
            id:textAreaRect
            //anchors.fill:parent
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            width: textLabel.contentWidth + dashChecker.width+0

            //            Component.onCompleted: {
            //            console.log("textAreaRect="+textLabel.contentWidth + "+" + dashChecker.width + "="+ textAreaRect.width)
            //            }
            color: root.labelFontColor
            Text
            {
                id: textLabel
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                //anchors.fill:parent
                // anchors.horizontalCenter: buttonReact.horizontalCenter
                verticalAlignment :Text.AlignVCenter
                //anchors.verticalCenter: parent.verticalCenter
                text: convertValueToUserText(root.value)//root.value
                font.family : root.commonFontFamily
                font.pointSize:  root.labelFontSize
                Layout.fillHeight: true
                color: root.labelРighlightingFontColor
                renderType: Text.NativeRendering // Rendering type (optional)
                leftPadding:root.labelLeftPadding
                //                                Component.onCompleted: {
                //                                    console.log("textLabel.width+"+textLabel.width)
                //                                }

            }
            Rectangle {
                id:leftTextMargin
                anchors.left:textLabel.right
                anchors.top: textLabel.top
                anchors.bottom: textLabel.bottom
                width:root.checkerMargin
                color:root.activBackgroundButtonColor
            }


            Rectangle {
                id:dashChecker
                anchors.left:leftTextMargin.right
                anchors.top: textLabel.top
                anchors.bottom: textLabel.bottom
                //anchors.leftMargin: root.checkerMargin
                width: root.checkerSize*2  + root.checkerMargin*2
                // color:"red"
                //                    Component.onCompleted: {
                //                        console.log("dashChecker.width+"+dashChecker.width)
                //                    }

                Component{
                    id:dash
                    Rectangle{
                        id:oneDash
                        color:root.dashColor
                        width: root.checkerSize
                        height: root.checkerHeigh
                    }
                }

                Loader {
                    id:dash_cross_left
                    sourceComponent: dash
                    y: dashChecker.height/2
                    transform: Rotation { origin.x: root.checkerSize/2;
                        origin.y: root.checkerHeigh/2
                        angle: 45 }
                }

                Loader {
                    id:dash_cross_right
                    sourceComponent: dash
                    y: dashChecker.height/2
                    x: root.checkerSize - root.checkerHeigh
                    transform: Rotation  { origin.x: root.checkerSize/2;
                        origin.y: root.checkerHeigh/2
                        angle: -45 }
                }
            }

            Rectangle{
                id:viewReact
                visible: false
                anchors.left:parent.left
                y: textLabel.y - root.value * textLabel.height
                color: root.activBackgroundButtonColor
                height: textLabel.height * getArrValueCount()
                property int hoveredItem: -1
                property bool isActive: false
                z:1
                Component {
                    id: contactDelegate
                    Rectangle {
                        id:wrapper
                        color: ListView.isCurrentItem ? root.activMainButtonColor:(viewReact.hoveredItem === index)?"grey": root.activBackgroundButtonColor
                        width: textAreaRect.width +root.checkerMargin + 5;
                        height: textLabel.height
                        //                        Component.onCompleted: {
                        //                        console.log("wrapper="+wrapper.width)
                        //                        }
                        Text {
                            id:listViewtext
                            anchors.fill: parent
                            verticalAlignment :Text.AlignVCenter
                            font.family : root.commonFontFamily
                            font.pointSize : root.labelFontSize
                            color: wrapper.ListView.isCurrentItem ? root.activBackgroundButtonColor : "black"
                            leftPadding:root.labelLeftPadding
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: name
                            z:1
                        }

                        Rectangle{
                            id:leftViewBorder
                            anchors.top:parent.top
                            anchors.bottom:parent.bottom
                            anchors.left:parent.left
                            width:root.labelBorderColorWidth
                            color: root.activMainButtonColor
                        }
                        Rectangle{
                            id:rightViewBorder
                            anchors.top:parent.top
                            anchors.bottom:parent.bottom
                            anchors.right:parent.right
                            width:root.labelBorderColorWidth
                            color:  root.activMainButtonColor
                        }
                        Rectangle{
                            id:topViewBorder
                            anchors.top:parent.top
                            anchors.left:parent.left
                            anchors.right:parent.right
                            height:root.labelBorderColorWidth
                            color:  root.activMainButtonColor
                            visible: (index ===0)?true:false
                        }

                        Rectangle{
                            id:bottomViewBorder
                            anchors.bottom:parent.bottom
                            anchors.left:parent.left
                            anchors.right:parent.right
                            height:root.labelBorderColorWidth
                            color:  root.activMainButtonColor
                            visible:(index === root.getArrValueCount() - 1)?true:false
                        }


                        MouseArea{
                            anchors.fill:parent
                            propagateComposedEvents:false
                            z:1
                            onCanceled: {
                            labelMouseArea.enabled = true
                            }
                            onActiveFocusChanged: {
                                labelMouseArea.enabled = true
                            }
                            onClicked: {
                                viewReact.hoveredItem = -1;
                                //console.log("onReleased")
                                //console.log("onClicked+"+index)
                                //console.log("onClicked+"+listViewtext.text)
                                if (view.currentIndex !== index){
                                    view.currentIndex = index
                                    root.value = view.currentIndex
                                    textLabel.text = convertValueToUserText(root.value)
                                }
                                else{
                                    viewReact.visible = false;
                                   // console.log("else view.currentIndex+"+view.currentIndex)
                                }
                                viewReact.visible = false;

                                labelMouseArea.enabled = true
                                //viewReact.isActive=false

                            }

                            onPressed: {
                                //root.state="s_viewPressed"
                                //console.log("onPressed+"+index)
                                viewReact.hoveredItem = index;

                            }
                            onReleased: {
                                //console.log("onReleased+")
                                if (viewReact.hoveredItem!==-1)
                                    viewReact.hoveredItem=-1
                            }
                        }
                    }
                }

                ListView {
                    id: view
                    anchors.fill: parent
                    model: model
                    highlightRangeMode :ListView.ApplyRange
                    delegate: contactDelegate
                    focus: true
                    //highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                    Component.onCompleted: {
                        if (root.value < root.getArrValueCount())
                            view.currentIndex = root.value;
                        else
                            view.currentIndex = 0;
                    }
                }

                ListModel {
                    id: model
                    Component.onCompleted: {
                        root.valueArr.forEach(function(item, i, arr) {
                            append({"name": arr[i]});
                        });
                    }
                }


                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        //console.log("click")
                        //root.state = 's_LabelClicked'
                    }
                }
            }

            MouseArea {
                id:labelMouseArea
                // anchors.fill:parent
                anchors.left: textAreaRect.left
                anchors.top: textAreaRect.top
                anchors.bottom: textAreaRect.bottom
                anchors.right: textAreaRect.right
                propagateComposedEvents:false
                z:0
                onClicked: {

                    //console.log("viewReact.visible="+viewReact.visible)
                    //if(!viewReact.visible && viewReact.isActive===false){
                    if(!viewReact.visible){
                        //console.log("MouseArea click")
                        //console.log("iewReact.isActive+"+viewReact.isActive)
                        root.state = 's_LabelClicked'
                        labelMouseArea.enabled=false

                        //viewReact.isActive=true

                    }
                }

                onPressed: {

                    if(!viewReact.visible && viewReact.isActive===false){
                        //console.log("MouseArea onPressed")
                        root.state='s_LabelPressed'
                        //viewReact.isActive===true
                    }
                }

                onReleased: {
                    root.state='s_LabelReleased'
                }
                //}
            }



        }

        states: [
            State {
                name: "s_LabelClicked"
                PropertyChanges {
                    target: root;
                    viewReactVisible: true;
                }
            },

            State {
                name: "s_LabelPressed"

                PropertyChanges {
                    target: root;
                    textAreaRectColor: root.pressedBackgroundButtonColor;
                }

                PropertyChanges {
                    target: root;
                    textLabelColor: root.pressedMainButtonColor;
                }

                PropertyChanges {
                    target: root;
                    dashRectColor: root.pressedBackgroundButtonColor;
                }

                PropertyChanges {
                    target: root;
                    dashColor: root.pressedMainButtonColor;
                }

                PropertyChanges {
                    target: root;
                    leftMarginRectColor: root.pressedBackgroundButtonColor;
                }


            },

            State {
                name: "s_LabelReleased"

                PropertyChanges {
                    target: root;
                    textAreaRectColor: root.labelРighlightingFontColor;
                }

                PropertyChanges {
                    target: root;
                    textLabelColor: root.labelFontColor;
                }

                PropertyChanges {
                    target: root;
                    dashRectColor: root.labelРighlightingFontColor;
                }

                PropertyChanges {
                    target: root;
                    dashColor: root.labelFontColor;
                }

                PropertyChanges {
                    target: root;
                    leftMarginRectColor: root.labelРighlightingFontColor;
                }
            },

            State {
                name: "s_standart"

                //                PropertyChanges {
                //                    target: root;
                //                    textAreaRectColor: root.labelРighlightingFontColor;
                //                }

                //                PropertyChanges {
                //                    target: root;
                //                    textLabelColor: root.labelFontColor;
                //                }

                //                PropertyChanges {
                //                    target: root;
                //                    dashRectColor: root.labelРighlightingFontColor;
                //                }

                //                PropertyChanges {
                //                    target: root;
                //                    dashColor: root.labelFontColor;
                //                }
            }



            //            State {
            //                name: "s_hovered"
            //                PropertyChanges {
            //                    target: root;
            //                    border.color: root.hoveredButtonColor
            //                    dashColor: root.hoveredButtonColor;
            //                }
            //            },

            //            State {
            //                name: "s_dashPressed"
            //                PropertyChanges {
            //                    target: root;
            //                    color: root.activBackgroundButtonColor;
            //                    dashColor: root.pressedBackgroundButtonColor;
            //                }
            //            },

            //            State {
            //                name: "s_notActive"
            //                PropertyChanges {
            //                    target: root;
            //                    dashColor: root.pressedBackgroundButtonColor;
            //                    border.color: root.activMainButtonColor
            //                    color: root.activBackgroundButtonColor;
            //                }
            //            }

        ]

























        function convertValueToUserText(index){

            return root.valueArr[index].toString(10);

        }

        function getArrValueCount(){
            return root.valueArr.length;
        }


    }


}
