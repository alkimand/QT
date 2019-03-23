#ifndef CLIENTBASE_H
#define CLIENTBASE_H
#include <QThread>
//#include <QtNetwork>
#include <QObject>
#include "settingmap.h"
#include "modelserviseudp.h"
#include "proximodelserviseudp.h"

//class QUdpSocket;

class Server;
class WorkerBaseClass;

class ClientBase: public QObject
//class ClientBase: public QThread
{
    Q_OBJECT
    Q_PROPERTY(QString documentTittle READ readDocumentTittle WRITE setDocumentTittle NOTIFY documentTittleChanged)
    Q_PROPERTY(ProxiModelServiseUDP * proximodel READ readproxiModel WRITE setproximodel NOTIFY proxiModelChanged)

public:
    explicit ClientBase();//no const

//virtual
  virtual ~ClientBase();
    void run();
    void sendTittle(const QString &);
    void setproximodel(const ProxiModelServiseUDP *proximodel);

    void setDocumentTittle(const QString );

    QString readDocumentTittle()
    {
        return tittle;
    }

    ProxiModelServiseUDP *readproxiModel() const
    {
        return proximodel;
    }

    ProxiModelServiseUDP *proximodel;

protected:
    WorkerBaseClass *worker;
    CLIENT_TYPE type; //const no pointer
    //Server *server;
    ClientBase *child;
    QString tittle;


   // virtual void setStatus(const int &){};


public slots:
void saveAsSlot();
void saveSlot();
void setStatus(const int &);
void clearDataPool();
void openInExplorerSlot();
void filterChangedSlot(const int &, const QString &);
void setNameDocumentSlot(const QString &);



private:

signals:
void documentTittleChanged();
void proxiModelChanged();



    //QUdpSocket* m_pudp;
    //private slots:
    //    void slotProcessDatagrams();
};

#endif // CLIENTBASE_H
