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

public:
    explicit ClientBase();//no const

    //virtual
    virtual ~ClientBase();
    void run();
    void sendTittle(const QString &);
    void setDocumentTittle(const QString );
    QString readDocumentTittle();


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
    void openInDesktopServicesSlot();
    void filterChangedSlot(const int &, const QString &);
    void setNameDocumentSlot(const QString &);

signals:
    void documentTittleChanged();

private:

};

#endif // CLIENTBASE_H
