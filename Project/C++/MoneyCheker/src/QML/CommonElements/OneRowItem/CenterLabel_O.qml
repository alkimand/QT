import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//import"../../Setting"
import "../SmallCrossChekerButton/MoneyCheker"
import "RowLogic.js" as Logic

Component{
  //  id:root
       // property int labelMargins
    Item{
        id:root
//Component.onCompleted: {console.log("value="+value);}

        property color labelFontColor:labelFontColor_L
        property color labelРighlightingFontColor:labelРighlightingFontColor_L
        property int labelFontSize:labelFontSize_L
        property int labelBorderColorWidth:labelBorderColorWidth_L
        property int labelLeftPadding:labelLeftPadding_L
        property int labelMargins :labelMargins_L

        property var value : value_L
        property int type : type_L
        property int textBlockWidth:textBlockWidth_L
        property string commonFontFamily:commonFontFamily_L

        anchors.fill:parent

        Rectangle {
            id:textAreaRect
            anchors.fill:parent
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
                        textArea.value = 0;
                    }
                    textArea.text= "";
                    textArea.placeholderText = Logic.valueToUserText(textArea.value, root.type);
                    labelMouseArea.cursorShape = Qt.ArrowCursor;
                    //console.log("textArea.text="+ textArea.text)
                }

                Keys.onReturnPressed: { _onEnterPressed(event) }
                Keys.onEnterPressed: { _onEnterPressed(event) }
                Component.onCompleted: {
                    var UserValue
                    //console.log("root.type" + root.value + " " + root.type)
                    UserValue = Logic.valueToUserText(textArea.value, root.type);
                    //console.log("UserValue=" + UserValue)
//                    switch (root.type)   {
//                    case Logic.DataType.DATE_DATA_TYPE:

//                        //UserValue = Qt.formatDate(UserValue, "dd.MM.yyyy");
//                        //console.log("UserValue+formatDate=" + UserValue);
//                           //     (value).toString(10);//convert
//                        //userText = Qt.formatDate(userText, "dd.MM.yyyy");
//                        //UserValue = Logic.valueToUserText(textArea.value, root.type);
//                        break;
//                    }

                    textArea.placeholderText = UserValue;

                    //console.log("placeholderText="+ textArea.placeholderText)
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
                        console.log("textArea.value+"+ textArea.value);

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
                                //console.log("textArea.value="+textArea.value)
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
                            //console.log(textArea.activeFocus);
                            textArea.forceActiveFocus();
                        }
                    }
                }
            }
        }
    }
}
