#ifndef PROXIMODELSERVISEBASECLASS_H
#define PROXIMODELSERVISEBASECLASS_H
#include "settingmap.h"
#include "workerbaseclass.h"
#include "modelservisebaseclass.h"


#include <QObject>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>


//Proxi model
//https://stackoverrun.com/ru/q/10878631
//https://doc.qt.io/qt-5/qtwidgets-itemviews-customsortfiltermodel-example.html
//https://doc.qt.io/archives/qt-4.8/qsortfilterproxyModel.html

class ModelServiseBaseClass;
class QRegExp;

class  ProxiModelServiseBaseClass: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit  ProxiModelServiseBaseClass(WorkerBaseClass *,  CLIENT_TYPE const &);
    virtual ~ProxiModelServiseBaseClass();

   // bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

    // virtual  void data_model_handler(QStringList &) = 0;

     virtual bool filterAcceptsRow(int , const QModelIndex &) const override = 0;
     virtual void filterChanged(const int &, const QString & );




//signals:

protected:
    WorkerBaseClass *worker;
    ProxiModelServiseBaseClass *parent;
    ProxiModelServiseBaseClass *child;
    ModelServiseBaseClass *model;
    QVector <QStringList> v_filters;
    QVector <QRegExp> r_filters;
    QStringList filters;
    CLIENT_TYPE type;


private:




};



#endif // MODELSERVISEBASECLASS_H
