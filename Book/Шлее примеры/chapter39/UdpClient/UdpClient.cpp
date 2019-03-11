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
#include <QTextCodec>

// ----------------------------------------------------------------------
UdpClient::UdpClient(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("UdpClient");

    m_pudp = new QUdpSocket(this);
    m_pudp->bind(2424);
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

   // QDateTime dateTime;
    QDataStream in(&baDatagram, QIODevice::ReadOnly);

    //quint16 m_nNextBlockSize=0;
    //in.setVersion(QDataStream::Qt_5_3);
//     for (;;) {
//         if (!m_nNextBlockSize) {
//             if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
//                 break;
//             }
//             in >> m_nNextBlockSize;
//         }

//         if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
//             break;
//         }

        // QTime   time;
        // QString str;

         //QDataStream out(&arrBlock, QIODevice::WriteOnly);
        // in2 >> arrBlock;
        // in >> arrBlock;
         //in >> time >> str;
        // in >> str;

       //  QString strMessage = "Server has sent - " + str + " to Port " + QString::number(nPort);
                // time.toString() + " " + "Server has sent - " + str + " to Port " + QString::number(this->nPort);

         //m_ptxt->append(strMessage);

       //  m_nNextBlockSize = 0;

        // QByteArray encodedString = "...";
         QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
         QString string = codec->toUnicode(baDatagram);




    in.setVersion(QDataStream::Qt_5_3);

    //in >> dateTime;
    append("Received:" + string);
}

