import QtQuick 2.9
import QtQuick.Window 2.11
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import "./CustomToolButton"
import "./CustomComboBox"
import "../Action"
// Loader https://evileg.com/ru/post/191/
//https://www.iconfinder.com/iconsets/32x32-free-design-icons


ToolBar
{
    // DropArea {

    id: mainToolBar
    width: parent.width
    height:50
    //anchors.fill: parent
    property int toolButtonImplicitHeight: settingData.children[3].toolBarHeightToolButtonSetting
    property int toolButtonImplicitWidth: settingData.children[3].toolBarWidthToolButtonSetting
    property int toolButtonTextHeight: settingData.children[3].toolBarTextHeightToolButtonSetting
    property string toolButtonTextFont: settingData.children[3].toolBarTextFontToolButtonSetting
    property int comboBoxWidth: settingData.children[4].comboBoxWidthSetting
    property int toolButtonIconHeight: settingData.children[3].toolBarIconHeightSetting
    property int comboBoxHeight: settingData.children[4].comboBoxHeightSetting
    property int comboBoxTextHeight: settingData.children[4].comboBoxTextHeightSetting
    property string comboBoxStartTextFromSetting: settingData.children[1].fontfamilySetting
    property string comboBoxTextColor: settingData.children[4].comboBoxTextColor
    property string comboBoxBorderColor: settingData.children[4].comboBoxBorderColor
    focusReason : Qt.MouseFocusReason
    // height: butt.implicitHeight*2.8
    //CustomToolButtonIconText{}
    //height:150
    //visible : false
    //activeFocusOnTab:true
    Actions{id: actions}
    //GridLayout
    background: Rectangle

    {
        //implicitHeight: 40
               color: "white"
               anchors.fill:parent
    }
    Row
    {
        spacing: 0
        
        CustomToolButton{action: actions.fileOpenAction}
        CustomToolButton{action: actions.fileSaveAction}
        CustomToolButton{action: actions.downloadAction}
        CustomToolButton{action: actions.addAction}
        CustomToolButton{action: actions.stopAction}
        CustomToolButton{action: actions.playAction}
        CustomToolButton{action: actions.pauseAction}
        CustomToolButton{action: actions.markerAction}
        CustomToolButton{action: actions.searchAction}
        CustomToolButton{action: actions.clearAction}

//        Item {
//            Layout.fillWidth: true
//        }

    }
    //}



    //MouseArea
    //{ anchors.fill: parent
    //    drag.target:mainToolBar
    //    drag.axis: Drag.Drag.YAxis
    //    drag.minimumX: -1000
    //    drag.maximumX: 1000
    //    drag.minimumY: -1000
    //    drag.maximumY: 1000
    //}

}
