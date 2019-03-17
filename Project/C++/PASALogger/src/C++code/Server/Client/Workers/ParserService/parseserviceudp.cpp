#include "parseserviceudp.h"

#include <QDebug>



ParseServiceUDP:: ParseServiceUDP(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type):ParseServiceBaseClass(m_worker, m_type)
{
    qDebug()<< "create ParseServiceUDP";
    this->child = this;
    create_connect_to_worker();
}



void ParseServiceUDP:: create_connect_to_worker()
{
    //send data to worker
    //qDebug()<< "ParseServiceUDP::create_connect_to_worker";
    //connect(this, SIGNAL(parser_sendData(QStringList &)), worker, SLOT(receive_data_parser_handler(QStringList &)));
    connect(this, SIGNAL(parser_sendData(QStringList &)), worker, SLOT(receive_data_parser_slot(QStringList &)));
}


void ParseServiceUDP:: data_parser_handler( QByteArray const &  stream)
{
    //qDebug()<< "ParseServiceUDP receive_data_parser_handler";
    //qDebug()<< "New session";
    QRegExp rx("(^[0-1]{1})+([0-9]{1})+([/]{1})+([0-3]{1})+([0-9]{1})+([/]{1})");
    QString line(stream);
    // qDebug()<< " line:" <<  line;
    switch (type)
    {
    case  (UDP_CLIENT_TYPE):
    {
        if ( !line.contains(rx))
        {

            line = last_line + line;
            //qDebug()<< "last_line:" << last_line;
        }
        else
        {
            //qDebug()<< "line do not  contains(rx)";
        }
        QStringList parse_line=line.split("\r\n"); //temporary object
        last_line = parse_line.last();
        //qDebug()<< "last_line = parse_line.last():" << last_line;
        parse_line.removeLast();
        for (int i=0;i<parse_line.length();i++)
        {
            //qDebug()<< "i:" << i;
            //qDebug()<< "parse start for:" + parse_line.at(i);
            str_data_list = sl_parse_line(parse_line.at(i));

            emit parser_sendData (str_data_list);
            //for (int j=0;j<str_data_list.size();j++)
            // qDebug()<< str_data_list.at(j);
            str_data_list.clear();
        }
    }
        break;
    case  (TXT_CLIENT_TYPE):
        str_data_list = sl_parse_line(line);
        emit parser_sendData (str_data_list);
        str_data_list.clear();
        break;
    default:
        break;
    }
    return;
}

QStringList ParseServiceUDP::sl_parse_line(QString  const message )
{
    QStringList parse_string;
    QRegExp rx("(^[0-1]{1})+([0-9]{1})+([/]{1})+([0-3]{1})+([0-9]{1})+([/]{1})");
    if (!message.contains(rx)) //validation check
    {
        parse_string.append(message);
        //qDebug()<< "No valid message:" + message;
        return parse_string;
    }

    int position_1;
    int position_2;
    QString str = " ";
    str = " ";
    position_1 = message.indexOf(str);
    // if (!position) return parse_string;
    parse_string.append(message.left(position_1 )); // add Date
    str = "/";
    position_2 = message.indexOf(str, position_1 + 1 );
    parse_string.append(message.mid( position_1 + 1, position_2 - position_1 - 1)); // add Time
    position_1 = message.indexOf(str, position_2 + 1 );
    parse_string.append(message.mid( position_2 + 1, position_1 - position_2 -1)); // add Count
    position_2 = message.indexOf(str, position_1 + 1 );
    parse_string.append(message.mid( position_1 + 1, position_2 - position_1 -1)); // add Zone ID
    int n = position_2;
    position_1 = message.length() ;
    str = "=";
    position_2 = message.indexOf (str);
    QString msg = message.right( position_1 - position_2 );
    str = "/";
    position_1 = message.lastIndexOf (str,position_2 - 2);
    QString line_number = message.mid( position_1 + 1, position_2 - position_1 - 2);
    position_2 = message.lastIndexOf (str,position_1 - 2);
    QString function_number = message.mid( position_2 + 1, position_1 - position_2 - 1);
    position_1 = message.lastIndexOf (str,position_2 - 1);

    QString Service_name = message.mid( n + 1, position_2 - n - 1);
    parse_string.append(Service_name); // add Serice name
    parse_string.append(function_number); // add Function name
    parse_string.append(line_number); // add Line Number
    parse_string.append(msg);// add Message
    return parse_string;
}
