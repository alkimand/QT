import QtQuick 2.11
import"../../../Setting"
import QtQuick.Layouts 1.3
//import QtQuick.Controls 2.4
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

//https://v-silvansky.livejournal.com/25172.html edile mod for text
//https://stackoverflow.com/questions/50373489/is-it-possible-customize-the-qml-tableview-headerdelegate-individually  style

Rectangle
{
    id:rect
    width: 150;
    height: 60
    border.width: 0
    //color:"red"
    //Component.onCompleted: console.log("Rectangle+")
   // property int curentIndex: parent.index
    //property int index: parent.index
    property int moveMerginIndex:0
    //    Component.onCompleted:
    //    {

    //    }
    //    onXChanged:
    //    {
    //        var x = rect.x
    //        console.log("onXChanged +rect.x =" + rect.x)
    //    }


    //onLeftChanged: console.log("onLeftChanged +rect.x =" + rect.x)
    //onPosChanged: console.log("onPosChanged +rect.x =" + rect.x)
    //        NormalBorder
    //        {
    //            type:3
    //           // anchors.left: parent.left
    //          //  anchors.top: parent.top
    //        }

    MouseArea
    {
        anchors.fill:parent
        z:1
       acceptedButtons: Qt.RightButton | Qt.LeftButton
       onClicked:
       { if (mouse.button === Qt.RightButton)
           console.log("onClicked Qt.RightButton MouseArea:")
           else
           {
               console.log("onClicked Qt.LeftButton MouseArea:")
           }
       }
       onDoubleClicked:
       {
           console.log("onDoubleClicked MouseArea:")
       }

    }
    Repeater
    {
        anchors.fill:parent
        id:repeater
        model: 4
        //                Loader
        //                {
        //                    id:loader2
        //                    property int type:2//index
        //                    anchors.fill:parent
        //                    source: "NormalBorder.qml"
        //                }
        Rectangle
        {
            id:border

            width:0//tableView.borderwidth
            color:"red"// tableView.bordercolor
            z:1
            visible: false
            Component.onCompleted:
            {
                for (var index=0;index<5;index++){



                //console.log("index:"+index)
                switch (index)
                {
                case 0:
                   // anchors.left=parent.left;
                    //anchors.top=parent.top;
                    width=1//tableView.borderwidth/2;
                    height=1//parent.height;
                   // visible = true//(tableView.indexToMove===curentIndex)?false:true;
                    //console.log("index:"+index)
                    break;
                case 1:

                    anchors.left=parent.left;
                    anchors.top=parent.top;
                    width=parent.width;
                   // visible= true;
                    height=tableView.borderwidth;
                    //console.log("index:1")
                    break;

                case 2:

                    anchors.right=parent.right;
                    anchors.top=parent.top;
                    width=tableView.borderwidth/2;
                    height=parent.height;
                    //visible= (tableView.indexToMove===curentIndex+1)?false:true;;
                    color:"blue"
                    //console.log("index:2")
                    break;

                case 3:

                    anchors.left=parent.left;
                    anchors.bottom=parent.bottom;
                    width=parent.width;
                    height=tableView.borderwidth;
                    //visible= true;
                    //console.log("index:3")
                    break;
                default:
}
                }
                // if
            }
        }
    }

//    Repeater
//    {
//        anchors.fill:parent
//        // id:repeater
//        model: 2
//        Rectangle
//        {
//            id:moveBorder

//            width:0
//            color: tableView.borderMoveAreaColor
//            z:1
//            visible: false
//            //property int movngIndex
//            property int curentIndex:rect.curentIndex
//            Component.onCompleted:
//            {
//                //console.log("index:"+index)
//                switch (index)
//                {
//                case 0:
//                    anchors.left=parent.left;
//                    anchors.top=parent.top;
//                    width=tableView.borderMoveAreaWidth;
//                    height=parent.height;
//                    visible = (tableView.indexToMove===curentIndex)?true:false//((tableView.indexToMove===curentIndex)&& (tableView.indexToMoveSide===0))?true:false
//                    //console.log("index:"+index)
//                    break;

//                case 1:
//                    anchors.right=parent.right;
//                    anchors.top=parent.top;
//                    width=tableView.borderMoveAreaWidth;
//                    visible = (tableView.indexToMove===curentIndex+1)?true:false//setVisible(curentIndex)//((tableView.indexToMove===curentIndex)&& (tableView.indexToMoveSide===1))?true:false
//                    height=parent.height;
//                    //console.log("index:1")
//                    break;
//                default:
//                }
//            }
//        }
//    }

    //    function setVisible(cIndex)
    //    {
    //        if (((tableView.indexToMove===cIndex)))//&&(tableView.indexToMoveSide===0)) || ((tableView.indexToMove===(cIndex+1))&&(tableView.indexToMoveSide===1)))
    //        {
    //            return true;
    //        }
    //        else
    //        {
    //            return false;
    //        }
    //    }



    //        NormalBorder
    //        {
    //            type:2
    //            anchors.right: parent.right
    //            anchors.top: parent.top
    //        }
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

//        Rectangle
//        {
//            id:moveBorder
//           //visible:  false
//            anchors.right: parent.right
//            anchors.top: parent.top
//            //anchors.verticalCenter: parent.verticalCenter
//            width: 2//borderMoveAreaWidth
//            height: rect.height////parent.height
//            color: tableView.borderMoveAreaColor
//            z:1
//        }

        Rectangle
        {
            id:bottomBorder
           // visible:false // true
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
                width: tableView.buttonImageHeight
                height: tableView.buttonImageHeight
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: tableView.borderwidth+5
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

                //                Connections {
                //                    target: filterbutton
                //                    onClicked: {
                //                        console.debug(" filterbuttonon Clicked :")
                //                        //  console.debug("COLUMN:  "+ styleData.column)
                //                    }
                //                }
                //                            MouseArea
                //                            {
                //                                anchors.fill: parent
                //                                // propagateComposedEvents:true
                //                                hoverEnabled: true
                //                                onClicked: console.log("filterbutton onClicked " +index)
                //                                onEntered:  console.debug(" filterbutton onEntered")
                //                                onPressed: console.debug(" filterbutton onPressed")
                //                            }
                onClicked:
                {
                    console.log("filterbutton cliked")
                }
            }
            Text
            {
                id: textHeader
                //anchors.fill:parent
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
                verticalAlignment: tableView.textVerticalAlignment
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
            //MouseArea

          //  MoveMouseArea{}
        }

        //Second line of header
        Rectangle
        {
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
                //selectedtableView.textcolor : "red"
                selectionColor : "green"
                color: tableView.textcolor
                horizontalAlignment: tableView.textHorizontalAlignment
                verticalAlignment: tableView.textVerticalAlignment
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: "Search..." //{ rect.curentIndex +"/" + index}//"Search..."//rect.curentIndex
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
//    onXChanged:
//    {
//        var x = rect.x //- rect.moveMerginIndex//(rect.x - tableView.positionArray[rect.curentIndex])
//        // console.log("rect.moveMerginIndex =" + rect.moveMerginIndex)
//        console.log("onXChanged rect.x =" + rect.x)
//        //console.log("onXChanged tableView.positionArray[rect.curentIndex] =" + tableView.positionArray[rect.curentIndex])
//        //console.log("rect.x - rect.moveMerginIndex =" + x)

//        //console.log("onXChanged  x =" + x)
//        if (x < 0)
//        {
//            //console.log("onXChanged x<0)" )
//            if (x < (-rect.width  ))
//            {
//                //console.log("move x < (rect.width / 2) inedx to:"+(rect.curentIndex-1))
//                //tabView.moveTab(index,index - 1)

//                // oneTabView.x = 0
//                //tabView.moveTab(index,index)
//            }
//            else
//            {
//                // oneTabView.x = 0
//            }
//        }
//        else
//        {
//            // console.log("onXChanged x>0")
//            if (x > (rect.width / 2))
//            {
//                console.log("x>(oneTabView.width/2)")
//                // console.log("move inedx to:"+(rect.curentIndex+1))
//                var ind = rect.curentIndex
//                //console.log("rect.curentIndex"+rect.curentIndex)
//                // console.log("repeater.itemAt(ind+1).children[0].curentIndex:"+mainHeaderRepeater.itemAt(ind+1).children[0].curentIndex)
//                //mainHeaderRepeater.itemAt(ind + 1).children[0].curentIndex = ind // move -1 ind
//                //rect.curentIndex=ind + 1
//                //console.log("move x > (rect.width / 2)"+rect.curentIndex + " to:"+(rect.curentIndex+1))
//                movePosition(rect.curentIndex,rect.curentIndex+1)
//                //console.log("tabView.moveTab(index,index + 1)")
//                //oneTabView.x = 0
//                //tabView.moveTab(index,index + 1)
//            }
//            else
//            {
//                //oneTabView.x = 0
//            }
//        }
//        //console.log("onXChanged -- x =" + oneTabView.x)
//    }

    function movePosition(from,to)
    {
        if (from!==to)
        {
            console.log("move inedx from "+  from +" to " + to)
           // var indexFrom =indexFromCurentIndex(from)
            //var indexTo =indexFromCurentIndex(to)
            var indexFrom =indexFromCurentIndex(index)
            var indexTo =indexFromCurentIndex(rect.curentIndex+1)
            //var xx= mainHeaderRepeater.itemAt(indexFrom).x;
            //var xx2= mainHeaderRepeater.itemAt(indexTo).x;
            // rect.
            // rect.moveMerginIndex = rect.moveMerginIndex+150
            //rect.x=rect.x+150

            //movement

            var coordFrom = tableView.positionArray[indexFrom]
            //rect.x = tableView.positionArray[indexTo]

            console.log("rect.x "+ rect.x)

            headerRow.children[indexFrom].x = tableView.positionArray[indexTo]//++
            //rect.x=tableView.positionArray[indexTo]//++

            //headerRow.children[indexTo].x = headerRow.children[indexTo].x -
            console.log("headerRow.children[indexFrom].x.= " + headerRow.children[indexFrom].x)

           // headerRow.children[indexTo].x = coordFrom
           //  headerRow.children[indexFrom].anchors.left = headerRow.children[indexTo].anchors.left

            //tableView.positionArray[indexTo] = coordFrom
            //tableView.positionArray[indexFrom] =

           //tableView.positionArray[indexFrom] = tableView.positionArray[indexTo]//tableView.positionArray[indexTo];//
            console.log("tableView.positionArray[indexFrom].x:"+tableView.positionArray[indexFrom] )

            //tableView.positionArray[indexTo].x =distanseTo;

           // positionArray
             //textHeader.text="123"
            //mainHeaderRepeater.itemAt(indexFrom).index=1

            //mainHeaderRepeater.itemAt(mapFromRepeater(from)).x =150//mainHeaderRepeater.itemAt(mapFromRepeater(to)).x;
            // mainHeaderRepeater.itemAt(mapFromRepeater(to)).x = xx;

            //rect.moveMerginIndex = mainHeaderRepeater.itemAt(to-1).x

            //rect.moveMerginIndex = mainHeaderRepeater.itemAt(to-1).x



            // mainHeaderRepeater.itemAt(mapFromRepeater(from)).anchors.left = mainHeaderRepeater.itemAt(mapFromRepeater(to)).anchors.right
            //  mainHeaderRepeater.itemAt(mapFromRepeater(from)).anchors.right = mainHeaderRepeater.itemAt(mapFromRepeater(to+1)).anchors.left

            //curentIndex field
            headerRow.children[indexTo].children[0].curentIndex = from
            rect.curentIndex =  to;

            //
            //tableView.positionArray[from]


            //change map repeter
            var ind = tableView.indexPositionArray[indexFrom];
            tableView.indexPositionArray[indexFrom] = tableView.indexPositionArray[indexTo];
            //console.log("tableView.indexPositionArray[indexFrom]: "+tableView.indexPositionArray[indexFrom])
            tableView.indexPositionArray[indexTo] = ind;
            //console.log("tableView.indexPositionArray[indexTo]: "+tableView.indexPositionArray[indexTo])

           // var tittle = tableView.tittle[indexFrom]

           // tableView.tittle[indexFrom] = tableView.tittle[indexTo]
           // console.log("tableView.tittle[indexFrom]:" + tableView.tittle[indexFrom])

           // tableView.tittle[indexTo]=tittle
           // console.log("tableView.tittle[indexTo]:" + tableView.tittle[indexTo])

            //rect.x=tableView.positionArray[rect.curentIndex+2]
            //mainHeaderRepeater.itemAt(from).children[0].curentIndex = mainHeaderRepeater.itemAt(from).children[0].curentIndex
            //mainHeaderRepeater.itemAt(from).children[0].curentIndex = mainHeaderRepeater.itemAt(from).children[0].curentIndex

            //console.log("move inedx from 1% to 2%",ind,ind+1)
            //  console.log("rect.moveMerginIndex:",rect.moveMerginIndex)
        }
        //    function mapFromRepeater(ind) //income our curent index // outcome index in repeater
        //    {
        //        return tableView.indexPositionArray[ind]
        //    }
    }
//        function curentIndexFromIndex(ind)
//        {
//            return tableView.indexPositionArray[ind]
//        }
//        function indexFromCurentIndex(ind)
//        {
//            //tableView.indexPositionArray.count
//            for (var i = 0; i < tableView.tittleCount; i++)
//            {
//                if (tableView.indexPositionArray[i]===ind)
//                    return tableView.indexPositionArray[i]
//            }
//        }


}







