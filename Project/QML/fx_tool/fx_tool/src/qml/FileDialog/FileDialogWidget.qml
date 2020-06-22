import QtQuick 2.2
import QtQuick.Dialogs 1.0
import Qt.labs.settings 1.1
import Qt.labs.platform 1.0

FileDialog {
    id: fileDialog
    property int type_: 0
    title: "Please choose a file"
    nameFilters: "(*.fx)"
    // selectMultiple : true
    //selectedNameFilter : "(*.fx)"
    //fileMode:0
    folder : {"file:///" + app_data.getDefaultDir()}
    //sidebarVisible: true
    modality : Qt.WindowModal
    onAccepted: {

        //open
        if (type_===0){
            //fileDialog.fileMode = FileDialog.SaveFile
            //for (var i = 0 ;i < fileDialog.fileUrls.length;i++){
            main_root.openFile(fileDialog.file )
            //main_root.openFile(fileDialog.fileUrls[i]);
            // console.log("openFile="+fileDialog.fileUrls[i]);
            // }
        }
        else if (type_===1){
            //fileDialog.selectMultiple = FileDialog.SaveFile;
            main_root.saveFile(fileDialog.file )
            //main_root.saveFile(fileDialog.fileUrls[0])
        }
        fileDialog.close();
       //  fileDialog.fileMode = 0
    }
    onRejected: {
        // console.log("Canceled")
        fileDialog.close()
    }
    function setType(type){
        console.log("type ="+type)
        if (type_===0)
            fileDialog.fileMode = 0
       // }//FileDialog.OpenFile
        else if (type_===1)
            fileDialog.fileMode = 2

        //fileDialog.fileMode = 2
        //}
       type_ = type;
       // fileDialog.fileMode =0
     //
       console.log("fileMode+"+fileDialog.fileMode)


    }
}
