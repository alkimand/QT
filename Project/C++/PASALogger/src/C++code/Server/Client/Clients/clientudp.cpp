#include "clientudp.h"
#include <QDebug>
#include "workerbaseclass.h"
#include "workerudp.h"
#include "modelserviseudp.h"
#include <QQmlEngine>
#include <QQuickView>

//ClientUDP::ClientUDP(Server  *m_server, CLIENT_TYPE const &m_type) : ClientBase(m_server,m_type)
ClientUDP::ClientUDP() : ClientBase()
{
    qDebug()<< "create ClientUDP";
    this->child = this;
    this->type = UDP_CLIENT_TYPE;

    qmlRegisterType <ModelServiseUDP> ("ModuleName", 1, 0, "ModelServiseUDP");

    switch (type)
    {
    case UDP_CLIENT_TYPE:
        this-> worker = new WorkerUDP(this, type);
        this-> model = new ModelServiseUDP();//this, type);
      //  this-> someProperty = model;
         //someProperty=100;

//       QQuickView view;

//       view.engine()->rootContext()->setContextProperty("someProperty", someProperty);
//       view.setSource(QUrl::fromLocalFile("MyItem.qml"));
//       view.show();

        break;
    default:
        break;
    }

}

//void ClientUDP::setSomeProperty(ModelServiseUDP * property)
//{

//}

//ModelServiseUDP *ClientUDP::getSomeProperty() const
//{
//    return someProperty;
//}

//void ClientUDP::setSomeProperty(const ModelServiseUDP &)
//{

//}

//int ClientUDP::getSomeProperty() const
//{

//}

//void ClientUDP::setSomeProperty(const int &)
//{

//}

//ModelServiseUDP *ClientUDP::getSomeProperty() const
//{

//}

//void ClientUDP::setSomeProperty(const ModelServiseUDP &)
//{

//}



