import QtQuick 2.12
import "../../Menu/TabContextMenu"

MouseArea {
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
    onClicked: {
        //console.log("onClicked" )
        if (mouse.button === Qt.RightButton) {
            tab_view.contexMenuIndex = index
            tabContextMenu.popup()
            //console.log("oneTabView:mouse.button === Qt.RightButton" )
        }
        else {
            //console.log("mouse.button " + mouse.button)
            tab_view.contexMenuIndex = index
            tab_view.currentIndex = index
            //parent.parent.tabBarRectColor = settingData.children[2].tabRectangleColorIsSelictedSetting
        }
    }
}
