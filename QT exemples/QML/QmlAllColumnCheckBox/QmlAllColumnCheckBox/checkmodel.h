#ifndef CHECKMODEL_H
#define CHECKMODEL_H

#include <QAbstractTableModel>

struct SomeStruct
{
    bool check;
    QString description;
    int value;
};

class CheckModel : public QAbstractTableModel
{
Q_OBJECT

  enum Roles
      {
          CHECK, DESCRIPTION, VALUE
      };

public:
  CheckModel(QObject* parent = nullptr);
  int rowCount(const QModelIndex &parent = QModelIndex()) const {
    Q_UNUSED(parent); return list.count();
  }
  int columnCount(const QModelIndex &parent = QModelIndex()) const {
    Q_UNUSED(parent); return 3;
  }
  QHash<int, QByteArray> roleNames() const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  Q_INVOKABLE void setAllChecked(bool value);
  Q_INVOKABLE void setRowChecked(int row, bool value);

private:
  void fillModel();

  QVector<SomeStruct> list;
};

#endif // CHECKMODEL_H
