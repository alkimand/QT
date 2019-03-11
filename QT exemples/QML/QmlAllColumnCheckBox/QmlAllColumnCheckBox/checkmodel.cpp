#include "checkmodel.h"

#include <QtDebug>

CheckModel::CheckModel(QObject *parent) : QAbstractTableModel (parent)
{
  fillModel();
}

QHash<int, QByteArray> CheckModel::roleNames() const
{
  QHash<int, QByteArray> roles;
  roles.insert(Qt::UserRole+CHECK, "check");
  roles.insert(Qt::UserRole+DESCRIPTION, "description");
  roles.insert(Qt::UserRole+VALUE, "value");
  return roles;
}

QVariant CheckModel::data(const QModelIndex &index, int role) const
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

void CheckModel::setAllChecked(bool value)
{
  beginResetModel();
  qDebug() << 1;
  for (SomeStruct &s : list) {
      s.check = value;
      qDebug() << value;
    }
  endResetModel();
}

void CheckModel::setRowChecked(int row, bool value)
{
  if (row < 0 || row >= list.count())
    return;
  SomeStruct &s = list[row];
  s.check = value;
  emit dataChanged(index(row,0), index(row, columnCount()-1));
}

void CheckModel::fillModel()
{
  SomeStruct one = {true, "Some definition", 100};
  SomeStruct two = {false, "Some definition again", 200};
  SomeStruct three = {true, "Definition", 1000};
  list << one << two << three;
}

