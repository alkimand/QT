#ifndef MODELSERVISEUDP_H
#define MODELSERVISEUDP_H
#include "modelservisebaseclass.h"

#include <QObject>

struct SomeStruct
{
    bool check;
    QString description;
    int value;
};

class ModelServiseUDP: public ModelServiseBaseClass
{
//    enum TableRoles{
//        TableDataRole = Qt::UserRole + 1,
//        HeadingRole
//    };

    enum Roles
        {
            CHECK, DESCRIPTION, VALUE
        };

Q_OBJECT


public:
     explicit  ModelServiseUDP();//WorkerBaseClass *, CLIENT_TYPE const &);
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

signals:

public slots:
private:
    //QVector<QVector<QString>> table;
    void fillModel();

 QVector<SomeStruct> list;
};

#endif // MODELSERVISEUDP_H
