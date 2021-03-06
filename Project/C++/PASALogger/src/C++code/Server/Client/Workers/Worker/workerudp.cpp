#include "workerudp.h"

#include "workerbaseclass.h"
#include "parseserviceudp.h"
#include "modelservisetext.h"
#include "modelserviseudp.h"
#include "proximodelserviseudp.h"

#include <QDebug>

WorkerUDP::WorkerUDP(ClientBase *m_client, CLIENT_TYPE const & m_type):WorkerBaseClass(m_client,m_type)
{
    qDebug()<< "create WorkerUDP";
    this-> child = this;
    this->parser = new ParseServiceUDP (this, type);
    this->model = new ModelServiseUDP (this, type);
    this->proximodel = new ProxiModelServiseUDP (this, type);
    this->dataloader = new  DateLoaderUDP (this, type);
}

void WorkerUDP::test()
{
    qDebug()<< "WorkerUDP test";

}

void WorkerUDP::receive_data_parser_handler(QStringList & str_list)
{
    int size = str_list.length();
    if ((size == 8) || (size == 1))
    {
        line_vector.append(str_list);//?

        // for (int j=0; j<size; j++)
        // qDebug()<< str_list.at(j);
    }
    else
    {
        qDebug()<< "Wrong parse string in class WorkerUDP::receive_data_loader_handler:";
        // for (int j=0; j<size;j++)
        //qDebug()<< str_list.at(j);
    }
    this->model->data_model_handler(str_list);

}


WorkerUDP::~WorkerUDP()
{
    qDebug()<< "WorkerUDP";
}
