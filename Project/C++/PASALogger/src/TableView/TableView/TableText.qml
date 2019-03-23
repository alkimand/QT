import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
//import QtQuick.Controls 2.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4

import ClientText 1.0


TableUDPBaseTable
{
    type: "TXT_CLIENT_TYPE"
    id: control
    // Item
    //{
    ClientText
    {
        id: client
    }
    // }
    Component.onCompleted:
    {
        tabView.getTab(tabView.currentIndex).title = client.documentTittle
    }
}
