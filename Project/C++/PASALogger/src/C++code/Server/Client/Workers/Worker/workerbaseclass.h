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

class ParseServiceBaseClass;
class ClientBase;
class ModelServiseBaseClass;

class WorkerBaseClass: public QObject
{
    Q_OBJECT
public:
    explicit WorkerBaseClass(ClientBase * , CLIENT_TYPE  const &);
    virtual void test();
    WorkerBaseClass *parent;
    WorkerBaseClass *child;

    virtual ~WorkerBaseClass();
    void send_message(QByteArray  const &);
    QStringList message_list;
    //interfase for child class - all hendler are using in child class
    virtual void receive_data_loader_handler(QByteArray  const &) = 0;
    virtual void receive_data_parser_handler(QStringList &) = 0;
    QVector <QStringList> line_vector;
    ModelServiseBaseClass * getModeltoQMLService();
    ModelServiseBaseClass *model;
    virtual void setStatus(const int &) = 0;
    virtual void clearDataPool()=0;
    virtual void saveAsSlot()=0;
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
