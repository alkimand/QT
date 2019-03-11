#include "clientudp.h"
#include <QDebug>
#include "workerbaseclass.h"
#include "workerudp.h"
#include "modelserviseudp.h"
#include <QQmlEngine>

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
        this-> someProperty = new ModelServiseUDP();
         //someProperty=100;
        break;
    default:
        break;
    }

}

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



