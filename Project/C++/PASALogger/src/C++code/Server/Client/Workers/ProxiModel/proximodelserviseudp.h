#ifndef PROXIMODELSERVISEUDP_H
#define PROXIMODELSERVISEUDP_H
#include "settingmap.h"
#include "proximodelservisebaseclass.h"
#include "workerbaseclass.h"

#include <QObject>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>


class  ProxiModelServiseUDP: public ProxiModelServiseBaseClass
{
    Q_OBJECT
public:
    explicit  ProxiModelServiseUDP(WorkerBaseClass *,ModelServiseBaseClass *, CLIENT_TYPE const &);
      ~ProxiModelServiseUDP();





//signals:

protected:
    //QVector <QStringList> v_data;
  //  QStringList filters;

private:

    //QRegExp nameRegExp;
   // QRegExp yearRegExp;



};



#endif // PROXIMODELSERVISEUDP_H
