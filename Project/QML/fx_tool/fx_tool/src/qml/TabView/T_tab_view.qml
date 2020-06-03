import QtQuick 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.12

//import"../TableView/TableView"

//https://stackoverflow.com/questions/34410260/trouble-setting-activefocus-to-item-in-a-qml-root
//https://switch-case.ru/61977594 -selection
//import TableModel 1.0
//import "../TableView/"
//
import "./Style"

//import "../root/Style/Tab"
//import "../TableView/ItemDelegat/HeaderDelegate"
//import "../TableView/TableView" as MyTable

C1.TabView {
    id: root
    anchors.fill:parent
    //property int curIndex: 0
    property string newWindowTitle: "FreeYTVDownloader" //"new window " + root.count
    property int contexMenuIndex: -1
    property int indexUnderMouse: -1
    signal renametab()
    style: TabViewStyle{}
    Component
    {
        id:newTabComponent
        //property string type: "NONE1"
        Loader
        {
            id: loader
            anchors.fill: parent
            //source: "../ChoiceItem/ChoiceWindow.qml"
            //source = "../TableView/TableView/TableUDP.qml"
			
            property string type: "NONE"

            function setTable(name)
            {

                loader.source = ""
                //console.log("name:" + name)
                switch (name)
                {
                case "UDP logger" :
                    console.log("UDP logger")
                    //source= "../TableView/TableView/TableUDP.qml"

                    break
                case "Text logger" :
                    console.log("Text logger")
                    //source= "../TableView/TableView/TableText.qml"

                    break
                }
                //  root.getTab(contexMenuIndex).title = root.getTab(contexMenuIndex).title + ".txt"
            }
        }

    }

    Component
    {
        id:newTextComponent
        Loader
        {
            id: loader
            anchors.fill: parent
           // source: "../TableView/TableView/TableText.qml"
        }

    }

    function addTextComponent()
    {
        root.addTab(newWindowTitle,newTextComponent)
        root.currentIndex = root.count - 1
    }


//    function onCurIndChangeHeandler()
//    {
//        addNewTab()
//    }

//    function setStatus(status)
//    {
//        console.log("C1.root setStatus(status):" + status )
//        if (root.getTab(root.currentIndex).item.children[0].type === "UDP_CLIENT_TYPE")
//            root.getTab(root.currentIndex).item.children[0].setStatus(status)
//    }

    //move to  main
//    function saveAs()
//    {
//        //console.log("C1.root saveAs()")
//        if (root.getTab(root.currentIndex).item.children[0].type !== "NONE")
//            root.getTab(root.currentIndex).item.children[0].saveAs()

//    }

//    function save()
//    {
//        //console.log("C1.root save()")
//        //console.log(root.getTab(root.currentIndex).item.children[0].type)
//        if (root.getTab(root.currentIndex).item.children[0].type !== "NONE")
//            root.getTab(root.currentIndex).item.children[0].save()

//    }

//    function clearDataPool()
//    {
//        //console.log("clearDataPool")
//        if (root.getTab(root.currentIndex).item.children[0].type === "UDP_CLIENT_TYPE" | root.getTab(root.currentIndex).item.children[0].type === "TXT_CLIENT_TYPE")
//            root.getTab(root.currentIndex).item.children[0].clearDataPool()
//    }


    function addNewTab()
    {
        root.addTab(newWindowTitle,newTabComponent)
        //root.addTab(newWindowTitle,newChoiceComponent)
        root.currentIndex = root.count - 1
        root.contexMenuIndex = root.currentIndex
    }

    function closeAllButThisTab(index)
    {
        if (index < root.count - 1)
        {
            for (var i = root.count - 1 ;i > index;i--)
            {
                root.removeTab(i)
            }
        }
        for (i = index - 1 ;i > -1;i--)
        {
            root.removeTab(i)
        }
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
    function renameTab(index)
    {
        console.log("root:renametab()")
        root.renametab()
    }

    function sendTittleName(m_index, tittle)
    {
        //console.log("root:sendTittleName:index:" + m_index)
        // console.log("root:sendTittleName:tittle:" + tittle)

        //    if (root.getTab(m_index).item.children[0].type !== "NONE")

        if (root.getTab(m_index).item.children[0].type !== "NONE")
        {
            //console.log("BaseTableView:sendTittleName:" + tittle)
            //console.log("root.getTab(m_index).item.children[0].type:" + root.getTab(m_index).type)
            //console.log("root.getTab(m_index).item.children[0].type:" + root.getTab(m_index).item.type)
            //console.log("0" + root.getTab(m_index).item.type)

            //console.log("1" + root.getTab(m_index).item.children[0].type)
            //console.log("root.getTab(m_index).item.children[0].type:" + root.getTab(m_index).type)
            root.getTab(m_index).item.children[0].sendNameDocument(tittle)
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
