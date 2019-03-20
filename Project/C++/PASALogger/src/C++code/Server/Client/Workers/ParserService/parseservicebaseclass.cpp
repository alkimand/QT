#include "parseservicebaseclass.h"
#include <QDebug>
#include <QDataStream>

ParseServiceBaseClass::ParseServiceBaseClass(WorkerBaseClass * m_worker,  CLIENT_TYPE const  & m_type)
{
    worker = static_cast<WorkerBaseClass*>(m_worker);
    type = m_type;
    parent = this;
}

ParseServiceBaseClass::~ParseServiceBaseClass()
{
    qDebug()<< "~ParseServiceBaseClass()";
}

