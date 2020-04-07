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

        property var value :value_L
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


        //animation
        property int tottallAnimationTime : 400
        property int  upperAnimationTime
        property int  bottomAnimationTime

        property int  upperItemsCount: root.value
        property int  bottomItemsCount: root.valueArr.length - root.value - 1

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
                text: root.convertValueToUserText(root.value)//root.value
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
                        //console.log("labelMouseArea click")
                        //console.log("iewReact.isActive+"+viewReact.isActive)
                        root.state = 's_LabelClicked'

                        view.forceActiveFocus();
                        root.startAnimation()

                        viewReact.visible = view.activeFocus
                    }
                    else{
                        console.log("labelMouseArea click else")
                        view.focus = true
                        viewReact.visible = view.activeFocus
                    }
                }

                onPressed: {

                    // if(!viewReact.visible && view.isActive===false){
                    if(view.activeFocus===false){
                       // console.log("labelMouseArea onPressed")
                        root.state='s_LabelPressed'
                        //viewReact.isActive===true
                    }
                }

                onReleased: {
                    root.state='s_LabelReleased'
                }
            }

        }


        Rectangle{
            id:viewReact
            visible: view.activeFocus//view.visible
            width: textAreaRect.width +root.checkerMargin + 5
            anchors.left:parent.left
            y: textLabel.y - viewReact.height + root.modelTempValue * textLabel.height+ textLabel.height    //model.count * textLabel.height
            color: "red"//root.activBackgroundButtonColor
            //height: textLabel.height//textLabel.height * getArrValueCount()
            // height: textLabel.height * getArrValueCount()
            //  height: 5//textLabel.height*1
            height: textLabel.height * viewModel.count
            //implicitHeight :0
            property int hoveredItem: -1
            property bool isActive: false
            z:(view.activeFocus===1)?1:0

            ParallelAnimation {
                id:upper_animation
                running: false

                NumberAnimation { target: animation_top_reactangle; property: "height"; from: 0; to: textLabel.height; duration: root.upperAnimationTime }
                NumberAnimation { target: animation_right_top_border; property: "height"; from: 0; to: textLabel.height; duration: root.upperAnimationTime }
                NumberAnimation { target: animation_left_top_border; property: "height"; from: 0; to: textLabel.height; duration: root.upperAnimationTime }

            }


            ParallelAnimation {
                id:bottom_animation
                running: false

                NumberAnimation { target: animation_bottom_reactangle; property: "height"; from: 0; to: textLabel.height; duration:root.bottomAnimationTime }
                NumberAnimation { target: animation_left_bottom_border; property: "height"; from: 0; to: textLabel.height; duration:root.bottomAnimationTime }
                NumberAnimation { target: animation_right_bottom_border; property: "height"; from: 0; to: textLabel.height*(1); duration:root.bottomAnimationTime }


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
                id:animation_top_reactangle
                anchors.bottom:parent.top
                anchors.left:parent.left
                anchors.right:parent.right
                height: 0
                color: root.activBackgroundButtonColor
                z:1

                Rectangle{
                    id:animation_top_border
                    anchors.top:parent.top
                    anchors.left:parent.left
                    anchors.right:parent.right
                    height:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    z:1
                }

                Rectangle {
                    id:animation_right_top_border
                    //anchors.top:parent.top
                    anchors.bottom:parent.bottom
                    anchors.right:parent.right
                    width:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    height:0
                    z:1
                }

                Rectangle {
                    id:animation_left_top_border
                    anchors.bottom:parent.bottom
                    anchors.left:parent.left
                    width:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    height:0
                    z:1
                }

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

            Rectangle{
                id:animation_bottom_reactangle
                anchors.top:parent.bottom
                anchors.left:parent.left
                anchors.right:parent.right
                height: 0
                color: root.activBackgroundButtonColor
                z:1

                Rectangle{
                    id:animation_bottom_border
                    anchors.bottom:parent.bottom
                    anchors.left:parent.left
                    anchors.right:parent.right
                    height:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    z:1
                }

                Rectangle {
                    id:animation_left_bottom_border
                    anchors.bottom:parent.bottom
                    anchors.left:parent.left
                    width:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    height:0
                    z:1
                }

                Rectangle {
                    id:animation_right_bottom_border
                    anchors.bottom:parent.bottom
                    anchors.right:parent.right
                    width:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    height:0
                    z:1
                }
            }

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
                            //console.log("itemDelegate onClicked")
                            //console.log("onClicked+"+index)
                            //console.log("onClicked+"+listViewtext.text)
                            if (view.currentIndex !== index){
                                view.currentIndex = index
                                root.value = view.currentIndex
                                //console.log("root.value=" + root.value)
                                textLabel.text = root.convertValueToUserText(root.value)
                                //console.log(" textLabel.tex=" +  textLabel.text)




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
                                //root.test()
                                //root.startAnimation()
                            }

//                            root.upperItemsCount= root.value
//                            root.bottomItemsCount= root.valueArr.length - root.value - 1
//                            root.modelTempValue=0
//                            viewModel.clear()
//                            viewModel.insert(0, {"name": root.valueArr[root.value]});



                            // console.log("viewReact viewReact="+viewReact.height)
                            // console.log("view.height="+view.height)
                            //viewReact.visible = false;//++

                            labelMouseArea.enabled = true
                            view.focus = false


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
                model: viewModel
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

                Keys.onSpacePressed: viewModel.insert(0, { "name": "Item " + viewModel.count })

                onFocusChanged: {
                console.log("ListView onFocusChanged")
                }
               onVisibleChanged: {


                   //console.log("ListView onVisibleChanged")
                  // if (view.activeFocus===false){
                      // viewReact.visible = view.activeFocus
                       root.upperItemsCount = root.value
                       root.bottomItemsCount = root.valueArr.length - root.value - 1
                       root.modelTempValue = 0
                       viewModel.clear()
                       viewModel.append ({"name": root.valueArr[root.value]});
                       view.currentIndex = 0
                  // }

                   if (view.activeFocus===false){
                       viewReact.visible = view.activeFocus
                   }

                   //console.log("viewReact.visible="+viewReact.visible)
                   //console.log("view.activeFocus="+view.activeFocus)
                   //console.log("view.visible="+view.visible)

               }
            }

            ListModel {
                id: viewModel
                Component.onCompleted: {
                    //                        root.valueArr.forEach(function(item, i, arr) {
                    //                            append({"name": arr[i]});
                    //                        });
                    viewModel.append({"name":root.valueArr[root.value]})
                }
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
            }
        ]



        function getModelCount(){
            var nodelLenght = viewModel.count;
            //console.log("model.length=" + nodelLenght)
            return nodelLenght;
        }


        function convertValueToUserText(index){

            return root.valueArr[index].toString(10);
        }

        function getArrValueCount(){
            return root.valueArr.length;

        }

        Timer {
            id:timer
            interval: 500; running: false; repeat: false
            onTriggered: {
                root.startAdd()
            }
        }

        Timer {
            id:upperTimer
            interval: root.upperAnimationTime; running: false; repeat: false
            onTriggered: {
                root.addUpperItems()
                //upper_animation.start()
            }
        }

        Timer {
            id:bottomTimer
            interval: root.bottomAnimationTime; running: false; repeat: false
            onTriggered: {
                root.addBottomItems()
                //upper_animation.start()
            }

        }

        function addUpperItems(){
            //console.log("root.upperItemsCount="+root.upperItemsCount)
            //stop animation
            topViewBorder.visible = true;
            animation_top_reactangle.visible = false
            root.upperItemsCount -= 1;
            viewModel.insert(0, {"name": root.valueArr[root.upperItemsCount]});

            if (root.upperItemsCount > 0){
                //.log("root.upperAnimationTime="+root.upperAnimationTime)
                // upper_animation.stop()
                upper_animation.start()
                topViewBorder.visible = false;
                animation_top_reactangle.visible = true
                upperTimer.start()
                //console.log("Adding more root.upperItemsCount ="+root.upperItemsCount)

            }
            else {
                //console.log("Stop upper animation")

            }

        }

        function addBottomItems(){
            //console.log("root.bottomItemsCount="+root.bottomItemsCount)
            //stop animation
            bottomViewBorder.visible = true;
            animation_bottom_reactangle.visible = false
            viewModel.append({"name": root.valueArr[root.valueArr.length - root.bottomItemsCount]});
            root.bottomItemsCount -= 1;

            root.modelTempValue+=1;

            if (root.bottomItemsCount > 0){
                bottom_animation.start()
                bottomViewBorder.visible = false;
                animation_bottom_reactangle.visible = true
                bottomTimer.start()
                //console.log("Adding more root.bottomItemsCount ="+root.bottomItemsCount)
            }
            else {
               // console.log("Stop bottom animation")
            }

        }


        function startAnimation(){
            if (root.value!==0 && root.value!==(root.valueArr.length-1))
            {
                //console.log("startAnimation root.value!==0 && root.value!==root.valueArr.length")
                if (root.value!==0)
                    root.upperAnimationTime = root.tottallAnimationTime / (root.value)
                else
                    root.upperAnimationTime =  0
                root.bottomAnimationTime = root.tottallAnimationTime/(root.valueArr.length - root.value - 1)
                //console.log("viewModel.count="+viewModel.count)
                //console.log("root.value="+root.value)
                //console.log("root.valueArr.length="+root.valueArr.length)
                //console.log("root.upperAnimationTime="+root.upperAnimationTime)
                //console.log("root.bottomAnimationTime="+root.bottomAnimationTime)

                upper_animation.running = true;
                bottom_animation.running = true;
                //start animation
                topViewBorder.visible = false;
                bottomViewBorder.visible = false;
                animation_top_reactangle.visible = true
                animation_bottom_reactangle.visible = true

                bottomTimer.start()
                upperTimer.start()

            }
            else if (root.value===0){
                //console.log("startAnimation else root.value===0")
                root.bottomAnimationTime = root.tottallAnimationTime/(root.valueArr.length - 1)
                bottom_animation.running = true;
                bottomViewBorder.visible = false;
                animation_bottom_reactangle.visible = true
                bottomTimer.start()

            }
            else {
                //console.log("startAnimation else")
                root.upperAnimationTime = root.tottallAnimationTime/(root.valueArr.length - 1)
                //console.log("root.upperAnimationTime="+root.upperAnimationTime)
                upper_animation.running = true;

                topViewBorder.visible = false;
                animation_top_reactangle.visible = true
                upperTimer.start()

            }
        }

    }


}
