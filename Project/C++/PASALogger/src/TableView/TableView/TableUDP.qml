import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
//import QtQuick.Controls 2.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
//https://stackoverrun.com/ru/q/10546523
//https://coredump.su/questions/27332298/qml-tableview-qabstracttablemodel-how-edit-model-data-from-qml
//https://habr.com/ru/post/302428/ //-main post
//https://evileg.com/en/post/183/ - доступ к TabView
import ClientUDP 1.0


TableUDPBaseTable
{
    type: "UDP_CLIENT_TYPE"
    id: control
    ClientUDP
    {
        id: client

    }
    onRowCountChanged:
    {
       // console.log("+")
    }


    function setStatus(status)
    {
        console.log("setStatus(status)")
        client.setStatus(status)

    }




//    Connections {
//        target: client

//    }

  }

