#ifndef WORKERTEXT_H
#define WORKERTEXT_H
#include "workerbaseclass.h"
#include <QObject>


class WorkerText: public WorkerBaseClass
{

    Q_OBJECT

public:
    explicit WorkerText(ClientBase * m_client, CLIENT_TYPE  const &);
    void test();
    void receive_data_loader_handler(QByteArray const &);
    void receive_data_parser_handler(QStringList  &);
    void setStatus(const int &){};
    ~WorkerText();
    void clearDataPool();
protected:




private:


};

#endif // WORKERUDP_H
