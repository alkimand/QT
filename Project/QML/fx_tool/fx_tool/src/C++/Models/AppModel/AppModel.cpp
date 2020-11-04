#include "AppModel.h"
#include "Item.h"

#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QDesktopServices>
#include <QTextStream>
#include <QStringList>
#include <QDir>
#include <QDirIterator>
#include <QRegExp>

#include <QThread>

#include <QSharedPointer>

#include <QFuture>
#include <QtConcurrent>

static const char className[] = "AppModel::";

AppModel::AppModel(QObject *parent):QAbstractTableModel(parent){
    //Q_UNUSED(parent);
    //parentModel_ = this;
    // modelType_ = modelType
    //setupWidgetModel();

    QString path = QDir::currentPath();
    QString fileName = "test.txt";
    QString fullFilePath = path  + "/" + fileName;
    Init();
    //SetupModel();

}

//void AppModel::setDirectory(QString directory) {
//    directory_ = directory;
//}

void AppModel::parseItem(pItem item){
    //LOOGGER("+");
    //qDebug() << QThread::currentThreadId();
    Props item_status;
    if (item.get()->isPropertyExist(ItemEnums::EItemProperty::kStatus)){
        item_status = item.get()->getProperty(ItemEnums::EItemProperty::kStatus);
        if (item_status == Props(ItemEnums::eItemStatus::kParsed)) {
            item.get()->cleanModel();
        }

        if (item_status != Props(ItemEnums::eItemStatus::kInit)){
            item.get()->setProperty(ItemEnums::EItemProperty::kStatus, Props(ItemEnums::eItemStatus::kParseError));
            int id = item.get()->getProperty(ItemEnums::EItemProperty::kId).toInt();
            item.get()->parse();
            if (item.get()->getProperty(ItemEnums::EItemProperty::kStatus) != Props(ItemEnums::eItemStatus::kParseError)){
                item.get()->setProperty(ItemEnums::EItemProperty::kStatus, Props(ItemEnums::eItemStatus::kParsed));
                //emit itemParsed(id);
            }
        }
    }
}

pItem AppModel::getItemByID(const QString id){
    pItem item_ = nullptr;
    foreach (pItem item, app_data_){
        if (item.get()->getProperty(ItemEnums::EItemProperty::kId) == id){
            item_ = item;
            break;
        }
    }
    return item_;
}

int AppModel::haveSameModelByProperty(const ItemEnums::EItemProperty property_type,const Props property) {
    int id = -1;
    for (auto item: app_data_){
        Props item_property =  item.get()->getProperty(property_type);
        if (item_property == property) {
            id = (item.get()->getProperty(ItemEnums::EItemProperty::kId)).toInt();
            break;
        }
    }
    return id;
}

void AppModel::createItem(const QString &path){
    // LOOGGER("+");
    // auto future = QtConcurrent::run([=]() {
    model_counter_++;
    Item *item = new Item(this);
    pItem ptem = pItem(item, &QObject::deleteLater);
    ptem.get()->setupDefault(default_property_map_);
    ptem.get()->setFile(path);
    ptem.get()->setProperty(ItemEnums::EItemProperty::kId, QString::number(model_counter_));
    QString icon = getPropperIcon(path);
    ptem.get()->setProperty(ItemEnums::EItemProperty::kIcon, icon);
    // parseItem(ptem);//--
    int row = app_data_.size();
    beginInsertRows(QModelIndex(), row, row);
    app_data_.push_back(ptem);
    endInsertRows();
    // });
}

int AppModel::getLastCreatedItemId(){
    return model_counter_;
}

void AppModel::saveFile(const QString file_path, const QString id) {
    Props item_status;
    pItem item = getItemByID(id);
    item.get()->saveFile(file_path);
}

void AppModel::deleteFile(const QString id){
    if (id != "-1"){
        pItem  item = getItemByID(id);
        item.get()->deleteFile();
        int index = app_data_.indexOf(item);
        beginRemoveRows(QModelIndex(), index, index);
        app_data_.remove(index);
        endRemoveRows();
    }
}

QString AppModel::getPropperIcon(const QString file_name) {
    QString icon = DEFAULT_ICON;
    if(file_name.contains(FREEYTVDOWNLOADER))
        icon = FREEYTVDOWNLOADER_ICON;
    else if(file_name.contains(FREETIKTOKDOWNLOADER))
        icon = FREETIKTOKDOWNLOADER_ICON;
    else if(file_name.contains(FREEYOUTUBETOMP3CONVERTER))
        icon = FREEYOUTUBETOMP3CONVERTER_ICON;
    else if(file_name.contains(SPECIAL))
        icon = SPECIAL_ICON;
    return icon;
}

int AppModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return app_data_.size();
}

int AppModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return APP_MAIN_MODEL_COUNT;
}

QHash<int, QByteArray> AppModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole + MODEL_ROLES::TITLE, TITLE_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ID, ID_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ICON_PATH, ICON_S);
    roles.insert(Qt::EditRole, EDITE_S);
    // return { {Qt::DisplayRole, "display"} };
    //roles.insert(Qt::DisplayRole, "display");
    roles.insert(Qt::DisplayRole, DISPLAY_S);
    //roles.insert(Qt::UserRole + DATA_ID::DISPLAY, DISPLAY_S);
    return roles;
}

Qt::ItemFlags AppModel::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if(index.isValid()){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

QVariant AppModel::headerData(int section, Qt::Orientation orientation, int role) const {
    Q_UNUSED(orientation);
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    switch (section) {
    case int(DATA_ID::FEATURE):
        return tr(FEATURE_S);
        break;
    case int(DATA_ID::FEATURE_NAME):
        return tr(NAME_S);
        break;
    case int(DATA_ID::IS_ACTIVE):
        return tr(IS_ACTIVE_S);
        break;
    }
    return QVariant();
}


QVariant AppModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();
    QVariant result;
    switch (role) {
    case (int(Qt::DisplayRole)):
        result =  "";//app_data_.at(index.row()).value(DATA_ID(index.column()));
        //QString("%1, %2").arg(index.column()).arg(index.row());
        break;
    case (int(Qt::UserRole + MODEL_ROLES::TITLE)):
        if (app_data_.at(index.row()).get()->isPropertyExist(ItemEnums::EItemProperty::kFileName))
            result = app_data_.at(index.row()).get()->getProperty(ItemEnums::EItemProperty::kFileName);
        break;
    case (int(Qt::UserRole + MODEL_ROLES::ID)):
        if (app_data_.at(index.row()).get()->isPropertyExist(ItemEnums::EItemProperty::kId))
            result = app_data_.at(index.row()).get()->getProperty(ItemEnums::EItemProperty::kId);
        break;
    case (int(Qt::UserRole + MODEL_ROLES::ICON_PATH)):
        if (app_data_.at(index.row()).get()->isPropertyExist(ItemEnums::EItemProperty::kIcon))
            result = app_data_.at(index.row()).get()->getProperty(ItemEnums::EItemProperty::kIcon);
        break;
    }
    QString temp =  QString::number(index.row())+" " +  QString::number(index.column());//index.row();
    //qDebug()<< "data " + temp + " = " + result.toString();
    return result;
}

bool AppModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    bool result = false;
    // qDebug()<< "setData"+value.toString();
    if (index.isValid() && (role==Qt::EditRole
                            || role==(Qt::UserRole + MODEL_ROLES::TITLE))) {

        app_data_.at(index.row()).get()->setProperty(ItemEnums::EItemProperty::kFileName, value.toString());
        result = true;
        //QString temp =  QString::number(index.row())+" " +  QString::number(index.column());
        //qDebug()<< "setdata " + temp + " =" + value.toString();
    }
    return result;
}

void AppModel::Init(){
    QString status =INT2QS(int(ItemEnums::eItemStatus::kInit));
    QString id =INT2QS(0);
    default_property_map_.insert(ItemEnums::EItemProperty::kId, id );
    default_property_map_.insert(ItemEnums::EItemProperty::kStatus, status);
    default_property_map_.insert(ItemEnums::EItemProperty::kFilePath,"");
    default_property_map_.insert(ItemEnums::EItemProperty::kFileName,"");
    default_property_map_.insert(ItemEnums::EItemProperty::kIcon, DEFAULT_ICON);
    default_property_map_.insert(ItemEnums::EItemProperty::kDateLastSaved,"");
    default_property_map_.insert(ItemEnums::EItemProperty::kFormat,"fx");
}

void AppModel::parseFolder(const QString file_path){
    for (const QString &filePath : FindFilies(file_path)) {
        //LOOGGER("parse one file - "+ filePath);
        this->createItem(QDir::toNativeSeparators(filePath));
    }
}

QStringList AppModel::FindFilies(const QString file_path) {
    QStringList files;
    QString path = file_path;
    if (file_path.isEmpty())
        path = QDir::currentPath();
    QStringList filters;
    filters << FX_EXTENSION;
    QDirIterator it(path, filters, QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);
    while (it.hasNext())
        files << it.next();
    files.sort();

    return files;


    // QString directory;

    //directory = QFileDialog::getExistingDirectory(0, tr("Find Files"), QDir::currentPath());
    //   QDir::toNativeSeparators(QFileDialog::getExistingDirectory(parent, tr("Find Files"), QDir::currentPath()));

    //    QString filters("Excel files (*.xlsx , *.xls);;Text files (*.txt);;All files (*.*)");
    //    //QString defaultFilter("Fx files (*.fx)");
    //    QString defaultFilter("All files (*.*)");
    //    QString defaultPath = path_;
    //    //QString fullFilePath = QFileDialog::getSaveFileName(0, "Save file", defaultPath, filters, &defaultFilter);
    //    //directory = QFileDialog::getExistingDirectory(0, tr("Find Files"), QDir::currentPath());
    //    if (directory.isEmpty())
    //        directory = QDir::currentPath();

    //    QStringList filter;
    //filter<<"*.fx";
    //QDirIterator it(directory, filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    //QStringList files;
}





AppModel::~AppModel() {
    //qDebug()<< "~ItemModel()";
}
