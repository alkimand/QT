import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

// https://doc.qt.io/QT-5/qtquickcontrols2-customize.html#customizing-combobox
ComboBox {
    id:control

    //    Layout.columnSpan: 6
    //    Layout.rowSpan: 1
    //currentText: "Bahnschrift"

    delegate: ItemDelegate
    {
        width: control.width
        contentItem: Text
        {
            text: modelData
            color: mainToolBar.comboBoxTextColor
            font: control.isFont?modelData:"Arial Black" //control.font
            elide: Text.ElideRight
            //font.pointSize:12//comboBoxTextHeight
            //font.pointSize:10
            //elide: Text.ElideMiddle
            verticalAlignment: Text.AlignVCenter
            // horizontalAlignment: Text.AlignHCenter
        }
        highlighted: control.highlightedIndex === index
    }

    indicator: Canvas
    {
        id: canvas
        x: control.width - width - control.rightPadding
        y: control.topPadding + (control.availableHeight - height) / 2
        width: 12
        height: 8
        contextType: "2d"

        Connections
        {
            target: control
            onPressedChanged: canvas.requestPaint()
        }

        onPaint:
        {
            context.reset();
            context.moveTo(0, 0);
            context.lineTo(width, 0);
            context.lineTo(width / 2, height);
            context.closePath();
            context.fillStyle = control.pressed ? "black" : "#0f4ba8";
            context.fill();
        }
    }

    contentItem: Text
    {
        leftPadding: 10
        rightPadding: control.indicator.width + control.spacing

        text: control.displayText//mainToolBar.comboBoxStartTextFromSetting //control.displayText
        font: control.isFont?control.displayText:"Arial Black" //mainToolBar.comboBoxStartTextFromSetting //control.font
        //font.pointSize:12//comboBoxTextHeight
        color: control.pressed ? "#92aac9" : mainToolBar.comboBoxTextColor

        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        //horizontalAlignment: Text.AlignRight
    }

    background: Rectangle
    {
        implicitWidth: 120
        implicitHeight: 40
        border.color: control.pressed ? "#92aac9" : "#92aac9"
        border.width: control.visualFocus ? 2 : 1
        radius: 2
    }

    popup: Popup
    {
        y: control.height - 1
        width: control.width
        implicitHeight: contentItem.implicitHeight
        padding: 1

        contentItem: ListView
        {
            clip: true
            implicitHeight: contentHeight
            model: control.popup.visible ? control.delegateModel : null
            currentIndex: control.highlightedIndex

            //ScrollIndicator.vertical: ScrollIndicator {    }
            //            delegate:Text
            //            {
            //                text: control.displayText
            //            }
            ScrollBar.vertical: ScrollBar { width: 20}
        }

        background: Rectangle
        {
            border.color: "#92aac9"
            radius: 2
        }
    }
    onCurrentTextChanged:
    {
        console.log("settingData.children[1].fontfamilySetting is = " + control.currentText)
        settingData.children[1].fontfamilySetting = control.currentText
    }


}
