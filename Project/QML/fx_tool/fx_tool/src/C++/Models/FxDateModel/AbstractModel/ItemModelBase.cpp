#include "ItemModelBase.h"
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QTextStream>

static const char className[] = "ItemModelBase::";

ItemModelBase::ItemModelBase(QObject *parent):QAbstractTableModel(parent){
    Q_UNUSED(parent);

    QString path = QDir::currentPath();
    QString fileName = "test.txt";
    QString fullFilePath = path  + "/" + fileName;
}


int ItemModelBase::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return worksheet_data_.size();
}

int ItemModelBase::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return column_count_;
}

QHash<int, QByteArray> ItemModelBase::roleNames() const {
    QHash<int, QByteArray> roles;
    roles.insert(Qt::EditRole, EDITE_S);
    roles.insert(Qt::DisplayRole, DISPLAY_S);
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
    }
    return QVariant();
}


QVariant ItemModelBase::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    QVariant result;
    switch (role) {
    case (int(Qt::DisplayRole)):
        result =  worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        //QString("%1, %2").arg(index.column()).arg(index.row()); //use for Debug
        break;

    case (int(Qt::UserRole + MODEL_ROLES::DISPLAY)):
        result = worksheet_data_.at(index.row()).value(DATA_ID(index.column()));
        break;

    }
    QString temp =  QString::number(index.row())+" " +  QString::number(index.column());//index.row();
    //qDebug()<< "data " + temp + " =" + result.toString();
    return result;
}

void ItemModelBase::createModel(const FileData &map){
    //LOOGGER("+");
    int size=0;
    std::map<std::string, std::string>::const_iterator it;
    it = map.begin();
    map.begin();
    while (it != map.end()){
        QStringList text = QString::fromUtf8(it->first.c_str()).split(".");
        Date_Map map;
        if (text.size() > 1){
            size = 3;
            map[DATA_ID::FEATURE] = QVariant(text.at(0));
            map[DATA_ID::FEATURE_NAME] = QVariant(text.at(1));
            map[DATA_ID::IS_ACTIVE] = QVariant(QString::fromUtf8(it->second.c_str()));
        }
        else {
            size = 2;
            map[DATA_ID::FEATURE] = QVariant(text.at(0));
            map[DATA_ID::FEATURE_NAME] = QVariant(QString::fromUtf8(it->second.c_str()));
            column_count_ = 2 ;
            // map[DATA_ID::IS_ACTIVE] = QVariant(QString(""));
        }
        worksheet_data_.append(map);
        ++it;
    }
}


void ItemModelBase::removeRow(const int row) {
    worksheet_data_.remove(row);
}


void ItemModelBase::addRow(const int row){
    Date_Map map;
    map[DATA_ID::FEATURE] = QVariant("");
    map[DATA_ID::FEATURE_NAME]= QVariant("");
    map[DATA_ID::IS_ACTIVE] = "0";
    worksheet_data_.insert(row + 1,map);
}


void ItemModelBase::copyRow(const int row){
    Date_Map map = worksheet_data_.at(row);
    worksheet_data_.insert(row + 1, map);
}


bool ItemModelBase::setData(const QModelIndex &index, const QVariant &value, int role) {
    bool result = false;
    // qDebug()<< "setData"+value.toString();
    if (index.isValid() && role==Qt::EditRole) {
        switch (role){
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
            result = true;
            break;
        }
        QString temp =  QString::number(index.row())+" " +  QString::number(index.column());
        //qDebug()<< "setdata " + temp + " =" + value.toString();
    }
    return result;
}

ItemModelBase::~ItemModelBase() {
    //  qDebug()<< "~ItemModelBase()";
}

void ItemModelBase::cleanModelData(){
    //LOOGGER("+");
    worksheet_data_.clear();
}

QVector<Date_Map> *ItemModelBase::getData(){
    return &worksheet_data_;
}
