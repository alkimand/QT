#pragma once

#include <QWidget>
#include <QVector>
#include "settingmap.h"
//class QTcpServer;
//class QTextEdit;
//class QTcpSocket;
#include "clientbase.h"
//class ClientBase;

// ======================================================================
class Server : public QObject {
Q_OBJECT
private:
//    QTcpServer* m_ptcpServer;
//    QTextEdit*  m_ptxt;
//    quint16     m_nNextBlockSize;

private:
    //void sendToClient(QTcpSocket* pSocket, const QString& str);
    QVector <ClientBase*> clients;

public:
   // Server(int nPort, QWidget* pwgt = 0);
     explicit Server(QObject* parent = nullptr);

protected:
    ClientBase * createClient(CLIENT_TYPE const &);

public slots:
   // virtual void slotNewConnection();
           // void slotReadClient   ();
};

