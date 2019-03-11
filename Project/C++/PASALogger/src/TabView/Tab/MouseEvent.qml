import QtQuick 2.12
import "../../ContextMenu/TabContextMenu"
MouseArea
{
    id : mouseArea
    acceptedButtons: Qt.LeftButton | Qt.RightButton
    anchors.fill: parent
    hoverEnabled:true
    propagateComposedEvents : true
    preventStealing: true

    drag.target:oneTabView
    drag.axis: Drag.XAxis
    drag.minimumX: getMinimumDrapWidth(index)
    drag.maximumX: getMaxDrapWidth(index)//oneTabView.width //- rect.width
    //pressAndHoldInterval: 0
    //tabView.currentIndex = tabView.count - 1
    //hoverEnabled:true
    z:0
    onClicked:
    {

        //console.log("onClicked" )
        if (mouse.button === Qt.RightButton)
        {
            tabView.contexMenuIndex = index
            tabContextMenu.popup()
            //console.log("oneTabView:mouse.button === Qt.RightButton" )
        }
        else
        {
            //console.log("mouse.button " + mouse.button)
            tabView.contexMenuIndex = index
            tabView.currentIndex = index
            //parent.parent.tabBarRectColor = settingData.children[2].tabRectangleColorIsSelictedSetting
        }
    }
}
