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

