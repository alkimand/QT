#include "clientbase.h"
#include "Server.h"
#include "workerbaseclass.h"
#include <QDebug>

//ClientBase::ClientBase( Server  *m_server,  CLIENT_TYPE const & m_type)
ClientBase::ClientBase()
{
    tittle = "DEFAULT";
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

void ClientBase::sendTittle(const QString & m_tittle)
{
    tittle = m_tittle;
    //qDebug()<< " ClientBase::sendTittle:"+ tittle ;
}

void ClientBase::setDocumentTittle(const QString m_tittle)
{
    tittle =  m_tittle;
}

QString ClientBase::readDocumentTittle()
{
    return tittle;
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

void ClientBase::setNameDocumentSlot(const QString & tittle)
{
    qDebug()<< "ClientBase::setNameDocumentSlot" + tittle;
    this->worker->setNameDocument(tittle);
}


void ClientBase::setStatus(const int & status)
{
 qDebug()<< "ClientBase::setStatus";
 if (type == UDP_CLIENT_TYPE)
 this->worker->setStatus(status);
}
