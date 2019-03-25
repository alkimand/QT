import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
//import QtQuick.Controls 2.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4

import "../ItemDelegat/ItemDelegate"
import "../ItemDelegat/HeaderDelegate"
import "../ItemDelegat/RowDelegat"
import "../../ContextMenu/TableViewContexMenu/HeaderContexMenu"
import "../../ContextMenu/TableViewContexMenu/ItemContexMenu"
import "../"
import "../ItemDelegat/HeaderDelegate"

//https://github.com/todbot/blink1/tree/master/qt/blink1control/qml/qml/Base style
//https://github.com/hdweiss/qt-creator-visualizer/blob/master/lib/qtcreator/qtcomponents/TableView.qml //++
//https://doc.qt.io/qt-5/qml-qtquick-tableview.html Docs
//https://habr.com/ru/post/138837/ - QML - C++
//https://stackoverrun.com/ru/q/11938643 //table
//https://stackoverflow.com/questions/50099412/custom-tableviewcolumn-delegate-problems
//https://doc.qt.io/qt-5/qml-qtquick-text.html about HorizontalAlignment

//Item
//{
// anchors.fill:paret
//import ModuleName 1.0
// qmlRegisterType <ModelServiseUDP> ("ModuleName", 1, 0, "TypeName");
//TableViewTest3
C1.TableView
//C1.TableView
{
    //find headerClickArea in BasicTableView.qml

    id: tableView
    //Drag.active: false
    anchors.fill: parent
    property int borderwidth: settingData.children[5].tableViewhHederDelegatBorderWidthSetting
    property int borderMoveAreaWidth: settingData.children[5].tableViewhHederDelegatBorderMoveAreaWidthSetting //if move column to
    property color borderMoveAreaColor: settingData.children[5].tableViewhHederDelegatBorderMoveAreaColorSetting
    property color bordercolor: settingData.children[5].tableViewhHederDelegatBorderColorSetting
    property color textcolor: settingData.children[5].tableViewhHederDelegatTextColorSetting
    property color backgroundcolor:settingData.children[5].tableViewhHederDelegatBuckgroundColorSetting
    property string textFont: settingData.children[5].tableViewhHederTextFontSetting
    property int textPointSize: settingData.children[5].tableViewhHederTextPointSizeSetting
    property bool textBolt: settingData.children[5].tableViewhHederTextBoltSetting
    property int textHorizontalAlignment: settingData.children[5].tableViewhHederTextHorizontalAlignmentSetting
    //property int textableViewerticalAlignment: settingData.children[5].tableViewhHederTextableViewerticalAlignmentSetting
    //color:settingData.children[5].tableViewhHederDelegatBackgroundColorSetting
    property int buttonImageHeight: settingData.children[5].tableViewhHederImageHeightSetting

    property string imageFilterSource: settingData.children[5].tableViewhHederImageFilterIconSetting
    property string imageFilterAddSource: settingData.children[5].tableViewhHederImageFilterAddIconSetting
    property string imageFilterDeleteSource: settingData.children[5].tableViewhHederImageFilterDeleteIconSetting

    property string imageSortAscendingSource: settingData.children[5].tableViewhHederImageSortAscendingIconSetting
    property string imageSortDescendingSource: settingData.children[5].tableViewhHederImageSortDescendingIconSetting

    property int widthSetting: settingData.children[5].tableViewhWidthSetting
    property int heightSetting: settingData.children[5].tableViewhHeighSetting

    property bool filterIsACtive: true//--
    property bool sortIsACtive: false//true
    property int sortStatus: 1//true--
    property var tittle: ["Date/Time", "TimeStamp", "Count", "Zone Id", "Servise Name", "Function Name", "Line Number", "Message"]//+-
    property int name: 0//true--
    property int tittleCount: 8 //in header
    property int mouseMoveStartX: 0
    property int mouseMoveFinishX: 0
    property int selectRow: -1
    property string type: "NONE"

    property var titles :[]
    property var roleList : []





    //https://stackoverflow.com/questions/30818886/qml-window-resize-move-flicker - resize bug



    //++
    itemDelegate: ItemDelegate {}
    headerDelegate: HeaderDelegate { id:headDelegat }
    rowDelegate:RowDelegat{}
    ItemContexMenu{id:itemContexMenu}
    HeaderContexMenu{id:headerContexMenu }
    //--
// https://stackoverflow.com/questions/27230818/qml-tableview-with-dynamic-number-of-columns

//    property var titles:
//    {
//        var t=[]
//        for(var i=0;i< columnCount; i++)
//        {
//            t.push(getColumn(i).title)
//        }
//        return t
//    }

//       // ["0" , "2", "Date/Time", "TimeStamp", "Count", "Zone Id", "Servise Name", "Function Name", "Line Number", "Message"]
//    property var curTitles:
//    {
//        var t=[]
//        for(var i=0;i< columnCount; i++)
//        {
//            t.push(getColumn(i).title)
//        }
//        return t
//    }

//    onTitlesChanged:
//    {
//        for(var i=0; i<titles.length; i++)
//        {
//            if(curTitles.indexOf(titles[i])==-1)
//            {
//                var column = addColumn(columnComponent)
//                column.title=titles[i]
//                column.role=titles[i]
//            }
//        }
//        for(var i=curTitles.length-1;i>=0;i--)
//        {
//            if(titles.indexOf(curTitles[i])==-1)
//            {
//                removeColumn(i)
//            }
//        }
//    }


























    property int test: implicitWidth/10
    //implicitWidth:window.width

    function clearDataPool()
    {
        //console.log("clearDataPool")
        client.clearDataPool()
    }

    function saveAs()
    {
        //if (tableView.type!== "NONE")
        console.log("BaseTableView:saveAs()")
        client.saveAsSlot()
        console.log("BaseTableView:client.documentTittle: "+client.documentTittle)
        if (client.documentTittle !== "DEFAULT")
        tabView.getTab(tabView.contexMenuIndex).title = client.documentTittle
        console.log("saveAs()")
    }

    function save()
    {
        console.log("BaseTableView:save()")
        if (tableView.type!== "NONE")
        {
            client.saveSlot()
            if (client.documentTittle !== "DEFAULT")
            tabView.getTab(tabView.contexMenuIndex).title = client.documentTittle
            console.log(" client.documentTittle: "+ client.documentTittle)

        }
    }

    function openInExplorer()
    {
        if (tableView.type!== "NONE")
            client.openInExplorerSlot()
        //console.log("openInExplorer()")
    }

    function openInDesktopServices()
    {
        if (tableView.type!== "NONE")
            client.openInDesktopServicesSlot()
        //console.log("openInExplorer()")
    }

    function sendNameDocument(tittle)
    {
        if (tableView.type!== "NONE")
            client.setNameDocumentSlot(tittle)
    }

    function filterChanged(column, text)
    {
        if (tableView.type!== "NONE")
            client.filterChangedSlot(column, text)
        //console.log("tableView.filterChanged(column, text)")
    }

    function removeColumnTable()
    {
       // if (tableView.type!== "NONE")
          //  client.filterChangedSlot(column, text)
        console.log("tableView.removeColumnTable")
        titles =  ["DATE", "TIME", "COUNT", "SERVICENAME", "LINENUMBER", "MESSAGE"]
      //  titles.length

    }
}

