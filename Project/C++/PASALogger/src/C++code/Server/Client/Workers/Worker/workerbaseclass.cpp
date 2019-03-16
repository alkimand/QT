#include "workerbaseclass.h"
#include "workerudp.h"
#include "parseserviceudp.h"

#include <QDebug>

WorkerBaseClass::WorkerBaseClass(ClientBase *m_client, CLIENT_TYPE const & m_type)
{
    //qDebug()<< "WorkerBaseClass+";
    parent = this;
    this->client = static_cast<ClientBase*>(m_client);

    //this->client = m_client;
    type = m_type;



}

void WorkerBaseClass::test()
{
    qDebug()<< "WorkerBaseClass test";
}

void WorkerBaseClass::send_message(QByteArray   const & msg)
{
    //qDebug()<< "Send_message: ";
    emit dataloader->sendData(msg);
}

ModelServiseBaseClass *WorkerBaseClass::getModeltoQMLService()
{
    return this->model;
}

void WorkerBaseClass::receive_data_loader_slot(QByteArray  const & message)
{
        //qDebug()<< " WorkerBaseClass receive_data_loader_slot ";
        //qDebug()<< "message:" + message;
        this->child->receive_data_loader_handler(message);
       //this->child->receive_data_loader_handler(message);

//        switch (type)

//        case UDP_CLIENT_TYPE:
//           // WorkerUDP *worker= qobject_cast<WorkerUDP*>(this());
//           // worker->test();
//            break;
//        default:
//            break;
//        }
// QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
}

void WorkerBaseClass::receive_data_parser_slot(QStringList & list)
{
    //QStringList list;
    this->child->receive_data_parser_handler(list);
}
