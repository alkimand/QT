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
            if (view_id==-1)
                tab_view.createTab(item_id)
            else {
                var view_id_;
                for (var i = 0;i< tab_view.count;i++){
                    view_id_ = tab_view.getTab(i).item.children[0].children[0].view_id_;
                    if (view_id_=== view_id) {
                        tab_view.getTab(i).item.children[0].children[0].item.modelReset();
                        break;
                    }
                }
            }
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
                var file_path = app_data.getFilePathByID(main_root.getTableId());
                if (file_path  !== "")
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
//                        console.log("tab_view.indexUnderMouse=" + tab_view.indexUnderMouse)
//                        console.log("tab_view.contexMenuIndex=" + tab_view.contexMenuIndex)
//                       console.log("1_onCloseTabAct= " + tab_view.count )
//                        console.log("1_tab_view.currentIndex=" + tab_view.currentIndex)
            var index_;

            if (tab_view.contexMenuIndex > -1 && (tab_view.contexMenuIndex <  tab_view.count)) {
                index_ = tab_view.contexMenuIndex;
            }
            else if (tab_view.indexUnderMouse > -1 && (tab_view.indexUnderMouse <  tab_view.count)) {
                index_ = tab_view.indexUnderMouse;
            }
            else {
                tab_view.contexMenuIndex =-1;
                tab_view.indexUnderMouse =-1;
                console.log("Bug onCloseTabAct currentIndex=" + tab_view.currentIndex)
                return;
            }
         //console.log("2_tab_view.index_=" + index_)
            tab_view.removeTab(index_)
            if (tab_view.count > 0){
                tab_view.contexMenuIndex = -1
                tab_view.indexUnderMouse = -1
                tab_view.refreshTab()
            }
        }

        onCloseAllButThis: {
            main_root.closeAllButThis()
            tab_view.currentIndex = 0;
        }

        onRefresh: {
            app_data.parseItem(main_root.getTableId(), main_root.getCurentTableViewId())
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

    function test () {
        // main_root.getCurentTableViewId()
        //console.log("tab_view.currentIndex ="+(tab_view.currentIndex));
        //var id_ = tab_view.getTab(0).item.children[0].children[0].current_id_
        //var i2 = tab_view.getTab(tab_view.currentIndex).item.children[0].item.children[0].view_id_
        //console.log("main_root test() ="+(id_));
        console.log("main_root test() ="+(main_root.getCurentTableViewId()));
    }

    function onTolBarButtonPush (id){
        app_data.parseItem(id);
    }

    function getTableId(){
        var id_ = "-1"
        if (tab_view.count > 0) {
            if (tab_view.indexUnderMouse > -1 && (tab_view.indexUnderMouse <  tab_view.count))
                id_ = tab_view.getTab(tab_view.indexUnderMouse).item.children[0].children[0].item.current_id_
            else if (tab_view.contexMenuIndex > -1 && (tab_view.contexMenuIndex <  tab_view.count))
                id_ = tab_view.getTab(tab_view.contexMenuIndex).item.children[0].children[0].item.current_id_
            else
                id_ = tab_view.getTab(tab_view.currentIndex).item.children[0].children[0].item.current_id_
        }
        //console.log("getTableId() =" + id_);
        return id_;
    }

    function getCurentTableViewId() {
        var id_ = -1
        //console.log("indexUnderMouse =" + tab_view.indexUnderMouse);
        //console.log("contexMenuIndex =" + tab_view.contexMenuIndex);
        if (tab_view.count > 0){
            if (tab_view.indexUnderMouse > -1 && (tab_view.indexUnderMouse <  tab_view.count))
                id_ = tab_view.getTab(tab_view.indexUnderMouse).item.children[0].children[0].item.view_id_
            else if (tab_view.contexMenuIndex > -1 && (tab_view.contexMenuIndex <  tab_view.count))
                id_ = tab_view.getTab(tab_view.contexMenuIndex).item.children[0].children[0].item.view_id_
            else
                id_ = tab_view.getTab(tab_view.currentIndex).item.children[0].children[0].item.view_id_
            //console.log("view_id_ =" + id_);
        }
        //console.log("view_id_ =" + id_);
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
