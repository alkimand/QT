#ifndef PARSESERVICETEXT_H
#define PARSESERVICETEXT_H
#include "parseserviceudp.h"

class ParseServiceText: public ParseServiceUDP
{

    Q_OBJECT
public:
    explicit  ParseServiceText (WorkerBaseClass *, CLIENT_TYPE const &);

    void data_parser_handler(QByteArray const &);
   ~ ParseServiceText();


private:
    //QString* udp_socket;
    //int port;
    //QStringList sl_parse_line(QString const);

signals:

protected:
    //void create_connect_to_worker();



private:



};

#endif // PARSESERVICEUDP_H
