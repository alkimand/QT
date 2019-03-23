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
    void receive_data_parser_handler(QStringList  &);
    ~WorkerText();

protected:




private:


};

#endif // WORKERUDP_H
