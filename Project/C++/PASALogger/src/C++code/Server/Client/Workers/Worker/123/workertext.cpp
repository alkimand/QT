#include "workertext.h"

//#include "workerbaseclass.h"
#include "parseservicetext.h""
#include "modelservistext.h"
#include "dateloadertext.h"

#include <QDebug>

WorkerText::WorkerText(ClientBase *m_client, CLIENT_TYPE const & m_type):WorkerBaseClass(m_client,m_type)
{
    qDebug()<< "create WorkerText";
    this-> child = this;
    //send_message("567");
    //child->test();

//    switch (type)
//    {
//    case UDP_CLIENT_TYPE:
//        this->dataloader = new  DateLoaderText (this, type);
//        this->parser = new ParseServiceText (this, type);
//        this->model = new ModelServiseText (this, type);
//        break;
//    default:
//        break;
//    }
}

void WorkerText::test()
{
    qDebug()<< "WorkerText test";

}

void WorkerText::receive_data_parser_handler(QStringList & str_list)
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
        qDebug()<< "Wrong parse string in class WorkerText::receive_data_loader_handler:";
       // for (int j=0; j<size;j++)
            //qDebug()<< str_list.at(j);
    }
    this->model->data_model_handler(str_list);

}

void WorkerText::receive_data_loader_handler(QByteArray const & message)
{
    //qDebug()<< "1: WorkerText::receive_data_loader_handler in" ;
   this-> parser->data_parser_handler(message);
}

