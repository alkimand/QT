import QtQuick 2.11
import"../../../Setting"
import QtQuick.Layouts 1.3
//import QtQuick.Controls 2.4
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
//import "../../../ContextMenu/TableViewContexMenu/HeaderContexMenu"

//https://v-silvansky.livejournal.com/25172.html edile mod for text
//https://stackoverflow.com/questions/50373489/is-it-possible-customize-the-qml-tableview-headerdelegate-individually  style
//https://stackoverflow.com/questions/42849848/how-do-i-correctly-handle-mouse-events-in-a-qml-tableview-with-overlapping-mouse event mouse area
//https://forum.qt.io/topic/62636/how-can-i-get-the-tableview-column-header-click-qml/5

Rectangle
{
    id:rect
    //width: tableView.widthSetting
    height: 60
    border.width: 2
    //anchors.right: (styleData.column===4)?parent.right:""
    visible: (styleData.column<tableView.tittleCount && styleData.column>-1)?true:false
    //visible: false
    MouseArea
    {
        id:mouseArea
        anchors.fill: parent
        //cursorShape : Qt.OpenHandCursor
        acceptedButtons: Qt.RightButton | Qt.LeftButton
        onClicked:
        {
            if (mouse.button === Qt.RightButton)
            {
                headerContexMenu.popup()
                console.debug("mouse.button === Qt.RightButton")
            }
        }
        //        onMouseXChanged:
        //        {
        //            cursorShape = Qt.OpenHandCursor
        //        }

    }
    Connections {
        target: styleData//tableView.__mouseArea//styleData
        onPressedChanged:
        {
            var areaX = styleData.mouseheaderClickAreaX
            if  (areaX !== 0)
            {
                var areaY = styleData.mouseheaderClickAreaY;
                var buttonName = "";
                console.debug("onPressedChanged  Header Delegat mouseheaderClickAreaX:"+ areaX + " mouseheaderClickAreaY: " + areaY);
                if (areaY < topHeader.height)
                {
                    buttonName = topHeader.childAt(areaX, areaY).name;
                    //console.debug("areaY < topHeader.height")
                    if (buttonName!==0)
                    {
                        rect.forceActiveFocus()
                        console.debug("itemAt:"+ topHeader.childAt(areaX, areaY).name);
                        if (buttonName==="filterbutton")
                        {
                            filterbutton.clicked()
                        }
                        if (buttonName==="sortbutton")
                        {
                            sortbutton.clicked()
                        }
                    }
                }
                else
                {
                    areaY = areaY - topHeader.height//rect.height/2
                    //console.debug("areaY > topHeader.height areaY:" + areaY )
                    buttonName = bottomheader.childAt(areaX, areaY).name;
                    if (buttonName!==0)
                    {
                        if (buttonName==="searchTextArea")
                        {
                            console.debug("buttonName===searchTextArea" )
                            //console.debug("positionAt" + searchTextArea.positionAt(areaX, areaY))
                            searchTextArea.moveCursorSelection(searchTextArea.positionAt(areaX, areaY),TextEdit.SelectCharacters)
                            //positionAt(int x, int y)
                            //searchTextArea.selectAll()
                            searchTextArea.deselect()
                            //searchTextArea.cursorPosition(2)
                            searchTextArea.forceActiveFocus()

                            // linkActivated("string")
                        }
                    }
                }
            }
        }
    }

    Rectangle
    {
        id:leftBorder
        // visible:  false
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        width: tableView.borderwidth/2;
        height: parent.height
        color: tableView.bordercolor
    }
    Rectangle
    {
        id:topBorder
        //visible:  false
        anchors.top: parent.top
        anchors.left: parent.left
        height:  5//borderwidth
        width: parent.width
        color: tableView.bordercolor
        //color: "#f9d810"
    }
    Rectangle
    {
        id:rightBorder

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        width: tableView.borderwidth/2;
        height: parent.height
        color: tableView.bordercolor
        //visible: false
    }

    Rectangle
    {
        id:bottomBorder
       visible:false // true
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        height: borderwidth
        width: parent.width
        color: tableView.bordercolor
        //z:1
    }

    GridLayout
    {
        clip: true
        // visible: (styleData.column<5)?true:false
        anchors.fill: parent
        anchors.leftMargin:tableView.borderwidth/2
        anchors.rightMargin:tableView.borderwidth/2
        anchors.topMargin:tableView.borderwidth + 2
        anchors.bottomMargin:tableView.borderwidth
        rows: 2
        columns: 1
        //rowSpacing: 6
        Rectangle
        {

            id: topHeader
            color:tableView.backgroundcolor
            border.width: 0
            //opacity: 0
            Layout.row: 1
            Layout.column: 1
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            //visible: false
            Button
            {
               id:filterbutton
                //visible: (styleData.column<5)?true:false
                width: tableView.buttonImageHeight
                height: tableView.buttonImageHeight
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: tableView.borderwidth+5
                property string name: "filterbutton"
                Rectangle
                {
                    id: backgroundImageFilter
                    anchors.fill: parent
                    color: topHeader.color
                    //opacity: 0.3
                    Image
                    {
                        id: imageFilter
                        anchors.fill: parent
                        smooth: true
                        fillMode: Image.PreserveAspectFit
                        anchors.centerIn: parent
                        height: parent.height
                        width:parent.height
                        source: (tableView.filterIsACtive)?tableView.imageFilterAddSource:tableView.imageFilterDeleteSource
                        visible: true//false if use ColorOverlay
                    }


                }

                onClicked:
                {
                    console.log("filterbutton cliked")
                }
            }
            Text
            {
                id: textHeader
                //anchors.fill:parent
                property string name: "textHeader"
                anchors.left: filterbutton.right
                anchors.right: sortbutton.left//parent.right
                anchors.leftMargin: 10
                anchors.rightMargin: tableView.buttonImageHeight

                text: styleData.value// {tableView.tittle[index]}//{tableView.tittle[rect.curentIndex]}// tableView.tittle[index]//{tableView.tittle[rect.curentIndex]}
                //{tableView.tittle[rect.curentIndex]}//{tableView.tittle[rect.curentIndex]}indexFromCurentIndex rect.curentIndex

                //Layout.preferredWidth: headerReactangle.width//-filterbutton.leftMargin  - textHeader.leftMargin - 2*tableView.buttonImageHeight -sortbutton.rightMargin-200
                elide: Text.ElideRight
                //wrapMode: Text.WordWrap
                font.bold : tableView.textBolt
                font.family : tableView.textFont
                font.pointSize : tableView.textPointSize
                color: tableView.textcolor
                horizontalAlignment: tableView.textHorizontalAlignment
                //verticalAlignment: tableView.textVerticalAlignment//++
                // Layout.alignment:Qt.AlignHCenter
                // Layout.alignment:Qt.AlignCenter

            }
            Button
            {
                //visible: false
                id:sortbutton
                width: tableView.buttonImageHeight
                height: tableView.buttonImageHeight
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: tableView.borderwidth+5
                property string name: "sortbutton"
                Rectangle
                {
                    id: backgroundSortButton
                    anchors.fill: parent
                    color: /*"black"*/topHeader.color
                    Image
                    {
                        id: imagesort
                        anchors.fill: parent
                        smooth: true
                        fillMode: Image.PreserveAspectFit
                        anchors.centerIn: parent
                        height: parent.height
                        width:parent.height
                        source: (tableView.sortStatus===1)?tableView.imageSortAscendingSource:tableView.imageSortDescendingSource
                        visible: true
                    }
                }
                onClicked:
                {
                    console.log("sortbutton cliked")
//                    console.log("rect.x:" + rect.x)
//                    console.log("rect.width:" + rect.width)
//                    console.log(" window.width:" +  window.width)
//                    console.log(" window.x:" +  window.x)
                }
            }

            Rectangle
            {
                id:firstHeaderbottomBorder
                visible:  true
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                height: borderwidth/2
                width: parent.width
                color: bordercolor
            }
        }

        //Second line of header
        Rectangle
        {
            id:bottomheader
            Layout.row: 2
            Layout.column: 1
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.width: 0
            TextArea
            {
                id:searchTextArea
                width:parent.width
                font.bold : tableView.textBolt
                font.family : tableView.textFont
                font.pointSize : tableView.textPointSize
                selectByKeyboard:true
                selectByMouse: true
                property string name: "searchTextArea"
                //selectedtableView.textcolor : "red"
                selectionColor : "green"
                color: tableView.textcolor
                horizontalAlignment: tableView.textHorizontalAlignment
                //verticalAlignment: tableView.textVerticalAlignment
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: "Search..."//(searchTextArea.text.length!==0)?"Search...":searchTextArea.text //{ rect.curentIndex +"/" + index}//"Search..."//rect.curentIndex
                inputMethodHints: Qt.ImhNoPredictiveText
                hoverEnabled:true
                textFormat: Qt.RichText
                background : Rectangle
                {
                    anchors.fill: parent
                    color:backgroundcolor
                }
                onPressed: console.log("TextField cliked")
            }
        }
    }

}
