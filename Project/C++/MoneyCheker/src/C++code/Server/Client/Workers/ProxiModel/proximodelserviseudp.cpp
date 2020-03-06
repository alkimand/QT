#include "proximodelserviseudp.h"
#include "modelservisetext.h"
#include "modelserviseudp.h"
#include "modelservisebaseclass.h"
#include <QDebug>

ProxiModelServiseUDP::ProxiModelServiseUDP(WorkerBaseClass * m_worker, CLIENT_TYPE const  & m_type):ProxiModelServiseBaseClass(m_worker, m_type)
{

    this->child = this;
    qDebug()<< "ProxiModelServiseUDP";

    this-> model = static_cast<ModelServiseUDP*> (this-> worker->getModeltoQMLService());

    QRegExp regExp("");
    for (int i=0; i< model->columnCount(); i++)
    {
        //QRegExp regExp("(\\d+)");
        QRegExp regExp("");
        regExp.setCaseSensitivity(Qt::CaseInsensitive);
        regExp.setPatternSyntax(QRegExp::RegExp);
        r_filters.append(regExp);
    }



    this->setSourceModel(model);


//      QRegExp regExp2("SAL");
//      r_filters.replace(7,regExp2);

//      regExp2.setPattern("sa_vp4");
//      r_filters.replace(6,regExp2);







}

ProxiModelServiseUDP::~ProxiModelServiseUDP()
{
    qDebug()<< "~ProxiModelServiseUDP()";
}

bool ProxiModelServiseUDP::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
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
    return true;
}

