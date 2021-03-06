#ifndef PARSESERVICEBASECLASS_H
#define PARSESERVICEBASECLASS_H
#include "settingmap.h"
#include "workerbaseclass.h"
#include <QByteArray>
#include <QObject>
#include <QDataStream>
#include <QRegExp>

//class WorkerBaseClass;

class ParseServiceBaseClass: public QObject
{
    Q_OBJECT
public:
      explicit ParseServiceBaseClass(WorkerBaseClass *, CLIENT_TYPE const &);


    virtual  void data_parser_handler(QByteArray const &) = 0;
    virtual ~ParseServiceBaseClass();

protected:
    CLIENT_TYPE type;
    virtual void create_connect_to_worker() = 0;
    QString last_line;
    QStringList str_data_list;
    WorkerBaseClass *worker;
    ParseServiceBaseClass *parent;
    ParseServiceBaseClass *child;


signals:

void parser_sendData(QStringList & );

private:
    virtual  QStringList sl_parse_line(QString  const) = 0;
};

#endif // PARSESERVICEBASECLASS_H




