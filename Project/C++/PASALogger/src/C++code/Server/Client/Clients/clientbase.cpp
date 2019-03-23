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

void ClientBase::saveSlot()
{
    this->worker->save();
}

void ClientBase::clearDataPool()
{

    this->worker->clearDataPool();
}

void ClientBase::openInExplorerSlot()
{
    this->worker->openInExplorer();
}

void ClientBase::filterChangedSlot(const int & column, const QString & text)
{
     //qDebug()<< "ClientBase::filterChangedSlot";
     this->worker->filterChanged(column,text);
}


void ClientBase::setStatus(const int & status)
{
 qDebug()<< "ClientBase::setStatus";
 if (type == UDP_CLIENT_TYPE)
 this->worker->setStatus(status);
}
