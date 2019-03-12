#include "modelserviseudp.h"
#include <QDebug>


ModelServiseUDP::ModelServiseUDP(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type):ModelServiseBaseClass(m_worker, m_type)
{
    this->child = this;
    fillModel();
     qDebug()<< "create ModelServiseUDP";

 }

  QHash<int, QByteArray> ModelServiseUDP::roleNames() const
  {
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole+CHECK, "check");
    roles.insert(Qt::UserRole+DESCRIPTION, "description");
    roles.insert(Qt::UserRole+VALUE, "value");
    return roles;
  }

  QVariant ModelServiseUDP::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();

    SomeStruct s = list.at(index.row());
    switch (role) {
      case Qt::UserRole+CHECK: return s.check;
      case Qt::UserRole+DESCRIPTION: return s.description;
      case Qt::UserRole+VALUE: return s.value;
      }

    return QVariant();
  }

  void ModelServiseUDP::setAllChecked(bool value)
  {
    beginResetModel();
    qDebug() << 1;
    for (SomeStruct &s : list) {
        s.check = value;
        qDebug() << value;
      }
    endResetModel();
  }

  void ModelServiseUDP::setRowChecked(int row, bool value)
  {
    if (row < 0 || row >= list.count())
      return;
    SomeStruct &s = list[row];
    s.check = value;
    emit dataChanged(index(row,0), index(row, columnCount()-1));
  }

  void ModelServiseUDP::fillModel()
  {
    SomeStruct one = {true, "Some definition", 100};
    SomeStruct two = {false, "Some definition again", 200};
    SomeStruct three = {true, "Definition", 1000};
    list << one << two << three;
  }
