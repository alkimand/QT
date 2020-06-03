import QtQuick 2.9
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
//import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
//Item{


//M_Action{}
//Add

//https://www.iconfinder.com/iconsets/32x32-free-design-icons


// ColumnLayout{
ToolBar
{
    id: mainToolBar
    width: parent.width
    height: butt.implicitHeight*2.8

    //height:150
    //visible : false
    GridLayout {
        //anchors.margins: 1

        id: grid
        //height: butt.implicitHeight*2
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: grid.rowSpacing
        anchors.rightMargin: grid.rowSpacing
        anchors.topMargin: grid.columnSpacing
        //anchors.horizontalCenter : parent.horizontalCenter
        rows: 3
        columns: 25
        //scale: 0.5
        //implicitHeight :5
        // maximumHeight :7


        //Layout.minimumHeight : 50

        // Layout.maximumHeight : 70

        //RowLayout {
        //anchors.fill: parent
        //anchors.margins: spacing
        //spacing: 0
        ToolButton
        {

            anchors.margins: 1
            id: butt
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 1
            action: fileOpenAction

        }
        //activeFocusOnPress:true}
        //ToolButton { action: fileSaveAsAction }
        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 2
            //anchors.left: parent.left
            action:  fileSaveAction
            //scale: 0.5
        }





        //            //ToolBarSeparator {}
        //            //++
        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 3
            action: copyAction
        }
        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 4
            action: cutAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 5
            action: pasteAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 6
            action: boldAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 7
            action: italicAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 8
            action: underlineAction
        }

        //            //ToolBarSeparator {}

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 9
            action: alignLeftAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 10
            action: alignCenterAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 11
            action: alignRightAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 12
            action: alignJustifyAction
        }

        //            //ToolBarSeparator {}

        ComboBox
        {
            id: fontFamilyComboBox
            //id: control
            implicitWidth: 170
            model: Qt.fontFamilies()
            Layout.columnSpan: 6
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 16
            //onValueChanged: console.log(value)
            onCurrentTextChanged: console.log(currentText)
            //model: Qt.fa
            // property bool special : false
            //editable: true
            // onActivated: {
            // if (special == false || index != 0) {
            //document.fontFamily = textAt(index)
            // }
            //http://doc.qt.io/qt-5/qml-qtquick-controls-combobox.html
//            delegate : ItemDelegate
//            {
//                Text
//                {
//                    text:currentText
//                }
//            }

        }

        SpinBox
        {
            id: fontSizeSpinBox
           // activeFocusOnPress: false
            implicitWidth: 70
            value: 12
            //property bool valueGuard: true
            onValueChanged: console.log(value)
            //onValueChanged: parent.tabView.
                //tableView
                //cnangeFontFamyly(value)
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 22
        }

        ToolButton
        {
            id: colorButton
            //property var color : document.textColor
            Rectangle {
                id: colorRect
                anchors.fill: parent
                anchors.margins: 8
                color:"red"
                //color: Qt.darker(document.textColor, colorButton.pressed ? 1.4 : 1)
                border.width: 1
                border.color: Qt.darker(colorRect.color, 2)
            }
            onClicked: {
                //colorDialog.color = document.textColor
                colorDialog.open()
            }
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 23
        }


        //--
        Item {
            // Layout.columnSpan: 1
            //Layout.rowSpan: 1
                            Layout.row: 1
                            Layout.column: 24
                            Layout.fillWidth: true
        }
        //ToolButton { action: settingAction }

        //activeFocusOnTab : true ?
        //contentItem : Image { source: "c:/Users/User/Desktop/lab1/1/PASALogger/images/ToolBarIcon/editredo.png"; fillMode: Image.TileVertically}

        //    ToolBar {
        //        id: secondaryToolBar
        //        width: parent.width
        //        //visible : false
        //        RowLayout
        //        {
        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 1
            action: downloadAction

        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 2
            action: addAction

        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 3
            action: playAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 4
            action: pauseAction
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 5
            action:stopAction
        }
        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 6
            action:markerAction
        }

        TextField
        {
            id: searchBox
            Layout.rowSpan: 1
            Layout.columnSpan: 7
            implicitWidth: 250
            Layout.row: 2
            Layout.column: 16
            //width: window.width / 5 * 2
            //anchors.right: parent.right
            //anchors.verticalCenter: parent.verticalCenter
            placeholderText: "Search..."
            inputMethodHints: Qt.ImhNoPredictiveText
        }

        ToolButton
        {
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 23
            action:eraseAction
        }

        Item
        {
            // Layout.columnSpan: 1
//                Layout.rowSpan: 1
//                Layout.row: 2
//                Layout.column: 20
                Layout.fillWidth: true
        }

        //    }

        //{}
    }
}





