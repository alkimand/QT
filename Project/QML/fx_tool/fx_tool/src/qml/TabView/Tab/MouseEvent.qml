import QtQuick 2.12
import "../../Menu/TabContextMenu"
import Actions 1.0

MouseArea {
    id : mouseArea
    acceptedButtons: Qt.AllButtons
    anchors.fill: parent
    hoverEnabled:true
    propagateComposedEvents : false
    preventStealing: true

    drag.target: root
    drag.axis: Drag.XAxis
    drag.minimumX: getMinimumDrapWidth(styleData.index)
    drag.maximumX: getMaxDrapWidth(styleData.index)//oneTabView.width //- rect.width
    //pressAndHoldInterval: 0
    //tabView.currentIndex = tabView.count - 1
    //hoverEnabled:true
    z:0

    onClicked: {
      //  console.log("mouse.button " + mouse.button)
       // console.log("onClicked index= "+ styleData.index)
       // console.log("tab_view.currentIndex="+ tab_view.currentIndex )
       // console.log("tab_view.contexMenuIndex="+ tab_view.contexMenuIndex )
       tab_view.contexMenuIndex = styleData.index
       tab_view.indexUnderMouse = styleData.index

        if (mouse.button === Qt.RightButton) {


            tabContextMenu.popup()
            //console.log("oneTabView:mouse.button === Qt.RightButton" )
        }
        else if (mouse.button === Qt.LeftButton) {
            //console.log("mouse.button " + mouse.button)
           // tab_view.contexMenuIndex = styleData.index
        //    tab_view.indexUnderMouse = styleData.index
            tab_view.currentIndex = styleData.index
            root.activateButton()
        }
        else if (mouse.button === Qt.MidButton) {
            Actions.closeTabAct()
        }

    }
}
