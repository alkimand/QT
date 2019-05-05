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
    
    ClientText
    {
        id: client
    }
    
    defaultTitles : ["Row", "Check" ,"Date/Time", "TimeStamp", "Count","Zone Id", "Service Name", "Function Name", "Line Number", "Message"]
    titles : ["Row", "Check" ,"Date/Time", "TimeStamp", "Count","Zone Id", "Service Name", "Function Name", "Line Number", "Message"]
    roleList : ["row", "check" ,"date", "time", "count","zone", "serviceName", "functionName", "lineNumber", "message"]
    widthList : [ 50, 50, 100, 100, 100, 100, 200, 200, 100, 400 ]
    skipColumn : [ "Row", "Check" ]
    
    Component.onCompleted:
    {
        tabView.getTab(tabView.currentIndex).title = client.documentTittle
    }
}
