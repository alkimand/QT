import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ItemDelegate {
    id:root
    property alias placeholderText: textArea.placeholderText
    //Component.onCompleted: {console.log("value="+value);}
    property color labelFontColor: "white"
    property color labelРighlightingFontColor:  "#4385ef"
    property color labelBackgroundRectangleColor:"white"
    property int labelFontSize: 12
    property int labelBorderColorWidth:1
    property int labelLeftPadding: 5
    //property int labelMargins :8
    property var value : model.type
    implicitWidth: 100
    implicitHeight:30
    property string commonFontFamily: "Arrial"
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
            selectByMouse : true
            //overwriteMode :true
            selectByKeyboard :true
            wrapMode : TextEdit.WordWrap
            //leftPadding:root.labelLeftPadding
            textMargin: 0
            activeFocusOnPress :false

            background: Rectangle {
                id:background_
                implicitWidth:  root.implicitWidth
                implicitHeight: textAreaRect.height
                //border.color: (textArea.activeFocus)?root.labelРighlightingFontColor:"transparent"
                border.color: root.labelРighlightingFontColor
                color: root.labelBackgroundRectangleColor
                border.width: root.labelBorderColorWidth
            }

            onEditingFinished: {
                // console.log("onEditingFinished")
                labelMouseArea.cursorShape = Qt.ArrowCursor;
                root.finishEdit()
            }

            Keys.onReturnPressed: { _onEnterPressed(event) }
            Keys.onEnterPressed: { _onEnterPressed(event) }
            Component.onCompleted: {

            }
            Keys.onPressed:  {
                //console.log("Keys.onPressed= "+textArea.text)
                //edite = textArea.text;
                //textArea.text = display_
            }

            function _onEnterPressed(event) {
                if (!(event.modifiers & Qt.ControlModifier)) {
                    //console.log("_onEnterPressed=" + display_)
                    edite = textArea.text;
                    textArea.placeholderText = display_;
                    //textArea.text=""; //bug ?
                    textArea.focus = false;
                    //root.finishEdit()//bug ?
                }
            }

            function finishEditHandler() {
                // console.log("finishEditHandler =" + display_);
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
                    //console.log("onClicked "+ display_)
                    root.startEdit()
                    if (textArea.text === display_){
                        textArea.text = display_;
                        //  edite =  textArea.text
                        // textArea.text = display_
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
                    // console.log("onFocusChanged")
                }
                onExited:{
                    //  background_.color ="white"
                    //("onExited = ")
                    //  console.log("onExited")
                }

                onEntered: {
                    // console.log("onEntered")
                    // background_.color ="red"
                }
                onCanceled: {
                    // console.log("onCanceled")
                }
            }
        }
    }
}
