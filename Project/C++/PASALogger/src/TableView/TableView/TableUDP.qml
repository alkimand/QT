import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
//import QtQuick.Controls 2.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4

import ClientUDP 1.0


BaseTableView
{
    ClientUDP
    {
        id: client
        Component.onCompleted:
        {

        }
    }
    model: client.model

    C1.TableViewColumn
    {
        role: "date"
        title: "Date/Time"
        width: window.width/5
    }
    C1.TableViewColumn
    {
        role: "time"
        title: "TimeStamp"
        //  width: window.width/5
    }

    C1.TableViewColumn
    {
        role: "count"
        title: "Count"
        width: window.width/5
    }
    C1.TableViewColumn
    {
        role: "zone"
        title: "Zone Id"
        width: window.width/5
    }

    C1.TableViewColumn
    {
        role: "serviceName"
        title: "Service Name"
        width: window.width/5
    }

    C1.TableViewColumn
    {
        role: "functionName"
        title: "Function Name"
        width: window.width/5
    }

    C1.TableViewColumn
    {
        role: "lineNumber"
        title: "Line Number"
        width: window.width/5
    }

    C1.TableViewColumn
    {
        role: "message"
        title: "Message"
        width: window.width/5
    }
}

