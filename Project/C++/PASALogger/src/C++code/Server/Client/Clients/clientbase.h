#ifndef CLIENTBASE_H
#define CLIENTBASE_H
//#include <QtNetwork>
#include <QObject>
#include "settingmap.h"

//class QUdpSocket;

class Server;
class WorkerBaseClass;

class ClientBase: public QObject
{
    Q_OBJECT

public:
    explicit ClientBase();//no const



protected:
    WorkerBaseClass *worker;
    CLIENT_TYPE type; //const no pointer
    Server *server;
    ClientBase *child;


private:




    //QUdpSocket* m_pudp;
    //private slots:
    //    void slotProcessDatagrams();
};

#endif // CLIENTBASE_H
