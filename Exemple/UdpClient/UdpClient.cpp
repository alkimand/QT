// ======================================================================
//  UdpClient.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include <QtNetwork>
#include <QtGui>
#include "UdpClient.h"
#include <QDebug>

// ----------------------------------------------------------------------
UdpClient::UdpClient(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("UdpClient");

    m_pudp = new QUdpSocket(this);
    m_pudp->bind(3500);
    connect(m_pudp, SIGNAL(readyRead()), SLOT(slotProcessDatagrams()));    
}

// ----------------------------------------------------------------------
void UdpClient::slotProcessDatagrams()
{
    QByteArray baDatagram;
    do {
        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(), baDatagram.size());
    } while(m_pudp->hasPendingDatagrams());



    //QDateTime dateTime;
    QString dateTime;
    QDataStream in(&baDatagram, QIODevice::ReadOnly);

    //quint8 v;
    //in >> v;

    //quint16 length = 0;
    //in >> length;

    in.readRawData(baDatagram.data(), m_pudp->pendingDatagramSize());
    QString string(baDatagram);



  //  in.setVersion(QDataStream::Qt_5_3);
    //in >> dateTime;
//    in >> dateTime;
//    in >>sVal;
//    in >>fVal;
//    in >>dVal;
//    in >>Empty;





    this->clear();
    this->append(string);
    //append(string);
    //append("Received:" + dateTime);
    //append("Received:" + sVal);
    //append("Received:"  fVal);
    //append("Received:"  dVal);
    //append("Received:" + Empty);
    //qDebug()<<this->;
}

