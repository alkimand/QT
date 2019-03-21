#include "workerudp.h"

#include "workerbaseclass.h"
#include "parseserviceudp.h"
#include "modelservisetext.h"
#include "modelserviseudp.h"

#include <QDebug>

WorkerUDP::WorkerUDP(ClientBase *m_client, CLIENT_TYPE const & m_type):WorkerBaseClass(m_client,m_type)
{
    qDebug()<< "create WorkerUDP";
    this-> child = this;
    //send_message("567");
    //child->test();

    switch (type)
    {
    case UDP_CLIENT_TYPE:
        this->parser = new ParseServiceUDP (this, type);
        this->model = new ModelServiseUDP (this, type);
        //this->model = new ModelServiseText (this, type);
        this->dataloader = new  DateLoaderUDP (this, type);
        break;
    default:
        break;
    }
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

void WorkerUDP::receive_data_loader_handler(QByteArray const & message)
{
    //qDebug()<< "1: WorkerUDP::receive_data_loader_handler in" ;
   this-> parser->data_parser_handler(message);
}
