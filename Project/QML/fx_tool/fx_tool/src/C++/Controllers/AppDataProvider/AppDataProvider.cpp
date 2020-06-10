#include "AppDataProvider.h"
#include <QDebug>
#include <QWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDirIterator>
#include <QStringList>
#include <QDir>

#include "AbstractItemBase.h"
#include "ItemModelBase.h"

#include "ItemPropery.h"

#include <QExplicitlySharedDataPointer>

#include <QSharedPointer>

static const char className[] = "AppDataProvider::";

AppDataProvider::AppDataProvider() {
    qDebug()<< "AppDataProvider";
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_1), "test");
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_3), 1000);

    // instance();

    // if (s_instance_) {
    //   qDebug()<< "create s_instance_";
    //s_instance_ = new AppDataProvider();
    // }

    // qDebug()<< "create AppDataProvider";
    //FindFilies();
    Init();

}





void AppDataProvider::createItem(const QString &file_path) {
    static int  id_counter_ = 0;
    pItem item = pItem(new Item, &QObject::deleteLater);
    item.get()->setupDefault(default_property_map_);
    item.get()->setFile(file_path);
    //item.get()->setProperty(ItemEnums::EItemProperty::kId, QString::number(id_counter_));
    setItemProp_int(kId, id_counter_);
    parseItem(item);
    id_counter_++;
    app_data_.push_back(item);
}

void AppDataProvider::PreapreItem(const QString path){

}


void AppDataProvider::openInExplorer() {
    QStringList args;
    QDir dir;
    //        QString fullFilePath = filePath + fileName;
    //        if ( fileExists(fullFilePath))
    //        {
    //            args << "/select," << QDir::toNativeSeparators(filePath + fileName);

    //            process->start("explorer.exe", args);
    //            //QDesktopServices::openUrl(QUrl::fromLocalFile(fullFilePath));
    //            //qDebug()<<"ModelServiseBaseClass::openInExplorer:fullFilePath:" +  fullFilePath;
    //        }
    //        else
    //        {
    //            if (dir.exists(filePath))
    //            {
    //                // qDebug()<<"ModelServiseBaseClass::openInExplorer:filePath:" +  filePath;
    //                QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    //            }
    //        }
}

void AppDataProvider::Init(){
    LOOGGER("");
    default_property_map_.insert(ItemEnums::EItemProperty::kId,"0");
    default_property_map_.insert(ItemEnums::EItemProperty::kStatus, Props(ItemEnums::eItemStatus::kInit));
    default_property_map_.insert(ItemEnums::EItemProperty::kFilePath,"");
    default_property_map_.insert(ItemEnums::EItemProperty::kFileName,"");
    default_property_map_.insert(ItemEnums::EItemProperty::kIcon,"");
    default_property_map_.insert(ItemEnums::EItemProperty::kDateLastSaved,"");
    default_property_map_.insert(ItemEnums::EItemProperty::kFormat,"fx");

    for (const QString &filePaths : FindFilies()) {
        createItem(QDir::toNativeSeparators(filePaths));
    }

}

ItemEnums::eItemStatus AppDataProvider::parseItem(pItem item) {
    ItemEnums::eItemStatus status = ItemEnums::eItemStatus::kInit;
    if (GetItemProp(kStatus) != Props(ItemEnums::eItemStatus::kInit)){
        //int id = item.get()->getProperty(ItemEnums::EItemProperty::kStatus).toInt();
        int id = GetItemProp(kStatus).toInt();
        item.get()->parse();
        if (GetItemProp(kStatus) == Props(ItemEnums::eItemStatus::kParsed)){
            emit itemParsed(id);
        }
    }
    return status;
}


QStringList AppDataProvider::FindFilies(const QString file_path) {
    QStringList files;
    QString path = file_path;
    if (file_path.isEmpty())
        path = QDir::currentPath();
    QStringList filters;
    filters << FX_EXTENSION;
    QDirIterator it(path, filters, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
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

void AppDataProvider::loadDirectory(const QString &directory){
    Q_ASSERT(QDir(directory).exists());
}

void AppDataProvider::openFile() {
    //std::wstring folder_path = digi::getAppSpecificFolder(fs::EAppSpecificFolder::eConfig);
    //QString path = QFileDialog::getOpenFileName(0, tr("Open File"), WS2Q(folder_path), tr("*.fx"));
   // QString path = QFileDialog::getOpenFileName(0, tr("Open File"), fileName, tr("*.fx"));
    //QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    //QString fileName = fileComboBox->currentText();
}

