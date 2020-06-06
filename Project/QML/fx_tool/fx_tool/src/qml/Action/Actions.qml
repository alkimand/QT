import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQml.Models 2.12
pragma Singleton

Item
{
	id: root
    property string toolBarIconPath: '../../images/ToolBarIcon/'
    //property string tableViewIconPath: '../../images/TableViewIcon/'
    //property string appButtonIconPath: '../../images/AppButton/'
	
	signal closeTabAct();	
	signal closeAllTabAct();
	signal fileOpen(var url);
	signal openAction();
    signal saveAction(var save_as);

    
    property Action fileOpenAction : Action {
        icon.source: toolBarIconPath + 'fileopen.png'
        //shortcut : QKeySequence::Open
        icon.name: "document-open"
        text: "Open"

        onTriggered: {
            //fileDialog.selectExisting = true
            //fileDialog.open()
            console.log("Action:" + text);

        }
    }
	
	    property Action addAction:Action
    {
        id: addAction
        icon.source: toolBarIconPath + 'plus.png'
        //shortcut : QKeySequence::Open)
        icon.name: "document-add"
        text: "Add"

        onTriggered:
        {
            console.log("Action:" + text);
			root.openAction();
            //main_root.test()
			
        }
    }
	
    property Action fileSaveAction:Action
    {
        id: fileSaveAction
        icon.source: toolBarIconPath + 'filesave.png'

        //shortcut : QKeySequence::Open)
        icon.name: "document-save"
        text: "Save"

        onTriggered:
        {
            console.log("Action:" + text);
			root.openAction();
           // tab_view_.save()
        }
    }

    property Action fileSaveAsAction:Action
    {
        id: fileSaveAsAction
        icon.source:  toolBarIconPath + 'filesave.png'
        //shortcut : QKeySequence::Open)
        icon.name: "document-saveAs"
        text: "Save As..."

        onTriggered:
        {
            //console.log("fileSaveAsAction");
           console.log("Action:" + text);
        }
    }

    property Action closeAction:Action
    {
        icon.source: toolBarIconPath + 'close.png'
        //shortcut : QKeySequence::Open)
        icon.name: "document-close"
        text: "Close"

        onTriggered:
        {
            console.log("Action:" + text);
            root.closeTabAct();
          //tab_view_.removeTab(tab_view_.contexMenuIndex)
        }
    }
	
	    property Action closeAllAction:Action {
        icon.source: toolBarIconPath + 'close.png'
        //shortcut : QKeySequence::Open)
        icon.name: "document-close"
        text: "CloseAll"

        onTriggered:
        {
            console.log("Action:" + text);
            root.closeAllTabAct();
          //tab_view_.removeTab(tab_view_.contexMenuIndex)
        }
    }
	
	
	property Action closeTabAction:Action
    {
        icon.source: toolBarIconPath + 'close.png'
        //shortcut : QKeySequence::Open)
        icon.name: "document-close"
        text: "Close"

        onTriggered: {
            console.log("Action:" + text);
			root.closeTabAct()
          //tab_view_.removeTab(tab_view_.contexMenuIndex)
        }
    }
	
	
    property Action closeAllButThisAction:Action
    {
        id: closeAllButThisAction
        icon.source: toolBarIconPath + 'close.png'
        //shortcut : QKeySequence::Open)
        icon.name: "document-close All"
        text: "Close all but this"

        onTriggered:
        {
		console.log("Action:" + text);
            //tab_view_.closeAllButThisTab(tab_view_.contexMenuIndex)
        }
    }
 
    property Action renameTabAction:Action
    {
        id: renameTabAction
        icon.source: toolBarIconPath + 'rename.png'
        //shortcut : QKeySequence::Open)
        icon.name: "rename"
        text: "Rename Tab"

        onTriggered:
        {
            //console.log("renameTabAction")
			console.log("Action:" + text);
            //tab_view_.renameTab(tab_view_.contexMenuIndex)
            //tab_view_.removeTab(tab_view_.currentIndex)
        }
    }

    property Action openInExplorerAction:Action
    {
        id: openInExplorerAction
        icon.source: toolBarIconPath + 'explorer.png'
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Open in Explorer"

        onTriggered:
        {
		console.log("Action:" + text);
            //console.log("openInExplorerAction")
           // tab_view_.openInExplorer()
            //tab_view_.removeTab(tab_view_.currentIndex)
        }
    }

    property Action openDesktopServicesAction:Action
    {
        id: openDesktopServicesAction
        icon.source: "../images/ToolBarIcon/explore.png"
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Open in desktop services"
        onTriggered:
        {
		console.log("Action:" + text);
          //  console.log("openInDesktopServicesAction")
           // tab_view_.openInDesktopServices()
        }
    }

    property Action removeColumnAction:Action
    {
        id: removeColumnAction
        icon.source: "../images/ToolBarIcon/remove_column.png"
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Remove column"
        onTriggered:
        {
			console.log("Action:" + text);
            //console.log("removeColumnAction")
            //tab_view_.removeColumnTab()
        }
    }

    property Action restoreColumnAction:Action
    {
        id: restoreColumnAction
        icon.source: "../images/ToolBarIcon/show_all_column.png"
        //shortcut : QKeySequence::Open)
        icon.name: "Open"
        text: "Show all columns"
        onTriggered:
        {
            console.log("restoreColumnAction")
            tab_view_.restoreColumnTab()
        }
    }
}


