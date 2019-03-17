#include "modelservisetext.h"
#include <QDebug>


ModelServiseText::ModelServiseText(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type):ModelServiseBaseClass(m_worker, m_type)
{
    this->child = this;
    //fillModel();
    qDebug()<< "create ModelServiseText";

}

void ModelServiseText::data_model_handler(QStringList & list)
{
   // qDebug()<< "ModelServiseText data_model_handler";
    //beginResetModel();
    if (list.size() !=8){return ;}
    this->v_data.append(list);
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
     //emit dataChanged(index, index, { role });
        emit dataChanged(index, index);
}



QHash<int, QByteArray> ModelServiseText::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole+DATE, "date");
    roles.insert(Qt::UserRole+TIME, "time");
    roles.insert(Qt::UserRole+COUNT, "count");
    roles.insert(Qt::UserRole+ZONE, "zone");
    roles.insert(Qt::UserRole+SERVICENAME, "serviceName");
    roles.insert(Qt::UserRole+FUNCTIONNAME, "functionName");
    roles.insert(Qt::UserRole+LINENUMBER, "lineNumber");
    roles.insert(Qt::UserRole+MESSAGE, "message");
    return roles;
}

QVariant ModelServiseText::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role)
    {
    case Qt::UserRole+DATE: return this->v_data.at(index.row()).at(0);
    case Qt::UserRole+TIME: return this->v_data.at(index.row()).at(1);
    case Qt::UserRole+COUNT: return this->v_data.at(index.row()).at(2);
    case Qt::UserRole+ZONE: return this->v_data.at(index.row()).at(3);
    case Qt::UserRole+SERVICENAME: return this->v_data.at(index.row()).at(4);
    case Qt::UserRole+FUNCTIONNAME: return this->v_data.at(index.row()).at(5);
    case Qt::UserRole+LINENUMBER: return this->v_data.at(index.row()).at(6);
    case Qt::UserRole+MESSAGE: return this->v_data.at(index.row()).at(7);
    }

    return QVariant();
}


void ModelServiseText::fillModel()
{
    QStringList list;
    for (int i =0; i<8; i++)
    {

        list.clear();
        for (int j =0; j<8; j++)
        {
            list.append(QString::number(j));
        }
        this->v_data.append(list);


    }
}
