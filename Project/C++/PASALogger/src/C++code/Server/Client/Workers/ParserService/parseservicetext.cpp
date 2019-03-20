#include "parseservicetext.h"

#include <QDebug>



ParseServiceText:: ParseServiceText(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type):ParseServiceUDP(m_worker, m_type)
{
    qDebug()<< "create ParseServiceText";
    this->child = this;
    create_connect_to_worker();
}


void ParseServiceText:: data_parser_handler( QByteArray const &  stream)
{
    //qDebug()<< "ParseServiceText receive_data_parser_handler";
    //qDebug()<< "New session";
    QRegExp rx("(^[0-1]{1})+([0-9]{1})+([/]{1})+([0-3]{1})+([0-9]{1})+([/]{1})");
    QString line(stream);
   // qDebug()<< " line:" <<  line;
    if ( !line.contains(rx))
    {

        //line = last_line + line;
        //qDebug()<< "last_line:" << last_line;
    }
    else
    {
        //qDebug()<< "line do not  contains(rx)";
    }
        str_data_list = sl_parse_line(line);
        emit parser_sendData (str_data_list);
        str_data_list.clear();
        return;
}

ParseServiceText::~ParseServiceText()
{
    qDebug()<< "~ParseServiceText()";
}
