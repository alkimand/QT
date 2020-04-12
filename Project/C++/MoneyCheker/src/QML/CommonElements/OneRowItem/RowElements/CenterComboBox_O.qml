import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "../../SmallCrossChekerButton/MoneyCheker"
import "../RowLogic.js" as Logic
import "../../../Setting"

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
        property var modelTempValue : 0
        property int type : type_L
        property int textBlockWidth:textBlockWidth_L

        //toDo
        property int checkerSize:8
        property int checkerHeigh:2
        property int checkerMargin:15
        property var valueArr : valueArr_L

        //more arayes


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
        property bool isAnimationInProgressByTimer: false

        property int tottallAnimationTime : tottallAnimationTime_L
        property int  upperAnimationTime
        property int  bottomAnimationTime

        property int  upperItemsCount: root.value
        property int  bottomItemsCount: root.valueArr.length - root.value - 1
        property int  tempChousenValueInCombo

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
                enabled: true
                z:0
                onClicked: {
                   // console.log("labelMouseArea onClicked")



                    // console.log("viewReact viewReact="+viewReact.height)
                    //  console.log("view.height="+view.height)
                    //console.log("viewReact.visible="+viewReact.visible)
                    //if(!viewReact.visible && viewReact.isActive===false){
                    if(!view.activeFocus){
                        //console.log("labelMouseArea click")
                        //console.log("iewReact.isActive+"+viewReact.isActive)
                        root.state = 's_LabelClicked'
                        root.startOpenAnimation();
                    }
                    else{
                        console.log("labelMouseArea click else") //to Do
                        restartModel("labelMouseArea");
                    }

                    view.visible = true;
                    view.forceActiveFocus();
                    viewReact.visible = view.focus;

                   // root.getStatus("labelMouseArea");
                }

                onPressed: {
                   // console.log("labelMouseArea onPressed")
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
            color: "red"//"transparent"//"red"//root.activBackgroundButtonColor
            height: textLabel.height * viewModel.count
            property int hoveredItem: -1
            property bool isActive: false
            z:1//(view.activeFocus===1)?1:0

            ParallelAnimation {
                id: upper_animation_start
                running: false
                NumberAnimation { target: animation_top_reactangle; property: "height"; from: 0; to: textLabel.height; duration: root.upperAnimationTime }
                NumberAnimation { target: animation_right_top_border; property: "height"; from: 0; to: textLabel.height; duration: root.upperAnimationTime }
                NumberAnimation { target: animation_left_top_border; property: "height"; from: 0; to: textLabel.height; duration: root.upperAnimationTime }
            }

            ParallelAnimation {
                id: bottom_animation_start
                running: false
                NumberAnimation { target: animation_bottom_reactangle; property: "height"; from: 0; to: textLabel.height; duration:root.bottomAnimationTime }
                NumberAnimation { target: animation_left_bottom_border; property: "height"; from: 0; to: textLabel.height; duration:root.bottomAnimationTime }
                NumberAnimation { target: animation_right_bottom_border; property: "height"; from: 0; to: textLabel.height; duration:root.bottomAnimationTime }
            }

            ParallelAnimation {
                id: upper_animation_finish
                running: false
                NumberAnimation { target: animation_top_reactangle; property: "height"; from:  textLabel.height; to: 0; duration: root.upperAnimationTime }
                NumberAnimation { target: animation_right_top_border; property: "height"; from:  textLabel.height; to: 0; duration: root.upperAnimationTime }
                NumberAnimation { target: animation_left_top_border; property: "height"; from:  textLabel.height; to: 0; duration: root.upperAnimationTime }
            }

            ParallelAnimation {
                id: bottom_animation_finish
                running: false
                NumberAnimation { target: animation_bottom_reactangle; property: "height"; from: textLabel.height; to: 0; duration:root.bottomAnimationTime }
                NumberAnimation { target: animation_left_bottom_border; property: "height"; from: textLabel.height; to: 0; duration:root.bottomAnimationTime }
                NumberAnimation { target: animation_right_bottom_border; property: "height"; from: textLabel.height; to: 0; duration:root.bottomAnimationTime }
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
                z:2

                Rectangle{
                    id:animation_top_border
                    anchors.top:parent.top
                    anchors.left:parent.left
                    anchors.right:parent.right
                    height:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    z:3
                }

                Rectangle {
                    id:animation_right_top_border
                    //anchors.top:parent.top
                    anchors.bottom:parent.bottom
                    anchors.right:parent.right
                    width:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    height:0
                    z:3
                }

                Rectangle {
                    id:animation_left_top_border
                    anchors.bottom:parent.bottom
                    anchors.left:parent.left
                    width:root.labelBorderColorWidth
                    color:  root.activMainButtonColor
                    height:0
                    z:3
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
                        enabled: !(root.isAnimationInProgressByTimer)
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
                            if (view.currentIndex !== index){
                                root.tempChousenValueInCombo = index;
                            }
                            else{
                                root.tempChousenValueInCombo = root.value
                            }
                            root.startFinishAnimation()
                        }

                        onPressed: {
                            viewReact.hoveredItem = index;

                        }
                        onReleased: {
                            if (viewReact.hoveredItem !== -1)
                                viewReact.hoveredItem = -1;
                        }
                    }
                }
            }

            ListView {
                id: view
                anchors.fill: parent
                visible: view.activeFocus
                model: viewModel
                highlightRangeMode: ListView.ApplyRange
                delegate: itemDelegate
                focus: true
                interactive: true
                flickableDirection: Flickable.VerticalFlick
                boundsBehavior: Flickable.StopAtBounds

                Component.onCompleted: {
                    if (root.value < root.getArrValueCount()){
                        view.currentIndex = 0//root.value;
                        root.restartModel("view .onCompleted")
                        console.log("view Component.onCompleted")
                    }
                    else
                        view.currentIndex = 0;
                }

                Keys.onSpacePressed: viewModel.insert(0, { "name": "Item " + viewModel.count })

                onFocusChanged: {
                    //console.log("ListView onFocusChanged =" +view.focus)
                    if (!view.focus && !isAnimationInProgressByTimer)
                        root.startFinishAnimation()
                    //console.log("startFinishAnimation onFocusChanged =")
                }
                onVisibleChanged: {
                    if ( view.activeFocus===false){
                    }
                }
            }

            ListModel {
                id: viewModel
                Component.onCompleted: {
                    //console.log("viewModel.onCompleted")
                    viewModel.append({"name":root.valueArr[root.value]})
                }
            }

        }

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
            id:afterOpenAnimationRestoringTimer
            interval: root.tottallAnimationTime; running: false; repeat: false
            onTriggered: {
                root.restartAfterOpenAnimation()
                //upper_animation_start.start()
            }
        }

        Timer {
            id:afterFinshAnimationRestoringTimer
            interval: root.tottallAnimationTime; running: false; repeat: false
            onTriggered: {
                root.restartAfterFinishAnimation()
                //upper_animation_start.start()
            }
        }

        Timer {
            id:upperTimer
            interval: root.upperAnimationTime; running: false; repeat: false
            onTriggered: {
                root.addUpperItems()
                //upper_animation_start.start()
            }
        }

        Timer {
            id:upperRemoveTimer
            interval: root.upperAnimationTime; running: false; repeat: false
            onTriggered: {
                root.removeUpperItems()
                //upper_animation_start.start()
            }
        }

        Timer {
            id:bottomRemoveTimer
            interval: root.bottomAnimationTime; running: false; repeat: false
            onTriggered: {
                root.removeBottomItems()
            }
        }

        Timer {
            id:bottomOpenTimer
            interval: root.bottomAnimationTime; running: false; repeat: false
            onTriggered: {
                root.addBottomItems()
                //upper_animation_start.start()
            }

        }


        function addUpperItems(){
            //console.log("addUpperItems root.upperItemsCount="+root.upperItemsCount)
            //stop animation
            topViewBorder.visible = true;
            animation_top_reactangle.visible = false
            root.upperItemsCount -= 1;
            viewModel.insert(0, {"name": root.valueArr[root.upperItemsCount]});

            if (root.upperItemsCount > 0){
                //.log("root.upperAnimationTime="+root.upperAnimationTime)
                // upper_animation_start.stop()
                upper_animation_start.start()
                topViewBorder.visible = false;
                animation_top_reactangle.visible = true
                upperTimer.start()
                //console.log("Adding more root.upperItemsCount ="+root.upperItemsCount)
            }
            else {
//                console.log("Stop Start animation from addUpperItems side")
//                console.log("in addUpperItems upperItemsCount=" + root.upperItemsCount)
//                console.log("in addUpperItems viewModel.count=" + viewModel.count)
            }

        }



        function addBottomItems(){
            //console.log("root.bottomItemsCount="+root.bottomItemsCount)
            //stop animation
            var error = true;
            bottomViewBorder.visible = true;
            animation_bottom_reactangle.visible = false
            viewModel.append({"name": root.valueArr[root.valueArr.length - root.bottomItemsCount]});
            root.bottomItemsCount -= 1;

            root.modelTempValue+=1;

            if (root.bottomItemsCount > 0){
                bottom_animation_start.start()
                bottomViewBorder.visible = false;
                animation_bottom_reactangle.visible = true
                bottomOpenTimer.start()
                //console.log("Adding more root.bottomItemsCount ="+root.bottomItemsCount)
            }
            else {
//                console.log("Stop Start animation from addBottomItems side");
//                console.log("in addBottomItems bottomItemsCount=" + root.bottomItemsCount)
//                console.log("in addBottomItems viewModel.count=" + viewModel.count)
            }
        }

        function removeUpperItems(){
            //console.log("in removeUpperItems")
            //console.log("root.upperItemsCount="+root.upperItemsCount)
            //console.log("viewModel.count="+viewModel.count)


            root.upperItemsCount -= 1;
            if (viewModel.count > 0){
                viewModel.remove(0);
                topViewBorder.visible = false;
                animation_top_reactangle.visible = true;
                upper_animation_finish.start();
                topViewBorder.visible = false;
            }
            if (root.upperItemsCount > 0 && viewModel.count > 0){
                topViewBorder.visible = false;
                animation_top_reactangle.visible = true;
                upperRemoveTimer.start()
            }
            else {
//                console.log("Stop Finish animation from removeUpperItems side");
//                console.log("in removeBottomItems upperItemsCount=" + root.upperItemsCount)
//                console.log("in removeBottomItems viewModel.count=" + viewModel.count)
            }
        }


        function removeBottomItems(){
           // console.log("in removeBottomItems bottomItemsCount=" + root.bottomItemsCount)
           // console.log("in removeBottomItems viewModel.count=" + viewModel.count)

            if (viewModel.count >0) {
                viewModel.remove(viewModel.count - 1);
                root.modelTempValue-=1;
                bottomViewBorder.visible = false;
                animation_bottom_reactangle.visible = true;
                bottom_animation_finish.start();
                root.bottomItemsCount -= 1;
            }
            else {
//                console.log("in removeBottomItems else viewModel.count=" + viewModel.count)
//                console.log("in removeBottomItems bottomItemsCount=" + root.bottomItemsCount)
            }
            if (root.bottomItemsCount > 0 && viewModel.count > 0){
                bottomRemoveTimer.start()
            }
            else {
//                console.log("Stop Start animation from removeBottomItems side")
//                console.log("in removeBottomItems bottomItemsCount=" + root.bottomItemsCount)
//                console.log("in removeBottomItems viewModel.count=" + viewModel.count)
            }
        }

        function startOpenAnimation(){
            root.restartModel("startOpenAnimation");
            root.isAnimationInProgressByTimer = true;
            afterOpenAnimationRestoringTimer.start();
            //console.log("startFinishAnimation root.value= "+ root.value +"=" + root.valueArr[root.value])
            //console.log("in startOpenAnimation viewModel.count=" + viewModel.count +" =" + viewModel.get(0).name)
            if (root.value!==0 && root.value!==(root.valueArr.length - 1))
            {
                root.upperAnimationTime = root.tottallAnimationTime / (root.value);
                root.bottomAnimationTime = root.tottallAnimationTime/(root.valueArr.length - root.value - 1);
                upper_animation_start.running = true;
                bottom_animation_start.running = true;
                topViewBorder.visible = false;
                bottomViewBorder.visible = false;
                animation_top_reactangle.visible = true;
                animation_bottom_reactangle.visible = true;
                bottomOpenTimer.start();
                upperTimer.start();
            }
            else if (root.value === 0){
                root.bottomAnimationTime = root.tottallAnimationTime/(root.valueArr.length - 1);
                bottom_animation_start.running = true;
                bottomViewBorder.visible = false;
                animation_bottom_reactangle.visible = true
                //getStatus("startOpenAnimation")
                bottomOpenTimer.start()

            }
            else {
                root.upperAnimationTime = root.tottallAnimationTime/(root.valueArr.length - 1)
                upper_animation_start.running = true;
                topViewBorder.visible = false;
                animation_top_reactangle.visible = true;
                upperTimer.start()
            }
        }

        function startFinishAnimation(){
            //itemDelegateMouseArea.enabled = false;
            //animationTimer.start();
            root.isAnimationInProgressByTimer = true;
            afterFinshAnimationRestoringTimer.start();



            if (root.value!==0 && root.value!==(root.valueArr.length - 1))
            {
                //console.log("finishAnimation root.value!==0 && root.value!==root.valueArr.length")
                root.upperItemsCount = root.value;
                root.bottomItemsCount = root.valueArr.length - root.value - 1;
                root.removeUpperItems();
                root.removeBottomItems();
            }
            else if (root.value===0){
                root.bottomAnimationTime = root.tottallAnimationTime/(root.valueArr.length - 1);
                root.bottomItemsCount = root.valueArr.length  - 1;
                root.removeBottomItems();
            }
            else {
                root.upperAnimationTime = root.tottallAnimationTime/(root.valueArr.length - 1);
                root.upperItemsCount = root.valueArr.length  - 1;
                root.removeUpperItems();
            }
        }


        function restartModel(from){
            //console.log("restartModel from " + from + " root.value= " + root.value)
            root.upperItemsCount = root.value
            root.bottomItemsCount = root.valueArr.length - root.value - 1
            root.modelTempValue = 0
            //console.log("restartModel root.value= "+ root.value +"=" + root.valueArr[root.value])
            if (viewModel.count != 1){

                viewModel.clear()
                viewModel.append ({"name": root.valueArr[root.value]});
                view.currentIndex = 0
                //console.log("restartModel from " + from + " root.value= " + root.value)
            }
            else {
                viewModel.set(0,{"name" : root.valueArr[root.value]})
            }

        }

        function restartAfterOpenAnimation() {
            viewReact.visible = true;
            labelMouseArea.enabled = false;
            view.visible = true;
            view.focus = true;
            root.restartUIAfterAnimation();
            view.forceActiveFocus();
            root.isAnimationInProgressByTimer = false;
        }

        function restartAfterFinishAnimation(){
            viewReact.visible = false;
            labelMouseArea.enabled = true;
            view.visible = false;
            view.focus = false;
            root.restartUIAfterAnimation();
            view.focus = false;
            root.isAnimationInProgressByTimer = false;
            root.value = root.tempChousenValueInCombo;
        }


        function restartUIAfterAnimation() {

            topViewBorder.visible = true;
            bottomViewBorder.visible = true;
            animation_top_reactangle.visible = false;
            animation_bottom_reactangle.visible = false;
            //labelMouseArea.enabled = true;
        }

        function getStatus(from) {
            console.log("  getStatus from " + from)
            console.log("   view.visible="+view.visible)
            console.log("   view.focus="+view.focus)
            console.log("   view.textAreaRect.visible="+textAreaRect.visible)
            //console.log("   view.textAreaRect.visible="+textAreaRect.visible)
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

    }

}
