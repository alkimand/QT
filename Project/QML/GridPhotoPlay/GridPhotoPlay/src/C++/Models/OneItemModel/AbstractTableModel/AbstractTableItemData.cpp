#include "AbstractTableItemData.h"
#include <QDebug>

#include <QFileDialog>
#include <QTextStream>

static const char className[] = "AbstractTableItemData::";


AbstractTableItemData::AbstractTableItemData(QObject *parent):QAbstractTableModel(parent){
    //Q_UNUSED(parent);
    //parentModel_ = this;
    // modelType_ = modelType
    //setupWidgetModel();

   // QString path = QDir::currentPath();
   // QString fileName = "test.txt";
   // QString fullFilePath = path  + "/" + fileName;
    //SetupModel();

}


int AbstractTableItemData::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    //if (tiles_->size() > 0)
//        return tiles_->size();
    return 0;
}

int AbstractTableItemData::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    //if (tiles_->size() > 0)
     //   return tiles_->at(0).size();
    return 0;
}

QHash<int, QByteArray> AbstractTableItemData::roleNames() const {
    //QHash<int, QByteArray> roles;
    //    roles.insert(Qt::UserRole + DATA_ID::FEATURE, FEATURE_S);
    //    roles.insert(Qt::UserRole + DATA_ID::FEATURE_NAME, FEATURE_NAME_S);//FEATURE_NAME_S
    //    roles.insert(Qt::UserRole + DATA_ID::IS_ACTIVE, IS_ACTIVE_S);
    return { {Qt::DisplayRole, "display"} };
   // roles.insert(Qt::EditRole, EDITE_S);
   // roles.insert(Qt::DisplayRole, DISPLAY_S);
   // return roles;
}

Qt::ItemFlags AbstractTableItemData::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if(index.isValid()){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

QVariant AbstractTableItemData::headerData(int section, Qt::Orientation orientation, int role) const {
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


QVariant AbstractTableItemData::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    QVariant result;
    switch (role) {
    case Qt::DisplayRole:
            return QString("%1, %2").arg(index.column()).arg(index.row());
        case (int(Qt::UserRole + DATA_ID::ICON)):

//            if (tiles_->size() > index.row()
//                && tiles_->at(index.row()).contains(DATA_ID(role - int(Qt::UserRole)))
//                    && index.column() < 4) {
//                result = worksheet_data_.at(index.row()).value(DATA_ID(role - int(Qt::UserRole)));
//                 //qDebug()<< "data" + result.toString();
//               // return worksheet_data_.at(index.row()).value(DATA_ID(role - int(Qt::UserRole)));
//            }
            break;

   // case (int(Qt::DisplayRole)):
        // result = worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        // result = worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        //return worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
       // result =  worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        //QString("%1, %2").arg(index.column()).arg(index.row());
     //   break;

    case (int(Qt::UserRole + MODEL_ROLES::DISPLAY)):
       // result = worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        break;

    }
    QString temp =  QString::number(index.row())+" " +  QString::number(index.column());//index.row();
    //qDebug()<< "data " + temp + " =" + result.toString();
    return temp;
        //result;
}

void AbstractTableItemData::setupModel( QList<QList <QSharedPointer<Tile>>>  tiles){
    tiles_ = &tiles;
    LOOGGER("+");
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
        //qDebug() << QString::fromUtf8(it->first.c_str())<< "=" <<QString::fromUtf8(it->second.c_str());
        //++it;
 //   }
//    if (!worksheet_data_.isEmpty() && size ==3){

//        std::sort(worksheet_data_.begin(), worksheet_data_.end(), [] (Date_Map lh, Date_Map rh)
//         {return lh[DATA_ID::FEATURE_NAME] < 2;});

//       // qSort(worksheet_data_->begin(), sworksheet_data_end(), prefLessThan);

//    }
}

//void AbstractTableItemData::removeRow(const int row) {
//    worksheet_data_.remove(row);
//}

//void AbstractTableItemData::addRow(const int row){
//    Date_Map map;
//    map[DATA_ID::FEATURE] = QVariant("");
//    map[DATA_ID::FEATURE_NAME]= QVariant("");
//    map[DATA_ID::IS_ACTIVE] = "0";
//    worksheet_data_.insert(row + 1,map);
//}

//void AbstractTableItemData::copyRow(const int row){
//    Date_Map map = worksheet_data_.at(row);
//    worksheet_data_.insert(row + 1, map);
//}


bool AbstractTableItemData::setData(const QModelIndex &index, const QVariant &value, int role) {
    bool result = false;
    // qDebug()<< "setData"+value.toString();
    if (index.isValid() && role==Qt::EditRole) {
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
    }
    return result;
}

AbstractTableItemData::~AbstractTableItemData() {
    //  qDebug()<< "~AbstractTableItemData()";
}

//void AbstractTableItemData::SetupModel() {
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

void AbstractTableItemData::cleanModelData(){
    //LOOGGER("+");
    //worksheet_data_.clear();
}

//QVector<Date_Map> *AbstractTableItemData::getData(){
//    return &worksheet_data_;
//}
