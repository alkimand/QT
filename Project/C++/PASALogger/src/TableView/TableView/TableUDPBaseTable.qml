import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
//import QtQuick.Controls 2.4



BaseTableView
{
    id: control

     //model: client.model

        model: client.proximodel

        C1.TableViewColumn
        {
            id:dateColumn
            role: "date"
            title: "Date/Time"
            //onWidthChanged: ccDate.width = Math.max(60, ccPanel.width - ccSize.width - ccName.width)
            width: 100
        }
        C1.TableViewColumn
        {
            id:timeColumn
            role: "time"
            title: "TimeStamp"
            width: 100
        }

        C1.TableViewColumn
        {
            id:countColumn
            role: "count"
            title: "Count"
            width: 100
        }
        C1.TableViewColumn

        {
            id:zoneColumn
            role: "zone"
            title: "Zone Id"
             width:100
        }

        C1.TableViewColumn
        {
            id:serviceColumn
            role: "serviceName"
            title: "Service Name"
            width: 300
        }

        C1.TableViewColumn
        {
            id:functionColumn
            role: "functionName"
            title: "Function Name"
            width: 400
        }

        C1.TableViewColumn
        {
            id:lineColumn
            role: "lineNumber"
            title: "Line Number"
            width: 60
        }

        C1.TableViewColumn
        {
            id:messageColumn
            role: "message"
            title: "Message"
            width: control.width-dateColumn.width-timeColumn.width-countColumn.width-zoneColumn.width-serviceColumn.width-functionColumn.width-lineColumn.width - 20
        }

}

