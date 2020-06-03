import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
//import "src/qml/Action"
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
            tab_view.removeTab(tab_view.currentIndex)
        }
    }

   // menuBar: MenuBar{id:mainMenuBar}
    menuBar: T_menu_bar {}// {id:menu_bar_}
    header: T_toolbar {} //{id:tool_bar_}
    
    T_tab_view {
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
