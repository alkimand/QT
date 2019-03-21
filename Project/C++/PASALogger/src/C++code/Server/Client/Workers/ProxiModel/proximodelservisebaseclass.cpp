#include "proximodelservisebaseclass.h"
#include <QDebug>

ProxiModelServiseBaseClass::ProxiModelServiseBaseClass(WorkerBaseClass * m_worker,  CLIENT_TYPE const  & m_type)
{
    worker = static_cast<WorkerBaseClass*>(m_worker);
    type = m_type;
    parent = this;


    qDebug()<< "ProxiModelServiseBaseClass loaded";
}

ProxiModelServiseBaseClass::~ProxiModelServiseBaseClass()
{
    qDebug()<< "~ProxiModelServiseBaseClass()";
}

