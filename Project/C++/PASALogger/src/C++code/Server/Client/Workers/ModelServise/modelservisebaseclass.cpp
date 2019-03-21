#include "modelservisebaseclass.h"

#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QProcess>
#include <QTime>

ModelServiseBaseClass::ModelServiseBaseClass(WorkerBaseClass * m_worker,  CLIENT_TYPE const  & m_type)
{
    this->worker = static_cast<WorkerBaseClass*>(m_worker);
    this->type = m_type;
    this->parent = this;
    this->defoultFileName = "DEFOULT";


    qDebug()<< "create ModelServiseBaseClass";
}

ModelServiseBaseClass::~ModelServiseBaseClass()
{
    qDebug()<< "~ModelServiseBaseClass()";
}

void ModelServiseBaseClass::getSaveFileName()
{

    QString filters("Music files (*.mp3);;Text files (*.txt);;All files (*.*)");
    QString defaultFilter("Text files (*.txt)");
    this->fileName = QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(), filters, &defaultFilter);
    this->defoultFileName = this->fileName;
        qDebug()<<" fileName:" + fileName ;
        qDebug()<<" defoultFileName:" + defoultFileName ;
}

void ModelServiseBaseClass::saveData()
{
    //qDebug()<< fileName ;
    QStringList list;
    int size =v_data.size();
    list.append(QString::number(size));
    list.append("false");
    list.append(QDate::currentDate().toString("MM/dd/yy"));
    list.append(QTime::currentTime().toString("HH:mm:ss"));
    list.append("");
    list.append("");
    list.append("");
    list.append("Save file at");
    list.append("");
    list.append(fileName);
    beginInsertRows(QModelIndex(),size,size);
    this->v_data.append(list);
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    //emit dataChanged(index, index, { role });
    emit dataChanged(index, index);
    endInsertRows();

    if ( !defoultFileName.isEmpty())
    {
        QFile file (fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate |  QIODevice::ReadWrite))
        {
            //file.open(QIODevice::Truncate);
            file.close();
        }
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        for(int i=0; i < this->v_data.size()-1;i++)
        {
            out<< this->v_data.at(i).at(2) << " ";
            for(int j = 3; j< child->columnCount()-1; j++)
            {
                out<< this->v_data.at(i).at(j) << "/";
            }
            out<< this->v_data.at(i).at(child->columnCount()-1) << "\r\n";
        }
        file.close();
    }
}

void ModelServiseBaseClass::openInExplorer()
{
    if ( !fileName.isEmpty())
    {
        QStringList args;
        args << "/select," << QDir::toNativeSeparators(fileName);
        QProcess *process = new QProcess(this);
        process->start("explorer.exe", args);
    }
}


void ModelServiseBaseClass::saveAs()
{
    qDebug()<< "ModelServiseBaseClass::saveAs()";
    getSaveFileName();
    saveData();
}

void ModelServiseBaseClass::save()
{
    qDebug()<< "ModelServiseBaseClass::save()";
    if ( defoultFileName == "DEFOULT" | defoultFileName.isEmpty())
    {
        getSaveFileName();
    }
    saveData();
}

void ModelServiseBaseClass::clearDataPool()
{
    //qDebug()<< "ModelServiseUDP::clearDataPool()";
    beginResetModel();
    this->v_data.clear();
    endResetModel();
}

