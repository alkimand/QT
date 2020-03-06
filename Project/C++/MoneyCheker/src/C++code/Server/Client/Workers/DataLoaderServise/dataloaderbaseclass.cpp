#include "dataloaderbaseclass.h"
#include "workerudp.h"
#include <QDebug>

DataLoaderBaseClass::DataLoaderBaseClass(WorkerBaseClass * m_worker,  CLIENT_TYPE const  & m_type)
{
    worker = static_cast<WorkerBaseClass*>(m_worker);
    type = m_type;
    parent = this;
    status = PLAY;
    //  qDebug()<< "create DataLoaderBaseClass";
}

DataLoaderBaseClass::~DataLoaderBaseClass()
{
    qDebug()<< "~DataLoaderBaseClass";
}

void DataLoaderBaseClass::create_connect_to_worker()
{
    connect(child, SIGNAL(sendData(QByteArray const &)), worker, SLOT(receive_data_loader_slot(QByteArray const &)));
}
