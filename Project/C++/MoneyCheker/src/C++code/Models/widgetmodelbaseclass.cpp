#include "widgetmodelbaseclass.h"
#include "RowItem.h"
#include <QDebug>
#include <QVector>

WidgetModelBaseClass::WidgetModelBaseClass()
{
   //RowItem *row_1 = new RowItem();
   QSharedPointer<RowItem> obj =
                      QSharedPointer<RowItem>(new RowItem);
   rows.push_back(obj);

   QSharedPointer<RowItem> obj_ =
                      QSharedPointer<RowItem>(new RowItem);
   rows.push_back(obj_);

}


QHash<int, QByteArray> WidgetModelBaseClass::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole+FIRST_TEXT, "first_text_");
    roles.insert(Qt::UserRole+VALUE, "value_");
    return roles;
}

//RowItem WidgetModelBaseClass::IdemData(const QModelIndex &index, int role) const
//{
//    //    if (!index.isValid())
//    //        return QVariant();
//    //    switch (role)
//    //    {
//    //    case Qt::UserRole+FIRST_TEXT: return 0;//QVariant (this->rows.at(index.row()));
//    //   // case Qt::UserRole+VALUE: return this->l_data.at(index.row()).at(1);
//    //        break;
//    //    }

//        return QVariant();

//}


QVariant WidgetModelBaseClass::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role)
    {
    case Qt::UserRole+FIRST_TEXT: return this->rows.at(index.row()).get()->textFirstRow();
                                                      // ndex.row()).textFirstRow();
    case Qt::UserRole+VALUE: return QVariant(25);
        break;
    }

    return QVariant();
}

WidgetModelBaseClass::~WidgetModelBaseClass()
{
    qDebug()<< "~WidgetModelBaseClass()";
}
