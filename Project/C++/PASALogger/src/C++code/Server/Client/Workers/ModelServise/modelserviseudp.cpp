#include "modelserviseudp.h"
#include <QDebug>


ModelServiseUDP::ModelServiseUDP(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type):ModelServiseBaseClass(m_worker, m_type)
{
    this->child = this;
    //fillModel();
    qDebug()<< "create ModelServiseUDP";

}

void ModelServiseUDP::data_model_handler(QStringList & list)
{
    beginResetModel();
    if (list.size() !=8){return ;}
    this->v_data.append(list);
   // QModelIndex startIndex=createIndex(0, 0);
    //QModelIndex stopIndex=createIndex(v_data.size(), 8 );
    //emit dataChanged(startIndex, stopIndex);
    //QStringList lst = this->v_data.last();
    //auto topLeftIndex = createIndex(0, 0, m_root.get());

     //emit dataChanged(createIndex(0,0),createIndex(v_data.size(),7));
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
     //emit dataChanged(index, index, { role });
        emit dataChanged(index, index);
    //emit dataChanged(index, index, Qt::EditRole);
     //qDebug()<< "data add" << list.first();
     endResetModel();
}



QHash<int, QByteArray> ModelServiseUDP::roleNames() const
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

QVariant ModelServiseUDP::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    //SomeStruct s = v_data.at(index.row());
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

//  void ModelServiseUDP::setAllChecked(bool value)
//  {
//    beginResetModel();
//    qDebug() << 1;
//    for (SomeStruct &s : list) {
//        s.check = value;
//        qDebug() << value;
//      }
//    endResetModel();
//  }

//  void ModelServiseUDP::setRowChecked(int row, bool value)
//  {
//    if (row < 0 || row >= list.count())
//      return;
//    SomeStruct &s = list[row];
//    s.check = value;
//    emit dataChanged(index(row,0), index(row, columnCount()-1));
//  }

void ModelServiseUDP::fillModel()
{
    //    SomeStruct one = {true, "Some definition", 100};
    //    SomeStruct two = {false, "Some definition again", 200};
//    //    SomeStruct three = {true, "Definition", 1000};
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
