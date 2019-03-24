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


signals:

protected:

private:



};

#endif // PARSESERVICEUDP_H
