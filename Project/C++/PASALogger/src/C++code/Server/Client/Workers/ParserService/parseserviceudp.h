#ifndef PARSESERVICEUDP_H
#define PARSESERVICEUDP_H
#include "parseservicebaseclass.h"


class ParseServiceUDP: public ParseServiceBaseClass
{

    Q_OBJECT
public:
    explicit  ParseServiceUDP (WorkerBaseClass *, CLIENT_TYPE const &);

    void data_parser_handler(QByteArray const &);


private:
    //QString* udp_socket;
    int port;
    QStringList sl_parse_line(QString const);



signals:

protected:
    void create_connect_to_worker();



private:



};

#endif // PARSESERVICEUDP_H
