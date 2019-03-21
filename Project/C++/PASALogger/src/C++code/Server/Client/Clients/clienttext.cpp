#include "clienttext.h"
#include <QDebug>
#include "workerbaseclass.h"

#include "workertext.h"
#include "modelserviseudp.h"
#include <QQmlEngine>
#include <QQuickView>

ClientText::ClientText() : ClientBase()
{
    qDebug()<< "create ClientText";
    this->child = this;
    this->type = TXT_CLIENT_TYPE;

    //qmlRegisterType <ModelServiseUDP> ("ModuleName", 1, 0, "ModelServiseUDP");

    //switch (type)
    //{
    //case UDP_CLIENT_TYPE:
    this-> worker = new WorkerText(this, type);
    //worker->moveToThread(this);
    this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());


    //        break;
    //    default:
    //        break;
    //}

}

void ClientText::run()
{
    // exec();
}

void ClientText::setVin(const ModelServiseUDP *model)
{
    qDebug()<< "ClientText::setVin";
}

ClientText::~ClientText()
{
    //  this->wait();
    qDebug()<< "~ClientText";
    delete worker;
}

void ClientText::clearDataPool()
{

    this->worker->clearDataPool();
}

void ClientText::saveAsSlot()
{
    this->worker->saveAsSlot();
}

//void ClientText::clearDataPool()
//{
//  qDebug()<< "ClientText::clearDataPool";
//  this->worker->clearDataPool();
//}




