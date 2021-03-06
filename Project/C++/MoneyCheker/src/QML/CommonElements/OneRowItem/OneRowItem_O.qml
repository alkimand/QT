import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Settings 1.0
import BorderRadiusWidget.qml 1.0
import "../SmallCrossChekerButton/MoneyCheker"
import "../OneRowItem/RowElements"
import "RowLogic.js" as Logic
//import ItemProperty 1.0


Item {
    id:root
    //common
    //    property Item centerCustomWidget : Item{
    //        Rectangle{
    //            //anchors.fill: parent
    //            color:"red"
    //            height:10
    //            width:10
    //        }
    //    }






    signal openRowView()

    //common style
    property string commonFontFamily
    property color backgroundColor
    property color backgroundFontColor
    property int rowItemWidth //weight
    property int rowItemHeight
    property int rowMargin  //to up if will need
    property int paddingLeft
    property int paddingRight
    property int textRowSpacing
    property int type
    property int textType
    property int textSecondLineType
    property int hasBorder
    property int borderRadius
    property int itemPropertyType //: ItemProperty.e_ItemProperty.STYLE_RADIAL

    //textLine
    property int textBlockWidth
    property color textFirstLineFontColor
    property color textSecondLineFontColor
    property int textFirstLineFontSize
    property int textSecondLineFontSize
    property int textFirstLineTopMargin
    property alias textFirstLine: textFirstLine_.text
    property alias textSecondLine : textSecondLine_.text

    //Label
    property color labelFontColor
    property color labelРighlightingFontColor
    property int labelFontSize
    property int labelBorderColorWidth
    property int labelLeftPadding
    property int labelMargins
    property var value

    //CenterComboBox_O
    property var valueArr

    //Button
    property color activMainButtonColor
    property color activBackgroundButtonColor
    property color pressedMainButtonColor
    property color pressedBackgroundButtonColor
    property int buttonSize// = 2*radius
    property int crossSize
    property int checkerSize
    property int checkerHeigh
    property int checkerMargin
    property int buttonBorderWidth
    property int oneRowItemBorderHeigh

    //CenterComboBox_O
    property int tottallAnimationTime



    width: root.rowItemWidth
    height:root.rowItemHeight

    // property bool isActive: false



    signal dataChaned_Row(int type_, variant value_)
    Connections {
        target: root
        onDataChaned_Row: {
            //console.log("Row onDataChanged")
            if (header_row.value!== root.value)
                header_row.value = root.value;


            if (header_row.textFirstLine!== root.textFirstLine)
             header_row.textFirstLine = root.textFirstLine;
         //   console.log("value="+value_)
            //}
        }
    }








    //to transfer up
    signal pushPlusButton()
    signal pushMinusButton()

    signal pushChekerOpenButton()
    signal pushChekerCloseButton()

    //use in this  class
    //signal activate()
    //signal disable()
    //z:-1


// signal openView()

    signal openView()

    Connections {
        target: centerLoader.item
        onOpenView: {
            root.openRowView()
           // console.log("onOpenView")
        }
    }
    Rectangle {
        id:parentReact
        anchors.fill: parent
        //anchors.left:parent.left
        //anchors.top: parent.top
        //anchors.bottom: parent.bottom
        color: root.backgroundColor

        Rectangle {
            id: textReact
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left:parent.left
            anchors.leftMargin: root.paddingLeft
            anchors.topMargin: 0
            width: root.textBlockWidth
            color: "transparent"
            GridLayout {

                id:column
                anchors.fill: parent
                rows: 2
                columns: 1
                rowSpacing : textRowSpacing
                Text
                {
                    id: textFirstLine_
                    width: textReact.width
                    Layout.alignment:Qt.AlignVCenter
                    horizontalAlignment : Text.AlignLeft
                    verticalAlignment :(textSecondLine_.visible)?Text.AlignBottom:Text.AlignVCenter
                    text: root.textFirstLine
                    font.family : root.commonFontFamily
                    font.pointSize:  root.textFirstLineFontSize
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    elide : Text.ElideRight //wrapped text
                    color: root.textFirstLineFontColor
                    renderType: Text.NativeRendering // Rendering type (optional)
                    Layout.columnSpan: 1
                    Layout.rowSpan: 1
                    Layout.row: 1
                    Layout.column: 1
                }

                Text
                {
                    id: textSecondLine_
                    visible:true
                    width: textReact.width
                    // anchors.verticalCenter: parent.verticalCenter
                    Layout.alignment:Qt.AlignVCenter
                    horizontalAlignment : Text.AlignLeft
                    verticalAlignment :Text.AlignTop
                    text: root.textSecondLine //Logic.valueToUserText (root.textSecondLine, root.textSecondLineType)
                    font.family : root.commonFontFamily
                    font.pointSize:  root.textSecondLineFontSize
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //font.bold :true
                    elide : Text.ElideRight //wrapped text
                    color: root.textSecondLineFontColor
                    renderType: Text.NativeRendering // Rendering type (optional)
                    Layout.columnSpan: 1
                    Layout.rowSpan: 1
                    Layout.row: 2
                    Layout.column: 1
                    Component.onCompleted: {
                        if (root.textSecondLine===""){
                            textSecondLine_.visible = false;
                            textReact.anchors.topMargin = root.textFirstLineTopMargin;
                        }
                    }
                }
            }
        }


        CenterLabel_O {
            id:centerLabel
        }

        CenterComboBox_O{
            id:centerComboBox
        }

        CenterDateCalendar_O{
            id:centerCalendar
        }


        Loader{
            id:centerLoader;

            anchors.top: parent.top;
            anchors.bottom: parent.bottom
            anchors.left:textReact.right;
            anchors.right:button_1.left;
            anchors.topMargin:root.labelMargins;
            anchors.bottomMargin:root.labelMargins;
            anchors.rightMargin: root.paddingRight;
            //z:1
            property color labelFontColor_L : root.labelFontColor;
            property color labelРighlightingFontColor_L: root.labelРighlightingFontColor;
            property color labelBackgroundRectangleColor_L:root.backgroundColor;
            property color activMainButtonColor_L: root.activMainButtonColor;
            property color activBackgroundButtonColor_L: root.activBackgroundButtonColor;
            property color pressedMainButtonColor_L: root.pressedMainButtonColor;
            property color pressedBackgroundButtonColor_L: root.pressedBackgroundButtonColor;
            property color hoveredButtonColor_L: Settings.oneRowItemSettings.hoveredButtonColor;


            property var valueArr_L : root.valueArr;
            property string commonFontFamily_L: root.commonFontFamily;
            property int labelFontSize_L: root.labelFontSize;
            property int labelBorderColorWidth_L: root.labelBorderColorWidth;
            property int labelLeftPadding_L: root.labelLeftPadding;
            property int labelMargins_L: root.labelMargins;
            property var value_L: root.value;
            property int textBlockWidth_L:root.textBlockWidth;
            property int textType_L: root.textType;
            property int tottallAnimationTime_L: root.tottallAnimationTime;

            property int type_L: root.type;
           //property int text_L: root.type;

            Component.onCompleted: {
                //console.log("type_L="+centerLoader.type_L)
            }
        }

        SmallCrossChekerButton_S {
            id:button_1
            anchors.topMargin: (root.height - root.buttonSize)/2
            anchors.bottomMargin: (root.height - root.buttonSize)/2
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: button_2.left
            anchors.rightMargin: root.paddingRight
            type: Settings.BlueButtonType.MINUS
            z:0
        }

        SmallCrossChekerButton_S {
            id:button_2
            anchors.topMargin: (root.height - root.buttonSize)/2
            anchors.bottomMargin: (root.height - root.buttonSize)/2
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: root.paddingRight
            type: Settings.BlueButtonType.PLUS
            z:0
        }


        //Bottom Border Radius
        BorderRadiusWidget {
            id:bottomLeftRadius
            visible:false
            anchors.left:parentReact.left
            anchors.bottomMargin:root.borderRadius
            anchors.leftMargin: root.borderRadius
            anchors.bottom: parentReact.bottom
            radius: root.borderRadius
            activeButtonColor:  root.backgroundColor
            transform: Rotation {
                origin.x: 0;
                origin.y:0;
                angle: 270
            }
            z:2
        }

        Rectangle{
            id:bottomLeftRadiusReact
            visible:false
            width:root.borderRadius
            height:root.borderRadius
            anchors.left:parentReact.left
            anchors.bottom:parentReact.bottom
            z:1
            color: root.backgroundFontColor
        }

        BorderRadiusWidget {
            id:bottomRightRadius
            visible:false
            anchors.right:parentReact.right
            anchors.bottomMargin:root.borderRadius
            anchors.rightMargin: root.borderRadius
            anchors.bottom: parentReact.bottom
            radius: root.borderRadius
            activeButtonColor: root.backgroundColor
            transform: Rotation {
                origin.x: parentReact.x;
                origin.y:parentReact.y;
                angle: 180
            }
            z:2
        }


        Rectangle{
            id:bottomRightRadiusReact
            visible:false
            width:root.borderRadius
            height:root.borderRadius
            anchors.right:parentReact.right
            anchors.bottom:parentReact.bottom
            z:1
            color: root.backgroundFontColor
        }
    }

    function stopFocusTextArea (){
        //textArea.
        //textArea.deselect()
    }

    Component.onCompleted:{
        root.onCompletedChangeButtom();
        root.onCompletedHasBorderRadius();
        //console.log("root.type="+root.type)

    }

    function onCompletedChangeButtom (){
        //console.log("on onCompletedChangeButtom")
        centerLoader.sourceComponent = centerLabel;

        switch (root.type)   {
        case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_TEXT_RIGHT_ALIGNEMENT :
            button_1.visible = false;
            centerLoader.anchors.right = button_2.left;
            button_2.type= Settings.BlueButtonType.CHECK
            centerLoader.anchors.rightMargin = root.paddingRight - 8
            centerLoader.source=""
            break;

        case Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_LEFT_ALIGNEMENT :
            button_1.visible = false;
            //button_2.visible = true;
            break;

        case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT :
            //console.log("ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT")
            button_1.visible = false;
            button_2.visible = false;
            centerLoader.anchors.right = parentReact.right
            centerLoader.sourceComponent = centerComboBox;
            break;

        case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_RIGHT_COMBOBOX_ALIGNEMENT :
            button_1.visible = false;
            button_2.visible = false;
            centerLoader.anchors.right = parentReact.right
            centerLoader.sourceComponent = centerComboBox;
            break;

        case Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_LABEL_ONLY :
            button_1.visible = false;
            button_2.visible = false;
            centerLoader.anchors.right = parentReact.right
            break;

        case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_LABEL_ONLY_LEFT_LABEL_ALIGNEMENT :
            button_1.visible = false;
            button_2.visible = false;
            //centerLoader.anchors.right = parentReact.right
            break;

        case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_DATE_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT :
            button_1.visible = false;
            button_2.visible = false;
            centerLoader.anchors.right = parentReact.right
            centerLoader.sourceComponent = centerCalendar;
            break;

            //        case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_CUSTOM_WiDGET_LEFT_COMBOBOX_ALIGNEMENT :
            //            console.log("on ONE_TEXT_LEFT_TEXT_AND_CUSTOM_WiDGET_LEFT_COMBOBOX_ALIGNEMENT")
            //            button_1.visible = false;
            //            button_2.visible = false;
            //            centerLoader.visible = false;
            //            //centerCustomWidget.parent = root;
            //            //centerCustomWidget.anchors.left = textReact.right
            //            // centerCustomWidget.anchors.top = parent.top

            //            break;


        case Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY :
            button_1.visible = false;
            button_2.visible = false;
            centerLoader.anchors.right = parentReact.right
            centerLoader.anchors.rightMargin = root.paddingRight - 8
            //centerLoader.source=""
            //textAreaRect.anchors.right = parentReact.right;
            break;
        }
    }



    function onCompletedHasBorderRadius (){
        switch (root.hasBorder)   {
        case Settings.HasBorder.UPPER_BORDER :
            //button_1.visible = false;
            break;

        case Settings.HasBorder.BOTTOM_BORDER :
            bottomLeftRadius.visible = true;
            bottomLeftRadiusReact.visible = true;
            bottomRightRadius.visible = true;
            bottomRightRadiusReact.visible = true;
            break;

        case Settings.HasBorder.UPPER_BOTTOM_BORDER :
            //console.log("ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT")
            //   button_1.visible = false;
            //  button_2.visible = false;
            //textAreaRect.anchors.right = parentReact.right
            break;
        }
    }
}





