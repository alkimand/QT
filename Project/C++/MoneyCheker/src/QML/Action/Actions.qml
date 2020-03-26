import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.12
//https://www.flaticon.com/search/5?word=search
//https://findicons.com/search/paper-document/74
//https://www.flaticon.com/most-downloaded
Item
{
    property string toolBarIconPath: '../../images/ToolBarIcon/'
    property string tableViewIconPath: '../../images/TableViewIcon/'
    property string appButtonIconPath: '../../images/AppButton/'


    property var buttonSettings: Item {
        id: fileOpenAction_

        //property var icon:""
        //property string icon.source: toolBarIconPath + 'fileopen.png'
        //shortcut : QKeySequence::Open)
        property string source:  toolBarIconPath + 'fileopen.png'
        //text: "Open"

    }


    property Action mainButtonCalculate :
        Action
    {
        //id: fileOpenAction
        icon.source: appButtonIconPath + 'calculator.png'
        //shortcut : QKeySequence::Open)
        icon.name: "calculate"
        text: "Calculate"
        onTriggered:
        {
            //fileDialog.selectExisting = true
            //fileDialog.open()
            //tabView.addTextComponent()
            console.log("mainButtonCalculate")

        }
    }

    property Action tabButtonMortageActivate :
        Action
    {
        //id: fileOpenAction
        icon.source: appButtonIconPath + 'home_blue.png'
        //shortcut : QKeySequence::Open)
        icon.name: "calculate"
        text: "MORTAGE"
        onTriggered:
        {
            //fileDialog.selectExisting = true
            //fileDialog.open()
            //tabView.addTextComponent()
            console.log("tabButtonMortageActivate")

        }
    }

    property Action mainButtonFavorite :
        Action
    {
        //id: fileOpenAction
        icon.source: appButtonIconPath + 'star_favorite.png'
        //shortcut : QKeySequence::Open)
        icon.name: "Favorite"
        text: "Favorite"

        onTriggered:
        {
            //fileDialog.selectExisting = true
            //fileDialog.open()
            //tabView.addTextComponent()
            console.log("mainButtonFavorite")

        }
    }


    property Action mainButtonPercent :
        Action
    {
        //id: fileOpenAction
        icon.source: appButtonIconPath + 'percent.png'
        //shortcut : QKeySequence::Open)
        icon.name: "percent"
        text: "percent"

        onTriggered:
        {
            //fileDialog.selectExisting = true
            //fileDialog.open()
            //tabView.addTextComponent()
            console.log("mainButtonPercent")

        }
    }


    property Action mainButtonSetting :
        Action
    {
        //id: fileOpenAction
        icon.source: appButtonIconPath + 'setting.png'
        //shortcut : QKeySequence::Open)
        icon.name: "Setting"
        text: "Setting"

        onTriggered:
        {
            //fileDialog.selectExisting = true
            //fileDialog.open()
            //tabView.addTextComponent()
            console.log("mainButtonSetting")

        }
    }


    property Action fileOpenAction :
        Action
    {
        id: fileOpenAction
        icon.source: toolBarIconPath + 'fileopen.png'
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
    //        icon.source: "../../images/ToolBarIcon/filesave.png"
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
        icon.source: toolBarIconPath + "filesave.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-save"
        text: "Save"

        onTriggered:
        {
            //console.log("fileSaveAction")
            tabView.save()
        }
    }

    property Action fileSaveAsAction:Action
    {
        id: fileSaveAsAction
        icon.source: toolBarIconPath + "filesave.png"
        //shortcut : QKeySequence::Open)
        icon.name: "document-saveAs"
        text: "Save As..."

        onTriggered:
        {
            //console.log("fileSaveAsAction")
            tabView.saveAs()
        }
    }

    property Action downloadAction:Action
    {
        id: downloadSaveAction
        icon.source: toolBarIconPath + "download.png"
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
        icon.source: toolBarIconPath + "plus.png"
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
        icon.source: toolBarIconPath + "close.png"
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
        icon.source: toolBarIconPath + "close.png"
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
        icon.source: toolBarIconPath + "stop.png"
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
        icon.source: toolBarIconPath + "play.png"
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
        icon.source: toolBarIconPath + "pause.png"
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
        icon.source: toolBarIconPath + "erase.png"
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
        icon.source: toolBarIconPath + "search.png"
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
        icon.source: toolBarIconPath + "filterIcon.png"
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
        icon.source: toolBarIconPath + "marker.png"
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
        icon.source: toolBarIconPath + "setting.png"
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
        icon.source: toolBarIconPath + "rename.png"
        //icon.source: "../images/ToolBarIcon/rename.jpg"
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
        icon.source: toolBarIconPath + "explorer.png"
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Open in Explorer"

        onTriggered:
        {
            console.log("openInExplorerAction")
            tabView.openInExplorer()
            //tabView.removeTab(tabView.currentIndex)
        }
    }

    property Action openDesktopServicesAction:Action
    {
        id: openDesktopServicesAction
        icon.source: toolBarIconPath + "explore.png"
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Open in desktop services"
        onTriggered:
        {
            console.log("openInDesktopServicesAction")
            tabView.openInDesktopServices()
        }
    }

    property Action removeColumnAction:Action
    {
        id: removeColumnAction
        icon.source: toolBarIconPath + "remove_column.png"
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Remove column"
        onTriggered:
        {
            console.log("removeColumnAction")
            tabView.removeColumnTab()
        }
    }

    property Action restoreColumnAction:Action
    {
        id: restoreColumnAction
        icon.source: toolBarIconPath + "show_all_column.png"
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Show all columns"
        onTriggered:
        {
            console.log("restoreColumnAction")
            tabView.restoreColumnTab()
        }
    }
}


