import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    width: 640
    height: 480

    // Указываем кнопкам имя для доступа к ним
    property alias button1: button1
    property alias button2: button2

    // Слой с кнопками
    RowLayout {
        anchors.centerIn: parent

        // Первая кнопка
        Button {
            id: button1
        }

        // вторая кнопка
        Button {
            id: button2
        }
    }
}
