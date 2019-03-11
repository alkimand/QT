import QtQuick 2.0
Item {
Rectangle {
    id: rowDel
    //color: "blue"
    //height: 60
    SystemPalette {
        id: myPalette;
        colorGroup: SystemPalette.Active
    }

    color: {
        var baseColor = styleData.alternate?myPalette.alternateBase:myPalette.base
        return styleData.selected?myPalette.highlight:baseColor
    }

    readonly property int modelRow: styleData.row ? styleData.row : 0

    MouseArea {
        //anchors.fill: parent
        onClicked: {
            console.log("[!] log: " + modelRow);
        }
    }
}

}
/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
