#include "ClientBase.h"
#include "WorkerBaseClass.h"

#include <QDebug>

IWorkerBaseClass::IWorkerBaseClass(ItemEnums::EClientType client_type):client_type_(client_type)
{
    parentWorker = this;
    //qDebug()<< "create WorkerBaseClass";
    //parent = this;
    //this->client = static_cast<ClientBase*>(m_client);

    //this->client = m_client;
   // type = m_type;
}

void IWorkerBaseClass::test()
{
    qDebug()<< "WorkerBaseClass test";
}

void IWorkerBaseClass::initModel()
{
    if (childWorker)
        childWorker->initModel();

}

void IWorkerBaseClass::refreshModel()
{

}

void IWorkerBaseClass::changeCurrentDateIndex(int index)
{
    curent_index_model = index;
    if (childWorker)
        refreshModel();
    //childWorker->dateIndexChanged(index);
}

p_model IWorkerBaseClass::getModel(int index)
{
    return ui_proxi_models_.value(index);
}

IWorkerBaseClass::~IWorkerBaseClass()
{
    qDebug()<< "~WorkerBaseClass()";

//    delete dataloader;
//    delete model;
//   // if (proximodel!=nullptr)
//    delete proximodel;
//    delete parser;
}

//void WorkerBaseClass::send_message(QByteArray   const & msg)//--
//{
//    //qDebug()<< "Send_message: ";
//    //emit dataloader->sendData(msg);
//}

//void WorkerBaseClass::receive_data_loader_handler(const QByteArray & message)
//{
//    this-> parser->data_parser_handler(message);
//}

//ModelServiseBaseClass *WorkerBaseClass::getModeltoQMLService()
//{
//    return this->model;
//}

//ProxiModelServiseBaseClass *WorkerBaseClass::getProxiModeltoQMLService()
//{
//    return this->proximodel;
//}

//void WorkerBaseClass::saveAs()
//{
//    this->model->saveAs();
//}

//void WorkerBaseClass::save()
//{
//    this->model->save();
//}

//void WorkerBaseClass::filterChanged(const int & column, const QString & text)
//{
//    this->proximodel->filterChanged(column,text);
//}

//void WorkerBaseClass::setNameDocument(const QString & tittle)
//{
// this->client->setDocumentTittle(tittle);
//}

//void WorkerBaseClass::openInExplorer()
//{
//    this->model->openInExplorer();
//}

//void WorkerBaseClass::openInDesktopServices()
//{
//    this->model->openInDesktopServices();
//}

//void WorkerBaseClass::sendFilePath(const QString & fullFilePath)
//{

//    this->model->setFilePath(fullFilePath);

//    QStringList list = fullFilePath.split("/");
//    QString fileName = list.last();
//    this->client->setDocumentTittle(fileName);
//}

//void WorkerBaseClass::sendFileName(const QString & fileName)
//{
//    this->model->setFileName(fileName);
//    this->client->setDocumentTittle(fileName);
//}

//void WorkerBaseClass::receive_data_loader_slot(QByteArray  const & message)
//{
//        //qDebug()<< " WorkerBaseClass receive_data_loader_slot ";
//        //qDebug()<< "message:" + message;
//        this->child->receive_data_loader_handler(message);
//       //this->child->receive_data_loader_handler(message);

////        switch (type)

////        case UDP_CLIENT_TYPE:
////           // WorkerUDP *worker= qobject_cast<WorkerUDP*>(this());
////           // worker->test();
////            break;
////        default:
////            break;
////        }
//// QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
//}

//void WorkerBaseClass::receive_data_parser_slot(QStringList & list)
//{
//    //QStringList list;
//    this->child->receive_data_parser_handler(list);
//}

//void  WorkerBaseClass::clearDataPool()
//{
//    this->model->clearDataPool();
//}

//void WorkerBaseClass::setStatus(const int & status)
//{
//    qDebug()<< "WorkerBaseClass::setStatus";
//    this->dataloader->setStatus(status);
//}

