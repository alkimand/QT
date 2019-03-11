import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
//import QtQuick.Controls 2.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import com.ics.demo 1.0

import ModuleName 1.0
//import TableModel 1.0
import "../ItemDelegat/ItemDelegate"
import "../ItemDelegat/HeaderDelegate"
import "../ItemDelegat/RowDelegat"
import "../../ContextMenu/TableViewContexMenu/HeaderContexMenu"
import "../../ContextMenu/TableViewContexMenu/ItemContexMenu"
import "../"
//https://stackoverrun.com/ru/q/11938643 //table
//https://stackoverflow.com/questions/50099412/custom-tableviewcolumn-delegate-problems
//https://doc.qt.io/qt-5/qml-qtquick-text.html about HorizontalAlignment
//import "src/TableView/ItemDelegat/ItemDelegate"
//import "../TableView/ItemDelegat/HeaderDelegate"
import "../ItemDelegat/HeaderDelegate"
//https://github.com/todbot/blink1/tree/master/qt/blink1control/qml/qml/Base style
//https://github.com/hdweiss/qt-creator-visualizer/blob/master/lib/qtcreator/qtcomponents/TableView.qml //++
//https://doc.qt.io/qt-5/qml-qtquick-tableview.html Docs
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
    property int tittleCount: 8
    property int mouseMoveStartX: 0
    property int mouseMoveFinishX: 0
    property int indexToMove: -1//--
    property int indexToMoveSide: -1//--
    property var positionArray: []//["Date/Time", "TimeStamp", "Count", "Zone Id", "Servise Name", "Function Name", "Line Number", "Message"]//--
    property int selectRow: -1//--
    // property var rects: ({}) //--
    property string modelName:"testmodel0"

    //    ModelServiseUDP
    //    {
    //        id: myObj
    //        // someProperty: 10
    //    }

    ClientUDP
    {
        id: model2
    }




    // model: model2//someModel
    model: sourceModel
    // model: sourceModel//TableModel {}
    //Also see BasicTableViewStyle.qml from E:\QT\5.13.0\mingw73_32\qml\QtQuick\Controls

    //headerDelegate
    //anchors.topMargin: 100




    property int test: implicitWidth/10
    //width: window.width
    implicitWidth:window.width

    //    rowDelegate: Rectangle
    //    {
    //        id: rect

    //            Component.onCompleted:
    //            {
    //                var id = sourceModel.get(sourceModel.mapRowToSource(styleData.row))["id"]
    //                tableView.rects[id] = rect;
    //            }
    //        }
    C1.TableViewColumn
    {
        role: "description"
        title: "Description"
        //width: window.width/5
    }
    C1.TableViewColumn
    {
        role: "value"
        title: "Value"
        width: window.width/5
    }
    //    C1.TableViewColumn
    //    {
    //        role: "zoneId"    // Эти роли совпадают с названиями ролей в C++ модели
    //        title: "Zone Id"
    //        width: window.width/5
    //    }
    //    C1.TableViewColumn
    //    {
    //        role: "count"    // Эти роли совпадают с названиями ролей в C++ модели
    //        title: "Count"
    //        width: window.width/5
    //    }
    //    C1.TableViewColumn
    //    {
    //        role: "serviceName"    // Эти роли совпадают с названиями ролей в C++ модели
    //        title: "Service Name"
    //        width: window.width/5
    //    }

    //C1.TableWithHeader{id:qw}

    // rowSpacing: 2
    //columnSpacing: 5
    //anchors.left:window.left
    //anchors.right:window.right
    // boundsBehavior:Flickable.StopAtBounds //https://doc.qt.io/qt-5/qml-qtquick-flickable.html#boundsBehavior-prop
    // anchors.topMargin:  150
    //implicitWidth: 200
    // ScrollBar.horizontal: ScrollBar {}
    //ScrollBar.vertical: ScrollBar {}
    //rowHeightProvider: function (row) { return 25 }

    // property var columnWidths: [test, tableView.implicitWidth/10, tableView.implicitWidth/10, tableView.implicitWidth/10, tableView.implicitWidth/10, tableView.implicitWidth/10, 2*tableView.implicitWidth/10, 2*implicitWidth/10]
    // columnWidthProvider: function (column) { return columnWidths[column] }

    //topMargin: header.implicitHeight
    itemDelegate: ItemDelegate {}
    headerDelegate: HeaderDelegate { id:headDelegat }


    ListModel
    {
        id: sourceModel
        ListElement {
            date: "Moby-Dick"
            timeStamp: "Herman Melville"
            count:"1"
            zoneId:"3"
            serviceName:"3"
            functionName:"4"
            lineNumber:"5"
            message:"6"

        }

        ListElement
        {
            date: "DickMoby"
            timeStamp: "lle"
            count:"6"
            zoneId:"5"
            serviceName:"4"
            functionName:"3"
            lineNumber:"2"
            message:"1"
        }
    }

    rowDelegate:RowDelegat{}
    ItemContexMenu{id:itemContexMenu}
    HeaderContexMenu{id:headerContexMenu }


}
