#include "clientudp.h"
#include <QDebug>
#include "workerbaseclass.h"
#include "workerudp.h"
#include "modelserviseudp.h"
#include <QQmlEngine>
#include <QQuickView>

ClientUDP::ClientUDP() : ClientBase()
{
    qDebug()<< "create ClientUDP";
    this->child = this;
    this->type = UDP_CLIENT_TYPE;

    //qmlRegisterType <ModelServiseUDP> ("ModuleName", 1, 0, "ModelServiseUDP");

    switch (type)
    {
    case UDP_CLIENT_TYPE:
        this-> worker = new WorkerUDP(this, type);
        // this-> model
        //worker->moveToThread(this);
        this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());


        break;
    default:
        break;
    }

}

void ClientUDP::run()
{
    //  exec();
}

void ClientUDP::setVin(const ModelServiseUDP *model)
{
    qDebug()<< "ClientUDP::setVin";
}

ClientUDP::~ClientUDP()
{
    qDebug()<< "~ClientUDP";
    delete worker;
    //delete model;
    //this->wait();


}

void ClientUDP::clearDataPool()
{
  qDebug()<< "ClientUDP::clearDataPool";
  this->worker->clearDataPool();
}

void ClientUDP::setStatus(const int & status)
{
 qDebug()<< "ClientUDP::setStatus";
 this->worker->setStatus(status);
}




