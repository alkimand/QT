import QtQuick 2.12
import QtQuick.Controls 2.12

import "../ItemDelegate"

Loader {
    id:root
    source: setSourceLoader()
    property string placeholderText_L
        function setSourceLoader() {
        var clm =  column
        var loading_file=""
        if ((clm === 0) || (clm === 1))
             loading_file =  "../ItemDelegate/EditableLable.qml"
            else
            loading_file =  "../ItemDelegate/CheckBox.qml"
        return loading_file
    }
}
