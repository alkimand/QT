import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

import AppDataProvider 1.0

import Actions 1.0

//import QtQuick.Layouts 1.3
import "src/qml/ToolBar"
import "src/qml/Menu/HeaderMenuBar"
import "src/qml/TabView"

ApplicationWindow {
    id: main_root
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Fx tool")

    AppDataProvider {
        id:data_provider_
    }

    Connections {
        target: Actions
        onOpenAction: {
            tab_view.addNewTab()
        }

        onSaveAction : {
            main_root.test()
            //closeTab(tab_view_.currentIndex)
        }

        onCloseTabAct : {
            //console.log("1_onCloseTabAct=" + tab_view.count )
            //console.log("1_tab_view.currentIndex=" + tab_view.currentIndex)

            if (tab_view.indexUnderMouse > -1 && (tab_view.indexUnderMouse <  tab_view.count)){
                //indexUnderMouse
            }
            else {
                tab_view.indexUnderMouse-=1;
                //console.log("Bug onCloseTabAct currentIndex=" + tab_view.currentIndex)
                return;
            }

            var i = tab_view.indexUnderMouse;
            var cur_index = tab_view.currentIndex;
            tab_view.removeTab(tab_view.indexUnderMouse)
            if (tab_view.count > 0){
                tab_view.contexMenuIndex = -1
                tab_view.indexUnderMouse = -1
                //if (tab_view.count > 1)
                //tab_view.currentIndex = cur_index - 1
                //else
                //tab_view.currentIndex =0;
                tab_view.refreshTab()
            }
            // tab_view.currentIndex =
            //console.log("2_onCloseTabAct="+tab_view.count )
            //console.log("2_tab_view.currentIndex=" + tab_view.currentIndex)
        }

        onCloseAllTabAct: {
            for (var i = tab_view.count ;i > 0;--i){
                tab_view.removeTab(0)
            }
        }
    }


    menuBar: MenuBarWidget {}// {id:menu_bar_}
    header: ToolBarWidget {} //{id:tool_bar_}
    
    TabViewWidget {
        id:tab_view
        anchors.fill:parent
    }



    // property Actions actions : Actions{}

    //    FileDialog
    //    {
    //        id: fileDialog
    //        nameFilters: ["Text files (*.txt)", "HTML files (*.html, *.htm)"]
    //        onAccepted: {
    //            if (fileDialog.selectExisting)
    //                document.fileUrl = fileUrl
    //            else
    //                document.saveAs(fileUrl, selectedNameFilter)
    //        }
    //    }

    function test (){
        console.log("main_root test()");
    }
}
