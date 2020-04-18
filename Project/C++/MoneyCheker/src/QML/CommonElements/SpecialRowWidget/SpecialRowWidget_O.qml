import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Settings 1.0
import BorderRadiusWidget.qml 1.0
import "../OneRowItem/RowElements"
import "../OneRowItem/MoneyCheker"
import "../OneRowItem/RowLogic.js" as RowLogic



Item {
    id:root

    property int borderRadius : Settings.appContentWidgetSettings.borderRadius;
    property color topActiveColor:Settings.buttonSettings.buttonIsNotSelectedColorSetting;
    property color backgroundColor: Settings.appContentWidgetSettings.disactiveFontColor;
    property color activeButtonColor:"red"
    property color backgroundFontColor:"yellow"
    property int rowTextBlockWidth:Settings.elementsMortagePage.textBlockWidth;
    property int numberOfElements : 4;
    property int itemBorderHeight : Settings.oneRowItemSettings.oneRowItemBorderHeigh;
    property bool isOpen : true
    //property int upperAnimationMargin : Settings.oneRowItemSettings.oneRowItemBorderHeigh;

    property int animationTime:400
    height: root.numberOfElements * Settings.oneRowItemSettings.rowItemHeight + Settings.appContentWidgetSettings.buttonHeight + (root.numberOfElements)* Settings.oneRowItemSettings.oneRowItemBorderHeigh + root.borderRadius;
    //height: Settings.appContentWidgetSettings.buttonHeight

    //common
    //    property Item centerCustomWidget : Item{
    //        Rectangle{
    //            //anchors.fill: parent
    //            color:"red"
    //            height:10
    //            width:10
    //        }
    //    }

    BorderRadiusWidget {
        id:topLeftRadius
        anchors.left:parent.left
        anchors.top:parent.top
        anchors.topMargin:root.borderRadius
        anchors.leftMargin: root.borderRadius
        radius: root.borderRadius
        activeButtonColor:  root.topActiveColor
        transform: Rotation {
            origin.x: 0;
            origin.y:0;
            angle: 0
        }
        z:2
    }

    Rectangle{
        id:topLeftRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        anchors.left:parent.left
        anchors.top:parent.top
        z:1
        color: root.backgroundColor
    }


    Rectangle{
        id:centerRect
        anchors.top:parent.top
        anchors.left:topLeftRadiusReact.right
        anchors.right: topRightRadiusReact.left
        height:root.borderRadius
        color: root.topActiveColor
    }


    BorderRadiusWidget {
        id:topRightRadius
        anchors.right:parent.right
        anchors.top:parent.top
        anchors.topMargin:root.borderRadius
        anchors.rightMargin: root.borderRadius
        radius: root.borderRadius
        activeButtonColor:  root.topActiveColor
        transform: Rotation {
            origin.x: root.x;
            origin.y: root.y;
            angle: 90}

        z:2
    }

    Rectangle{
        id:topRightRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        anchors.right:parent.right
        anchors.top:parent.top
        z:1
        color: root.backgroundColor
    }

    OneRowItem_S {
        id:header_row
        anchors.top:topLeftRadius.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        //anchors.fill: parent
        rowItemHeight:Settings.appContentWidgetSettings.buttonHeight - Settings.appContentWidgetSettings.borderRadius;
        backgroundColor: root.topActiveColor;
        // paddingRight:Settings.elementsMortagePage.paddingRight;
        labelРighlightingFontColor:"black";
        value: 1210010
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
        textSecondLineType: RowLogic.DataType.STRING_DATA_TYPE;
        type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_TEXT_RIGHT_ALIGNEMENT;
        textFirstLine: "Monthly payment"
        textSecondLine: (RowLogic.valueToUserText ("test", RowLogic.DataType.STRING_DATA_TYPE))
    }


    Component {
        id:itemBorder
        Rectangle {
            height:root.itemBorderHeight
            color: Settings.columnSettings.columnFreeSpaceColor;
        }
    }



    //body

    Loader {
        id:border_1
        sourceComponent: itemBorder
        anchors.top:header_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id: preincipal_row
        visible: (height > backgroundReact.height && backgroundReact.visible===false)? false : true
        anchors.top:border_1.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        value: 8255578
        textBlockWidth : root.rowTextBlockWidth
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
        textFirstLine: "Principal & interest"
    }

    Loader {
        id:border_2
        sourceComponent: itemBorder
        anchors.top:preincipal_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id: tax_row
        visible: (height*1 > backgroundReact.height && backgroundReact.visible===false)? false : true
        anchors.top:border_2.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        value: 58
        textBlockWidth : root.rowTextBlockWidth
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
        textFirstLine: "Property tax"
    }

    Loader {
        id:border_3
        sourceComponent: itemBorder
        anchors.top:tax_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id: insurance_row
        visible: (height*2 > backgroundReact.height && backgroundReact.visible===false)? false : true
        anchors.top:border_3.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        value: 10721
        textBlockWidth : root.rowTextBlockWidth
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
        textFirstLine: "Property insuranse"
    }

    Loader {
        id:border_4
        sourceComponent: itemBorder
        anchors.top:insurance_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    OneRowItem_S {
        id: pmi_row
       // visible: (height*3 > backgroundReact.height && backgroundReact.visible===false)? false : true
        visible: (backgroundReact.visible===true)? false : true
        anchors.top:border_4.bottom
        anchors.left:parent.left
        anchors.right: parent.right
        value: 5894
        textBlockWidth : root.rowTextBlockWidth
        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
        textFirstLine: "PMI"
    }

    Loader {
        id:border_5
        sourceComponent: itemBorder
        anchors.top:pmi_row.bottom
        anchors.left:parent.left
        anchors.right:parent.right
    }

    //
    BorderRadiusWidget {
        id:borromLeftRadius
        anchors.left:parent.left
        anchors.leftMargin: root.borderRadius
        anchors.bottom:parent.bottom
        anchors.bottomMargin: root.borderRadius - root.itemBorderHeight

        radius: root.borderRadius
        activeButtonColor:  root.topActiveColor
        transform: Rotation {
            origin.x: root.x;
            origin.y: root.y;
            angle: 270
        }
        z:2
    }

    Rectangle{
        id:bottomLeftRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        anchors.left:parent.left
        anchors.bottom:parent.bottom
        z:1
        color: root.backgroundColor
    }


    Rectangle{
        id:centerBottomRect
        anchors.bottom:parent.bottom
        anchors.left:topLeftRadiusReact.right
        anchors.right: topRightRadiusReact.left
        anchors.bottomMargin: - root.itemBorderHeight
        ///nchors.bottomMargin: 0//root.itemBorderHeight
        height:root.borderRadius
        color: root.topActiveColor
    }


    BorderRadiusWidget {
        id:bottomRightRadius
        anchors.right:parent.right
        anchors.bottom:parent.bottom
        anchors.bottomMargin: root.borderRadius - root.itemBorderHeight
        anchors.rightMargin: root.borderRadius
        radius: root.borderRadius
        activeButtonColor:  root.topActiveColor
        transform: Rotation {
            origin.x: root.x;
            origin.y: root.y;
            angle: 180
        }
        z:2
    }

    Rectangle{
        id:bottomRightRadiusReact
        width:root.borderRadius
        height:root.borderRadius
        //anchors.topMargin: numberOfElements * Settings.oneRowItemSettings.rowItemHeight + Settings.oneRowItemSettings.oneRowItemBorderHeigh*4;
        anchors.right:parent.right
        anchors.bottom:parent.bottom
        z:1
        color: root.backgroundColor
    }

    Rectangle{
        id:backgroundReact
        visible: false
        anchors.left:parent.left
        anchors.right:parent.right
        anchors.top:border_1.bottom
        height : root.numberOfElements * Settings.oneRowItemSettings.rowItemHeight +(root.numberOfElements)* Settings.oneRowItemSettings.oneRowItemBorderHeigh
        //anchors.topMargin: numberOfElements * Settings.oneRowItemSettings.rowItemHeight + Settings.oneRowItemSettings.oneRowItemBorderHeigh*4;
        z:1
        color: "white"//root.backgroundColor
    }


    Timer {
        id:animationTimer
        interval: root.animationTime; running: false; repeat: false
        onTriggered: {
            //root.addUpperItems()
            //upper_animation_start.start()
            backgroundReact.visible = false
            //backgroundReact.height =
        }
    }



    ParallelAnimation {
        id: close_animation
        running: false
        NumberAnimation { target: root; property: "height";
            from: root.numberOfElements * Settings.oneRowItemSettings.rowItemHeight + Settings.appContentWidgetSettings.buttonHeight + (root.numberOfElements)* Settings.oneRowItemSettings.oneRowItemBorderHeigh + root.borderRadius;
            to: Settings.appContentWidgetSettings.buttonHeight +  0*root.itemBorderHeight + root.borderRadius;
            duration:root.animationTime }
        NumberAnimation { target: backgroundReact; property: "height"; from: root.numberOfElements * Settings.oneRowItemSettings.rowItemHeight +(root.numberOfElements)* Settings.oneRowItemSettings.oneRowItemBorderHeigh ; duration:root.animationTime; to: 0 }
        // NumberAnimation { target: animation_right_bottom_border; property: "height"; from: 0; to: textLabel.height; duration:root.bottomAnimationTime }
    }

    ParallelAnimation {
        id: open_animation
        running: false
        NumberAnimation { target: root; property: "height";
            from: Settings.appContentWidgetSettings.buttonHeight +  0 *root.itemBorderHeight + root.borderRadius;
            to: root.numberOfElements * Settings.oneRowItemSettings.rowItemHeight + Settings.appContentWidgetSettings.buttonHeight + (root.numberOfElements)* Settings.oneRowItemSettings.oneRowItemBorderHeigh + root.borderRadius;
            duration:root.animationTime }
        NumberAnimation { target: backgroundReact; property: "height"; from: 0; to: root.numberOfElements * Settings.oneRowItemSettings.rowItemHeight +(root.numberOfElements)* Settings.oneRowItemSettings.oneRowItemBorderHeigh ; duration:root.animationTime }
    }


    MouseArea{
        anchors.fill:parent
        propagateComposedEvents :false

        onClicked: {
            if (root.isOpen){
                backgroundReact.height=0
                backgroundReact.visible = true
                close_animation.start()
            }
            else{

                backgroundReact.visible = true
                open_animation.start()
            }
            animationTimer.start()
            root.isOpen=!root.isOpen
        }
    }























}





