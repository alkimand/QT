#ifndef DATALOADERBASECLASS_H
#define DATALOADERBASECLASS_H
#include "settingmap.h"
#include <QObject>

class WorkerBaseClass;
class QDataStream;

class DataLoaderBaseClass: public QObject
{
    Q_OBJECT
public:
    explicit  DataLoaderBaseClass(WorkerBaseClass *, CLIENT_TYPE const &);
    WorkerBaseClass *worker;
    DataLoaderBaseClass *parent;
    DataLoaderBaseClass *child;
    virtual ~DataLoaderBaseClass();
    virtual void setStatus(const int &)=0;
private:
    CLIENT_TYPE type;



signals:
  //  void sendData(QByteArray const &);
    void sendData(QByteArray const &);


protected:
    virtual void create_connect_to_worker();
    STATUS status;

};

#endif // DATALOADERBASECLASS_H

