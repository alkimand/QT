#include "texteditworker.h"
#include "creator.h"
#include <QTextEdit>
#include <QFile>
#include <QByteArray>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
//QT + MSword
//http://www.cyberforum.ru/qt/thread1566350.html

TextEditWorker::TextEditWorker(Creator *parent, QWidget *widget):Worker(parent)
{
    workingwidget = static_cast <QTextEdit*> (widget);
}

void TextEditWorker::setworkingdirectory(const QString & directory)
{
    this->workingdirectory = directory;
}

int TextEditWorker::getNum()
{
    return workingwidget->toPlainText().length();
}

void TextEditWorker::setDate(const QDate &date)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForTr(codec);
    // QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QString  StringSelectDate = date.toString("dd.MM.yyyy");

    QString fullPath = workingdirectory + "/" + StringSelectDate + ".txt";
    //qDebug()<<"fullPath - " << fullPath;
    //qDebug()<<"workingdirectory - " << workingdirectory;
    QDir dir;
    QFile file (fullPath);
    if (file.exists())
    {
        QString text;
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream out(&file);
            out.setCodec("UTF-8");          // Установка кодека
            text = out.readAll();       // Считываем весь файл в QString
        }
        file.close();
        workingwidget->setText(text);
        emit  TextEditWorkerLoadFile();
        emit  setLCDNumber(workingwidget->toPlainText().length());
    }
    else
    {
        workingwidget->clear();
        emit  setLCDNumber(0);
    }
}

void TextEditWorker::clearSlot()
{
    workingwidget->clear();
}

void TextEditWorker::setWorkingDirectorySlot(const QString & directory)
{
    //qDebug()<<"setWorkingDirectorySlot - " << directory ;
    this->workingdirectory = directory;
}

void TextEditWorker::createNewFile(const QDate & date)
{
    //qDebug()<<" TextEditWorker createNewFile(const QDate & date) - " << date;
    QString  StringSelectDate = date.toString("dd.MM.yyyy");
    QDir dir;
    QString fullPath = workingdirectory + "/" + StringSelectDate + ".txt";
    QFile file (fullPath);
    if (file.exists())
    {
        // qDebug()<< "  File already exists - " << fullPath; //if Error
    }
    else
    {
        //dir.mkpath(fullPath);
        file.open(QIODevice::ReadWrite);
        //qDebug()<< "File not  exists - " << fullPath;
        file.close();
        emit createNewFileSignal(date);
    }
}

void TextEditWorker::deleteFile(const QDate & date)
{
    QString  StringSelectDate = date.toString("dd.MM.yyyy");
    QDir dir;
    QString fullPath = workingdirectory + "/" + StringSelectDate + ".txt";
    QFile file (fullPath);
    if (file.exists())
    {
        file.remove();
        //qDebug()<< "  file.remove() - " << fullPath;
        emit createNewFileSignal(date);
    }
    else
    {
    }
}

void TextEditWorker::SaveFile(const QDate &date)
{
    QString  StringSelectDate = date.toString("dd.MM.yyyy");
    QDir dir;
    QString fullPath = workingdirectory + "/" + StringSelectDate + ".txt";
    QFile file (fullPath);
    if (file.exists())
    {

        file.open(QIODevice::WriteOnly | QIODevice::Truncate |  QIODevice::ReadWrite);
        QTextStream out(&file);
        out << this->workingwidget->toPlainText();
        file.close();
        emit  setLCDNumber(workingwidget->toPlainText().length());
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Вначале нужно создать файл кнопкой NEW");
        msgBox.exec();
    }

}


