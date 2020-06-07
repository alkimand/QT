import QtQuick 2.0

Loader {
    id: loader
    property string sourceIconPathLoader : parent.action.icon.source
    property string textFirstLineLoader : parent.action.text
    property string textFontLoader:parent.textFont

    property int textHeightLoader : parent.textHeight

    property color buttonBackColorLoader:parent.buttonBackColor

    anchors.fill: parent
    source: setSourceLoader()

    function setSourceLoader() {
        var toolBarStateToolButton =  parent.button_type
        var loading_file=""
        if (toolBarStateToolButton === 1)
            loading_file =  "./CustomToolButtonIcon.qml"
        if(toolBarStateToolButton === 2)
            loading_file =  "./CustomToolButtonText.qml"
        if(toolBarStateToolButton === 3)
            loading_file = "./CustomToolButtonIconText.qml"

        //console.log("loading_file:" + loading_file)
        return loading_file
    }
}
