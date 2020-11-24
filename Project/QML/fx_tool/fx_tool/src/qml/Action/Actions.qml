import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQml.Models 2.12
pragma Singleton

Item
{
    id: root
    property string toolBarIconPath: '../../images/ToolBarIcon/'

    signal closeTabAct();
    signal closeAllTabAct();
    signal fileOpen(var url);
    signal openAction();
    signal saveAction();
    signal saveAsAction();
    signal closeAllButThis()
    signal refresh();
    signal removeRow();
    signal addRow();
    signal copyRow();
    signal deleteFile();


    property Action pushTolBarButton : Action {
        icon.source: toolBarIconPath + 'fileopen.png'
        icon.name: "document-open"
        property int item_id: -1
        text: "createTable"

        onTriggered: {
            console.log("Action:" + text);
        }
    }
    
    property Action fileOpenAction : Action {
        icon.source: toolBarIconPath + 'fileopen.png'
        icon.name: "document-open"
        text: "Open"

        onTriggered: {
            root.openAction();
        }
    }

    property Action addAction:Action
    {
        id: addAction
        icon.source: toolBarIconPath + 'plus.png'
        icon.name: "document-add"
        text: "Add"

        onTriggered: {
            console.log("Action:" + text);
        }
    }

    property Action fileSaveAction:Action
    {
        id: fileSaveAction
        icon.source: toolBarIconPath + 'filesave.png'
        icon.name: "document-save"
        text: "Save"

        onTriggered: {
            root.saveAction();
        }
    }

    property Action fileSaveAsAction:Action
    {
        id: fileSaveAsAction
        icon.source:  toolBarIconPath + 'filesave.png'
        icon.name: "document-saveAs"
        text: "Save As..."
        onTriggered: {
            root.saveAsAction();
        }
    }

    property Action closeAppAction:Action
    {
        icon.source: toolBarIconPath + 'close.png'
        icon.name: "document-close"
        text: "Close"
        onTriggered: {
            console.log("Action:" + text);
            root.closeTabAct();
        }
    }

    property Action closeTabAction:Action
    {
        icon.source: toolBarIconPath + 'close.png'
        icon.name: "document-close"
        text: "Close"

        onTriggered: {
            root.closeTabAct()
        }
    }


    property Action closeAllButThisAction:Action
    {
        id: closeAllButThisAction
        icon.source: toolBarIconPath + 'close.png'
        icon.name: "document-close All"
        text: "Close all but this"

        onTriggered:{
            root.closeAllButThis()
        }
    }

    property Action refreshAction:Action {
        icon.source: toolBarIconPath + 'refresh.png'
        icon.name: ""
        text: "Refresh"
        onTriggered:{
            console.log("Action:" + text);
            root.refresh()
        }
    }

    property Action renameTabAction:Action
    {
        id: renameTabAction
        icon.source: toolBarIconPath + 'rename.png'
        icon.name: "rename"
        text: "Rename Tab"

        onTriggered: {
            console.log("Action:" + text);
        }
    }

    property Action openInExplorerAction:Action
    {
        id: openInExplorerAction
        icon.source: toolBarIconPath + 'explorer.png'
        icon.name: "Open"
        text: "Open in Explorer"

        onTriggered: {
            console.log("Action:" + text);
        }
    }

    property Action openDesktopServicesAction:Action
    {
        id: openDesktopServicesAction
        icon.source: "../images/ToolBarIcon/explore.png"
        icon.name: "Open"
        text: "Open in desktop services"
        onTriggered:
        {
            console.log("Action:" + text);
        }
    }

    property Action removeRowAction:Action {
        icon.source: toolBarIconPath + 'remove_row.png'
        icon.name: "Remove row"
        text: "Remove row"
        onTriggered: {
            console.log("Action:" + text);
            root.removeRow();
        }
    }
    
    property Action addRowAction:Action {
        icon.source: toolBarIconPath + 'add_row.png'
        icon.name: "Add row"
        text: "Add row"
        onTriggered: {
            console.log("Action:" + text);
            root.addRow();
        }
    }
    
    property Action copyRowAction:Action {
        icon.source: toolBarIconPath + 'copy_row.png'
        icon.name: "Copy row"
        text: "Copy row"
        onTriggered: {
            console.log("Action:" + text);
            root.copyRow();
        }
    }
    
    property Action deleteFileAction:Action {
        icon.source: toolBarIconPath + 'delete_file.png'
        icon.name: "Copy row"
        text: "Delete file"
        onTriggered: {
            console.log("Action:" + text);
            root.deleteFile();
        }
    }

}


