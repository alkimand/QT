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

        property var value : 1//value_L
        property var modelTempValue : 0
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
        property color  dashColor: root.labelРighlightingFontColor

        //property bool isAnimationStart: animationStart.running

        anchors.fill:parent
        Rectangle {
            id:textAreaRect
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            width: textLabel.contentWidth + dashChecker.width+0
            color: root.labelFontColor
            Text
            {
                id: textLabel
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment :Text.AlignVCenter
                text: convertValueToUserText(root.value)//root.value
                font.family : root.commonFontFamily
                font.pointSize:  root.labelFontSize
                Layout.fillHeight: true
                color: root.labelРighlightingFontColor
                renderType: Text.NativeRendering // Rendering type (optional)
                leftPadding:root.labelLeftPadding
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
                width: root.checkerSize*2  + root.checkerMargin*2
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
                visible: view.activeFocus
                width: textAreaRect.width +root.checkerMargin + 5
                anchors.left:parent.left
                //y: textLabel.y                    //--
                y: textLabel.y - viewReact.height + root.modelTempValue * textLabel.height+ textLabel.height    //model.count * textLabel.height
                color: root.activBackgroundButtonColor
                //height: textLabel.height//textLabel.height * getArrValueCount()
                // height: textLabel.height * getArrValueCount()
                //  height: 5//textLabel.height*1
                height: textLabel.height * model.count
                //implicitHeight :0
                property int hoveredItem: -1
                property bool isActive: false
                z:1

                ParallelAnimation {
                    id:animation
                    running: false
                    NumberAnimation { target: viewReact; property: "height"; from: textLabel.height * model.count; to: textLabel.height * model.count + 2; duration: 1000 }
                    //NumberAnimation { target: viewReact; property: "y"; to: 50; duration: 1000 }
                }






                Component.onCompleted: {
                    //  console.log("viewReact viewReact="+viewReact.height)
                    //  console.log("view.height="+view.height)
                }

                Rectangle{
                    id:leftViewBorder
                    anchors.top:parent.top
                    anchors.bottom:parent.bottom
                    anchors.left:parent.left
                    width:root.labelBorderColorWidth
                    color: root.activMainButtonColor
                   z:1
                }

                Rectangle{
                    id:rightViewBorder
                    anchors.top:parent.top
                    anchors.bottom:parent.bottom
                    anchors.right:parent.right
                    width:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    z:1
                }

                Rectangle{
                    id:topViewBorder
                    anchors.top:parent.top
                    anchors.left:parent.left
                    anchors.right:parent.right
                    height:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    z:1
                }

                Rectangle{
                    id:bottomViewBorder
                    anchors.bottom:parent.bottom
                    anchors.left:parent.left
                    anchors.right:parent.right
                    height:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    z:1
                }



                //                                                NumberAnimation on height {
                //                                                     id: animationStart
                //                                                     // running: false
                //                                                     // from: textLabel.height*root.value; to: textLabel.height * getArrValueCount(); duration: 1000
                //                                                  }

                //                                NumberAnimation on height {
                //                                     id: animationStart_2
                //                                      running: false
                //                                      from: textLabel.height*root.value; to: textLabel.height * getArrValueCount(); duration: 1000
                //                                  }

                //                SequentialAnimation {
                //                    id: animationStart
                //                    running:  false
                //                    NumberAnimation  { target: viewReact;
                //                        property: "height";
                //                        from: textLabel.height*root.value; to: textLabel.height * getArrValueCount(); duration:500
                //                    }

                //                    NumberAnimation  { target: viewReact;
                //                        property: "height";
                //                        from: 0; to: textLabel.height*root.value; duration: 1000
                //                    }


                //  NumberAnimation { target: viewReact; property: "y"; from: 0; to: textLabel.y - root.value * textLabel.height; duration: 5000 }
                // NumberAnimation { target: viewReact; property: "height"; from: 0; to: textLabel.height * getArrValueCount(); duration: 800 }
                //               }

                //                displaced: Transition {
                //                    NumberAnimation { properties: "x,y"; duration: 400; easing.type: Easing.OutBounce }
                //                }


                Component {
                    id: itemDelegate
                    Rectangle {
                        id:wrapper
                        color: ListView.isCurrentItem ? root.activMainButtonColor :
                                                      (viewReact.hoveredItem === index)? "grey" : root.activBackgroundButtonColor
                        width: textAreaRect.width +root.checkerMargin + 5;
                        height: textLabel.height
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
                            z:0
                        }
z:0
                        //                        Rectangle{
                        //                            id:leftViewBorder
                        //                            anchors.top:parent.top
                        //                            anchors.bottom:parent.bottom
                        //                            anchors.left:parent.left
                        //                            width:root.labelBorderColorWidth
                        //                            color: root.activMainButtonColor
                        //                        }
                        //                        Rectangle{
                        //                            id:rightViewBorder
                        //                            anchors.top:parent.top
                        //                            anchors.bottom:parent.bottom
                        //                            anchors.right:parent.right
                        //                            width:root.labelBorderColorWidth
                        //                            color:  root.activMainButtonColor
                        //                        }
                        //                        Rectangle{
                        //                            id:topViewBorder
                        //                            anchors.top:parent.top
                        //                            anchors.left:parent.left
                        //                            anchors.right:parent.right
                        //                            height:root.labelBorderColorWidth
                        //                            color:  root.activMainButtonColor
                        //                            visible: (index ===0)?true:false
                        //                        }

                        //                        Rectangle{
                        //                            id:bottomViewBorder
                        //                            anchors.bottom:parent.bottom
                        //                            anchors.left:parent.left
                        //                            anchors.right:parent.right
                        //                            height:root.labelBorderColorWidth
                        //                            color:  root.activMainButtonColor
                        //                            visible:(index === root.getArrValueCount() - 1)?true:false
                        //                        }


                        MouseArea{
                            anchors.fill:parent
                            id:itemDelegateMouseArea
                            propagateComposedEvents:false
                            z:1
                            onCanceled: {
                                //  labelMouseArea.enabled = true
                            }
                            onActiveFocusChanged: {
                                // labelMouseArea.enabled = true
                            }
                            onClicked: {
                                viewReact.hoveredItem = -1;
                                console.log("itemDelegate onClicked")
                                //console.log("onClicked+"+index)
                                //console.log("onClicked+"+listViewtext.text)
                                if (view.currentIndex !== index){
                                    view.currentIndex = index
                                    root.value = view.currentIndex
                                    textLabel.text = convertValueToUserText(root.value)
                                }
                                else{
                                    //viewReact.visible = false;
                                    //model.append({"name":"Pizza"})
                                    // model.append({"name": "root.valueArr[root.value]"});
                                    // root.test_2();
                                    //    view.currentIndex = index
                                    //     root.value = view.currentIndex
                                    /// model.append({"name": root.valueArr[root.value]});
                                    //console.log("else view.currentIndex+"+view.currentIndex)
                                    //viewReact.height =viewReact.height+5;
                                    //view.contentHeight = view.contentHeight+5;
                                    //view.height = view.height+5;
                                    root.test()
                                }

                                // console.log("viewReact viewReact="+viewReact.height)
                                // console.log("view.height="+view.height)
                                //viewReact.visible = false;//++

                                //labelMouseArea.enabled = true
                                //view.focus = false
                                //viewReact.isActive=false

                            }

                            onPressed: {
                                //root.state="s_viewPressed"
                                //console.log("onPressed+"+index)
                                viewReact.hoveredItem = index;

                            }
                            onReleased: {
                                //console.log("onReleased+")
                                if (viewReact.hoveredItem !== -1)
                                    viewReact.hoveredItem = -1;
                            }
                        }
                    }
                }

                ListView {
                    id: view
                    // visible: false
                    anchors.fill: parent
                    // anchors.left: viewReact.left
                    //anchors.top: viewReact.top
                    //y:0//viewReact.y
                    //y: 0//viewReact.y //+ root.value * textLabel.height
                    //height: 0//textLabel.height// * getArrValueCount()
                    //implicitHeight :0
                    //contentHeight:0//textLabel.height
                    visible: view.activeFocus
                    model: model
                    highlightRangeMode: ListView.ApplyRange
                    delegate: itemDelegate
                    focus: true
                    //highlight: Rectangle { color: "lightsteelblue"; radius: 5 }

                    interactive: true
                    flickableDirection: Flickable.VerticalFlick
                    boundsBehavior: Flickable.StopAtBounds


                    Component.onCompleted: {
                        if (root.value < root.getArrValueCount())
                            view.currentIndex = 0//root.value;
                        else
                            view.currentIndex = 0;
                    }

                    Keys.onSpacePressed: model.insert(0, { "name": "Item " + model.count })

                    //                    add: Transition {
                    //                        NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 400 }
                    //                        NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 400 }
                    //                    }

                    //                    displaced: Transition {
                    //                        NumberAnimation { properties: "x,y"; duration: 400; easing.type: Easing.OutBounce }
                    //                    }

                    //                    displaced: Transition {
                    //                        id: dispTrans
                    //                        SequentialAnimation {
                    //                            PauseAnimation {
                    //                                duration: (dispTrans.ViewTransition.index -
                    //                                           dispTrans.ViewTransition.targetIndexes[0]) * 100
                    //                            }
                    //                            ParallelAnimation {
                    //                                NumberAnimation {
                    //                                    property: "x"; to: dispTrans.ViewTransition.item.x + 20
                    //                                    easing.type: Easing.OutQuad
                    //                                }
                    //                                NumberAnimation {
                    //                                    property: "y"; to: dispTrans.ViewTransition.item.y + 50
                    //                                    easing.type: Easing.OutQuad
                    //                                }
                    //                            }
                    //                            NumberAnimation { properties: "x,y"; duration: 500; easing.type: Easing.OutBounce }
                    //                        }
                    //                    }


                    //                    add: Transition {
                    //                        NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 400 }
                    //                        NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 400 }
                    //                    }

                    //                                        displaced: Transition {
                    //                                            NumberAnimation { properties: "x,y"; duration: 400; easing.type: Easing.OutBounce }
                    //                                        }

                }

                ListModel {
                    id: model
                    Component.onCompleted: {
                        //                        root.valueArr.forEach(function(item, i, arr) {
                        //                            append({"name": arr[i]});
                        //                        });

                        root.test_2()
                        // model.append(0, {"name": root.valueArr[root.value]})

                        //  console.log("root.value+"+ root.value)
                        //   console.log(" root.valueArr[root.value]+"+ root.valueArr[root.value]);

                        // append({"name": root.valueArr[root.value]});
                    }
                }


                //                MouseArea{
                //                    anchors.fill: parent
                //                    //id:myMouse
                //                    onClicked: {
                //                        console.log("click")
                //                        //root.state = 's_LabelClicked'
                //                    }
                //                }

                //                NumberAnimation on height {
                //                      running: myMouse.kcliked
                //                      from: 0; to: textLabel.height * getArrValueCount()
                //                  }



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
                    // console.log("viewReact viewReact="+viewReact.height)
                    //  console.log("view.height="+view.height)
                    //console.log("viewReact.visible="+viewReact.visible)
                    //if(!viewReact.visible && viewReact.isActive===false){
                    if(!view.activeFocus){
                        //root.isAnimationStart = onClicked
                        console.log("labelMouseArea click")
                        //console.log("iewReact.isActive+"+viewReact.isActive)
                        root.state = 's_LabelClicked'
                        //animationStart.start()
                        //labelMouseArea.enabled = false
                        view.forceActiveFocus();


                        //viewReact.isActive=true
                        //root.addItemsToViewModel(root.value);
                    }
                    else
                        console.log("labelMouseArea click else")
                }

                onPressed: {

                    // if(!viewReact.visible && view.isActive===false){
                    if(view.activeFocus===false){
                        console.log("labelMouseArea onPressed")
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



        function getModelCount(){
            var nodelLenght = model.count;
            console.log("model.length=" + nodelLenght)
            return nodelLenght;
        }


        function convertValueToUserText(index){

            return root.valueArr[index].toString(10);
        }

        function getArrValueCount(){
            return root.valueArr.length;

        }

        function addItemsToViewModel(value){
            model.clear();

            //model.append({"name":"2"});
            model.append({"name": root.valueArr[root.value+1]});
            //root.valueArr.forEach(function(item, i, arr) {
            //                if( i >root.value)
            //model.append({"name": arr[i]});

            //                else if  (i !==root.value)
            //                    model.insert((root.value),arr[i])

            //
            //

            //append({"name": root.valueArr[root.value]});
            //  });
        }

        function test(){

          //  console.log("viewReact.height =" + viewReact.height )

          //  viewReact.height=
           // textLabel.height * model.count
            animation.running = true;

            //++
            model.insert(0, {"name": root.valueArr[0]});
            root.modelTempValue=root.modelTempValue;


            model.append({"name": root.valueArr[3]});
            root.modelTempValue=root.modelTempValue + 1;

           // console.log("root.modelTempValue="+root.modelTempValue)
            // console.log("root.value+"+root.value)

            console.log("root.modelTempValue=" + root.modelTempValue)
            console.log("model.count=" + model.count)
            console.log("viewReact.height =" + viewReact.height )



        }

        function test_2(){
            model.append({"name": root.valueArr[root.value]});

        }


    }


}
