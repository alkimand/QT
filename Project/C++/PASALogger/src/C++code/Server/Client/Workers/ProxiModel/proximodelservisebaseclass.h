#ifndef PROXIMODELSERVISEBASECLASS_H
#define PROXIMODELSERVISEBASECLASS_H
#include "settingmap.h"
#include "workerbaseclass.h"

#include <QObject>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>

//Proxi model
//https://stackoverrun.com/ru/q/10878631
//https://doc.qt.io/qt-5/qtwidgets-itemviews-customsortfiltermodel-example.html
//https://doc.qt.io/archives/qt-4.8/qsortfilterproxyModel.html


class  ProxiModelServiseBaseClass: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit  ProxiModelServiseBaseClass(WorkerBaseClass *, CLIENT_TYPE const &);
     WorkerBaseClass *worker;
     ProxiModelServiseBaseClass *parent;
     ProxiModelServiseBaseClass *child;

   // bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

    // virtual  void data_model_handler(QStringList &) = 0;


    CLIENT_TYPE type;



//signals:

protected:
    //QVector <QStringList> v_data;
    QStringList filters;

private:
    //QRegExp nameRegExp;
   // QRegExp yearRegExp;



};



#endif // MODELSERVISEBASECLASS_H
