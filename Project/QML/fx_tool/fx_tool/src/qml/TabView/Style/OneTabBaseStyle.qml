import QtQuick 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import Actions 1.0
import BorderRadiusWidget.qml 1.0

//import "../../../ContextMenu"
//import "../Tab"
//import "../../../ContextMenu/TabContextMenu"

import "../../Menu/TabContextMenu"
import "../Tab"

import Actions 1.0

Rectangle {
    id:oneTabView
    property int borderwidth: 2
    property int topBorderWidth: 8
    property int bottoBorderWidth: 3
    property int buttonImageHeight: 15
    property string borderRectColor: "black"
    property string textFont: "Arial Narrow"
    property int textHeight: 8

    property int radius: 5
    // Action fileSaveAction_//: Actions.fileSaveAction
    property string imageSaveSourse: Actions.fileSaveAction.icon.source
    property string imageCloseSource: Actions.closeTabAction.icon.source

    property color tabBarTextColor: "black"
    property color activeColor: "white"
    property color disactiveColor: "#dee1e6"
    property color beforeSelectColor: "#eeeff2"
    property color widgetBorderColor: "#77a9ef"
    property color rightTabColor: "#909497"
    //"#77a9ef" - blue

    //property color tabBarRectColorIfSelectingStart: "#B83669"
    property color tabBarRectColor:styleData.selected? activeColor : disactiveColor
    color: getActiveTabColor()
    border.width: 0//tabBarRectColor//
    //property string test:  "test Rectangle"
    implicitWidth: Math.round(textArea.implicitWidth
                              + imageFilesave.width
                              + closebutton.width + 15)
    implicitHeight: Math.round(textArea.implicitHeight
                               + topBorderWidth
                               + bottoBorderWidth + 0)

    //anchors.leftMargin: 50

    TabContextMenu { id: tabContextMenu }
    signal senTab()

    onSenTab: {
        console.log("onSenTab+" )
        if (tab_view.contexMenuIndex===index) {
            //oneTabView.renameTab()
            console.log("oneTabView.renameTab" )
        }
    }
    Connections {
        target: tab_view
        onRenametab: {
            //oneTabView.senTab()
            console.log("onRenametab" )
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled:true
        propagateComposedEvents : true
        preventStealing: true
        drag.target:oneTabView
        drag.axis: Drag.XAxis
        drag.minimumX: getMinimumDrapWidth(index)
        drag.maximumX: getMaxDrapWidth(index)
        //acceptedButtons: Qt.LeftButton | Qt.RightButton
        z:1
        onEntered: {
            tab_view.indexUnderMouse = index
        }
        onExited: {
            tab_view.indexUnderMouse = -1
        }
        onReleased: {
            oneTabView.x = 0
        }
    }

    Rectangle {
        id:topLeftBorder
        visible: (styleData.selected
                 || (styleData.index === tab_view.indexUnderMouse))
                 ? true: false
        anchors.left: parent.left
        anchors.top: parent.top
        //anchors.verticalCenter: parent.verticalCenter
        width: 0//borderwidth;
        height: parent.height
        color: borderRectColor
    }

    Rectangle {
        id:topBorder
        visible: true
        anchors.top: parent.top
        anchors.left: parent.left
        height: topBorderWidth
        width: parent.width
        color: oneTabView.disactiveColor
        //color: "#f9d810"
        z:0
    }

            Rectangle {
                color: oneTabView.widgetBorderColor
                width: parent.width
                height: 1
                anchors.top: parent.top
                z:1
            }

    Rectangle {
        id:rightBorder
        visible: (styleData.selected
                  || (styleData.index === (tab_view.currentIndex - 1))
                  || (styleData.index === tab_view.count-1)
                  || (styleData.index === tab_view.indexUnderMouse))
                 ? false:true
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        width: 1//borderwidth;
        height: 20
        color: rightTabColor
        Component.onCompleted: {
            //console.log("tab_view.count="+ tab_view.count)
            //console.log("styleData.index="+ styleData.index)
        }
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
        color: oneTabView.activeColor
    }

    Button
    {
        id:savebutton
        width: buttonImageHeight
        height: buttonImageHeight
        //anchors.verticalCenter: parent.verticalCenter
        anchors.left: leftBorder.right//Math.round(image.right+100)
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: textArea.implicitHeight/2
        Rectangle
        {
            height: parent.height-0
            width:parent.height-0
            anchors.centerIn: parent
            color: oneTabView.color
            Image
            {
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
                    tab_view.contexMenuIndex = index;
                    tab_view.currentIndex = index;
                    Actions.fileSaveAction.triggered()
                }
            }
        }
    }

    TextArea
    {
        id: textArea
        anchors.left: savebutton.right//Math.round(image.right+100)
        anchors.leftMargin: 0
        //anchors.topMargin: 20
         //anchors.horizontalCenter: parent.horizontalCenter
        //anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        anchors.topMargin: 8//implicitHeight/2
        text: styleData.title
        font.family : textFont
        font.pointSize : textHeight
        color: tabBarTextColor
        inputMethodHints: Qt.ImhNoPredictiveText

//        onEditingFinished:
//        {
//            tab_view.getTab(index).title = text.text
//            tab_view.sendTittleName(index, tab_view.getTab(index).title)
//            //tab_view.getTab(tab_view.currentIndex).item.children[0].filterChangedSlot(tab_view.getTab(index).title)

//        }
        onTextChanged:
        {
            tab_view.getTab(index).title = textArea.text
            tab_view.sendTittleName(index, tab_view.getTab(index).title)
        }
//        Keys.onEnterPressed:
//        {
//            console.log("Keys.onEnterPressed")
//            //text.editingFinished()
//        }




        function _onEnterPressed(event)
        {
            if ((event.modifiers & Qt.ControlModifier))
            {
                sendMessage()
                console.log("event.modifiers")
            }
            else
            {
                console.log("else")
                event.accepted = false;
//                oneTabView.forceActiveFocus()
//                //text.remove(text.length - 1,length )
//                text.editingFinished()
//                text.remove(text.length,length+1 )
            }
        }

        Keys.onReturnPressed: { _onEnterPressed(event) }
        Keys.onEnterPressed:
        {
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

    Button
    {
        id:closebutton
        width: buttonImageHeight
        height: buttonImageHeight
        //anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        anchors.topMargin: textArea.implicitHeight/2
        anchors.left: textArea.right//Math.round(image.right+100)
        anchors.leftMargin: 5
        visible: true
        Rectangle
        {
            height: parent.height-0
            width:parent.height-0
            color: oneTabView.color
            Image
            {
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
                onClicked:
                {
                    tab_view.contexMenuIndex = index
                    tab_view.currentIndex = index
                    //console.log("closeTab clicked index:" + index)
                    //closeTab(index)
                    Actions.closeTabAction.triggered()
                    //Actions.closeTabAct();
                    //Actions.closeTabAction();
                }
            }
        }
    }

    onXChanged:
    {
        var x = oneTabView.x
        //console.log("onXChanged ++ x =" + oneTabView.x)
        if (x < 0)
        {
            //console.log("onXChanged x<0)" )
            if (x < (-oneTabView.width / 2))
            {
                //console.log("x<(-oneTabView.width/2))")
                tab_view.moveTab(index,index - 1)

                // oneTabView.x = 0
                //tab_view.moveTab(index,index)
            }
            else
            {
                // oneTabView.x = 0
            }
        }
        else
        {
            //console.log("onXChanged x>0)")
            if (x > (oneTabView.width / 2))
            {
                //console.log("x>(oneTabView.width/2)")

                //console.log("tab_view.moveTab(index,index + 1)")
                //oneTabView.x = 0
                tab_view.moveTab(index,index + 1)
            }
            else
            {
                //oneTabView.x = 0
            }
        }
        //console.log("onXChanged -- x =" + oneTabView.x)
    }


    function getActiveTabColor() {
        var color = oneTabView.activeColor
        if (!styleData.selected) {
            if (index === tab_view.indexUnderMouse)
                color = oneTabView.beforeSelectColor
            else
                color = oneTabView.disactiveColor
        }
        return color
    }


    function getMinimumDrapWidth(index) {
        var xOffsetLeft = 0
        if (index!==0)
            xOffsetLeft = oneTabView.width*1//index
        return -xOffsetLeft
    }


    function getMaxDrapWidth(index)
    {
        var xOffsetRight = 0
        if (index!==(tab_view.count - 1))
        {
            xOffsetRight = oneTabView.width*1//(tab_view.count - 1 - index)
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

