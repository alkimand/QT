#include "modelservisebaseclass.h"
#include <QDebug>

ModelServiseBaseClass::ModelServiseBaseClass(WorkerBaseClass * m_worker,  CLIENT_TYPE const  & m_type)
{
    worker = static_cast<WorkerBaseClass*>(m_worker);
    type = m_type;
    parent = this;


    qDebug()<< "create ModelServiseBaseClass";
}

ModelServiseBaseClass::~ModelServiseBaseClass()
{
    qDebug()<< "~ModelServiseBaseClass()";
}


void ModelServiseBaseClass::saveAs()
{
    qDebug()<< "ModelServiseBaseClass::saveAs()";


}

void ModelServiseBaseClass::clearDataPool()
{
    //qDebug()<< "ModelServiseUDP::clearDataPool()";
    beginResetModel();
    this->v_data.clear();
    endResetModel();
}
