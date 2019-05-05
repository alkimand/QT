import QtQuick 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../../ToolBar/CustomToolButton"
// https://evileg.com/ru/post/65/

Rectangle
{

    id:control
    width: 400
    height: 200
    visible: (styleData.column===tableView.filterDialogActiveColumn)?true:false
    //    color: "red"
    anchors.top: parent.bottom
    anchors.left: parent.left
    border.width : 2
    border.color : "black"

    //z:1



    //     Dialog
    //     {
    //         //anchors.top:filterTableView.bottom
    //        /// x:control.x
    //         //y:control.y-filterTableView.height

    //           standardButtons: Dialog.Ok | Dialog.Cancel
    C1.TableView
    {
        id: filterTableView
        //anchors.fill: parent
        anchors.top: parent.top
        anchors.left: parent.left
        width: control.width
        height: 150
        frameVisible: false
        sortIndicatorVisible: true
        model:sourceModel
//        rowDelegate:
//        {

//        }
        C1.TableViewColumn
        {
            id: filterTextColyumn
            title: "Title"
            role: "title"
//            delegate:C1.TextArea
//            {
//                text: styleData.value
//            }

            //movable: false
            //resizable: false
            width: 150
        }

        C1.TableViewColumn
        {
            id: enabledColyumn
            width: (filterTableView.width-filterTextColyumn.width)/3
            //height: 50
            delegate:
                C1.CheckBox
            {
                //checked: true
                checked: model.enable
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 3


            }

            title: "Enable"
            role: "enable"
            //movable: false
           // resizable: false
        }

        C1.TableViewColumn
        {
            id: includeColyumn
            width:(filterTableView.width-filterTextColyumn.width)/3
            delegate:
                C1.CheckBox
            {
                //checked: true
                checked: model.include
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 3
                width: 50
            }

            title: "Include"
            role: "include"


           // movable: false
           // resizable: false

        }


        C1.TableViewColumn
        {
            id: excludeColyumn
            width: (filterTableView.width-filterTextColyumn.width)/3
            delegate: C1.CheckBox
            {
                id: checkBox
                checked: model.exclude
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 3

                //    onVisibleChanged: //if (visible) checked = model.check
                // onClicked: //model.check = checked
            }

            title: "Exclude"
            role: "exclud"
            movable: false
            resizable: false
        }


        ListModel
        {
            id: sourceModel
            ListElement
            {
                title: "Service"
                enable: true
                include: true
                exclude:false
                author: "Herman Melville"
            }
            ListElement
            {
                //id: listElement
                title: "status"
                enable: true
                include: false
                exclude:true
                author: "Mark Twain"
            }
        }
    }



    ToolBar
    {
        id: filterToolBar
        width: control.width
        anchors.top: filterTableView.bottom
        anchors.left: parent.left
        height:control.height-filterTableView.height
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
        background: Rectangle
        {
            color: "white"
            //gradient: Gradient.PerfectBlue
            anchors.fill:parent
        }
        Row
        {
            id:buttonRow
            spacing: 0
            CustomToolButton{action: actions.addNewFilterAction}
            CustomToolButton{action: actions.deleteFilterAction}
            //CustomToolButton{action: actions.activeAllFilterAction}
           // CustomToolButton{action: actions.inactiveAllFilterAction}
            CustomToolButton{action: actions.closeFilterDialogAction}
        }
    }
}

