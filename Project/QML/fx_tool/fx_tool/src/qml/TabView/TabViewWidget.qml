import QtQuick 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.12
import "./Style"

C1.TabView {
    id: root
    anchors.fill:parent
    //anchors.leftMargin: 5
    //anchors.leftMargin: 50
    //property int curIndex: 0
    property string title:        "Default"
    property int contexMenuIndex:               -1
    property int indexUnderMouse:               -1
    property string current_temp_id:            "0"
    property int current_temp_view_id:           0

    signal renametab()
    signal refreshTab()

    style: TabViewStyle{}

    onCurrentIndexChanged: {
        for (var i = 0  ;i < root.count;i++){
            refreshTab()
        }
    }

    Component {
        id: table_view_template
        Rectangle {
            anchors.fill: parent
            color: "white"
            z:0
            Rectangle {
                anchors.fill: parent
                anchors.leftMargin:5
                color: "white"
                z:1

                //                function test() {
                //                    console.log("test Rectangle")
                //                }

                Loader {
                    id: table_view_loader
                    anchors.fill: parent
                    anchors.rightMargin:0
                    anchors.topMargin: 10
                    anchors.bottomMargin: 5
                    property string current_id_: root.current_temp_id
                    property int view_id_: root.current_temp_view_id
                    source: "../TableView/BaseTableView.qml"
                    Component.onCompleted: {
                        var temp = root.current_temp_id; //hack
                        current_id_ = temp;
                        temp = root.current_temp_view_id
                        view_id_ = temp;
                        // console.log("view_id_ =" + view_id_);
                    }

                    //                    function test() {
                    //                        console.log("test Loader")
                    //                    }
                }
            }
        }
    }

    function createTab(item_id) {
        //console.log("createTab+" + item_id);
        root.current_temp_view_id ++;
        var item_title = app_data.getFileTitleByID(item_id);
        root.current_temp_id = item_id;
        root.addTab(item_title,table_view_template);
        root.currentIndex = root.count - 1;
        root.contexMenuIndex = root.currentIndex;
    }



    function saveTab(index) //ToDo
    {
        //root.removeTab(index)
    }
    function selectTab(index) //ToDo //--
    {
        //var tab=getTab(index)
        console.log("selectTab + ")
        console.log("index = +" + index)
        console.log("root.getTab(index).children[0].rowHeight = " + root.getTab(index).children[0].rowHeight)
        root.getTab(index).children[0].selectTab(2)
        // root.selection.selectAll()
        // tableView.selection.clear()
        // tableView.selection.select(row)
        //root.removeTab(index)
    }
    function renameTab(index) {
        console.log("root:renametab()")
        root.renametab()
    }

    function sendTittleName(m_index, tittle)
    {
        //console.log("root:sendTittleName:index:" + m_index)
        // console.log("root:sendTittleName:tittle:" + tittle)

        //    if (root.getTab(m_index).item.children[0].type !== "NONE")

        //if (root.getTab(m_index).item.children[0].type !== "NONE")
        {
            //console.log("BaseTableView:sendTittleName:" + tittle)
            //console.log("root.getTab(m_index).item.children[0].type:" + root.getTab(m_index).type)
            //console.log("root.getTab(m_index).item.children[0].type:" + root.getTab(m_index).item.type)
            //console.log("0" + root.getTab(m_index).item.type)

            //console.log("1" + root.getTab(m_index).item.children[0].type)
            //console.log("root.getTab(m_index).item.children[0].type:" + root.getTab(m_index).type)
            //root.getTab(m_index).item.children[0].sendNameDocument(tittle)
            //sendTittleName(m_index, tittle)
        }
    }


    function openInExplorer()
    {
        //        text.selectAll()
        //        text.forceActiveFocus()
        console.log(root.getTab(root.contexMenuIndex).item.children[0].type)
        console.log("openInExplorer")
        if (root.getTab(root.contexMenuIndex).item.children[0].type !== "NONE")
            root.getTab(root.contexMenuIndex).item.children[0].openInExplorer()
    }

    function openInDesktopServices()
    {
        //        text.selectAll()
        //        text.forceActiveFocus()
        console.log("openInDesktopServices")
        if (root.getTab(root.contexMenuIndex).item.children[0].type !== "NONE")
            root.getTab(root.contexMenuIndex).item.children[0].openInDesktopServices()
    }

    function removeColumnTab()
    {
        //        text.selectAll()
        //        text.forceActiveFocus()
        //console.log("removeColumnTab")
        root.getTab(root.contexMenuIndex).item.children[0].removeColumnTable()
    }

    function restoreColumnTab()
    {
        //        text.selectAll()
        //        text.forceActiveFocus()
        //console.log("restoreColumnTab")

        root.getTab(root.contexMenuIndex).item.children[0].restoreColumnTable()
    }
}
