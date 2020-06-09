#include "ItemModelBase.h"
#include "AbstractItem.h"
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QTextStream>

ItemModelBase::ItemModelBase(QObject *parent){
    //parentModel_ = this;
    // modelType_ = modelType
    //setupWidgetModel();

    QString path = QDir::currentPath();
    QString fileName = "test.txt";
    QString fullFilePath = path  + "/" + fileName;
    SetupModel();

}


//ItemModelBase::ItemModelBase(QObject *parent)
//{

//}

void ItemModelBase::setPropertyMap() {
    /*
    if (childModel_)
        childModel_->setupDefaultPropertyMap();*/
}

int ItemModelBase::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return worksheet_data_.size();

}

int ItemModelBase::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return DATE_MAP_SIZE;//worksheet_data_.size(); //TODO
}

QHash<int, QByteArray> ItemModelBase::roleNames() const {
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole + DATA_ID::FEATURE, FEATURE_S);
    roles.insert(Qt::UserRole + DATA_ID::NAME, NAME_S);
    roles.insert(Qt::UserRole + DATA_ID::IS_ACTIVE, IS_ACTIVE_S);
    roles.insert(Qt::EditRole, EDITE_S);

   // return { {Qt::DisplayRole, "display"} };
    //roles.insert(Qt::DisplayRole, "display");
    roles.insert(Qt::DisplayRole, DISPLAY_S);
    //roles.insert(Qt::UserRole + DATA_ID::DISPLAY, DISPLAY_S);
    return roles;
}

Qt::ItemFlags ItemModelBase::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if(index.isValid()){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

QVariant ItemModelBase::headerData(int section, Qt::Orientation orientation, int role) const {
    Q_UNUSED(orientation);
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    switch (section) {
    case int(DATA_ID::FEATURE):
        return tr(FEATURE_S);
        break;
    case int(DATA_ID::NAME):
        return tr(NAME_S);
        break;
    case int(DATA_ID::IS_ACTIVE):
        return tr(IS_ACTIVE_S);
        break;
    }
    return QVariant();
}


QVariant ItemModelBase::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    QVariant result;
    switch (role) {
//    case (int(Qt::UserRole + DATA_ID::FEATURE)):
//    case (int(Qt::UserRole + DATA_ID::NAME)):
//    case (int(Qt::UserRole + DATA_ID::IS_ACTIVE)):
//        if (worksheet_data_.size() > index.row()
//                && worksheet_data_.at(index.row()).contains(DATA_ID(role - int(Qt::UserRole)))
//                && index.column() < 4) {
//            result = worksheet_data_.at(index.row()).value(DATA_ID(role - int(Qt::UserRole)));
//             //qDebug()<< "data" + result.toString();
//           // return worksheet_data_.at(index.row()).value(DATA_ID(role - int(Qt::UserRole)));
//        }
//        break;

    case (int(Qt::DisplayRole)):
       // result = worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
       // result = worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        //return worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        result =  worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
                //QString("%1, %2").arg(index.column()).arg(index.row());
        break;

     case (int(Qt::UserRole + DATA_ID::DISPLAY)):
      result = worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
      break;

    }
    QString temp =  QString::number(index.row())+" " +  QString::number(index.column());//index.row();
    //qDebug()<< "data " + temp + " =" + result.toString();
    return result;
}

bool ItemModelBase::setData(const QModelIndex &index, const QVariant &value, int role) {
    bool result = false;
   // qDebug()<< "setData"+value.toString();
    if (index.isValid() && role==Qt::EditRole) {
        switch (role){
        //case Qt::EditRole:
        //    case (int(Qt::UserRole + DATA_ID::FEATURE)):
        //    case (int(Qt::UserRole + DATA_ID::NAME)):
        //    case (int(Qt::UserRole + DATA_ID::IS_ACTIVE)):
        //        if (worksheet_data_.size() > index.row()) {
        //            if(worksheet_data_.at(index.row()).contains(DATA_ID(role - int(Qt::UserRole)))) {
        //                worksheet_data_[index.row()][DATA_ID(role - int(Qt::UserRole))] = value.toString();
        //            }
        //            else {
        //                Date_Map temp (worksheet_data_.at(index.row()));
        //                temp[DATA_ID(role - int(Qt::UserRole))] = value.toString();
        //                worksheet_data_.replace(index.row(), temp);
        //            }
        //        }
        //        else {
        //            Date_Map temp;
        //            temp[DATA_ID(role - int(Qt::UserRole))] = value.toString();
        //            worksheet_data_.insert(index.row(), temp);
        //        }

        //        result = true;
        //        break;
        case (int(Qt::EditRole)):
            if (worksheet_data_.size() > index.row()) {
                if(worksheet_data_.at(index.row()).contains(DATA_ID(index.column()))) {
                    worksheet_data_[index.row()][DATA_ID(index.column())] = value.toString();
                }
                else {
                    Date_Map temp (worksheet_data_.at(index.row()));
                    temp[DATA_ID(index.column())] = value.toString();
                    worksheet_data_.replace(index.row(), temp);
                }
            }
            else {
                Date_Map temp;
                temp[DATA_ID(index.column())] = value.toString();
                worksheet_data_.insert(index.row(), temp);
            }

            //emit dataChanged(index, index);
            result = true;
            break;


            //default
            //:return  QSqlTableModel::setData(index,value,Qt::EditRole);



            // case (int(Qt::UserRole + DATA_ID::FEATURE)):
            //                else {

            //                }


            // worksheet_data_.at(index.row())

            // .insert("plenty", 2000);
            //return value(DATA_ID(role - int(Qt::UserRole)));
            //}
        }
 QString temp =  QString::number(index.row())+" " +  QString::number(index.column());
  //qDebug()<< "setdata " + temp + " =" + value.toString();
    }
    return result;
}

ItemModelBase::~ItemModelBase() {
    qDebug()<< "~ItemModelBase()";
}

void ItemModelBase::SetupModel() {
    int m[6] = {0, 1, 2, 3, 4, 5};
    int count = 0;
    int c[3] = {0, 1, 2};
    for (int &i : m){
        Date_Map temp;
        for (int &j : c) {
            temp[DATA_ID(j)]= QVariant(count++).toString();
        }
        worksheet_data_.push_back(temp);
    }
}