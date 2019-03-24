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
    this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());
    this-> proximodel = static_cast<ProxiModelServiseUDP*> (this-> worker->getProxiModeltoQMLService());

}

void ClientText::run()
{
    // exec();
}

void ClientText::setVin(const ModelServiseUDP *model)
{
    qDebug()<< "ClientText::setVin";
}

void ClientText::setproximodel(const ProxiModelServiseUDP *proximodel)
{

}

//void ClientText::setDocumentTittle(const QString m_tittle)
//{

//    tittle =  m_tittle;
//}

ClientText::~ClientText()
{
    //  this->wait();
    qDebug()<< "~ClientText";
    delete worker;
}

