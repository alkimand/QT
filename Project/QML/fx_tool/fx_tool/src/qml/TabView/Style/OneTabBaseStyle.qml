import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

import QtQuick.Layouts 1.12
//import QtGraphicalEffects 1.0
//import QtQml.StateMachine 1.12

import Actions 1.0
import BorderRadiusWidget.qml 1.0

import "../../Menu/TabContextMenu"
import "../Tab"

import Actions 1.0

Rectangle {
    id:root
    property bool isActive: false
    property int borderwidth: 2
    property int borderTopMargin: 8
    property int bottoBorderWidth: 3
    property int buttonImageHeight: 15

    property string borderRectColor: "black"
    property string textFont: "Arial Narrow"
    property int textHeight: 8

    property int radius: 12
    // Action fileSaveAction_//: Actions.fileSaveAction
    property string imageSaveSourse: Actions.fileSaveAction.icon.source
    property string imageCloseSource: Actions.closeTabAction.icon.source

    property color tabBarTextColor: "black"

    property color activeColor: "white"
    property color disactiveColor: "#dee1e6"
    property color backgroundColor

    property color beforeSelectColor: "#eeeff2"
    property color widgetBorderColor: "#77a9ef"
    property color rightTabColor: "#909497"


    //"#77a9ef" - blue

    //property color tabBarRectColorIfSelectingStart: "#B83669"
    property color tabBarRectColor:styleData.selected? activeColor : disactiveColor
    color: activeColor
    border.width: 0//tabBarRectColor//
    implicitWidth: Math.round(textArea.implicitWidth
                              + savebutton.width + root.radius
                              + closebutton.width +
                              + (1*root.radius + 10)
                              )
    implicitHeight: Math.round(textArea.implicitHeight
                               + borderTopMargin
                               + bottoBorderWidth + 00)
    signal enter()
    signal exit()

    //states
    signal activateButton()
    signal hoverButton()
    signal disableButton()


    //singal to upper level
    signal activateTab()



    TabContextMenu { id: tabContextMenu }
    signal senTab()

    Connections {
        target: root
        onEnter: {
            tab_view.indexUnderMouse = styleData.index
            tab_view.contexMenuIndex = styleData.index
           // console.log("onEnter="+styleData.index)
            //console.log("tab_view.count="+tab_view.count)

            if (styleData.index === (tab_view.currentIndex)) {
                index = styleData.index;
                //root.activateButton()
                root.activateTab()
                //console.log("activateButton=" + styleData.index)
            }
            else {
                //console.log("hoverButton=" + styleData.index)
                root.hoverButton()
            }
        }

        onExit: {
            //console.log("onExit="+styleData.index)
            //console.log("tab_view.count="+tab_view.count)
            tab_view.indexUnderMouse = -1
            if (styleData.index !== (tab_view.currentIndex)) {
                root.disableButton()
                //console.log("disableButton " + styleData.index)
            }
        }

        onDisableButton: {
            root.state = "disabled"
        }

        onHoverButton: {
            root.state = "hovered"
        }

        onActivateButton: {
            root.state = "activated"
        }
    }

    Connections {
        target: tab_view
        onRefreshTab: {
            if (styleData.index !== (tab_view.currentIndex)){
                root.disableButton()
                //console.log("disableButton=" + styleData.index)
            }
            else {
                root.activateButton()
                //console.log("activateButton=" + styleData.index)
            }
            //else

            //tab_view.refreshTab();
        }
    }


    MouseArea {
        anchors.fill: parent
        hoverEnabled:true
        propagateComposedEvents : true
        preventStealing: true
        drag.target:root
        drag.axis: Drag.XAxis
        drag.minimumX: getMinimumDrapWidth(index)
        drag.maximumX: getMaxDrapWidth(index)
        //acceptedButtons: Qt.LeftButton | Qt.RightButton
        z:1
        onEntered: {
            root.enter()
        }
        onExited: {
            root.exit()
        }
        onReleased: {
            root.x = 0
        }

//        onWheel: {
//            console.log("onWheel" )
//        }
    }


    Rectangle {
        id:topLeftBorder
        visible:  true
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin:root.borderTopMargin
        //anchors.verticalCenter: parent.verticalCenter
        width: root.radius//borderwidth;
        height: root.radius
        color: root.disactiveColor
        z:1
    }

    BorderRadiusWidget {
        id:topLeftRadius
        visible: true
        anchors.left: parent.left
        anchors.topMargin:root.radius + root.borderTopMargin
        anchors.leftMargin: root.radius
        anchors.top: parent.top
        radius: root.radius
        activeButtonColor:  root.activeColor
        z:2
    }

    Rectangle {
        id:centerLeftBorder
        visible: true
        anchors.top: topLeftBorder.bottom
        anchors.bottom: bottomLeftBorder.top
        //anchors.verticalCenter: parent.verticalCenter
        width: root.radius//borderwidth;
        //height: parent.height
        color: root.activeColor
        z:2
    }



    Rectangle {
        id:bottomLeftBorder
        visible:  false
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin:root.bottoBorderWidth
        width: root.radius//borderwidth;
        height: root.radius
        color: root.activeColor

    }


    BorderRadiusWidget {
        id:bottomLeftRadius
        visible: false
        anchors.left: parent.left
        anchors.bottomMargin:root.radius + root.bottoBorderWidth
        anchors.leftMargin: root.radius
        anchors.bottom: parent.bottom
        radius: root.radius
        activeButtonColor:  root.activeColor
        transform: Rotation {
            origin.x: 0;
            origin.y:0;
            angle: 270
        }
        z:1
    }
    BorderRadiusWidget {
        id:bottomLeftOutsideRadius
        visible: false
        anchors.right: parent.left
        anchors.bottomMargin:root.bottoBorderWidth +root.radius
        anchors.rightMargin: root.radius
        anchors.bottom: parent.bottom
        radius: root.radius
        transform: Rotation {
            origin.x: 0;
            origin.y:0;
            angle: 180
        }
        z:3
    }

    Rectangle {
        id:bottomOutsideLeftBorder
        visible:  true
        anchors.right: parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin:root.bottoBorderWidth
        width: root.radius//borderwidth;
        height: root.radius
        color:  root.activeColor
        z:2
    }

    Rectangle {
        id:topBorder
        visible: true
        anchors.top: parent.top
        anchors.left: parent.left
        height: borderTopMargin
        width: parent.width
        color: root.disactiveColor
        //color: "#f9d810"
        z:0
    }



    Rectangle {
        color: root.widgetBorderColor
        width: parent.width
        height: 1
        anchors.top: parent.top
        z:1
    }

    Rectangle {
        id:rightBorder
        visible: false
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: root.borderTopMargin + rightBorder.height/2
        width: 1//borderwidth;
        height: 14
        color: rightTabColor
        z:4
    }
    //tab_view.count
    Rectangle {
        id:bottomBorder
        visible: true
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        height: bottoBorderWidth
        width: parent.width
        // gradient: Gradient.PerfectBlue
        color: root.activeColor
        z:4
    }

    Button {
        id:savebutton
        width: buttonImageHeight
        height: buttonImageHeight
        //anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left//topLeftBorder.right//Math.round(image.right+100)
        anchors.leftMargin: 5 + root.radius
        anchors.top: parent.top
        anchors.topMargin: textArea.implicitHeight/2
        Rectangle {
            height: parent.height-0
            width:parent.height-0
            anchors.centerIn: parent
            color: root.color
            Image {
                id: imageFilesave
                fillMode: Image.PreserveAspectFit
                anchors.centerIn: parent
                height: parent.height-0
                width:parent.height-0
                visible: true
                source: imageSaveSourse
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled:true
                propagateComposedEvents : true
                preventStealing: true
                onClicked: {
                    // tab_view.contexMenuIndex = styleData.index;
                    //tab_view.currentIndex = styleData.index;

                    tab_view.contexMenuIndex = styleData.index
                    tab_view.indexUnderMouse = styleData.index
                    //console.log("tab_view.indexUnderMouse =" + tab_view.indexUnderMouse )

                    Actions.fileSaveAction.triggered()
                }
            }
        }
    }
    //https://stackoverflow.com/questions/52544548/how-can-i-disable-the-mouse-wheel-for-a-textarea-without-disabling-the-entire-co
    TextArea {
        id: textArea
        anchors.left: savebutton.right//Math.round(image.right+100)
        anchors.leftMargin: 0
        activeFocusOnPress :false
        anchors.top: parent.top
        anchors.topMargin: 8//implicitHeight/2
        text: styleData.title
        font.family : textFont
        font.pointSize : textHeight
        color: tabBarTextColor
        //flickableItem: Item{}
        inputMethodHints: Qt.ImhNoPredictiveText
        //        inputMethodHints: Qt.ImhSensitiveData
        //                          | Qt.ImhPreferUppercase
        //                          | Qt.ImhNoPredictiveText
        //acceptedButtons: Qt.LeftButton | Qt.RightButton
        //        onEditingFinished:
        //        {
        //            tab_view.getTab(index).title = text.text
        //            tab_view.sendTittleName(index, tab_view.getTab(index).title)
        //            //tab_view.getTab(tab_view.currentIndex).item.children[0].filterChangedSlot(tab_view.getTab(index).title)

        //        }
//        MouseArea{
//            propagateComposedEvents : true
//            anchors.fill:parent
//            onWheel: {
//                console.log("onWheel" )
//            }
//            onClicked:{
//                console.log("onClicked" )
//            }
//        }
//        onTextChanged:    {
//          //  console.log("onTextChanged" )
//            //            tab_view.getTab(styleData.index).title = textArea.text
//            //            tab_view.sendTittleName(styleData.index, tab_view.getTab(styleData.index).title)
//        }
        //        Keys.onEnterPressed:
        //        {
        //            console.log("Keys.onEnterPressed")
        //            //text.editingFinished()
        //        }




        function _onEnterPressed(event) {
            if ((event.modifiers & Qt.ControlModifier))  {
                sendMessage()
                console.log("event.modifiers")
            }
            else  {
                console.log("_onEnterPressed else")
                event.accepted = false;
                //                root.forceActiveFocus()
                //                //text.remove(text.length - 1,length )
                //                text.editingFinished()
                //                text.remove(text.length,length+1 )
            }
        }

        Keys.onReturnPressed: { _onEnterPressed(event) }
        Keys.onEnterPressed: {
            _onEnterPressed(event)
            console.log("Keys.onEnterPressed")
        }
    }

    Rectangle {
        property string name : "centralReactangle"
        id:centralReactangle
        opacity: 0
        anchors.right: closebutton.left
        anchors.left: savebutton.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        MouseEvent{}
    }
    Rectangle {
        property string name : "topReactangle"
        id:topReactangle
        opacity: 0
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: savebutton.top
        MouseEvent{}
    }

    Rectangle {
        opacity: 0
        anchors.right: savebutton.left
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        MouseEvent{}
    }

    Rectangle {
        opacity: 0
        anchors.right: parent.right
        anchors.left: closebutton.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        MouseEvent{}
    }

    Button {
        id:closebutton
        width: buttonImageHeight
        height: buttonImageHeight
        //anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        anchors.topMargin: textArea.implicitHeight/2
        anchors.left: textArea.right//Math.round(image.right+100)
        anchors.leftMargin: 5
        visible: true
        Rectangle {
            height: parent.height-0
            width:parent.height-0
            color: root.color
            Image {
                id: imageClose
                fillMode: Image.PreserveAspectFit
                anchors.centerIn: parent
                height: parent.height-0
                width:parent.height-0
                source: imageCloseSource
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled:true
                propagateComposedEvents : true
                preventStealing: true
                onClicked: {
                    tab_view.contexMenuIndex = styleData.index
                    tab_view.indexUnderMouse = styleData.index
                    Actions.closeTabAction.triggered()
                }
                onEntered: {
                    if (tab_view.currentIndex !== styleData.index)
                        console.log("closeTab clicked index:" + styleData.index)
                }

//                onWheel: {
//                    console.log("onWheel" )
//                }
            }
        }
    }

    Rectangle {
        id:topRightBorder
        visible:  true
        anchors.left: closebutton.right
        anchors.top: parent.top
        anchors.topMargin:root.borderTopMargin
        //anchors.verticalCenter: parent.verticalCenter
        width: root.radius//borderwidth;
        height: root.radius
        color: root.disactiveColor
        z:1
    }

    BorderRadiusWidget {
        id:topRightRadius
        visible: true
        anchors.left: closebutton.right
        anchors.topMargin:root.radius + root.borderTopMargin
        anchors.rightMargin: root.radius
        anchors.top: parent.top
        radius: root.radius
        activeButtonColor:  root.activeColor
        transform: Rotation {
            origin.x: 0;
            origin.y:0;
            angle: 90
        }
        z:2
    }

    Rectangle {
        id:centerRightBorder
        visible: true
        anchors.top: topRightRadius.bottom
        anchors.bottom: bottomRightBorder.top

        //anchors.verticalCenter: parent.verticalCenter
        width: root.radius//borderwidth;
        //height: parent.height
        color: root.activeColor
        z:3
    }

    Rectangle {
        id: bottomRightBorder
        visible:  false
        anchors.left: closebutton.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin:root.bottoBorderWidth
        //anchors.verticalCenter: parent.verticalCenter
        width: root.radius//borderwidth;
        height: root.radius
        color: root.activeColor
        z:1
    }

    BorderRadiusWidget {
        id:bottomRightRadius
        visible: false
        anchors.bottom: parent.bottom
        anchors.left: closebutton.right
        anchors.bottomMargin:root.bottoBorderWidth +root.radius
        anchors.leftMargin: 0
        radius: root.radius
        activeButtonColor:   root.activeColor
        transform: Rotation {
            origin.x: 0;
            origin.y:0;
            angle: 180
        }
        z:2
    }

    BorderRadiusWidget {
        id:bottomOutsideRightRadius
        visible: false
        anchors.bottom: parent.bottom
        anchors.left: topRightRadius.right
        anchors.bottomMargin:root.bottoBorderWidth +root.radius
        anchors.leftMargin:2*root.radius
        radius: root.radius
        activeButtonColor:  root.activeColor
        transform: Rotation {
            origin.x: 0;
            origin.y:0;
            angle: 270
        }
        z:3
    }

    Rectangle {
        id: bottomOutsideRightBorder
        visible:  false
        anchors.bottom: parent.bottom
        anchors.left: topRightRadius.right
        anchors.leftMargin: root.radius
        anchors.bottomMargin:root.bottoBorderWidth
        width: root.radius//borderwidth;
        height: root.radius
        color: root.activeColor
        z:2
    }

    //    Rectangle {
    //        id: bottomRightBorder_
    //        visible:  true
    //        anchors.left: closebutton.right
    //        anchors.bottom: parent.bottom
    //        anchors.bottomMargin:root.bottoBorderWidth
    //        //anchors.verticalCenter: parent.verticalCenter
    //        width: root.radius//borderwidth;
    //        height: root.radius
    //        color: "red"
    //        z:10
    //    }


    onXChanged: {
        var x = root.x
        if (x < 0){
            if (x < (-root.width / 2))
                tab_view.moveTab(index,index - 1)
        }
        else {
            if (x > (root.width / 2))
                tab_view.moveTab(index,index + 1)
        }
    }

    states: [
        State {
            name: "disabled"

            PropertyChanges {
                target: rightBorder;
                visible: styleData.index !== (tab_view.currentIndex - 1)
                         && (styleData.index !== tab_view.indexUnderMouse - 1)
                         && (styleData.index !== tab_view.count - 1)
                         ? true:false;
            }

            PropertyChanges {
                target: root;
                color: root.disactiveColor;
            }
            PropertyChanges {
                target: topLeftRadius;
                activeButtonColor: root.disactiveColor;
            }
            PropertyChanges {
                target: topRightRadius;
                activeButtonColor: root.disactiveColor;
            }

            PropertyChanges {
                target: topLeftBorder;
                color: root.disactiveColor;
            }
            PropertyChanges {
                target: centerLeftBorder;
                color: root.disactiveColor;
            }
            PropertyChanges {
                target: bottomLeftRadius;
                activeButtonColor: root.disactiveColor;
            }
            PropertyChanges {
                target: bottomLeftBorder;
                color: (styleData.index === (tab_view.currentIndex + 1)
                        //|| (styleData.index === tab_view.currentIndex + 1))
                        )
                       ?
                           root.activeColor: root.disactiveColor;
                //"red":"blue"
                //  color: root.disactiveColor;
            }


            PropertyChanges {
                target: centerRightBorder;
                color: root.disactiveColor;
            }


            PropertyChanges {
                target: bottomRightRadius;
                activeButtonColor:
                    //                    (styleData.index === (tab_view.currentIndex - 1)
                    //                     )
                    //                    ? root.activeColor: root.disactiveColor;
                    root.disactiveColor;
            }

            PropertyChanges {
                target: bottomRightBorder;
                color: (styleData.index === (tab_view.currentIndex - 1)
                        )? root.activeColor: root.disactiveColor;
            }

            PropertyChanges {
                target: bottomOutsideLeftBorder;
                visible: false;
            }

            PropertyChanges {
                target: bottomOutsideRightRadius;
                visible: false;
            }
            PropertyChanges {
                target: bottomOutsideRightBorder;
                visible: false;
            }


            //            PropertyChanges {
            //                target: bottomLeftOutsideRadius;
            //                activeButtonColor:"blue"
            //            }

            //            PropertyChanges {
            //                target: bottomLeftOutsideRadius;
            //                visible: (styleData.index === (tab_view.currentIndex - 1)
            //                        )? true: false;
            //            }

        },

        State {
            name: "hovered"
            PropertyChanges {
                target: rightBorder;
                visible: false;
            }
            PropertyChanges {
                target: root;
                color: beforeSelectColor;
            }
            PropertyChanges {
                target: topLeftRadius;
                activeButtonColor: root.beforeSelectColor;
            }
            PropertyChanges {
                target: topRightRadius;
                activeButtonColor: root.beforeSelectColor;
            }

            PropertyChanges {
                target: centerRightBorder;
                color: root.beforeSelectColor;
            }

            PropertyChanges {
                target: topLeftBorder;
                color: root.disactiveColor;
            }


            PropertyChanges {
                target: centerLeftBorder;
                color: root.beforeSelectColor;
            }

            PropertyChanges {
                target: bottomLeftBorder;
                color: // root.beforeSelectColor;
                       (styleData.index === (tab_view.currentIndex + 1)
                        )
                       ? root.activeColor: root.beforeSelectColor;

            }

            PropertyChanges {
                target: bottomLeftRadius;
                activeButtonColor: root.beforeSelectColor;
            }
            //            PropertyChanges {
            //                target: bottomLeftBorder;
            //                visible: false;
            //            }

            PropertyChanges {
                target: bottomRightRadius;
                activeButtonColor:
                    (styleData.index === (tab_view.currentIndex - 1))
                    ? root.beforeSelectColor: root.beforeSelectColor;

            }

            PropertyChanges {
                target: bottomRightBorder;
                color:
                    (styleData.index === (tab_view.currentIndex - 1))
                    ? root.activeColor: root.beforeSelectColor;
            }


            PropertyChanges {
                target: bottomLeftOutsideRadius;
                visible: true
                // root.beforeSelectColor: root.disactiveColor;
            }

            //TODO
            PropertyChanges {
                target: bottomLeftOutsideRadius;
                activeButtonColor: root.beforeSelectColor
                //"red"
                //                  ((tab_view.indexUnderMouse === (tab_view.currentIndex+1))
                //                   && styleData.index === (tab_view.currentIndex)
                //                   )
                //                ? root.beforeSelectColor: root.disactiveColor;
                // ? root.activeColor : root.disactiveColor;
                // ?"red":"blue"
            }

            PropertyChanges {
                target: bottomOutsideRightBorder;
                visible: (styleData.index === tab_view.indexUnderMouse) ?true:false
            }
            PropertyChanges {
                target: bottomOutsideRightBorder;
                color:
                    ((tab_view.indexUnderMouse === (tab_view.currentIndex+1))
                     && styleData.index === (tab_view.currentIndex)
                     )
                    ? root.disactiveColor: root.beforeSelectColor;
                //               ? "yellow": "blue";
            }

            PropertyChanges {
                target: bottomOutsideRightRadius;
                visible: (styleData.index === tab_view.indexUnderMouse) ?true:false
            }

            PropertyChanges {
                target: bottomOutsideRightRadius;
                activeButtonColor:
                    ((tab_view.indexUnderMouse === (tab_view.currentIndex+1))
                     && styleData.index === (tab_view.currentIndex)
                     )
                //                ? root.beforeSelectColor: root.disactiveColor;
                    ? root.activeColor : root.disactiveColor;
            }




        },
        State {
            name: "activated"
            PropertyChanges {
                target: rightBorder;
                visible: false;
            }
            PropertyChanges {
                target: root;
                color: activeColor;
            }
            PropertyChanges {
                target: topLeftRadius;
                activeButtonColor: root.activeColor;
            }
            PropertyChanges {
                target: topRightRadius;
                activeButtonColor: root.activeColor;
            }

            PropertyChanges {
                target: centerLeftBorder;
                color: root.activeColor;
            }

            PropertyChanges {
                target: centerRightBorder;
                color: root.activeColor;
            }

            PropertyChanges {
                target: bottomLeftBorder;
                color: root.activeColor;
            }

            PropertyChanges {
                target: bottomRightRadius;
                activeButtonColor: root.activeColor;
            }

            PropertyChanges {
                target: bottomRightBorder;
                color: root.activeColor;
            }


            PropertyChanges {
                target: bottomLeftOutsideRadius;
                visible: true
            }

            PropertyChanges {
                target: bottomLeftOutsideRadius;
                activeButtonColor:
                    ((tab_view.indexUnderMouse === (tab_view.currentIndex-1))
                     && styleData.index === (tab_view.currentIndex)
                     )
                    ? root.beforeSelectColor: root.disactiveColor;
            }


            PropertyChanges {
                target: bottomOutsideRightBorder;
                visible: ((styleData.index === tab_view.indexUnderMouse
                           && (styleData.index !== tab_view.currentIndex - 1))
                          || styleData.index === tab_view.currentIndex
                          ) ?true:false
            }

            PropertyChanges {
                target: bottomOutsideRightRadius;
                activeButtonColor:
                    ((tab_view.indexUnderMouse === (tab_view.currentIndex+1))
                     && styleData.index === (tab_view.currentIndex)
                     )
                // ? "yellow": "blue";
                    ? root.beforeSelectColor: root.disactiveColor;
            }

            PropertyChanges {
                target: bottomOutsideRightRadius;
                visible: true
            }

        }
    ]

    Component.onCompleted:{
        //tab_view.currentIndex = styleData.index
        // root.enter()
        //root.state = "activated"

    }

    function getActiveTabColor() {
        var color = root.activeColor
        if (!styleData.selected) {
            if (index === tab_view.indexUnderMouse)
                color = root.beforeSelectColor
            else
                color = root.disactiveColor
        }
        return color
    }


    function getMinimumDrapWidth(index) {
        var xOffsetLeft = 0
        if (index!==0)
            xOffsetLeft = root.width*1//index
        return -xOffsetLeft
    }


    function getMaxDrapWidth(index) {
        var xOffsetRight = 0
        if (index!==(tab_view.count - 1)) {
            xOffsetRight = root.width*1//(tab_view.count - 1 - index)
        }
        //console.log("getMaxDrapWidth(index) + =" + xOffsetRight)
        return  xOffsetRight
    }

    function renameTab() {
        textArea.select(0,textArea.text.lastIndexOf("."))
        //textArea.selectAll()
        textArea.forceActiveFocus()
    }

}

