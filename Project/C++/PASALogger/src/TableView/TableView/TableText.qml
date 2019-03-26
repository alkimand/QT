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
        C1.TableViewColumn{}
    }


    defaultTitles : ["Row", "Check" ,"Date/Time", "TimeStamp", "Count","Zone Id", "Service Name", "Function Name", "Line Number", "Message"]
    titles : ["Row", "Check" ,"Date/Time", "TimeStamp", "Count","Zone Id", "Service Name", "Function Name", "Line Number", "Message"]
    roleList : ["row", "check" ,"date", "time", "count","zone", "serviceName", "functionName", "lineNumber", "message"]
    widthList : [ 50, 50, 100, 100, 200, 200, 200, 200, 200, 200 ]
    skipColumn : [ "Row", "Check" ]


    property var curTitles:
    {
        console.log("curTitles")
        var t=[]
        for(var i=0;i<columnCount;i++)
        {
            t.push(getColumn(i).title)
        }
        return t
    }


    onColmnChanged:
    {
        console.log("onNameChanged")
        var t=[]
        for(var i=0;i<columnCount;i++)
        {
            t.push(getColumn(i).title)
        }
        curTitles =t
    }

    onTitlesChanged:
    {
        colmnChanged()
        //console.log("onTitlesChanged:")
        for(var i=0;i<titles.length;i++)
        {
            if((curTitles.indexOf(titles[i])==-1) && (skipColumn.indexOf(titles[i])==-1))
            {
                var column = addColumn(columnComponent)
                column.title=titles[i]
                column.role=roleList[i]
                column.width = widthList[i]
                control.moveColumn(columnCount-1, titles.indexOf(titles[i]) - skipColumn.length)

            }
        }
        colmnChanged()
        for(var i=curTitles.length-1;i>=0;i--)
        {
            if(titles.indexOf(curTitles[i])==-1 )
            {
                //console.log("onTitlesChanged:remove:i:"+i +" "+curTitles[i])
                removeColumn(i)
            }
        }
    }

    Component.onCompleted:
    {
        tabView.getTab(tabView.currentIndex).title = client.documentTittle

    }
}
