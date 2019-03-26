#include "proximodelservisebaseclass.h"
#include <QRegExp>
#include <QDebug>

ProxiModelServiseBaseClass::ProxiModelServiseBaseClass(WorkerBaseClass * m_worker, CLIENT_TYPE const  & m_type)
{
    worker = static_cast<WorkerBaseClass*>(m_worker);
    type = m_type;
    parent = this;






    //model = m_model;



    // QRegExp *regExp  = r_filters.at(7);//const_cast<QRegExp *>( r_filters.at(7));



    qDebug()<< "ProxiModelServiseBaseClass loaded";

}

ProxiModelServiseBaseClass::~ProxiModelServiseBaseClass()
{
    qDebug()<< "~ProxiModelServiseBaseClass()";
}

void ProxiModelServiseBaseClass::filterChanged(const int &column, const QString &text)
{
    //qDebug()<< "ProxiModelServiseBaseClass() filterChanged column:"  << column << "text:" << text ;

     QRegExp regExp(text);
     regExp.setCaseSensitivity(Qt::CaseInsensitive);
     regExp.setPatternSyntax(QRegExp::RegExp);
     if (column > -1 && column < sourceModel()->columnCount())
     r_filters.replace(column,regExp);
     this->invalidateFilter();

}

