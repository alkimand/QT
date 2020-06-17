import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

//import AppDataProvider 1.0

import Actions 1.0

//import QtQuick.Layouts 1.3
import "src/qml/ToolBar"
import "src/qml/Menu/HeaderMenuBar"
import "src/qml/TabView"
import "src/qml/FileDialog"

ApplicationWindow {
    id: main_root
    visible: true
    width: 500
    height: 800
    title: qsTr("QML Fx tool")
    property string curent_file_path_: ""

    signal openFile(string file_path)
    signal saveFile(string file_path)//, string item_id)

    FileDialogWidget { id:file_dialog }

    //from AppDataProvider
    Connections {
        target: app_data
        onItemParsed:{
            tab_view.createTab(item_id)
            //console.log("onItemParsed")
        }
    }
    Connections {
        target: main_root
        onOpenFile:{
            app_data.openFile(file_path);

        }
        onSaveFile: {
            app_data.saveFile(file_path, main_root.getTableId());
        }
    }

    //from Actions
    Connections {
        target: Actions
        onOpenAction: {
            console.log("onOpenAction+")
            file_dialog.setType(0);
            file_dialog.open();
        }

        onSaveAction : {
            console.log("onSaveFile")
            if (tab_view.count > 0) {
                //file_dialog.setType(1)
                main_root.saveFile(app_data.getFilePathByID(main_root.getTableId()));
            }
        }

        onSaveAsAction : {
            console.log("onSaveFile")
            if (tab_view.count > 0) {
                file_dialog.setType(1);
                file_dialog.open();
            }
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

        onCloseAllButThis: {
            main_root.closeAllButThis()
            tab_view.currentIndex = 0;
        }

    }





    menuBar: MenuBarWidget {}// {id:menu_bar_}
    header: ToolBarWidget { id:tool_bar_}
    

    TabViewWidget {
        id:tab_view
        anchors.fill:parent
        //z:0
    }

    //    Rectangle{
    //        id:background
    //        color: "red"
    //        anchors.top: tab_view.top
    //        anchors.bottom: tab_view.bottom
    //        anchors.left:parent.left
    //        anchors.right:parent.right
    //        z:0
    //    }

    function test (i){
        console.log("main_root test() ="+(i));
    }

    function onTolBarButtonPush (id){
        app_data.toolBarButtonPush(id);
    }

    function getTableId(){
        var id_ = "-1"
        if (tab_view.count > 0){
            if (tab_view.indexUnderMouse > -1 && (tab_view.indexUnderMouse <  tab_view.count)){
                id_ = tab_view.getTab(tab_view.indexUnderMouse).item.children[0].current_id_
            }
            else {
                id_ = tab_view.getTab(tab_view.currentIndex).item.children[0].current_id_
            }
            //console.log("getTableId() =" + id_);
        }
        else {
            id_= "-1"
        }
        return id_;
    }


    function closeAllButThis() {
        //console.log("closeAllButThisT+");
        var index;
        if (tab_view.count > 0) {
            if (tab_view.contexMenuIndex > -1 && (tab_view.contexMenuIndex <  tab_view.count)){
                index = tab_view.contexMenuIndex
            }
            else {
                index = tab_view.currentIndex
            }
        }
        else {
            index = -1
        }

        if (index < tab_view.count - 1) {
            for (var i = tab_view.count - 1 ;i > index;i--)
                tab_view.removeTab(i)
        }
        for (i = index - 1 ;i > -1;i--)
            tab_view.removeTab(i)
            tab_view.refreshTab()
    }

    Component.onCompleted: {
        //app_data.appStart()
    }
}
