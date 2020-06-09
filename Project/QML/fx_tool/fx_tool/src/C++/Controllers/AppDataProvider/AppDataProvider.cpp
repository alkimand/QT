#include "AppDataProvider.h"
#include <QDebug>
#include <QWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDirIterator>
#include <QDir>

#include "AbstractItem.h"
#include "ItemModelBase.h"

#include <QExplicitlySharedDataPointer>

#include <QSharedPointer>

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
    FindFilies();
}





void AppDataProvider::createItem(const QString path) {
    //();
    // Item
    // ItemModel *temp = new ItemModel();

    //QExplicitlySharedDataPointer<ItemModel> base(new ItemModel);

     QSharedPointer<ItemModel> obj =
       QSharedPointer<ItemModel>(new ItemModel);
    //AbstractItem
    //ItemModel
    //Item item = Item(new ItemModel, &QObject::deleteLater);
    //item.get()->PreapreItem(path);
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


void AppDataProvider::FindFilies(const QString path_) {


    QString directory;


    //directory = QFileDialog::getExistingDirectory(0, tr("Find Files"), QDir::currentPath());
    //   QDir::toNativeSeparators(QFileDialog::getExistingDirectory(parent, tr("Find Files"), QDir::currentPath()));

    QString filters("Excel files (*.xlsx , *.xls);;Text files (*.txt);;All files (*.*)");
    //QString defaultFilter("Fx files (*.fx)");
    QString defaultFilter("All files (*.*)");
    QString defaultPath = path_;
    //QString fullFilePath = QFileDialog::getSaveFileName(0, "Save file", defaultPath, filters, &defaultFilter);
    //directory = QFileDialog::getExistingDirectory(0, tr("Find Files"), QDir::currentPath());
    if (directory.isEmpty())
        directory = QDir::currentPath();

    QStringList filter;
    filter<<"*.fx";
    QDirIterator it(directory, filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QStringList files;
    while (it.hasNext())
        files << it.next();
    files.sort();

    for (const QString &filePath : files) {
        qDebug()<<" fileName:" + filePath ;
        createItem(QDir::toNativeSeparators(filePath));
    }
}

void AppDataProvider::loadDirectory(const QString &directory){
    Q_ASSERT(QDir(directory).exists());

}

void AppDataProvider::openFile(const QString &fileName){
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    //QString fileName = fileComboBox->currentText();
}
