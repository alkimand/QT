#include "Item/AbstractTableModel/ItemModelBase.h"
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QTextStream>



static const char className[] = "ItemModelBase::";


ItemModelBase::ItemModelBase(TileMatrix *tiles_matrix, QObject *parent):QAbstractTableModel(parent) ,tiles_matrix_(tiles_matrix) {
    Q_UNUSED(parent);
    size_.first = tiles_matrix_->size();
    size_.second = tiles_matrix_[0].size();

    //origin_coordinates_ = tiles_matrix_->at(index.row()).at(index.column()).get()->getOriginCoordinates();


}

//ItemModelBase::ItemModelBase(QObject *parent)
//{

//}


int ItemModelBase::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return size_.first;
}

int ItemModelBase::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return size_.second;
}

QHash<int, QByteArray> ItemModelBase::roleNames() const {
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole + MODEL_ROLES::IMAGE_SOURCE, IMAGE_SOURCE_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::BORDER_SOURCE, BORDER_SOURCE_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ID, ID_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ORIGIN_X, ORIGIN_X_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ORIGIN_Y, ORIGIN_Y_S);
    //    roles.insert(Qt::UserRole + DATA_ID::IS_ACTIVE, IS_ACTIVE_S);
    //roles.insert(Qt::EditRole, EDITE_S);
    //roles.insert(Qt::DisplayRole, DISPLAY_S);
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
        return tr(FEATURE_NAME_S);
        break;
        //    case int(DATA_ID::IS_ACTIVE):
        //        return tr(IS_ACTIVE_S);
        //        break;
    }
    return QVariant();
}


QVariant ItemModelBase::data(const QModelIndex &index, int role) const {
    //qDebug()<< "data2= " + QString::number(index.row()) +"_" + QString::number(index.column());
    if (!index.isValid())
        return QVariant();

    QVariant result;
    QString pixmap_controller_template = "image://" + QString("%1") + "/" + tiles_matrix_->at(index.row()).at(index.column()).get()->getSIndex();
    switch (role) {
        //    //    case (int(Qt::UserRole + DATA_ID::FEATURE)):
        //    //    case (int(Qt::UserRole + DATA_ID::NAME)):
        //    //    case (int(Qt::UserRole + DATA_ID::IS_ACTIVE)):
        //    //        if (worksheet_data_.size() > index.row()
        //    //                && worksheet_data_.at(index.row()).contains(DATA_ID(role - int(Qt::UserRole)))
        //    //                && index.column() < 4) {
        //    //            result = worksheet_data_.at(index.row()).value(DATA_ID(role - int(Qt::UserRole)));
        //    //             //qDebug()<< "data" + result.toString();
        //    //           // return worksheet_data_.at(index.row()).value(DATA_ID(role - int(Qt::UserRole)));

    case (int(Qt::UserRole + MODEL_ROLES::IMAGE_SOURCE)):
        result = pixmap_controller_template.arg(QString(TILE_BODY_IMAGE_PROVIDER));
        // (TILE_BODY_IMAGE_PROVIDER) + "/" + QString::number(index.row())+"_" +  QString::number(index.column());//index.row();
        break;

    case (int(Qt::UserRole + MODEL_ROLES::BORDER_SOURCE)):
        result = pixmap_controller_template.arg(QString(TILE_BORDER_IMAGE_PROVIDER));
        break;
    case (int(Qt::UserRole + MODEL_ROLES::ID)):
        result = tiles_matrix_->at(index.row()).at(index.column()).get()->getSIndex();
        break;
    case (int(Qt::UserRole + MODEL_ROLES::ORIGIN_X)):
        result = tiles_matrix_->at(index.row()).at(index.column()).get()->getOriginCoordinates().first;
        break;
    case (int(Qt::UserRole + MODEL_ROLES::ORIGIN_Y)):
        result = tiles_matrix_->at(index.row()).at(index.column()).get()->getOriginCoordinates().second;
        break;
    }
    //qDebug()<< "data= " + temp;
    //ring temp =  QString::number(index.row())+"_" +  QString::number(index.column());//index.row();
    //    //qDebug()<< "data " + temp + " =" + result.toString();
    return result;
}

//void ItemModelBase::createModel(const FileData &map){
//    //LOOGGER("+");
//    int size=0;
//    std::map<std::string, std::string>::const_iterator it;
//    it = map.begin();
//    map.begin();
//    while (it != map.end()){
//        QStringList text = QString::fromUtf8(it->first.c_str()).split(".");
//        Date_Map map;
//        if (text.size() > 1){
//            size = 3;
//            map[DATA_ID::FEATURE] = QVariant(text.at(0));
//            map[DATA_ID::FEATURE_NAME] = QVariant(text.at(1));
//            map[DATA_ID::IS_ACTIVE] = QVariant(QString::fromUtf8(it->second.c_str()));
//        }
//        else {
//            size = 2;
//            map[DATA_ID::FEATURE] = QVariant(text.at(0));
//            map[DATA_ID::FEATURE_NAME] = QVariant(QString::fromUtf8(it->second.c_str()));
//            column_count_ = 2 ;
//            // map[DATA_ID::IS_ACTIVE] = QVariant(QString(""));
//        }
//        worksheet_data_.append(map);
//        //qDebug() << QString::fromUtf8(it->first.c_str())<< "=" <<QString::fromUtf8(it->second.c_str());
//        ++it;
//    }
////    if (!worksheet_data_.isEmpty() && size ==3){

////        std::sort(worksheet_data_.begin(), worksheet_data_.end(), [] (Date_Map lh, Date_Map rh)
////         {return lh[DATA_ID::FEATURE_NAME] < 2;});

////       // qSort(worksheet_data_->begin(), sworksheet_data_end(), prefLessThan);

////    }
//}




bool ItemModelBase::setData(const QModelIndex &index, const QVariant &value, int role) {
    bool result = true;
    //    // qDebug()<< "setData"+value.toString();
    //    if (index.isValid() && role==Qt::EditRole) {
    //        switch (role){
    //        case (int(Qt::EditRole)):
    //            if (worksheet_data_.size() > index.row()) {
    //                if(worksheet_data_.at(index.row()).contains(DATA_ID(index.column()))) {
    //                    worksheet_data_[index.row()][DATA_ID(index.column())] = value.toString();
    //                }
    //                else {
    //                    Date_Map temp (worksheet_data_.at(index.row()));
    //                    temp[DATA_ID(index.column())] = value.toString();
    //                    worksheet_data_.replace(index.row(), temp);
    //                }
    //            }
    //            else {
    //                Date_Map temp;
    //                temp[DATA_ID(index.column())] = value.toString();
    //                worksheet_data_.insert(index.row(), temp);
    //            }

    //            //emit dataChanged(index, index);
    //            result = true;
    //            break;
    //        }
    //        QString temp =  QString::number(index.row())+" " +  QString::number(index.column());
    //        //qDebug()<< "setdata " + temp + " =" + value.toString();
    //    }
    return result;
}

ItemModelBase::~ItemModelBase() {
    //  qDebug()<< "~ItemModelBase()";
}

//void ItemModelBase::SetupModel() {
//    int m[6] = {0, 1, 2, 3, 4, 5};
//    int count = 0;
//    int c[3] = {0, 1, 2};
//    for (int &i : m){
//        Q_UNUSED(i);
//        Date_Map temp;
//        for (int &j : c) {
//            temp[DATA_ID(j)]= QVariant(count++).toString();
//        }
//        worksheet_data_.push_back(temp);
//    }
//}



