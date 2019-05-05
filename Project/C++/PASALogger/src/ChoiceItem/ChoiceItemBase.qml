import QtQuick 2.12
import QtQuick.Controls 2.12

//https://evileg.com/ru/post/179/
//https://habr.com/ru/post/184416/
Item
{
    id:control
    property string type: "NONE"
    Rectangle
    {
        id:rectangle
        anchors.fill: parent

        Text
        {
            id: textHeader
            anchors.top: parent.top
            anchors.left:parent.left
            anchors.right:parent.right
            anchors.topMargin: 10
            font.bold : true
            text: "Choice type of new document"
            verticalAlignment: Text.AlignVCenter
            font.pointSize : 15
            horizontalAlignment: Text.AlignHCenter

        }

        ListView
        {
            id: listView
            // Размещаем его в оставшейся части окна приложения
            anchors.top: textHeader.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right


            /* в данном свойстве задаём вёрстку одного объекта
                 * который будем отображать в списке в качестве одного элемента списка
                 * */
            delegate: Item
            {
                id: item
                anchors.left: parent.left
                anchors.right: parent.right
                height: 40

                // В данном элементе будет находиться одна кнопка
                Button
                {
                    id:button
                    anchors.fill: parent
                    anchors.margins: 5
                    // property color buttonBackColor:
                    /* самое интересное в данном объекте
                         * задаём свойству text переменную, по имени которой будем задавать
                         * свойства элемента
                         * */
                    text: idshnik

                    // По клику по кнопке отдаём в текстовое поле индекс элемента в ListView

                    //color: menuBarItem.highlighted ? "#77a9ef" : "transparent"

                    contentItem: Text
                    {
                        id: buttonText
                        text: button.text
                        //font: button.font
                        font {pointSize:12 ; bold:false}
                        opacity: enabled ? 1.0 : 0.3
                        color: "black"//control.down ? "#17a81a" : "#21be2b"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle
                    {
                        id : buttonBackground
                        anchors.fill: parent
                        // implicitWidth: 100
                        //implicitHeight: 40
                        color: "white"
                        opacity: enabled ? 1 : 0.3
                        border.color: settingData.children[3].toolBarButtonIsSelectedColorSetting //control.down ? "black" //: settingData.children[7].contextMenuBaseTextNoHighlightedColorSetting
                        border.width: 2
                        radius: 2
                    }

                    MouseArea
                    {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        propagateComposedEvents: true
                        preventStealing: true
                        onEntered:
                        {
                            buttonBackground.color = settingData.children[3].toolBarButtonIsSelectedColorSetting
                            buttonText.color = settingData.children[7].contextMenuBaseTextHighlightedColorSetting
                            buttonBackground.border.color = "black"


                        }
                        onExited:
                        {
                            buttonBackground.color = settingData.children[3].toolBarButtonIsNotSelectedColorSetting
                            buttonText.color = settingData.children[7].contextMenuBaseTextNoHighlightedColorSetting
                            buttonBackground.border.color = settingData.children[3].toolBarButtonIsSelectedColorSetting

                        }

                        onClicked:
                        {
                            control.parent.setTable(button.text)
                            //console.log("control.parent.setTable(1)")
                        }
                    }

                }
            }

            model: ListModel
            {
                id: listModel //
            }
        }
    }
    function setButtonModel(text)
    {
        listModel.append({idshnik: text})
    }
}
