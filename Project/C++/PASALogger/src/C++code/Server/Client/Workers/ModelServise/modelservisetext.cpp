#include "modelservisetext.h"
#include <QDebug>
#include <QTime>

ModelServiseText::ModelServiseText(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type):ModelServiseBaseClass(m_worker, m_type)
{
    this->child = this;
    //fillModel();

    qDebug()<< "create ModelServiseText";

}

void ModelServiseText::data_model_handler(QStringList & list)
{
    if (list.size() !=8){return ;}
    QStringList tempStringList;
    int size =l_data.size();
    tempStringList.append(QString::number(size));
    tempStringList.append("false");
    for (int i =0; i<8;i++)
    {
        tempStringList.append(list.at(i));
    }
    beginInsertRows(QModelIndex(),size,size);
    this->l_data.append(tempStringList);
    endInsertRows();
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    emit dataChanged(index, index);
}

ModelServiseText::~ModelServiseText()
{
    qDebug()<< "~ModelServiseText()";
}



QHash<int, QByteArray> ModelServiseText::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole+ROW, "row");
    roles.insert(Qt::UserRole+CHECK, "check");
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
    case Qt::UserRole+ROW: return this->l_data.at(index.row()).at(0);
    case Qt::UserRole+CHECK: return this->l_data.at(index.row()).at(1);
    case Qt::UserRole+DATE: return this->l_data.at(index.row()).at(2);
    case Qt::UserRole+TIME: return this->l_data.at(index.row()).at(3);
    case Qt::UserRole+COUNT: return this->l_data.at(index.row()).at(4);
    case Qt::UserRole+ZONE: return this->l_data.at(index.row()).at(5);
    case Qt::UserRole+SERVICENAME: return this->l_data.at(index.row()).at(6);
    case Qt::UserRole+FUNCTIONNAME: return this->l_data.at(index.row()).at(7);
    case Qt::UserRole+LINENUMBER: return this->l_data.at(index.row()).at(8);
    case Qt::UserRole+MESSAGE: return this->l_data.at(index.row()).at(9);
    }

    return QVariant();
}

void ModelServiseText::fillModel()
{
    QStringList list;
    int size =l_data.size();
    list.append(QString::number(size));
    list.append("");
    list.append(QDate::currentDate().toString("MM/dd/yy"));
    list.append(QTime::currentTime().toString("HH:mm:ss"));
    list.append("");
    list.append("");
    list.append("");
    list.append("Open file");
    list.append("");
    list.append("");
    //list.append(fileName);//no valid yet
    beginInsertRows(QModelIndex(),size,size);
    this->l_data.append(list);
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    emit dataChanged(index, index);
    endInsertRows();
}


