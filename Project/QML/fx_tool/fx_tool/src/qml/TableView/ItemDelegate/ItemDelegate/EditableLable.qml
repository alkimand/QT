import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

//import "../../SmallCrossChekerButton/MoneyCheker"
//import "../RowLogic.js" as Logic
//import Settings 1.0

ItemDelegate {
    //  id:root
    // property int labelMargins
    property alias placeholderText: textArea.placeholderText

    Item{
        id:root
        //Component.onCompleted: {console.log("value="+value);}

        property color labelFontColor: "white"
        property color labelРighlightingFontColor:  "#4385ef"
        property color labelBackgroundRectangleColor:"white"
        property int labelFontSize: 12
        property int labelBorderColorWidth:1
        property int labelLeftPadding: 5
        //property int labelMargins :8

        property var value : model.type
        //property int textType : textType_L
        //property int type : type_L
        property int textBlockWidth: 100
        property int textBlockHeight: 30

        property string commonFontFamily: "Arrial"

        //property string value


        // signal openView()

        signal startEdit()
        signal finishEdit()

        Connections {
            target: root
            onFinishEdit: {
                textArea.finishEditHandler()
            }
            onStartEdit: {
                textArea.startEditHandler()
            }
        }



        implicitHeight: root.textBlockHeight
        implicitWidth: root.textBlockWidth

        Rectangle {
            id:textAreaRect
            anchors.fill:parent

            TextArea {
                id: textArea
                //horizontalAlignment : Text.AlignLeft //works
                verticalAlignment :Text.AlignVCenter
                //property var value: model.type//+-
                //property bool isActive : textArea.activeFocus
                anchors.fill:parent
                width: textAreaRect.width
                font.family : root.commonFontFamily
                font.pointSize : root.labelFontSize
                color: root.labelРighlightingFontColor
                selectedTextColor : root.labelFontColor
                inputMethodHints: Qt.ImhDate//ImhNoPredictiveText
                //inputMethodHints: Qt.ImhNoPredictiveText
                anchors.horizontalCenter: parent.horizontalCenter
                // anchors.verticalCenter: parent.verticalCenter
                placeholderTextColor : root.labelРighlightingFontColor
              //  placeholderText : display
                    //name
                //text:index
                //type3
                    //name.type2
                    //model.name.type2
                    //name.feature//index
                   // name //model.type
                selectByMouse : true
                //overwriteMode :true
                selectByKeyboard :true
                wrapMode : TextEdit.WordWrap
                //leftPadding:root.labelLeftPadding
                textMargin: 0
                activeFocusOnPress :false

                background: Rectangle {
                    id:background_
                    implicitWidth:  root.textBlockWidth
                    implicitHeight: textAreaRect.height
                    //border.color: (textArea.activeFocus)?root.labelРighlightingFontColor:"transparent"
                    border.color: root.labelРighlightingFontColor
                    color: root.labelBackgroundRectangleColor
                    border.width: root.labelBorderColorWidth
                }


                onEditingFinished: {
                   // console.log("onEditingFinished")
                    //console.log("textArea.text="+ textArea.text)
                    labelMouseArea.cursorShape = Qt.ArrowCursor;
                    root.finishEdit()
                }

                Keys.onReturnPressed: { _onEnterPressed(event) }
                Keys.onEnterPressed: { _onEnterPressed(event) }
                Component.onCompleted: {
                    // var UserValue = model.type;
                    //textArea.value
                    //console.log("root.type" + root.value + " " + root.type)
                    //UserValue = Logic.valueToUserText(textArea.value, root.textType);
                    //if (UserValue)
                    //   textArea.placeholderText = UserValue;
                    //console.log("placeholderText="+ textArea.placeholderText)

                    //                    switch (root.type)   {
                    //                    case Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_ONE_BUTTON_RIGHT_TEXT_RIGHT_ALIGNEMENT :
                    //                   case Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY :
                    //                       textArea.horizontalAlignment =Text.AlignRight
                    //                       textArea.selectByMouse=false;
                    //                       textArea.selectByKeyboard=false;
                    //                       labelMouseArea.enabled = false;
                    //                       break;
                    //                    }

                }

                function _onEnterPressed(event)
                {
                    if (!(event.modifiers & Qt.ControlModifier))
                    {
                        console.log("_onEnterPressed=" + display_)
                        data = textArea.text;
                        textArea.placeholderText = display_;
                        //textArea.text=""; //bug ?
                        textArea.focus = false;
                        //root.finishEdit()//bug ?
                    }
                }


                function finishEditHandler(){
                    console.log("finishEditHandler =" + display);
                    //name = textArea.text;

                    edite = textArea.text;
                    //if (textArea.placeholderText)
                        textArea.placeholderText = display_;
                    textArea.text="";
                    textArea.focus = false;
                }


                function startEditHandler(){
                    // console.log("startEditHandler");
                    labelMouseArea.cursorShape = Qt.IBeamCursor;
                    textArea.forceActiveFocus();
                    textArea.focus = true;
                    textArea.placeholderText = "";
                }

                MouseArea {
                    id:labelMouseArea
                    anchors.fill: parent
                    cursorShape : Qt.ArrowCursor
                    acceptedButtons: Qt.LeftButton
                    onClicked: {
                        //console.log("onClicked model.type="+ model.type)
                        root.startEdit()
                        if (textArea.text=== display){
                            var position = textArea.positionAt(mouse.x, mouse.y);
                            textArea.select(position,position);
                            textArea.deselect();
                        }
                        else {
                            textArea.text = display_;
                            textArea.selectAll();
                        }
                    }
                    onReleased: {
                        // console.log("onReleased")
                        // root.stopFocusTextArea ()
                    }

                    onDoubleClicked: {
                        if (textArea.activeFocus){
                            labelMouseArea.cursorShape=Qt.IBeamCursor;
                            textArea.text = display_;
                            textArea.selectAll();
                            //console.log(textArea.activeFocus);
                            textArea.forceActiveFocus();
                        }
                    }
                    onFocusChanged: {
                        console.log("onFocusChanged")
                    }
                    onExited:{
                        //  background_.color ="white"
                        //25console.log("onExited = "+model.type)
                    }

                    onEntered: {
                        // console.log("onEntered")
                        // background_.color ="red"
                    }
                }
            }
        }
    }
}
