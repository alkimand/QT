import QtQuick 2.12
import "../HeaderDelegate"
Loader
{
    id: headerloader
    property int index
    //oneTabView.x = 0
   // property int curentIndex:123
    source: "../HeaderDelegate/HeaderDelegate.qml" //setSourceLoader()// "./CustomToolButtonIconText.qml"//++
    //Component.onCompleted: console.log("headerloader+")
    function setSourceLoader()
    {
//        var toolBarStateToolButton = settingData.children[3].toolBarStateToolButtonSetting
//        if (toolBarStateToolButton === 1)
//            //parent.source = "./CustomToolButton/CustomToolButtonIcon.qml"
//            return "./CustomToolButtonIcon.qml"
//        if(toolBarStateToolButton === 2)
//            return "./CustomToolButtonText.qml"
//        if(toolBarStateToolButton === 3)
//            return "./CustomToolButtonIconText.qml"
//        console.log("toolBarStateToolButton:" + toolBarStateToolButton)
    }

}
