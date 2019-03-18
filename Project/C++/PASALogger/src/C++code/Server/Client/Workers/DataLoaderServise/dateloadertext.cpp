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
    qDebug()<< "create DateLoaderText";
    QString templatePath = QDir::current().canonicalPath();
    this->child = this;
    //--
    QString path = QDir::currentPath();
   // QString FolderPath = "/sourse/";
    QString FilePath = "W_fromKeyboard.txt";
    fileName = path  + "/" + FilePath;
    //--

    //fileName = QFileDialog::getOpenFileName(0,tr("Open text files"), templatePath, tr("Text Files (*.txt)"));//++
    create_connect_to_worker();
    this->status = DATALOAD;
    connect(this, SIGNAL(readyRead()), SLOT(slotProcessDatagrams()));

    emit readyRead();

}

DateLoaderText::~DateLoaderText()
{
    qDebug()<< "~DateLoaderText";
}

void DateLoaderText::create_connect_to_worker()
{
    //send data to worker
    //qDebug()<< "DateLoaderText::create_connect_to_worker";
    connect(this, SIGNAL(sendData(QByteArray const &)), worker, SLOT(receive_data_loader_slot(QByteArray const &)));
}

void DateLoaderText::start()
{


}

void DateLoaderText::stop()
{

}

void DateLoaderText::slotProcessDatagrams()
{
    //qDebug()<< "DateLoaderText::slotProcessDatagrams()";
    QByteArray baDatagram;
    QFile file (fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString str;

        while (!stream.atEnd())
        {
            str = stream.readLine().simplified();
            if (str.isEmpty() || str.contains("//",Qt::CaseInsensitive)){}
            else
            {
                {
                    baDatagram = str.toLatin1();
                    sendData(baDatagram);
                }
            }
        }
        file.close();
        if(stream.status()!= QTextStream::Ok)
        {
            qDebug() << "No file";
        }
    }
}

