#include "workerbaseclass.h"
#include "DateLoaderText.h"
#include <QTextStream>

#include <QtNetwork>
#include <QtGui>
#include <QFileDialog>
#include <QDebug>
//DateLoaderText::DateLoaderText(QWidget *pwgt)
//{

//}

DateLoaderText::DateLoaderText(WorkerBaseClass *m_worker, CLIENT_TYPE const & m_type): DataLoaderBaseClass(m_worker, m_type)
{
    //qDebug()<< "create DateLoaderText";

    //QString templatePath = QDir::current().canonicalPath();
    this->child = this;
    //--
    getOpenFileName();
    //--
    create_connect_to_worker();
    this->status = PLAY;
    connect(this, SIGNAL(readyRead()), SLOT(slotProcessDatagrams()));
    emit readyRead();
    qDebug()<< "create DateLoaderText-";
}

DateLoaderText::~DateLoaderText()
{
    qDebug()<< "~DateLoaderText";
}

void DateLoaderText::getOpenFileName()
{
    //qDebug()<< "DDateLoaderText::getOpenFileName()+";
    QString path = QDir::currentPath();
    QString fileName = "W_fromKeyboard — копия.txt";
    fullFilePath = path  + "/" + fileName;
    //fileName = QFileDialog::getOpenFileName(0,tr("Open text files"), templatePath, tr("Text Files (*.txt)"));//++
    this->worker->sendFilePath(fullFilePath);
    //qDebug()<< "DDateLoaderText::getOpenFileName(): "+ fullFilePath;
}

void DateLoaderText::slotProcessDatagrams()
{
    //qDebug()<< "DateLoaderText::slotProcessDatagrams()+";
    QByteArray baDatagram;
    QFile file (fullFilePath);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString str;
        //str = "O"//ToDo
        while (!stream.atEnd())
        {

            str = stream.readLine().simplified();
            if (str.isEmpty() || str.contains("//",Qt::CaseInsensitive)){}
            else
            {
                baDatagram = str.toLatin1();
                sendData(baDatagram);
                //qDebug()<< "DateLoaderText::slotProcessDatagrams(): " + str;
            }
        }
        file.close();
        if(stream.status()!= QTextStream::Ok)
        {
            qDebug() << "No file";
        }
    }
    else
    {
       qDebug() << "No file";
    }


    //qDebug()<< "DateLoaderText::slotProcessDatagrams()-";
}

