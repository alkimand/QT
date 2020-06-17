import QtQuick 2.2
import QtQuick.Dialogs 1.0
import Qt.labs.settings 1.1

FileDialog {
    id: fileDialog
    property int type_: 0
    title: "Please choose a file"
    nameFilters: "(*.fx)"
    selectMultiple : true
    selectedNameFilter : "(*.fx)"

    folder : {"file:///" + app_data.getDefaultDir()}
    //FileMode: Platform.FileDialog.SaveFile
    sidebarVisible: true
    modality : Qt.WindowModal
    onAccepted: {

        //open
        if (type_===0){
            fileDialog.selectMultiple = true;
            for (var i = 0 ;i < fileDialog.fileUrls.length;i++){
                main_root.openFile(fileDialog.fileUrls[i]);
                // console.log("openFile="+fileDialog.fileUrls[i]);
            }
        }
        else if (type_===1){
            fileDialog.selectMultiple = false;
            main_root.saveFile(fileDialog.fileUrls[0])
        }
        fileDialog.close();
    }
    onRejected: {
        // console.log("Canceled")
        fileDialog.close()
    }
    function setType(type){
        type_ = type;
    }
}
