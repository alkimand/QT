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


    Component
    {
        id: columnComponent
        C1.TableViewColumn{width: 100 }
    }

    titles: ["ROW", "CHECK" ,"DATE", "TIME", "COUNT"," ZONE", "SERVICENAME", "FUNCTIONNAME", "LINENUMBER", "MESSAGE"]
    roleList : ["row", "check" ,"date", "time", "count","zone", "serviceName", "functionName", "lineNumber", "message"]
    property var curTitles:
    {
        var t=[]
        for(var i=2;i<columnCount;i++)
        {
            t.push(getColumn(i).title)
        }
        return t
    }
    onTitlesChanged:
    {
        for(var i=0;i<titles.length;i++)
        {
            if(curTitles.indexOf(titles[i])==-1)
            {
                var column = addColumn(columnComponent)
                column.title=titles[i]
                column.role=roleList[i]
            }
        }
        for(var i=curTitles.length-1;i>=0;i--)
        {
            if(titles.indexOf(curTitles[i])==-1)
            {
                removeColumn(i)
            }
        }
    }

    Component.onCompleted:
    {
        tabView.getTab(tabView.currentIndex).title = client.documentTittle
    }
}
