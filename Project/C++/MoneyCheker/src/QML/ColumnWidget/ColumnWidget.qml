import QtQuick 2.12
import "ItemLoader/ButtonRow"
import "../Action"
import "../Setting"

//Item {
//:text_.text
//property int columnWidth//:text_.text
//property int titleBlockHeight :200//:text_.text

Rectangle {
    id:root
    property string title
    property Actions actions
    property int columnWidgetType
    property color rootClr: root.color
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    color: settingData.columnSettings.columnFreeSpaceColor
    //anchors.left: root.left
    border.color: "yellow"
    border.width: 1

    Text {
        id:text_
        anchors.top: root.top
        anchors.left: root.left
        height: settingData.columnSettings.titleBlockHeight
        font.family: "Helvetica"
        font.pointSize: 20
        color: "black"
        text: title
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Loader
    {
        id: loader_
        //anchors.margins: 4
        //height: calc(parent.height - text_.height)
        //anchors.left:
        anchors.top: text_.bottom
        anchors.bottom: root.bottom
        property Actions actions: root.actions
        //property int test:10
        //actions: root.actions
        //source: "../ColumnWidget/ItemLoader/ButtonRow/ButtonRow.qml"
        //visible: false

        //Component.onCompleted: console.log("loader_:" + loader_.actions.fileOpenAction.text)


        //property string type: "NONE"
        Component.onCompleted: {

            loader_.setSource(root.columnWidgetType)
        }
        //console.log(loader_.height)

        function setSource(name)
        {

            loader_.source = ""
            //console.log("name:" + name)
            switch (name)
            {
            case SettingData.ColumnWidgetType.EMPTY_SPACE :
                //console.log("EMPTY_SPACE")
                source= ""
                text_.text=""
                break

            case SettingData.ColumnWidgetType.BUTTON_SPACE :
                //console.log("BUTTON_SPACE");
                source= "../ColumnWidget/ItemLoader/ButtonRow/ButtonRow.qml";
                text_.text=""
                break;

            case SettingData.ColumnWidgetType.CALCULATOR_SPACE :
                //console.log("CALCULATOR_SPACE");
                root.width = settingData.appContentWidgetSettings.contentCalculatorPageWidth;
                //source= "../ColumnWidget/CalculatorArea/CalculatorArea.qml"
                source= "../Pages/Page_1/CalculatorArea/CalculatorArea.qml"
                text_.text=qsTr("Calculator")
                break;

            case SettingData.ColumnWidgetType.MORTAGE_SPACE :
                //console.log("MORTAGE_SPACE");
                //root.width = settingData.appContentWidgetSettings.contentCalculatorPageWidth;
                source= "../ColumnWidget/ItemLoader/ButtonRow/ButtonRow.qml"
                text_.text=qsTr("Mortage")
                break;

            }
        }
    }

}
