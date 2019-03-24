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

        this-> worker = new WorkerUDP(this, type);
        //worker->moveToThread(this);
        this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());
        this-> proximodel = static_cast<ProxiModelServiseUDP*> (this-> worker->getProxiModeltoQMLService());

}

void ClientUDP::setproximodel(const ProxiModelServiseUDP *proximodel)
{

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
