#include "clientudp.h"
#include <QDebug>
#include "workerbaseclass.h"
#include "workerudp.h"


//ClientUDP::ClientUDP(Server  *m_server, CLIENT_TYPE const &m_type) : ClientBase(m_server,m_type)
ClientUDP::ClientUDP() : ClientBase()
{
    qDebug()<< "create ClientUDP";
    this->child = this;

    switch (type)
    {
    case UDP_CLIENT_TYPE:
        this-> worker = new WorkerUDP(this, type);
        break;
    default:
        break;
    }

}
