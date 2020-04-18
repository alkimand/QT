import QtQuick 2.0
//import "./"

Loader
{
    id: loader
    property string sourceIconPathLoader : parent.action.icon.source //sourceIconPath//"../../images/ToolBarIcon/qt-logo.png" // defoult image
    property string textFirstLineLoader : parent.action.text //parent.textFirstLine                         // defoult text
    property int textHeightLoader : parent.textHeight
    property string textFontLoader:parent.textFont
    property color buttonBackColorLoader:parent.buttonBackColor
    //: "../../images/ToolBarIcon/fileopen.png"
    anchors.fill:parent
    //source : "./CustomToolButton/CustomToolButtonIcon.qml"
    // setSourceLoader()
    source:setSourceLoader()// "./CustomToolButtonIconText.qml"//++
    //source: "./CustomToolButtonIcon.qml"//+-
    //source: "./CustomToolButtonText.qml"//+-

    //toolBarStateToolButtonSetting
    //    (Settings.children[3].toolBarStateToolButtonSetting===1) ?source: "./CustomToolButtonIconText.qml": source: "./CustomToolButtonIconText.qml"
    //onStatusChanged: console.log("toolBarStateToolButton=")
//    Connections
//    {
//       target: loader

//           onChoiseLoaderSourse:
//       {
//           loader.setSourceLoader()
//       }
//    }
    //onItemChanged: setSourceLoader()
   // source: setSourceLoader()

    function setSourceLoader()
    {
        var toolBarStateToolButton = Settings.children[3].toolBarStateToolButtonSetting
        if (toolBarStateToolButton === 1)
            //parent.source = "./CustomToolButton/CustomToolButtonIcon.qml"
            return "./CustomToolButtonIcon.qml"
        if(toolBarStateToolButton === 2)
            return "./CustomToolButtonText.qml"
        if(toolBarStateToolButton === 3)
            return "./CustomToolButtonIconText.qml"
        console.log("toolBarStateToolButton:" + toolBarStateToolButton)
    }

}
