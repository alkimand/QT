#include "proximodelserviseudp.h"
#include "modelservisetext.h"
#include "modelserviseudp.h"
#include "modelservisebaseclass.h"
#include <QDebug>

ProxiModelServiseUDP::ProxiModelServiseUDP(WorkerBaseClass * m_worker,  ModelServiseBaseClass * m_model, CLIENT_TYPE const  & m_type):ProxiModelServiseBaseClass(m_worker, m_model, m_type)
{

    this->child = this;
    qDebug()<< "ProxiModelServiseUDP";

    this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());
    this->setSourceModel(model);
     QRegExp regExp("");

     for (int i=0; i<model->columnCount(); i++)
     {
         //QRegExp regExp("(\\d+)");
         QRegExp regExp("");
         regExp.setCaseSensitivity(Qt::CaseInsensitive);
         regExp.setPatternSyntax(QRegExp::RegExp);
         r_filters.append(regExp);

     }

      QRegExp regExp2("SAL");
     // r_filters.insert(7,regExp2);
      r_filters.replace(7,regExp2);
      //r_filters.remove(8);
      regExp2.setPattern("sa_vp4");
      r_filters.replace(6,regExp2);







}

ProxiModelServiseUDP::~ProxiModelServiseUDP()
{
    qDebug()<< "~ProxiModelServiseUDP()";
}

bool ProxiModelServiseUDP::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{

   // QModelIndex dataIndex;
    QModelIndex dataIndex;
    QString data;
    bool hasFilter = false;

    for (int i=0; i < model->columnCount(); i++)//model->columnCount()
    {
        dataIndex = sourceModel()->index(sourceRow, i, sourceParent);
        data = sourceModel()->data(dataIndex,Qt::UserRole + i).toString();

        //qDebug()<< "data:" + data + " sourceRow:" + sourceRow;

        //qDebug()<< "r_filters.at(i).pattern():" + r_filters.at(i).pattern();

        hasFilter = data.contains(r_filters.at(i));



        if (!hasFilter)
            return false;

    }
    //QModelIndex dataIndexROW = sourceModel()->index(sourceRow, 0, sourceParent);





    //QModelIndex functionIndex2 = model->index(sourceRow, 7, sourceParent);


   // QModelIndex functionIndex = static_cast< > (model)->index(sourceRow, 4, sourceParent);


    //ModelIndex yearIndex= sourceModel()->index(sourceRow, 5, sourceParent);

   // QString name= sourceModel()->data(nameIndex).toString();

    //QModelIndex dataIndex = sourceModel()->index(sourceRow, 7, sourceParent);
    //QString func= sourceModel()->data(dataIndex,Qt::UserRole+FUNCTIONNAME).toString();
    // QRegExp regExp("SAL");

    //qDebug()<< sourceRow  << " " <<func << " "<< func.contains(regExp)<<funcV;
    //qDebug()<< sourceRow  << " " <<func2 << " "<< func2.contains(regExp);

   // qDebug()<<func.contains(regExp);

   // return (func.contains(regExp));
   //return (func.contains(regExp));
    return true;
}

