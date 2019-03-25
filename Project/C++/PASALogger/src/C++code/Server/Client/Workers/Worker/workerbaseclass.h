#ifndef WORKERBASECLASS_H
#define WORKERBASECLASS_H
#include "settingmap.h"

#include <QObject>
#include <QVector>
#include <QStringList>

//class DataLoaderBaseClass;

#include "dataloaderbaseclass.h"
#include "dateloaderudp.h"
#include "dateloadertext.h"
#include "modelservisebaseclass.h"
#include "proximodelservisebaseclass.h"


class ParseServiceBaseClass;
class ClientBase;
class ModelServiseBaseClass;
class ProxiModelServiseBaseClass;

class WorkerBaseClass: public QObject
{
    Q_OBJECT
public:
    explicit WorkerBaseClass(ClientBase * , CLIENT_TYPE  const &);
    virtual void test();

    virtual ~WorkerBaseClass();
    void send_message(QByteArray  const &);
    // QStringList message_list;//--
    //interfase for child class - all hendler are using in child class
    virtual void receive_data_loader_handler(QByteArray  const &);
    virtual void receive_data_parser_handler(QStringList &) = 0;
    QVector <QStringList> line_vector;//--
    ModelServiseBaseClass * getModeltoQMLService();
    ProxiModelServiseBaseClass *getProxiModeltoQMLService();

    //QML/C++ relations
    virtual void setStatus(const int &);
    virtual void clearDataPool();
    virtual void saveAs();
    virtual void save();
    virtual void filterChanged(const int & , const QString & );
    virtual void setNameDocument(const QString & ); //Filename to Client to QML
    virtual void openInExplorer();
    virtual void openInDesktopServices();
    virtual void sendFileName(const QString & ); //send Filename to other service
    virtual void sendFilePath(const QString & );

protected:
    ModelServiseBaseClass *model;
    ProxiModelServiseBaseClass * proximodel;
    WorkerBaseClass *parent;
    WorkerBaseClass *child;

public slots:
    void receive_data_loader_slot(QByteArray  const &);
    void receive_data_parser_slot(QStringList  &);

protected:
    ClientBase *client;
    CLIENT_TYPE type;
    DataLoaderBaseClass *dataloader;
    ParseServiceBaseClass *parser;

private:

};

#endif // WORKERBASECLASS_H
