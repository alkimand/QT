#include "workerbaseclass.h"
#include "dateloaderudp.h"

#include <QtNetwork>
#include <QtGui>

#include <QDebug>

DateLoaderUDP::DateLoaderUDP(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type): DataLoaderBaseClass(m_worker, m_type)
{
    qDebug()<< "+create DateLoaderUDP";
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
    this->status = STATUS(status);
    emit udp_socket->readyRead();
}

void DateLoaderUDP::create_connect_to_worker()
{
    //send data to worker
    //qDebug()<< "DateLoaderUDP::create_connect_to_worker";
     connect(this->child, SIGNAL(sendData(QByteArray const &)), worker, SLOT(receive_data_loader_slot(QByteArray const &)));
}

void DateLoaderUDP::start()
{


}

void DateLoaderUDP::stop()
{

}

void DateLoaderUDP::slotProcessDatagrams()
{
    // qDebug()<< "DateLoaderUDP::slotProcessDatagrams()";
    QByteArray baDatagram;

    while((udp_socket->hasPendingDatagrams()) && (status == PLAY))
    {
        //qDebug()<< "1";
        baDatagram.resize(udp_socket->pendingDatagramSize());
        //qDebug()<< "2";
        udp_socket->readDatagram(baDatagram.data(), baDatagram.size());
        //qDebug()<< "3";
        QDataStream in(&baDatagram, QIODevice::ReadOnly);
        //qDebug()<< "4";
        in.setVersion(QDataStream::Qt_5_3); //+?
        //qDebug()<< "4.0";
        if (udp_socket->hasPendingDatagrams())
        {
            //qDebug()<< "4.2" + udp_socket->pendingDatagramSize();
            in.readRawData(baDatagram.data(), udp_socket->pendingDatagramSize());
        }
        else
        {
            //qDebug()<< "4.2 has no PendingDatagrams";
        }

       // QString line(baDatagram);
        //qint32 i;
        //in >> i;

       // in >> first_line;
        //line(baDatagram);

        emit sendData(baDatagram);
    }

}

