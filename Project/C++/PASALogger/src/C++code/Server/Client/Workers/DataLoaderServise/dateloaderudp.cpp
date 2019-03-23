#include "workerbaseclass.h"
#include "dateloaderudp.h"

#include <QtNetwork>
#include <QtGui>

#include <QDebug>

DateLoaderUDP::DateLoaderUDP(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type): DataLoaderBaseClass(m_worker, m_type)
{
    //qDebug()<< "create DateLoaderUDP";
    this->child = this;
    udp_socket = new QUdpSocket(this);
    //udp_socket->moveToThread(this);
    this->port = 3500;
    // udp_socket->bind(this->port);
    udp_socket->bind(3500);

    create_connect_to_worker();

    this->status = PLAY;
    //qDebug()<< "=create DateLoaderUDP";
    connect(udp_socket, SIGNAL(readyRead()),this->child, SLOT(slotProcessDatagrams()));
    //qDebug()<< "-create DateLoaderUDP";
}

DateLoaderUDP::~DateLoaderUDP()
{
    delete udp_socket;
    qDebug()<< "~DateLoaderUDP";
}

void DateLoaderUDP::setStatus(const int & status)
{
    qDebug()<< "DateLoaderUDP::setStatus:" + status;
//    if (this->status == PLAY)
//    {
//        this->status = STATUS(status);
//        if (this->status != PLAY)
//        {
////            if (udp_socket!=nullptr){
////                udp_socket = new QUdpSocket(this);
////                udp_socket->bind(3500);
////                connect(udp_socket, SIGNAL(readyRead()),this->child, SLOT(slotProcessDatagrams()));}
//            // udp_socket->open(QIODevice::ReadOnly);

//        }
//    }
//        else if (this->status ==PAUSE |this->status ==STOP)
//        {
////            udp_socket->close();
////            delete udp_socket;
//        }
   // this->status == PLAY

        this->status = STATUS(status);
        emit udp_socket->readyRead();
}

void DateLoaderUDP::slotProcessDatagrams()
{
    // qDebug()<< "DateLoaderUDP::slotProcessDatagrams()";
    QByteArray baDatagram;

    while((udp_socket->hasPendingDatagrams()) && (status == PLAY))
    {
        baDatagram.resize(udp_socket->pendingDatagramSize());
        udp_socket->readDatagram(baDatagram.data(), baDatagram.size());
        QDataStream in(&baDatagram, QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_5_3); //+?
        if (udp_socket->hasPendingDatagrams())
        {
            in.readRawData(baDatagram.data(), udp_socket->pendingDatagramSize());
        }
        else
        {
            //qDebug()<< "4.2 has no PendingDatagrams";
        };

        emit sendData(baDatagram);
    }
}

