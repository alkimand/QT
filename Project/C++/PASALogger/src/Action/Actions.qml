import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQml.Models 2.12
//https://www.flaticon.com/search/5?word=search
//https://findicons.com/search/paper-document/74
//https://www.flaticon.com/most-downloaded
Item
{
    //id: actionModel
    property Action fileOpenAction :
        Action
    {
        id: fileOpenAction
        icon.source: "../images/ToolBarIcon/fileopen.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-open"
        text: "Open"

        onTriggered:
        {
            //fileDialog.selectExisting = true
            //fileDialog.open()
            tabView.addTextComponent()

        }
    }

    //    property Action newAction:Action
    //    {
    //        id: newAction
    //        icon.source: "../images/ToolBarIcon/filesave.png"
    //        //shortcut : QKeySequence::Open)
    //        icon.name: "document-new"
    //        text: "New"

    //        onTriggered:
    //        {
    //            console.log("newAction:")
    //        }
    //    }

    property Action fileSaveAction:Action
    {
        id: fileSaveAction
        icon.source: "../images/ToolBarIcon/filesave.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-save"
        text: "Save"

        onTriggered:
        {
            console.log("fileSaveAction")
        }
    }

    property Action fileSaveAsAction:Action
    {
        id: fileSaveAsAction
        icon.source: "../images/ToolBarIcon/filesave.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-saveAs"
        text: "Save As..."

        onTriggered:
        {
            console.log("fileSaveAsAction")
        }
    }

    property Action downloadAction:Action
    {
        id: downloadSaveAction
        icon.source: "../images/ToolBarIcon/download.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-download"
        text: "Download"
        onTriggered:
        {
            console.log("downloadSaveAction")
            //fileDialog.open()
        }
    }

    property Action addAction:Action
    {
        id: addAction
        icon.source: "../images/ToolBarIcon/plus.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-add"
        text: "Add"

        onTriggered:
        {
            console.log("addAction")
            tabView.addNewTab()
        }
    }

    property Action closeAction:Action
    {
        id: closeAction
        icon.source: "../images/ToolBarIcon/close.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-close"
        text: "Close"

        onTriggered:
        {
            console.log("closeAction")

            tabView.removeTab(tabView.contexMenuIndex)
        }
    }
    property Action closeAllButThisAction:Action
    {
        id: closeAllButThisAction
        icon.source: "../images/ToolBarIcon/close.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-close All"
        text: "Close all but this"

        onTriggered:
        {
            tabView.closeAllButThisTab(tabView.contexMenuIndex)
        }
    }
    property Action stopAction:Action
    {
        id: stopAction
        icon.source: "../images/ToolBarIcon/stop.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-Stop"
        text: "Stop"

        onTriggered:
        {
            tabView.setStatus(3)
            console.log("stopAction")
        }
    }

    property Action playAction:Action
    {
        id: playAction
        icon.source: "../images/ToolBarIcon/play.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-start"
        text: "Start"

        onTriggered:
        {
            tabView.setStatus(1)
            console.log("playAction")
            //fileDialog.open()
        }
    }

    //ToDo paly/pause
    property Action pauseAction:Action
    {
        id: pauseAction
        icon.source: "../images/ToolBarIcon/pause.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-pause"
        text: "Pause"

        onTriggered:
        {
            tabView.setStatus(2)
            console.log("pauseAction")
            //fileDialog.open()
        }
    }

    property Action clearAction:Action
    {
        id: clearAction
        icon.source: "../images/ToolBarIcon/erase.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-clean"
        text: "Clean"

        onTriggered:
        {
           console.log("Action clearAction")
            tabView.clearDataPool()
            //tabView.setStatus(4)
            //fileDialog.open()
        }
    }

    property Action searchAction:Action
    {
        id: searchAction
        icon.source: "../images/ToolBarIcon/search.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-search"
        text: "Search"

        onTriggered:
        {
            console.log("pauseAction")
            //fileDialog.open()
        }
    }

    property Action setupFilterAction:Action
    {
        id: setupFilterAction
        icon.source: "../images/TableViewIcon/filterIcon.png"
        //shortcut : QKeySequence::Open)
        icon.name: "setup Filter"
        text: "Filters"

        onTriggered:
        {
            console.log("setupFilterAction")
            //fileDialog.open()
        }
    }

    property Action markerAction:Action
    {
        id:  markerAction
        icon.source: "../images/ToolBarIcon/marker.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-search"
        text: "Marker"

        onTriggered:
        {
            console.log(" markerAction")
            //fileDialog.open()
        }
    }

    property Action settingAction:Action
    {
        id: settingAction
        icon.source: "../images/ToolBarIcon/setting.png"
        //shortcut : QKeySequence::Open)
        icon.name: "setting"
        text: "Setting"

        onTriggered:
        {
            console.log("settingAction")
            //tabView.removeTab(tabView.currentIndex)
        }
    }

    property Action renameTabAction:Action
    {
        id: renameTabAction
        icon.source: "../images/ToolBarIcon/rename.png"
        //shortcut : QKeySequence::Open)
        icon.name: "rename"
        text: "Rename Tab"

        onTriggered:
        {
            console.log("renameTabAction")
            tabView.renameTab(tabView.contexMenuIndex)
            //tabView.removeTab(tabView.currentIndex)
        }
    }

    property Action openInExplorerAction:Action
    {
        id: openInExplorerAction
        icon.source: "../images/ToolBarIcon/explorer.png"
        //shortcut : QKeySequence::Open)
        icon.name: "rename"
        text: "Open in Explorer"

        onTriggered:
        {
            console.log("openInExplorerAction")
            tabView.openInExplorer()
            //tabView.removeTab(tabView.currentIndex)
        }
    }
}


