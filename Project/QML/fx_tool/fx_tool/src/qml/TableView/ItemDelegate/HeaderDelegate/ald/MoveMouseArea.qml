import QtQuick 2.12

MouseArea
{
    acceptedButtons: Qt.RightButton | Qt.LeftButton
    id:mainContexMenuArea
    anchors.top:parent.top
    anchors.bottom:parent.bottom
    anchors.left:filterbutton.right
    anchors.right:sortbutton.left
    //z:1

    drag.target:rect
    drag.axis: Drag.XAxis
    drag.minimumX: -2000//getMinimumDrapWidth(rect.curentIndex)
    drag.maximumX: 2000//getMaxDrapWidth(rect.curentIndex)
    // onDragChanged: {console.log("onDragChanged:"+rect.x)}
    //on
    onMouseXChanged:
    {
        if(drag.active)
        {
           // console.log("drag.active rect.x:"+rect.x)
          //  console.log("rect width.x:"+rect.width)

        }
    }
    //onDragChanged: console.log("onDragChanged:"+rect.x)

    //https://doc.qt.io/QT-5/qml-qtquick-item.html#mapToItem-method-1
    // childAt(real x, real y)
    onClicked:
    {
        if (mouse.button === Qt.RightButton)
        {
            var indexFrom =indexFromCurentIndex(index)
            var indexTo =indexFromCurentIndex(rect.curentIndex+1)


            console.log("indexFrom "+indexFrom)
            console.log("indexTo "+indexTo)
            console.log("onClicked rect.curentIndex "+rect.curentIndex)
            console.log("onClicked index: "+index)
            //console.log("mainHeaderRepeater.itemAt(indexFrom).x" + mainHeaderRepeater.itemAt(indexFrom).x)

            //index=index+1
            //console.log("onClicked index: "+index)
           // console.log("onClickedheaderMainObject.indexPositionArray[ind]: "+ (mainHeaderRepeater.itemAt(indexFrom).x+mainHeaderRepeater.itemAt(indexFrom).width))
   //        console.log("onClickedrect.x:"+rect.x)
            //console.log("curentIndexFromIndex(index) "+curentIndexFromIndex(index))
            //console.log("headerMainObject.tittle[0] "+headerMainObject.tittle[0] )
            //console.log("headerMainObject.tittle "+headerMainObject.tittle[curentIndexFromIndex(index)])
        }
        else
        {
           for (var i = 0; i < 8; ++i)
           {
               console.log("headerMainObject.indexPositionArray["+ i  +"] = "+ headerMainObject.indexPositionArray[i]);
               console.log("headerMainObject.positionArray["+ i  +"] = "+ headerMainObject.positionArray[i]);

           }
           //console.log("onClicked headerMainObject.tittle[0]:" + headerMainObject.tittle[0])
           //console.log("onClicked headerMainObject.tittle[1]:" + headerMainObject.tittle[1])
          // console.log("onClicked headerMainObject.tittle[2]:" + headerMainObject.tittle[2])
           //console.log("onClicked headerMainObject.tittle[3]:" + headerMainObject.tittle[3])
            //mainHeaderRepeater.model.
            //console.log("mainContexMenuArea Qt.LeftButton cliked")
//            console.log("rect.x:"+rect.x)
        }
    }
    onPressAndHold:
    {
        //console.log("onPressAndHold start x:"+mouseX)
    }
    onPressed:
    {
        console.log("onPressed: x:"+mouseX);
        mouseMoveStartX = mouseX;
    }

    onReleased:
    {
        var xx=rect.x
        if (!(headerMainObject.mouseMoveStartX===0))
        {
            //mouseMoveFinishX=mouseX;
            //console.log("Move from:"+headerMainObject.mouseMoveStartX + "to "+headerMainObject.mouseMoveFinishX)
        }
          //rect.x=headerMainObject.positionArray[rect.curentIndex]
        console.log("onReleased rect.x" + rect.x)
       // console.log("onReleased headerMainObject.positionArray[rect.curentIndex]" + headerMainObject.positionArray[rect.curentIndex])
        rect.x= 0//headerMainObject.positionArray[rect.curentIndex]
        console.log("mouseX:"+mouseX);
         //console.log("onReleased rect.x:index " + headerMainObject.positionArray[index] )
      //  console.log("onReleased rect.x:rect.curentIndex " + headerMainObject.positionArray[rect.curentIndex] )
       // console.log("onReleased rect.x:indexPositionArray " + headerMainObject.indexPositionArray[rect.curentIndex] )
//        console.log("onReleased rect.x:indexFromCurentIndex " + indexFromCurentIndex(rect.curentIndex) )
        //indexFromCurentIndex
         //rect.x = headerMainObject.positionArray[rect.curentIndex]
            //tabView.moveTab(index,index-1)

        //console.log("onReleased:"+mouseX)

        // rect.x = 0
    }

    function getMinimumDrapWidth(index)
    {
        var xOffsetLeft = 0
        if (index!==0)
        {
            xOffsetLeft = rect.width*1//index
        }
        console.log("getMaxDrapWidth(index) + =" + -xOffsetLeft)
        return -xOffsetLeft
    }

    function getMaxDrapWidth(index)
    {
        var xOffsetRight = 0
        if (index!==(tabView.count - 1))
        {
            xOffsetRight = rect.width*1//(tabView.count - 1 - index)
        }
        console.log("getMaxDrapWidth(index) + =" + xOffsetRight)
        return  xOffsetRight


    }


}
