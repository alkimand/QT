#include "modelservisebaseclass.h"

#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QProcess>
#include <QTime>
#include <QDesktopServices>

ModelServiseBaseClass::ModelServiseBaseClass(WorkerBaseClass * m_worker,  CLIENT_TYPE const  & m_type)
{
    this->worker = static_cast<WorkerBaseClass*>(m_worker);
    this->type = m_type;
    this->parent = this;
    this->defoultFileName = "DEFOULT";
    process = new QProcess(this);

    qDebug()<< "create ModelServiseBaseClass";
}

ModelServiseBaseClass::~ModelServiseBaseClass()
{
    qDebug()<< "~ModelServiseBaseClass()";
    delete process;
}

bool ModelServiseBaseClass::getSaveFileName()
{

    QString filters("Excel files (*.xlsx , *.xls);;Text files (*.txt);;All files (*.*)");
    QString defaultFilter("Text files (*.txt)");
    QString defaultPath = filePath;
    if (filePath.isEmpty())
        defaultPath = QDir::currentPath();
    QString fullFilePath = QFileDialog::getSaveFileName(0, "Save file", defaultPath, filters, &defaultFilter);
    if (!fullFilePath.isEmpty())
    {
        QStringList list = fullFilePath.split("/");
        fileName = list.last();
        defoultFileName = fileName;
        filePath = fullFilePath.left(fullFilePath.length() - fileName.length());
        return true;
    }
    else
    {
        return false;
    }
    qDebug()<<" fileName:" + fileName ;
    qDebug()<<" defoultFileName:" + defoultFileName ;
    qDebug()<<"  filePath:" +  filePath ;
}

void ModelServiseBaseClass::saveData()
{
    qDebug()<< "ModelServiseBaseClass::saveData()" ;
    //qDebug()<< fileName ;
    //    QStringList list;
    //    int size =l_data.size();
    //    list.append(QString::number(size));
    //    list.append("false");
    //    list.append(QDate::currentDate().toString("MM/dd/yy"));
    //    list.append(QTime::currentTime().toString("HH:mm:ss"));
    //    list.append("");
    //    list.append("");
    //    list.append("");
    //    list.append("Save file at");
    //    list.append("");
    //    list.append(fileName);
    //    beginInsertRows(QModelIndex(),size,size);
    //    this->l_data.append(list);
    //    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    //emit dataChanged(index, index, { role });
    //    emit dataChanged(index, index);
    //    endInsertRows();



    if ( (!defoultFileName.isEmpty()) |(!fileName.isEmpty()))
    {
        QFile file (filePath + fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate |  QIODevice::ReadWrite))
        {
            //file.open(QIODevice::Truncate);
            file.close();
        }
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        for(int i=0; i < this->l_data.size();i++)
        {
            out<< this->l_data.at(i).at(2) << " ";
            for(int j = 3; j< child->columnCount()-1; j++)
            {
                out<< this->l_data.at(i).at(j) << "/";
            }
            out<< this->l_data.at(i).at(child->columnCount()-1) << "\r\n";
        }
        file.close();
    }

    qDebug()<<"ModelServiseBaseClass::saveData():fileName:" + fileName ;
    qDebug()<<"ModelServiseBaseClass::saveData():defoultFileName:" + defoultFileName ;
    qDebug()<<"ModelServiseBaseClass::saveData():filePath:" +  filePath ;
}

void ModelServiseBaseClass::openInExplorer()
{
    QStringList args;
    QDir dir;
    QString fullFilePath = filePath + fileName;
    if ( fileExists(fullFilePath))
    {
        args << "/select," << QDir::toNativeSeparators(filePath + fileName);

        process->start("explorer.exe", args);
        //QDesktopServices::openUrl(QUrl::fromLocalFile(fullFilePath));
        //qDebug()<<"ModelServiseBaseClass::openInExplorer:fullFilePath:" +  fullFilePath;
    }
    else
    {
        if (dir.exists(filePath))
        {
            // qDebug()<<"ModelServiseBaseClass::openInExplorer:filePath:" +  filePath;
            QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
        }
    }
}

void ModelServiseBaseClass::openInDesktopServices()
{
    //qDebug()<< "ModelServiseBaseClass::openInDesktopServices()";
    QString fullFilePath = filePath + fileName;
    if (fileExists(fullFilePath))
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(fullFilePath));
    }
    else
    {
        openInExplorer();
    }
}

void ModelServiseBaseClass::setFilePath(const QString & fullFilePath)
{
    QStringList list = fullFilePath.split("/");
    fileName = list.last();
    defoultFileName = fileName;
    filePath = fullFilePath.left(fullFilePath.length() - fileName.length());

    //    qDebug()<<"ModelServiseBaseClass::setFilePath:fullFilePath:" + fullFilePath ;
    //    qDebug()<<"ModelServiseBaseClass::setFilePath:fileName:" + fileName ;
    //    qDebug()<<"ModelServiseBaseClass::setFilePath:defoultFileName:" + defoultFileName ;
    //    qDebug()<<"ModelServiseBaseClass::setFilePath:filePath:" +  filePath ;
}

void ModelServiseBaseClass::setFileName(const QString & m_fileName)
{
    fileName = m_fileName;
    defoultFileName = fileName;

    //    qDebug()<<"ModelServiseBaseClass::setFileName:fileName:" + fileName ;
    //    qDebug()<<"ModelServiseBaseClass::setFileName:defoultFileName:" + defoultFileName ;
    //    qDebug()<<"ModelServiseBaseClass::setFileName:filePath:" +  filePath ;
}


void ModelServiseBaseClass::saveAs()
{
    qDebug()<< "ModelServiseBaseClass::saveAs()";
    if (!getSaveFileName())
        return;
    saveData();
    this->worker->setNameDocument(fileName);
}

void ModelServiseBaseClass::save()
{
    //qDebug()<< "ModelServiseBaseClass::save()";

    if ( defoultFileName == "DEFOULT" | defoultFileName.isEmpty() |  (fileName!=defoultFileName))
    {
        if (!getSaveFileName())
            return;
    }
    saveData();
    this->worker->setNameDocument(fileName);
}

void ModelServiseBaseClass::clearDataPool()
{
    //qDebug()<< "ModelServiseUDP::clearDataPool()";
    beginResetModel();
    this->l_data.clear();
    endResetModel();
}

bool ModelServiseBaseClass::fileExists(QString & path)
{
    QFileInfo check_file(path);
    if (check_file.exists() && check_file.isFile())
    {
        return true;
    }
    else
    {
        return false;
    }
}
