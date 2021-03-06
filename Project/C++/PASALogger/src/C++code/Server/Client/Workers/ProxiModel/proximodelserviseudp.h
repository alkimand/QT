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
    explicit  ProxiModelServiseUDP(WorkerBaseClass *,CLIENT_TYPE const &);
      ~ProxiModelServiseUDP();
    bool filterAcceptsRow(int, const QModelIndex &) const override;

protected:

private:

};



#endif // PROXIMODELSERVISEUDP_H
