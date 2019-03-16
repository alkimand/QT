#ifndef WORKERTEXT_H
#define WORKERTEXT_H
#include "workerbaseclass.h"
//#include "dateloadertext.h"
//#include "dateloadertext.h"
#include <QObject>


class WorkerText: public WorkerBaseClass
{

    Q_OBJECT

public:
    explicit WorkerText(ClientBase * m_client, CLIENT_TYPE  const &);
    void test();
    //WorkerBaseClass *child;
   // WorkerUDP *child2;
    void receive_data_loader_handler(QByteArray const &);
    void receive_data_parser_handler(QStringList  &);


protected:




private:

};

#endif // WORKERUDP_H
