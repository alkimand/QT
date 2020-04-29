#ifndef CLIENTBASE_H
#define CLIENTBASE_H
#include <QThread>
//#include <QtNetwork>
#include <QObject>


//#include "ClientBaseInclude.h"

#include "props.h"
#include "WorkerBaseClass.h"
#include "MortageLoanWorker.h"
#include <QAbstractTableModel>


class ClientBase: public QObject
{
    Q_OBJECT


public:
    explicit ClientBase(ItemEnums::EClientType client_type);//no const

    virtual ~ClientBase();

    QAbstractTableModel *getModel(int index);


protected:
    //WorkerBaseClass *worker;
    void instance();
    void instanceWorker(ItemEnums::EClientType client_type);



protected:
    ItemEnums::EClientType client_type_; //const no pointer



    ClientBase *parent_client_;
    ClientBase *child_client_;

    IWorkerBaseClass *worker_;






public slots:


signals:


private:

};

#endif // CLIENTBASE_H
