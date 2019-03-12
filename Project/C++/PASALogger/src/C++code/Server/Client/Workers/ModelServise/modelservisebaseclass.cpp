#include "modelservisebaseclass.h"
#include <QDebug>

ModelServiseBaseClass::ModelServiseBaseClass(WorkerBaseClass * m_worker,  CLIENT_TYPE const  & m_type)
{
    worker = static_cast<WorkerBaseClass*>(m_worker);
    type = m_type;
    parent = this;


    qDebug()<< "ModelServiseBaseClass loaded";
}

