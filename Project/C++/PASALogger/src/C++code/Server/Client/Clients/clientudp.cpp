
#include <QDebug>
#include "clientudp.h"
//#include "workerbaseclass.h"
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

        this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());

        //    case TXT_CLIENT_TYPE:
        //        this-> worker = new WorkerText(this, type);
        //        this-> model = static_cast<ModelServiseText*> (this-> worker->getModeltoQMLService());
        //        break;

        break;
    default:
        break;
    }

}




