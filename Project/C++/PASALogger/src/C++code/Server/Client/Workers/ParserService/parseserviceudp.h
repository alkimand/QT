#ifndef PARSESERVICEUDP_H
#define PARSESERVICEUDP_H
#include "parseservicebaseclass.h"


class ParseServiceUDP: public ParseServiceBaseClass
{

    Q_OBJECT
public:
    explicit  ParseServiceUDP (WorkerBaseClass *, CLIENT_TYPE const &);

    virtual void data_parser_handler(QByteArray const &);
    ~ParseServiceUDP();

private:
    //QString* udp_socket;

signals:

protected:
    void create_connect_to_worker();
    QStringList sl_parse_line(QString const);
    int port;

private:



};

#endif // PARSESERVICEUDP_H
