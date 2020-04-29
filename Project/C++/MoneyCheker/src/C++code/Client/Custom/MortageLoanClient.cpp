#include "MortageLoanClient.h"
#include <QDebug>
//#include "workerbaseclass.h"

//#include "workertext.h"
//#include "modelserviseudp.h"
#include <QQmlEngine>
#include <QQuickView>

MortageLoanClient::MortageLoanClient(ItemEnums::EClientType client_type) : ClientBase(client_type)
{
    child_client_ = this;
    qDebug()<< "create MortageLoanClient";
    instanceWorker(client_type);

//    this->child = this;
//    this->type = TXT_CLIENT_TYPE;

//    //qmlRegisterType <ModelServiseUDP> ("ModuleName", 1, 0, "ModelServiseUDP");

//    this-> worker = new WorkerText(this, type);
//    //worker->moveToThread(this);
//    this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());
//    this-> proximodel = static_cast<ProxiModelServiseUDP*> (this-> worker->getProxiModeltoQMLService());

}

QAbstractTableModel *MortageLoanClient::getCalculatorModel() const
{
    qDebug()<< "MortageLoanClient:getCalculatorModel+";

    return parent_client_->getModel(int(ItemEnums::EModelType::Calculator));
}


void MortageLoanClient::setCalculatorModel(const QAbstractTableModel *model)
{
     qDebug()<< "setCalculatorModel+";
}



MortageLoanClient::~MortageLoanClient()
{
    //  this->wait();
   // qDebug()<< "~MortageLoanClient";
    //delete worker;
}


int MortageLoanClient::getText()
{
    return 1;
}

