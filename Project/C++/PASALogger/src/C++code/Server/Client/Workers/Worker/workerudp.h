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
    void receive_data_parser_handler(QStringList  &);
    ~WorkerUDP();

protected:




private:

};

#endif // WORKERUDP_H
