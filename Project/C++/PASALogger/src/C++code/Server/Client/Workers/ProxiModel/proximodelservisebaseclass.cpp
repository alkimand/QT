#include "proximodelservisebaseclass.h"
#include <QRegExp>
#include <QDebug>

ProxiModelServiseBaseClass::ProxiModelServiseBaseClass(WorkerBaseClass * m_worker, ModelServiseBaseClass * m_model, CLIENT_TYPE const  & m_type)
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

