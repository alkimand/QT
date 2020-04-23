#ifndef WIDGETMODELBASECLASS_H
#define WIDGETMODELBASECLASS_H
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "RowItem.h"
#include "props.h"
#include <QSharedPointer>

class WidgetModelBaseClass : public QAbstractTableModel
{
    enum Roles
        {
            FIRST_TEXT, VALUE
        };


     Q_OBJECT
public:
    WidgetModelBaseClass();



    int rowCount(const QModelIndex &parent = QModelIndex()) const {
      Q_UNUSED(parent); return rows.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const {
      Q_UNUSED(parent); return 1;
    }

        QHash<int, QByteArray> roleNames() const;
       QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        //RowItem IdemData(const QModelIndex &index, int role = Qt::DisplayRole) const;



    QVector <QSharedPointer<RowItem>>  rows;
    QVector <int> rtt;

     virtual ~WidgetModelBaseClass();
protected:
    Props::e_ModelType type;





};

#endif // WIDGETMODELBASECLASS_H
