#include "clientbase.h"
#include "Server.h"
#include "workerbaseclass.h"
#include <QDebug>

//ClientBase::ClientBase( Server  *m_server,  CLIENT_TYPE const & m_type)
ClientBase::ClientBase()
{

}

ClientBase::~ClientBase()
{
    //this->wait();
     qDebug()<< "~ClientBase()";
}

void ClientBase::run()
{
    //exec();
}

void ClientBase::saveAsSlot()
{
    this->worker->saveAs();
}


void ClientBase::clearDataPool()
{

    this->worker->clearDataPool();
}


void ClientBase::setStatus(const int & status)
{
 qDebug()<< "ClientBase::setStatus";
 if (type == UDP_CLIENT_TYPE)
 this->worker->setStatus(status);
}
