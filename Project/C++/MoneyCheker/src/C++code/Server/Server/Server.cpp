// ======================================================================

#include <QtNetwork>
#include <QtWidgets>
#include "Server.h"
#include "clientbase.h"
#include "clientudp.h"
#include <QDebug>
// ----------------------------------------------------------------------
//MyServer::MyServer(int nPort, QWidget* pwgt /*=0*/) : QWidget(pwgt)
//                                                    , m_nNextBlockSize(0)
//{
//    m_ptcpServer = new QTcpServer(this);
//    if (!m_ptcpServer->listen(QHostAddress::Any, nPort)) {
//        QMessageBox::critical(0,
//                              "Client Error",
//                              "Unable to start the client:"
//                              + m_ptcpServer->errorString()
//                             );

//        m_ptcpServer->close();
//        return;
//    }
//    connect(m_ptcpServer, SIGNAL(newConnection()),
//            this,         SLOT(slotNewConnection())
//           );

//    m_ptxt = new QTextEdit;
//    m_ptxt->setReadOnly(true);

//    //Layout setup
//    QVBoxLayout* pvbxLayout = new QVBoxLayout;
//    pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
//    pvbxLayout->addWidget(m_ptxt);
//    setLayout(pvbxLayout);
//}

//// ----------------------------------------------------------------------
///*virtual*/ void MyServer::slotNewConnection()
//{
//    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();
//    connect(pClientSocket, SIGNAL(disconnected()),
//            pClientSocket, SLOT(deleteLater())
//           );
//    connect(pClientSocket, SIGNAL(readyRead()),
//            this,          SLOT(slotReadClient())
//           );

//    sendToClient(pClientSocket, "Client Response: Connected!");
//}

//// ----------------------------------------------------------------------
//void MyServer::slotReadClient()
//{
//    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
//    QDataStream in(pClientSocket);
//    in.setVersion(QDataStream::Qt_5_3);
//    for (;;) {
//        if (!m_nNextBlockSize) {
//            if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
//                break;
//            }
//            in >> m_nNextBlockSize;
//        }

//        if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
//            break;
//        }
//        QTime   time;
//        QString str;
//        in >> time >> str;

//        QString strMessage =
//            time.toString() + " " + "Server has sent - " + str;
//        m_ptxt->append(strMessage);

//        m_nNextBlockSize = 0;

//        sendToClient(pClientSocket,
//                     "Client Response: Received \"" + str + "\""
//                    );
//    }
//}

//// ----------------------------------------------------------------------
//void MyServer::sendToClient(QTcpSocket* pSocket, const QString& str)
//{
//    QByteArray  arrBlock;
//    QDataStream out(&arrBlock, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_5_3);
//    out << quint16(0) << QTime::currentTime() << str;

//    out.device()->seek(0);
//    out << quint16(arrBlock.size() - sizeof(quint16));

//    pSocket->write(arrBlock);
//}
//void createClient(int tupe)
//{

//}
ClientBase *Server::createClient(CLIENT_TYPE const &type)
{
    ClientBase * client_test;
    switch (type)
    {
    case UDP_CLIENT_TYPE:
        //client_test = new ClientUDP(this,UDP_CLIENT_TYPE);
        //client_test = new ClientUDP( UDP_CLIENT_TYPE);
        client_test = new ClientUDP( );
        clients.push_back(client_test);
        break;

    default:
        break;
    }

    return client_test;
}

Server::Server(QObject *parent)
{
    //qDebug()<< "create Server";
    //create first seesion for test
    //ClientBase * client_test = new ClientBase(this);

    //createClient(UDP_CLIENT_TYPE);


}
