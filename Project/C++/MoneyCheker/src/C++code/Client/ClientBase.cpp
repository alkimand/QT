#include "ClientBase.h"
//#include "Server.h"

#include <QDebug>

//ClientBase::ClientBase( Server  *m_server,  CLIENT_TYPE const & m_type)
ClientBase::ClientBase(ItemEnums::EClientType client_type):client_type_(client_type)
{
    parent_client_ = this;
    //tittle = "DEFAULT";
}

ClientBase::~ClientBase()
{
    //this->wait();
    qDebug()<< "~ClientBase()";
}


void ClientBase::instance()
{
    instanceWorker(client_type_);
}

void ClientBase::instanceWorker(ItemEnums::EClientType client_type)
{
    qDebug()<< "ClientBase::instanceWorker()";
    switch (int(client_type)) {
    case ItemEnums::EClientType::kMortageLoanCalculator:
        worker_ = static_cast<IWorkerBaseClass*>(new MortageLoanWorker(client_type));
        break; //MortageLoanWorker
    default:
        qDebug()<< "Error in ClientBase::instanceWorker()";
        break;
    }

}


QAbstractTableModel * ClientBase::getModel(int index)
{
    qDebug()<< "ClientBase::getModel";

   return (worker_->getModel(index)).data();
}




//void ClientBase::run()
//{
//    //exec();
//}

//void ClientBase::sendTittle(const QString & m_tittle)
//{
//    tittle = m_tittle;
//    //qDebug()<< " ClientBase::sendTittle:"+ tittle ;
//}

//void ClientBase::setDocumentTittle(const QString m_tittle)
//{
//    tittle =  m_tittle;
//}

//QString ClientBase::readDocumentTittle()
//{
//    return tittle;
//}

//void ClientBase::saveAsSlot()
//{
//    this->worker->saveAs();
//}

//void ClientBase::saveSlot()
//{
//    this->worker->save();
//}

//void ClientBase::clearDataPool()
//{

//    this->worker->clearDataPool();
//}

//void ClientBase::openInExplorerSlot()
//{
//    this->worker->openInExplorer();
//}

//void ClientBase::openInDesktopServicesSlot()
//{
//    this->worker->openInDesktopServices();
//}

//void ClientBase::filterChangedSlot(const int & column, const QString & text)
//{
//     //qDebug()<< "ClientBase::filterChangedSlot";
//    this->worker->filterChanged(column,text);
//}

//void ClientBase::setNameDocumentSlot(const QString & tittle)
//{
//   //qDebug()<< "ClientBase::setNameDocumentSlot:"+tittle;

//   this->worker->sendFileName(tittle);
//}


//void ClientBase::setStatus(const int & status)
//{
// qDebug()<< "ClientBase::setStatus";
// if (type == UDP_CLIENT_TYPE)
// this->worker->setStatus(status);
//}
