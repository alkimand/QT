import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "../../SmallCrossChekerButton/MoneyCheker"
import "../RowLogic.js" as Logic
import Settings 1.0

Component{
    //  id:root
    // property int labelMargins
    Item{
        id:root
        //Component.onCompleted: {console.log("value="+value);}

        property color labelFontColor:labelFontColor_L
        property color labelРighlightingFontColor:labelРighlightingFontColor_L
        property color labelBackgroundRectangleColor:labelBackgroundRectangleColor_L
        property int labelFontSize:labelFontSize_L
        property int labelBorderColorWidth:labelBorderColorWidth_L
        property int labelLeftPadding:labelLeftPadding_L
        property int labelMargins :labelMargins_L

        property var value : value_L
        property int textType : textType_L
        property int type : type_L
        property int textBlockWidth:textBlockWidth_L
        property string commonFontFamily:commonFontFamily_L

        signal openView()

        anchors.fill:parent

        Rectangle {
            id:textAreaRect
            anchors.fill:parent

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
                activeFocusOnPress :false

                //                validator: RegExpValidator {
                //                    regExp:  /^((?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.){0,3}(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$/
                //                }

                background: Rectangle {
                    implicitWidth:  root.textBlockWidth
                    implicitHeight: textAreaRect.height
                    border.color: (textArea.activeFocus)?root.labelРighlightingFontColor:"transparent"
                    color: root.labelBackgroundRectangleColor
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
                        textArea.value = 0;
                    }
                    textArea.text= "";
                    textArea.placeholderText = Logic.valueToUserText(textArea.value, root.textType);
                    labelMouseArea.cursorShape = Qt.ArrowCursor;
                    //console.log("textArea.text="+ textArea.text)
                }

                Keys.onReturnPressed: { _onEnterPressed(event) }
                Keys.onEnterPressed: { _onEnterPressed(event) }
                Component.onCompleted: {
                    var UserValue
                    //console.log("root.type" + root.value + " " + root.type)
                    UserValue = Logic.valueToUserText(textArea.value, root.textType);
                    textArea.placeholderText = UserValue;
                    //console.log("placeholderText="+ textArea.placeholderText)

                    switch (root.type)   {
                    case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_TEXT_RIGHT_ALIGNEMENT :
                   case Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY :
                       textArea.horizontalAlignment =Text.AlignRight
                       textArea.selectByMouse=false;
                       textArea.selectByKeyboard=false;
                       labelMouseArea.enabled = false;
                       break;
                    }

                }



                function _onEnterPressed(event)
                {
                    if (!(event.modifiers & Qt.ControlModifier))
                    {
                        //event.accepted = false;
                        if (textArea.text!=="") {
                            textArea.value = parseFloat(textArea.text.replace(/[^0-9\.]+/g, ''));
                        }
                        else{
                            textArea.value=0;
                        }
                        // console.log("textArea.value+"+ textArea.value);

                        textArea.text = textArea.value.toString(10);//textArea.value //hack
                        textArea.placeholderText= textArea.value.toString(10) + " рубл";
                        textFirstLine_.forceActiveFocus();
                    }
                }

                MouseArea {
                    id:labelMouseArea
                    anchors.fill: parent
                    cursorShape : Qt.ArrowCursor
                    acceptedButtons: Qt.LeftButton
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
                                //console.log("textArea.value="+textArea.value)
                                textArea.text =textArea.value.toString(10);
                            }
                            else {
                                textArea.value=0;
                            }
                            textArea.selectAll();
                            //console.log(textArea.activeFocus );

                        }
                        textArea.forceActiveFocus();
                        textArea.focus = true;
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
                            //console.log(textArea.activeFocus);
                            textArea.forceActiveFocus();
                        }
                    }
                }
            }
        }
    }
}
