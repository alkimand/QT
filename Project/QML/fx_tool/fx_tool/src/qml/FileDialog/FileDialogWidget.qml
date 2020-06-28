import QtQuick 2.12
import QtQuick.Dialogs 1.2
import Qt.labs.settings 1.1
import Qt.labs.platform 1.0

FileDialog {
    id: fileDialog
    property int type_: dialog_type_L
    title: "Please choose a file"
    nameFilters: "(*.fx)"
    //selectMultiple : false
    //selectedNameFilter : "(*.fx)"
    fileMode: FileDialog.OpenFile
    folder : {"file:///" + app_data.getDefaultDir()}
    modality : Qt.WindowModal
    onAccepted: {

        //open
        if (type_=== 0) {
            main_root.openFile(fileDialog.file )
        }
        else if (type_=== 1) {
            main_root.saveFile(fileDialog.file )
        }
        fileDialog.close();
    }
    onRejected: {
        fileDialog.close()
    }

    Component.onCompleted: {
       // fileDialog.fileMode =  1//FileDialog.SaveFile
        fileDialog.open();
       // console.log("onCompleted type_= " + type_)
        //console.log("fileDialog.fileMode= " + fileDialog.fileMode)
    }
}
