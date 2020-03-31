import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import"../../Setting"
//import"../../Setting"
import "../SmallCrossChekerButton/MoneyCheker"




Item {
    id:root

    //common
    property string commonFontFamily
    property color backgroundColor
    property int rowItemWidth //weight
    property int rowItemHeight
    property int rowMargin  //to up if will need
    property int paddingLeft
    property int paddingRight
    property int textRowSpacing
    property int type
    property int textType
    property int textSecondLineType

    //textLine
    property int textBlockWidth
    property color textFirstLineFontColor
    property color textSecondLineFontColor
    property int textFirstLineFontSize
    property int textSecondLineFontSize
    property int textFirstLineTopMargin
    property string textFirstLine
    property string textSecondLine

    //Label
    property color labelFontColor
    property color labelРighlightingFontColor
    property int labelFontSize
    property int labelBorderColorWidth
    property int labelLeftPadding
    property int labelMargins
    property var value

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

    width: rowItemWidth
    height:rowItemHeight

    // property bool isActive: false


    //to transfer up
    signal pushPlusButton()
    signal pushMinusButton()

    signal pushChekerOpenButton()
    signal pushChekerCloseButton()

    //use in this  class
    //signal activate()
    //signal disable()

    Rectangle {
        id:parentReact
        anchors.fill: parent
        color:root.backgroundColor

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
                    text: root.textSecondLine
                    font.family : root.commonFontFamily
                    font.pointSize:  root.textSecondLineFontSize
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    font.bold :true
                    elide : Text.ElideRight //wrapped text
                    color: root.textFirstLineFontColor
                    renderType: Text.NativeRendering // Rendering type (optional)
                    Layout.columnSpan: 1
                    Layout.rowSpan: 1
                    Layout.row: 2
                    Layout.column: 1
                    Component.onCompleted: {
                        if (textSecondLine_.text===""){
                            textSecondLine_.visible = false;
                            textReact.anchors.topMargin = root.textFirstLineTopMargin;
                        }
                    }

                }

            }
        }

        Rectangle{
            id:textAreaRect
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left:textReact.right
            anchors.right:button_1.left
            anchors.topMargin:root.labelMargins
            anchors.bottomMargin:root.labelMargins
            anchors.rightMargin:root.paddingRight

            //width: 150//root.textBlockWidth

            TextArea {
                id: textArea
                //horizontalAlignment : Text.AlignLeft //works
                verticalAlignment :Text.AlignVCenter
                property var value: root.value//+-
                //property bool isActive : textArea.activeFocus
                anchors.fill:parent
                width: textAreaRect.width
                //text: !(isActive)?"2900":""
                font.family : root.commonFontFamily
                font.pointSize : root.labelFontSize
                color: root.labelРighlightingFontColor
                selectedTextColor : root.labelFontColor
                inputMethodHints: Qt.ImhDate//ImhNoPredictiveText
                //inputMethodHints: Qt.ImhNoPredictiveText
                anchors.horizontalCenter: parent.horizontalCenter
                // anchors.verticalCenter: parent.verticalCenter
                placeholderTextColor : root.labelРighlightingFontColor
                placeholderText : ""//"2900 010 руб"
                selectByMouse : true
                //overwriteMode :true
                selectByKeyboard :true
                wrapMode : TextEdit.WordWrap
                leftPadding:root.labelLeftPadding
                textMargin:0

                //                validator: RegExpValidator {
                //                    regExp:  /^((?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.){0,3}(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$/
                //                }

                background: Rectangle {
                    implicitWidth:  root.textBlockWidth
                    implicitHeight: textAreaRect.height
                    border.color: (textArea.activeFocus)?root.labelРighlightingFontColor:"transparent"
                    border.width: root.labelBorderColorWidth

                }

                onEditingFinished: {
                    //console.log("onEditingFinished")
                    //console.log("textArea.text="+ textArea.text)
                    if (textArea.text!==""){
                        textArea.value = parseFloat(textArea.text.replace(/[^0-9\.]+/g, ''));
                    }
                    else{
                        //textArea.placeholderText="nan%"
                        textArea.value=0
                    }
                    textArea.text= ""
                    textArea.placeholderText = textArea.valueToUserText(textArea.value)
                    labelMouseArea.cursorShape=Qt.ArrowCursor
                    //console.log("textArea.text="+ textArea.text)
                }

                Keys.onReturnPressed: { _onEnterPressed(event) }
                Keys.onEnterPressed: { _onEnterPressed(event) }
                Component.onCompleted: {
                    textArea.placeholderText = textArea.valueToUserText(textArea.value)
                }

                function valueToUserText(value){
                    var userText = "";
                    //console.log("valueToUserText=" + value)
                    switch (root.textType)   {
                    case SettingData.DataType.PERSENT_DATA_TYPE :
                        //dash_horizontal.visible = true;
                        //dash_vertical.visible = true;
                        break

                    case SettingData.DataType.CURRENCY_DATA_TYPE :
                        userText = (value + " руб.").toString(10)
                        //console.log("userText=" + userText)
                        break;

                    case SettingData.DataType.DATE_DATA_TYPE :
                       // dash_cross_left.visible = true;
                       // dash_cross_right.visible = true;
                        break;

                    }
                    return userText

                }

                function _onEnterPressed(event)
                {
                    if (!(event.modifiers & Qt.ControlModifier))
                    {
                        //event.accepted = false;
                        if (textArea.text!==""){
                            textArea.value = parseFloat(textArea.text.replace(/[^0-9\.]+/g, ''));
                        }
                        else{
                            textArea.value=0;
                        }
                        textArea.text = textArea.value.toString(10);//textArea.value //hack
                        textArea.placeholderText= textArea.value.toString(10) + " рубл";
                        textFirstLine_.forceActiveFocus();
                    }
                }

                MouseArea {
                    id:labelMouseArea
                    anchors.fill: parent
                    cursorShape : Qt.ArrowCursor
                    //onPressed: {
                    onClicked:{
                        //console.log("onClicked textArea.textArea.value="+textArea.value)
                        //console.log("onClicked")
                        if (textArea.activeFocus){
                            //console.log("onClicked textArea.activeFocus + value=" + textArea.value)
                            if (textArea.value!==parseFloat(textArea.text.replace(/[^0-9\.]+/g, ''))){
                                textArea.text = textArea.value.toString(10);
                                textArea.selectAll();
                            }
                            else{
                                //textArea.text =textArea.value.toString(10);
                                var position = textArea.positionAt(mouse.x, mouse.y);
                                //textArea.moveCursorSelection(textArea.positionAt(mouse.x, mouse.y),TextEdit.SelectCharacters)
                                textArea.select(position,position);
                                textArea.deselect();
                            }
                        }
                        else {
                            //console.log("onClicked not activeFocus textArea.isActive===false")
                            labelMouseArea.cursorShape=Qt.IBeamCursor;
                            //console.log("onClicked textArea.textArea.value="+textArea.value)
                            if (textArea.value!==0){
                                textArea.text =textArea.value.toString(10);
                            }
                            else {
                                textArea.value=0;
                            }
                            textArea.selectAll();
                            //console.log(textArea.activeFocus );
                            textArea.forceActiveFocus();
                        }
                    }
                    onReleased:{
                        // console.log("onReleased")
                        // root.stopFocusTextArea ()
                    }

                    onDoubleClicked: {
                        if (textArea.activeFocus){
                            labelMouseArea.cursorShape=Qt.IBeamCursor;
                            if (textArea.value!==0){
                                textArea.text =textArea.value.toString(10);
                            }
                            else{
                                textArea.value = 0;
                            }
                            textArea.selectAll();
                            console.log(textArea.activeFocu);
                            textArea.forceActiveFocus();
                        }
                    }
                }
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
            type: SettingData.BlueButtonType.MINUS
        }

        SmallCrossChekerButton_S {
            id:button_2
            anchors.topMargin: (root.height - root.buttonSize)/2
            anchors.bottomMargin: (root.height - root.buttonSize)/2
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: root.paddingRight
            type: SettingData.BlueButtonType.PLUS
        }
    }

    function stopFocusTextArea (){
        //textArea.
        //textArea.deselect()
    }
}





