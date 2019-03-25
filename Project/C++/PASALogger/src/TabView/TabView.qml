import QtQuick 2.12
import QtQuick.Controls 1.4 as C1
import"../TableView/TableView"
//import QtQuick.Controls 2.4
//https://stackoverflow.com/questions/34410260/trouble-setting-activefocus-to-item-in-a-qml-tabview
//https://switch-case.ru/61977594 -selection
//import TableModel 1.0
import "../TableView/"
import "../TabView/Style"
import "../TabView/Style/Tab"
import "../TableView/ItemDelegat/HeaderDelegate"
import "../TableView/TableView" as MyTable
import "../ChoiceItem"
C1.TabView
{
    id:tabView
    anchors.fill:parent
    //property int curIndex: 0
    property string newWindowTitle: "new window " + tabView.count
    property int contexMenuIndex: -1
    property int indexUnderMouse: -1
    //property string newWindowTitle: M_TabNew.title
    signal renametab()
    //onRenametab:{}
    style: TabViewStyle{}



    //    Component
    //    {
    //        id:tableComponent
    //        TableUDP{}
    //    }

    //    Component
    //    {
    //        id:choiceComponent
    //        ChoiceItemBase{}
    //    }


    //https://stackoverflow.com/questions/27230818/qml-tableview-with-dynamic-number-of-columns


    Component
    {
        id:newTabComponent
        //property string type: "NONE1"
        Loader
        {
            id: loader
            anchors.fill: parent
            source: "../ChoiceItem/ChoiceWindow.qml"
            property string type: "NONE"

            function setTable(name)
            {

                loader.source = ""
                //console.log("name:" + name)
                switch (name)
                {
                case "UDP logger" :
                    console.log("UDP logger")
                    source= "../TableView/TableView/TableUDP.qml"

                    break
                case "Text logger" :
                    console.log("Text logger")
                    source= "../TableView/TableView/TableText.qml"

                    break
                }
                //  tabView.getTab(contexMenuIndex).title = tabView.getTab(contexMenuIndex).title + ".txt"
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
            source: "../TableView/TableView/TableText.qml"
        }

    }

    function addTextComponent()
    {
        tabView.addTab(newWindowTitle,newTextComponent)
        tabView.currentIndex = tabView.count - 1
    }



    function openFile()//--
    {
        //var tab = tabView.getTab(tabView.currentIndex)
        // var item = tabView.contentItem
        // tabView.setTable(name)
        //var component =
        //component.source= "../TableView/TableView/TableText.qml"
        //tabView.addTab(newWindowTitle,component)
    }



    function onCurIndChangeHeandler()
    {
        addNewTab()
    }

    function setStatus(status)
    {
        console.log("C1.TabView setStatus(status):" + status )
        if (tabView.getTab(tabView.currentIndex).item.children[0].type === "UDP_CLIENT_TYPE")
            tabView.getTab(tabView.currentIndex).item.children[0].setStatus(status)
    }

    function saveAs()
    {
        //console.log("C1.TabView saveAs()")
        if (tabView.getTab(tabView.currentIndex).item.children[0].type !== "NONE")
            tabView.getTab(tabView.currentIndex).item.children[0].saveAs()

    }

    function save()
    {
        //console.log("C1.TabView save()")
        //console.log(tabView.getTab(tabView.currentIndex).item.children[0].type)
        if (tabView.getTab(tabView.currentIndex).item.children[0].type !== "NONE")
            tabView.getTab(tabView.currentIndex).item.children[0].save()

    }

    function clearDataPool()
    {
        //console.log("clearDataPool")
        if (tabView.getTab(tabView.currentIndex).item.children[0].type === "UDP_CLIENT_TYPE" | tabView.getTab(tabView.currentIndex).item.children[0].type === "TXT_CLIENT_TYPE")
            tabView.getTab(tabView.currentIndex).item.children[0].clearDataPool()
    }


    function addNewTab()
    {
        tabView.addTab(newWindowTitle,newTabComponent)
        //tabView.addTab(newWindowTitle,newChoiceComponent)
        tabView.currentIndex = tabView.count - 1
        tabView.contexMenuIndex = tabView.currentIndex
    }




    function closeTab(index)
    {
        tabView.removeTab(index)
    }
    function closeAllButThisTab(index)
    {
        if (index < tabView.count - 1)
        {
            for (var i = tabView.count - 1 ;i > index;i--)
            {
                tabView.removeTab(i)
            }
        }
        for (i = index - 1 ;i > -1;i--)
        {
            tabView.removeTab(i)
        }
    }
    function saveTab(index) //ToDo
    {
        //tabView.removeTab(index)
    }
    function selectTab(index) //ToDo //--
    {
        //var tab=getTab(index)
        console.log("selectTab + ")
        console.log("index = +" + index)
        console.log("tabView.getTab(index).children[0].rowHeight = " + tabView.getTab(index).children[0].rowHeight)
        tabView.getTab(index).children[0].selectTab(2)
        // tabView.selection.selectAll()
        // tableView.selection.clear()
        // tableView.selection.select(row)
        //tabView.removeTab(index)
    }
    function renameTab(index)
    {
        console.log("TabView:renametab()")
        tabView.renametab()
    }

    function sendTittleName(m_index, tittle)
    {
        //console.log("TabView:sendTittleName:index:" + m_index)
        // console.log("TabView:sendTittleName:tittle:" + tittle)

        //    if (tabView.getTab(m_index).item.children[0].type !== "NONE")

        if (tabView.getTab(m_index).item.children[0].type !== "NONE")
        {
            //console.log("BaseTableView:sendTittleName:" + tittle)
            //console.log("tabView.getTab(m_index).item.children[0].type:" + tabView.getTab(m_index).type)
            //console.log("tabView.getTab(m_index).item.children[0].type:" + tabView.getTab(m_index).item.type)
            //console.log("0" + tabView.getTab(m_index).item.type)

            //console.log("1" + tabView.getTab(m_index).item.children[0].type)
            //console.log("tabView.getTab(m_index).item.children[0].type:" + tabView.getTab(m_index).type)
            tabView.getTab(m_index).item.children[0].sendNameDocument(tittle)
            //sendTittleName(m_index, tittle)
        }
    }


    function openInExplorer()
    {
        //        text.selectAll()
        //        text.forceActiveFocus()
        console.log(tabView.getTab(tabView.contexMenuIndex).item.children[0].type)
        console.log("openInExplorer")
        if (tabView.getTab(tabView.contexMenuIndex).item.children[0].type !== "NONE")
            tabView.getTab(tabView.contexMenuIndex).item.children[0].openInExplorer()
    }

    function openInDesktopServices()
    {
        //        text.selectAll()
        //        text.forceActiveFocus()
        console.log("openInDesktopServices")
        if (tabView.getTab(tabView.contexMenuIndex).item.children[0].type !== "NONE")
            tabView.getTab(tabView.contexMenuIndex).item.children[0].openInDesktopServices()
    }

    function removeColumnTab()
    {
        //        text.selectAll()
        //        text.forceActiveFocus()
        console.log("removeColumnTab")
        tabView.getTab(tabView.contexMenuIndex).item.children[0].removeColumnTable()
    }



}
