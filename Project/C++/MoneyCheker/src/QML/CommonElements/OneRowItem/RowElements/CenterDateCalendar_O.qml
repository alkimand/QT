import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

////import "../SmallCrossChekerButton/MoneyCheker"
import "../RowLogic.js" as Logic
//import "../../Setting"

Component{
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

        property var value :  value_L //"07.25.2011" //4 //value_L{ return new Date()}
        property var modelTempValue : 0
        property int type : type_L
        property int textBlockWidth:textBlockWidth_L

        //toDo
        property int checkerSize:8
        property int checkerHeigh:2
        property int checkerMargin:7

        //more arayes

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
        property int  tempChousenValueInCombo

        //for this element only
        property int startYear: 2000

        signal openView()

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
                text: Logic.valueToUserText(root.value, Logic.DataType.DATE_DATA_TYPE, "en_EN")//root.valueLogic.valueToUserText
                font.family : root.commonFontFamily
                font.pointSize:  root.labelFontSize
                Layout.fillHeight: true
                color: root.labelРighlightingFontColor
                renderType: Text.NativeRendering // Rendering type (optional)
                leftPadding:root.labelLeftPadding
                //height:35
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
                width: root.checkerSize*2  + root.checkerMargin*1
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
                    //console.log("labelMouseArea onClicked")
                    //console.log(" yearsView.currentIndex"+ yearsView.currentIndex)
                    // monthView.forceActiveFocus()
                    //if(!viewReact.visible && viewReact.isActive===false){
                    if(!monthView.activeFocus){
                        //console.log("labelMouseArea click")
                        root.state = 's_LabelClicked'

                    }
                    else{
                        // console.log("labelMouseArea click else") //to Do
                        //restartModel("labelMouseArea");
                    }
                    root.startOpenAnimation();
                }

                onPressed: {
                    if(monthView.activeFocus===false){
                        root.state='s_LabelPressed'
                    }
                }

                onReleased: {
                    root.state='s_LabelReleased'
                }
            }
        }

        Rectangle{
            id:viewReact
            visible: false //monthView.activeFocus//monthView.visible
            width: textAreaRect.width +root.checkerMargin + 5
            anchors.left:parent.left
            // height: 48
            //width: 32
            y: -textLabel.height * 2// textLabel.y - viewReact.height + root.modelTempValue * textLabel.height+ textLabel.height    //model.count * textLabel.height
            color: root.activBackgroundButtonColor //"red"//"transparent"//"red"//root.activBackgroundButtonColor
            height: textLabel.height * 5//viewModel.count
            property int hoveredItem: -1
            property bool isActive: false
           // z:4//(monthView.activeFocus===1)?1:0

            onActiveFocusChanged: {
                //console.log("onActiveFocusChanged " + viewReact.focus)
                //console.log("activeFocus " + viewReact.activeFocus)
                if (!viewReact.activeFocus && !isAnimationInProgressByTimer){
                    root.value.setYear(yearsView.currentIndex + root.startYear)
                    root.value.setMonth(monthView.currentIndex)
                    textLabel.text = Logic.valueToUserText(root.value, Logic.DataType.DATE_DATA_TYPE, "en_EN")
                    root.startFinishAnimation()
                }
            }
            onFocusChanged: {

//                    if (monthView.focus)
//                       // console.log("monthView.focus=" + monthView.focus)
//                    else{

//                    }
                //console.log("viewReact.focus=" + viewReact.focus)
            }

            Component.onCompleted: {
               // console.log("viewReact.height=" + viewReact.height)
            }

            ParallelAnimation {
                id: animation_start
                running: false
                NumberAnimation { target: viewReact; property: "height"; from:  textLabel.height; to: textLabel.height * 5; duration: root.tottallAnimationTime }
                NumberAnimation { target: viewReact; property: "y";                             from: 0; to: -textLabel.height * 2; duration: root.tottallAnimationTime }
                NumberAnimation { target: monthView; property: "preferredHighlightBegin";       from: 0; to: monthView.height *2/5; duration: root.tottallAnimationTime }
                NumberAnimation { target: monthView; property: "preferredHighlightEnd";         from: 0; to: monthView.height *2/5; duration: root.tottallAnimationTime }
                NumberAnimation { target: yearsView; property: "preferredHighlightBegin";       from: 0; to: yearsView.height *2/5; duration: root.tottallAnimationTime }
                NumberAnimation { target: yearsView; property: "preferredHighlightEnd";         from: 0; to: yearsView.height *2/5; duration: root.tottallAnimationTime }
                NumberAnimation { target: centerCurentIndexReact; property: "height";           from: 0; to: textLabel.height; duration: root.tottallAnimationTime }
                NumberAnimation { target: centerCurentIndexReact; property: "anchors.topMargin";from:  -textLabel.height * 2; to: textLabel.height * 2; duration: root.tottallAnimationTime }
            }

            ParallelAnimation {
                id: animation_finish
                running: false
                NumberAnimation { target: viewReact; property: "height"; from:  textLabel.height * 5; to: textLabel.height; duration: root.tottallAnimationTime }
                NumberAnimation { target: viewReact; property: "y"; from: -textLabel.height * 2 ; to: 0; duration: root.tottallAnimationTime }
                NumberAnimation { target: monthView; property: "preferredHighlightBegin"; from:  monthView.height * 2/5; to: 0; duration: root.tottallAnimationTime }
                NumberAnimation { target: monthView; property: "preferredHighlightEnd"; from:  monthView.height * 2/5; to: 0; duration: root.tottallAnimationTime }
                NumberAnimation { target: yearsView; property: "preferredHighlightBegin"; from:  yearsView.height * 2/5; to: 0; duration: root.tottallAnimationTime }
                NumberAnimation { target: yearsView; property: "preferredHighlightEnd"; from:  yearsView.height * 2/5; to: 0; duration: root.tottallAnimationTime }
                NumberAnimation { target: centerCurentIndexReact; property: "height"; from:  textLabel.height; to: 0; duration: root.tottallAnimationTime }
                NumberAnimation { target: centerCurentIndexReact; property: "anchors.topMargin"; from:  textLabel.height * 2 ; to: -textLabel.height * 2; duration: root.tottallAnimationTime }
            }

            Rectangle{
                id:centerCurentIndexReact
                anchors.verticalCenter: parent.verticalCenter
                anchors.left:parent.left
                anchors.topMargin: textLabel.height * 2
                width:parent.width
                height: textLabel.height
                color: root.activMainButtonColor
                z:0
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

            Component {
                id: monthItemDelegate
                Rectangle {
                    id:wrapper
                    color: "transparent"
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
                        text: {  new Date(root.startYear, index, 1, 0, 0, 0, 0).toLocaleString(Qt.locale("en_EN"), "MMM")}

                        MouseArea{
                            anchors.fill:parent
                            enabled: (!isAnimationInProgressByTimer)
                            onClicked: {
                                if (monthView.currentIndex!==index){
                                    monthView.currentIndex = index
                                    //console.log("setMonth to "+(index))
                                }
                                else{
                                    // console.log("onClicked else")
                                    root.value.setMonth(index)
                                    textLabel.text = Logic.valueToUserText(root.value, Logic.DataType.DATE_DATA_TYPE, "en_EN")
                                    root.startFinishAnimation()
                                }

                            }
                        }
                    }
                }
            }

            Component {
                id: yearsItemDelegate
                Rectangle {
                    id:wrapper_2
                    color: "transparent"
                    width: textAreaRect.width +root.checkerMargin + 5;
                    height: textLabel.height
                    Text {
                        id:listViewtext_2
                        anchors.fill: parent
                        verticalAlignment :Text.AlignVCenter
                        font.family : root.commonFontFamily
                        font.pointSize : root.labelFontSize
                        color: wrapper_2.ListView.isCurrentItem ? root.activBackgroundButtonColor : "black"
                        leftPadding:root.labelLeftPadding
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: root.startYear + index //{  new Date( root.startYear + index , 0, 1, 0, 0, 0, 0).toLocaleString(Qt.locale("en_EN"), "yyyy")}

                        MouseArea {
                            anchors.fill:parent
                            enabled: (!isAnimationInProgressByTimer)
                            onClicked: {
                                //console.log("setYear index to "+(index))
                                if (yearsView.currentIndex!==index){
                                    yearsView.currentIndex = index
                                    root.value.setYear(index + root.startYear)
                                }
                                else {
                                    //console.log("onClicked else")
                                    root.value.setYear(index + root.startYear)
                                    textLabel.text = Logic.valueToUserText(root.value, Logic.DataType.DATE_DATA_TYPE, "en_EN")
                                    root.startFinishAnimation()
                                }
                            }
                        }
                    }
                }
            }

            ListView {
                id: monthView
                // visible: (monthView.focus)
                // anchors.fill: parent
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                width: textAreaRect.width/2
                highlightRangeMode: ListView.StrictlyEnforceRange
                preferredHighlightBegin: height * 0.4
                preferredHighlightEnd: height * 0.4
                clip: true
                model: 12
                delegate:monthItemDelegate

                Component.onCompleted: {
                    // monthView.currentIndex = root.value
                    // console.log("Component.onCompleted=" +root.value.getMonth())
                    //console.log("Date=" + Date.fromLocaleDateString( Qt.locale(), new Date().toLocaleDateString(), )//"dd.MM.YYYY").getMonth())//root.value
                    monthView.currentIndex = root.value.getMonth();
                    //console.log("monthView.height=" + monthView.height)
                }
                onFocusChanged: {
//                    if (monthView.focus)
//                       // console.log("monthView.focus=" + monthView.focus)
//                    else{

//                    }
                    console.log("monthView.focus=" + monthView.focus)
                }
            }

            ListView {
                id: yearsView
                //visible: (monthView.focus || yearsView.focus)
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                width: textAreaRect.width/2
                highlightRangeMode: ListView.StrictlyEnforceRange
                preferredHighlightBegin: height * 0.4
                preferredHighlightEnd: height * 0.4
                clip: true
                model: 60
                delegate:yearsItemDelegate

                Component.onCompleted: {
                    yearsView.currentIndex = root.value.getUTCFullYear() - root.startYear //root.value
                    // console.log("yearsView.height=" + yearsView.height)
                }

                    onActiveFocusChanged: {
                         //console.log("onActiveFocusChanged=" + yearsView.focus)
                    }
                onFocusChanged: {
//                    if (monthView.focus)
//                       // console.log("monthView.focus=" + monthView.focus)
//                    else{

//                    }
                    //console.log("yearsView.focus=" + yearsView.focus)
                   // console.log("yearsView.activeFocus=" + yearsView.activeFocus)

                }

            }
        }

        Timer {
            id:openAnimationRestoringTimer
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

        function startOpenAnimation(){
            //console.log("startOpenAnimation")
            root.isAnimationInProgressByTimer = true;
            animation_start.start()
            openAnimationRestoringTimer.start();
            root.openView()
        }

        function startFinishAnimation(){
            //console.log("startFinishAnimation")
            //itemDelegateMouseArea.enabled = false;
            animation_finish.start()
            root.isAnimationInProgressByTimer = true;
            afterFinshAnimationRestoringTimer.start();
        }

        function restartAfterOpenAnimation() {
            // console.log(" yearsView.currentIndex"+ yearsView.currentIndex)
            viewReact.visible = true;
            labelMouseArea.enabled = false;
            viewReact.focus = true;
            viewReact.forceActiveFocus();

            root.isAnimationInProgressByTimer = false;
            monthView.preferredHighlightBegin =  textLabel.height *2;
            monthView.preferredHighlightEnd = textLabel.height *2;

            yearsView.preferredHighlightBegin = textLabel.height *2;
            yearsView.preferredHighlightEnd = textLabel.height *2;

            yearsView.currentIndex = root.value.getUTCFullYear() - root.startYear
            monthView.currentIndex = root.value.getMonth();

            yearsView.positionViewAtIndex(yearsView.currentIndex - 2, ListView.Beginning)
            viewReact.forceActiveFocus();
            //root.z=3
        }

        function restartAfterFinishAnimation(){
            viewReact.visible = false;
            labelMouseArea.enabled = true;
            viewReact.focus = false;
            root.isAnimationInProgressByTimer = false;
            yearsView.preferredHighlightBegin = textLabel.height *2;
            yearsView.preferredHighlightEnd = textLabel.height *2;

            monthView.preferredHighlightBegin = textLabel.height *2;
            monthView.preferredHighlightEnd = textLabel.height *2;
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
