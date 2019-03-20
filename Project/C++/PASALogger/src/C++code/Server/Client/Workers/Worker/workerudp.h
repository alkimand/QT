#ifndef WORKERUDP_H
#define WORKERUDP_H
#include "workerbaseclass.h"
#include <QObject>


class WorkerUDP: public WorkerBaseClass
{

    Q_OBJECT

public:
    explicit WorkerUDP(ClientBase * m_client, CLIENT_TYPE  const &);
    void test();
    //WorkerBaseClass *child;
   // WorkerUDP *child2;
    void receive_data_loader_handler(QByteArray const &);
    void receive_data_parser_handler(QStringList  &);
    void setStatus(const int &);
    ~WorkerUDP();
    void clearDataPool();

protected:




private:

};

#endif // WORKERUDP_H
