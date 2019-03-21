#include "proximodelserviseudp.h"
#include <QDebug>

ProxiModelServiseUDP::ProxiModelServiseUDP(WorkerBaseClass * m_worker,  ModelServiseBaseClass * m_model, CLIENT_TYPE const  & m_type):ProxiModelServiseBaseClass(m_worker, m_model, m_type)
{

    this->child = this;
    qDebug()<< "ProxiModelServiseUDP";
}

ProxiModelServiseUDP::~ProxiModelServiseUDP()
{
    qDebug()<< "~ProxiModelServiseUDP()";
}

