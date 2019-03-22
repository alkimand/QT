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
    enum Roles
        {
            ROW, CHECK ,DATE, TIME, COUNT, ZONE, SERVICENAME, FUNCTIONNAME, LINENUMBER, MESSAGE
        };

    Q_OBJECT
public:
    explicit  ProxiModelServiseUDP(WorkerBaseClass *,ModelServiseBaseClass *, CLIENT_TYPE const &);
      ~ProxiModelServiseUDP();

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;




    QVector <QStringList> v_filters;
    QVector <QRegExp> r_filters;
    QStringList filters;






//signals:

protected:
    //QVector <QStringList> v_data;
  //  QStringList filters;

private:

    //QRegExp nameRegExp;
   // QRegExp yearRegExp;



};



#endif // PROXIMODELSERVISEUDP_H
