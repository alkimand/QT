import QtQuick 2.12
import QtQuick.Controls 2.12

import "../../../Action"
import Settings 1.0
import "../../../CommonElements/OneRowItem/MoneyCheker"
import "../../../CommonElements/OneRowItem/RowLogic.js" as RowLogic
import "../../../CommonElements/AreaRowHeader"
import "../../../CommonElements/RoundRowPillow/MoneyCheker"

Item {
    id:root
    // property Actions actions : parent.actions
    //property int radius : parent.actions

   // property int radius_
   // signal onDataChanged:
    property ListModel userObjectModel: MortageListModel {
        userTextAreaModels: root.userTextAreaModels
        Component.onCompleted: {
         //  console.log("ListModel onCompleted");
//            header.value = root.userObjectModel.get(0).value_m

//           header.textFirstLine = "_test"//(root.userObjectModel.get(0).firstRowText_m)+"_test"
//          // console.log("root.userObjectModel.get(0).value_m="+root.userObjectModel.get(0).value_m);
//            header.value = root.userObjectModel.get(0).value_m
//            header.textFirstLine = root.userObjectModel.get(0).firstRowText_m
//            header.dataChaned_Area(1, 12525)
        }

    }
    Component.onCompleted: {
     //   console.log("root onCompleted");
        //header.value = root.userObjectModel.get(0).value_m

    }

    property bool isOpen : true
    property bool isAnimationInProgress : false
    property int rowTextBlockWidth:Settings.elementsMortagePage.textBlockWidth;
    property int animationTime : 400
    property int borderRadius : Settings.appContentWidgetSettings.borderRadius;

    property int rowItemHeight : Settings.oneRowItemSettings.rowItemHeight
    property int itemBorderHeight : Settings.oneRowItemSettings.oneRowItemBorderHeigh;
    property int root : Settings.oneRowItemSettings.rowItemHeight
    property var userTextAreaModels : Settings.userTextAreaModels.monthlyPayment;
    property var userValueModel : [ 1255555555, 12252 , 1252, 4542, 2525]




    //height: viewReact.height + header.height + pillow.height

    Component {
        id:rowBorder
        Rectangle {
            height:Settings.elementsMortagePage.distanceBetweenRow;
            // color: Settings.columnSettings.columnFreeSpaceColor;
            color:"red"
        }
    }

    Component {
        id:betwinRowItem
        Rectangle {
            anchors.top:parent.top
            anchors.left:parent.left
            anchors.right:parent.right
            height:root.itemBorderHeight
            color: Settings.columnSettings.columnFreeSpaceColor;
        }
    }


    AreaRowHeader_O {
        id:header
        anchors.top:parent.top
        anchors.left:parent.left
        anchors.right: parent.right
        hasbottomBorder : true;
        animationTime: root.animationTime
        borderRadius: root.borderRadius
//value:225
        //userObjectModel:root.userObjectModel
        //value: 0//{return root.userObjectModel.get(0).value_m }// root.userValueModel[0]
       // textFirstLine : root.userTextAreaModels[0]

        rowTextBlockWidth:Settings.elementsMortagePage.textBlockWidth;
        Component.onCompleted: {
        //   console.log("AreaRowHeader_O onCompleted");
        }

        z:1

    }

    Rectangle{
        id:viewReact
        anchors.top:header.bottom
        anchors.topMargin: -(root.rowItemHeight + root.itemBorderHeight)
        anchors.left:parent.left
        anchors.right: parent.right
        color:"transparent"

        height: (root.rowItemHeight + root.itemBorderHeight) * userObjectModel.count // 500//Settings.oneRowItemSettings.rowItemHeight * view.count + root.itemBorderHeight *  view.count
        z:0

        Component {
            id: itemDelegate
            Item{
                id:item_
                anchors.left:parent.left
                anchors.right: parent.right
                height: item.height + root.itemBorderHeight
                OneRowItem_S {
                    id:item
                    anchors.left:parent.left
                    anchors.right: parent.right
                    // height: Settings.oneRowItemSettings.rowItemHeight
                    value: value_m
                    textBlockWidth : root.rowTextBlockWidth
                    textType: textType_m ;
                    type: type_m
                    textFirstLine: firstRowText_m
                }

                Loader {
                    sourceComponent : betwinRowItem
                    anchors.top:item.bottom
                    anchors.left:parent.left
                    anchors.right:parent.right
                }
            }
        }

        ListView {
            id: view
            anchors.fill: parent
            visible: true//view.activeFocus
            model: userObjectModel
            highlightRangeMode: ListView.ApplyRange
            delegate: itemDelegate
            focus: true
            interactive: true
            flickableDirection: Flickable.VerticalFlick
            boundsBehavior: Flickable.StopAtBounds
            cacheBuffer:10

            Component.onCompleted: {
                //     console.log("root.userValueModel.count="+root.userValueModel.count)
                //         console.log("root.userValueModel.length ="+root.userValueModel.length )
            }
        }

    }

    RoundRowPillow_S {
        id: pillow
        //anchors.top:viewReact.bottom
        y: (root.rowItemHeight + root.itemBorderHeight) * (userObjectModel.count-1) + header.height
        //anchors.topMargin:-root.itemBorderHeight
        anchors.left:parent.left
        anchors.right: parent.right
        z:1
    }

    Rectangle{
        anchors.top: pillow.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        anchors.bottom: viewReact.bottom
        color: "red"
       z:2
    }





    MouseArea{
        anchors.top: header.top
        anchors.left:root.left
        anchors.right: root.right
        anchors.bottom:pillow.bottom
        propagateComposedEvents : false
        z:2
        onClicked: {
          //  console.log("onClicked")
            if (root.isOpen){
                viewReact.height =(root.rowItemHeight + root.itemBorderHeight)
                viewReact.visible = false
                pillow.y= header.height
                //viewModel.clear()
            }
            else{
                afterOpenAnimationRestoringTimer.start()
                open_animation_start.start()
                //pillow.anchors.topMargin=-2
                viewReact.visible = true
               // viewReact.height=(root.rowItemHeight + root.itemBorderHeight) * userObjectModel.count

            }

            root.isOpen=!root.isOpen
        }

        // view.model = view.model-1
    }



    ParallelAnimation {
        id: open_animation_start
        running: false
        NumberAnimation { target: viewReact; property: "height"; from: root.rowItemHeight + root.itemBorderHeight; to:(root.rowItemHeight + root.itemBorderHeight) * userObjectModel.count; duration: 200}//root.animationTime }
        NumberAnimation { target: pillow; property: "y"; from:  header.height; to: (root.rowItemHeight + root.itemBorderHeight) * (userObjectModel.count - 1) + header.height ; duration: 200/2}//root.animationTime  }
      //  NumberAnimation { target: view; property: "height"; from: 0; to: (root.rowItemHeight + root.itemBorderHeight) * userObjectModel.count; duration: 200}
        //root.animationTime }
    }


    Timer {
        id:afterOpenAnimationRestoringTimer
        interval: root.animationTime; running: false; repeat: false
        onTriggered: {
            root.restartAfterOpenAnimation()
            //upper_animation_start.start()
        }
    }

 function restartAfterOpenAnimation(){
    // viewReact.visible = true
     pillow.anchors.topMargin=0
 }



//    function restoreModel(){
//        userValueModel.forEach(function(item, i, arr) {
//            viewModel.append({})
//        });

        //        for (let i = 0; i < userModel.length; i++) {

        //          viewModel.append()
        //        }

}



