import QtQuick 2.9
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
//import QtLocation 5.11
import QtGraphicalEffects 1.0
//import Qt.labs.handlers 1.0
//import "./../../../"
import "../../../ContextMenu"
import "../../Tab"
import "../../../ContextMenu/TabContextMenu"
Rectangle
{
    id:oneTabView
    property int borderwidth: settingData.children[2].tabBorderReactangleWidthSetting
    property int buttonImageHeight: settingData.children[2].tabButtonImageHeightSetting
    property string borderRectColor: settingData.children[2].tabBorderRectColorSetting
    property string textFont: settingData.children[2].tabOneTabTextFontSetting
    property int textHeight: settingData.children[2].tabOneTabTextHeightSetting
    property string imageSaveSourse: settingData.children[2].tabSaveButtonIconSetting
    property string imageCloseSource: settingData.children[2].tabCloseButtonIconSetting
    property color tabBarTextColor:settingData.children[2].tabBarTextColorSetting
    property color tabBarRectColorIfSelectingStart:settingData.children[2].tabBarRectColorIfSelectingStartSetting
    property color tabBarRectColor:styleData.selected?settingData.children[2].tabRectangleColorIsSelictedSetting: settingData.children[2].tabRectangleColorIsNotSelictedSetting
    color: getActiveTabColor()//styleData.selected?settingData.children[2].tabRectangleColorIsSelictedSetting: settingData.children[2].tabRectangleColorIsNotSelictedSetting
    border.width:settingData.children[2].tabBorderWidthSetting//tabBarRectColor//
    property string test:  "test Rectangle"
    implicitWidth:Math.round(text.implicitWidth + imageFilesave.width + closebutton.width + settingData.children[2].tabIndentSetting)


    signal senTab()
    onSenTab:
    {
        //console.log("onSenTab+" )
        if (tabView.contexMenuIndex===index)
        {
            oneTabView.renameTab()
            console.log("oneTabView.renameTab" )
        }
    }
    Connections
    {
        target:tabView
        onRenametab:
        {
            oneTabView.senTab()
            //console.log("oneTabView.senTab()" )
        }
    }




    MouseArea
    {
        anchors.fill: parent
        hoverEnabled:true
        propagateComposedEvents : true
        preventStealing: true
        drag.target:oneTabView
        drag.axis: Drag.XAxis
        drag.minimumX: getMinimumDrapWidth(index)
        drag.maximumX: getMaxDrapWidth(index)
        z:1
        onEntered:
        {
            tabView.indexUnderMouse = index
            //console.log("onEntered" )
        }
        onExited:
        {
            tabView.indexUnderMouse = -1
        }
        onReleased:
        {
            oneTabView.x = 0
        }



    }
    implicitHeight: settingData.children[2].tabimplicitHeightSetting
    //(auxiliaryTabIndex===index)?console.log: ("auxiliaryTabIndex===index:"index)
    Rectangle
    {
        id:leftBorder
        visible: if (!styleData.selected)  false
                 else   true
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        width: borderwidth;
        height: parent.height
        color: borderRectColor
    }

    Rectangle
    {
        id:topBorder
        visible: if (!styleData.selected)  false
                 else   true
        anchors.top: parent.top
        anchors.left: parent.left
        height: borderwidth
        width: parent.width
        color: borderRectColor
        //color: "#f9d810"
    }

    Rectangle
    {
        id:rightBorder
        visible: if (!styleData.selected)  false
                 else   true
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        width: borderwidth;
        height: parent.height
        color: borderRectColor
    }

    Rectangle
    {
        id:bottomBorder
        visible:if (styleData.selected)  false
                else   true
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        height: borderwidth
        width: parent.width
        // gradient: Gradient.PerfectBlue
        color: borderRectColor
    }

    Button
    {
        id:savebutton
        width: buttonImageHeight
        height: buttonImageHeight
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: leftBorder.right//Math.round(image.right+100)
        anchors.leftMargin: 5
        //    visible: true
        Rectangle
        {
            height: parent.height-0
            width:parent.height-0
            anchors.centerIn: parent
            color: oneTabView.color
            Image
            {
                id: imageFilesave
                //anchors.right: text.left
                //anchors.left: leftBorder.right
                //anchors.verticalCenter: parent.verticalCenter
                fillMode: Image.PreserveAspectFit
                anchors.centerIn: parent
                //sourceSize.height: closebutton.background.height - 6
                // height: sourceSize.height
                height: parent.height-0
                width:parent.height-0
                visible: true
                source: imageSaveSourse
            }
            MouseArea
            {
                anchors.fill: parent
                hoverEnabled:true
                propagateComposedEvents : true
                preventStealing: true
                onClicked:
                {
                    tabView.contexMenuIndex = index
                    tabView.currentIndex = index
                    console.log("savebutton cliked")
                    console.log(styleData.title)
                    //console.log(text.length)
                }
            }
        }
    }

    TextArea
    {
        id: text
        anchors.left: savebutton.right//Math.round(image.right+100)
        anchors.leftMargin: 0
        // anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: styleData.title
        font.family : textFont
        font.pointSize : textHeight
        color: tabBarTextColor
        inputMethodHints: Qt.ImhNoPredictiveText

        onEditingFinished:
        {
            tabView.getTab(index).title = text.text
        }
//        Keys.onEnterPressed:
//        {
//           text.editingFinished()
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
        Keys.onEnterPressed: { _onEnterPressed(event) }
    }

    Rectangle
    {
        property string name : "centralReactangle"
        id:centralReactangle
        opacity: 0
        anchors.right: closebutton.left
        anchors.left: savebutton.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        MouseEvent{}
    }
    Rectangle
    {
        property string name : "topReactangle"
        id:topReactangle
        opacity: 0
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: savebutton.top
        MouseEvent{}
    }

    Rectangle
    {
        opacity: 0
        anchors.right: savebutton.left
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        MouseEvent{}
    }

    Rectangle
    {
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
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: text.right//Math.round(image.right+100)
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
            MouseArea
            {
                anchors.fill: parent
                hoverEnabled:true
                propagateComposedEvents : true
                preventStealing: true
                onClicked:
                {
                    tabView.contexMenuIndex = index
                    tabView.currentIndex = index
                    console.log("closeTab clicked index:" + index)
                    closeTab(index)
                }
            }
        }
    }

    TabContextMenu { id: tabContextMenu }

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
                tabView.moveTab(index,index - 1)

                // oneTabView.x = 0
                //tabView.moveTab(index,index)
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

                //console.log("tabView.moveTab(index,index + 1)")
                //oneTabView.x = 0
                tabView.moveTab(index,index + 1)
            }
            else
            {
                //oneTabView.x = 0
            }
        }
        //console.log("onXChanged -- x =" + oneTabView.x)
    }
    function getActiveTabColor()
    {
        var color
        if (styleData.selected)
        {
            color = settingData.children[2].tabRectangleColorIsSelictedSetting
        }
        else
        {
            if (index === tabView.indexUnderMouse)
            {
                color = settingData.children[2].tabBarRectColorIfSelectingStartSetting
            }
            else
            {
                color = settingData.children[2].tabRectangleColorIsNotSelictedSetting
            }
        }
        return color
    }

    function getMinimumDrapWidth(index)
    {
        var xOffsetLeft = 0
        if (index!==0)
        {
            xOffsetLeft = oneTabView.width*1//index
        }
        return -xOffsetLeft
    }

    function getMaxDrapWidth(index)
    {
        var xOffsetRight = 0
        if (index!==(tabView.count - 1))
        {
            xOffsetRight = oneTabView.width*1//(tabView.count - 1 - index)
        }
        //console.log("getMaxDrapWidth(index) + =" + xOffsetRight)
        return  xOffsetRight


    }

    function renameTab()
    {
        text.selectAll()
        text.forceActiveFocus()
    }

}

