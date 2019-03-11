#define FILEEXTENSION ".txt"

#define COLOROFMAINDAYES "Qt::blue"
//main file add
#include "creator.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

//delegat add
#include "calendarworker.h"
#include "dialworker.h"
#include "listwidgetworker.h"
#include "texteditworker.h"
#include "pathlineeditworker.h"

//class add
#include <QCalendarWidget>
#include <QDebug>
#include <QDial>
#include <QMap>
#include <QDir> //Setting
#include <QDateTime>
#include <QFileInfo>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QFileDialog>
#include <QMessageBox>

Creator::Creator(MainWindow *parent)
{
    parentMainWindow = parent;
    MyDialWorker = new DialWorker (this,  parentMainWindow->ui->dial);
    MyCalendarWorker = new CalendarWorker (this,  parentMainWindow->ui->calendarWidget);
    connect (this, SIGNAL (setDate(const QDate&)), MyCalendarWorker, SLOT (setDate(const QDate&)));
    connect (this, SIGNAL (setupDateList(const QMap <QString,QString>&)), MyCalendarWorker, SLOT (setupDateList(const QMap <QString,QString>&)) );
    //connect (this, SIGNAL (CpathChanges(const QString &)), MyCalendarWorker, SLOT (setWorkingDirectorySlot(const QString &)));

    MyListWidgetWorker = new ListWidgetWorker (this,  parentMainWindow->ui->listWidget);
    connect (this, SIGNAL(setupDateList(const QMap <QString,QString>&)), MyListWidgetWorker, SLOT(setupDateList(const QMap <QString,QString>&)));
    connect (this, SIGNAL (setDate(const QDate&)), MyListWidgetWorker, SLOT (setDate(const QDate&)));
    connect (this, SIGNAL (CpathChanges(const QString &)), MyListWidgetWorker, SLOT (setWorkingDirectorySlot(const QString &)));

    MyTextEditWorker = new TextEditWorker (this,  parentMainWindow->ui->textEdit);
    connect (this, SIGNAL (CpathChanges(const QString &)), MyTextEditWorker, SLOT (setWorkingDirectorySlot(const QString &)));
    //MyTextEditWorker->setworkingdirectory( "C:/Users/stimofey/Desktop/New folder/");//костыль
    connect (this, SIGNAL (clearwidgetSignal()), MyTextEditWorker, SLOT (clearSlot()));
    connect (this, SIGNAL (setDate(const QDate&)), MyTextEditWorker, SLOT (setDate(const QDate&)));
    connect (this->MyTextEditWorker, SIGNAL(TextEditWorkerLoadFile()), this, SLOT(CTextEditWorkerLoadFile()));
    connect (this->MyTextEditWorker, SIGNAL(setLCDNumber(const int&)), this, SLOT(setLCDNumber(const int&)));

    //connect (this->MyTextEditWorker, SIGNAL(TextEditWorkerLoadFile()), this, SLOT(setLCDNumber()));
    connect (this->MyTextEditWorker, SIGNAL(createNewFileSignal(const QDate&)), this, SLOT(pathChangesSlot(const QDate&)));
    connect (this, SIGNAL(CDelpushButtonCliked(const QDate &)), this->MyTextEditWorker, SLOT(deleteFile(const QDate &)));
    connect (this, SIGNAL(CSaveFile(const QDate &)),this->MyTextEditWorker, SLOT (SaveFile(const QDate &)));

    //setLCDNumber


    //не верно (
    connect (this, SIGNAL (CNewpushButtonCliked(const QDate &)), MyTextEditWorker, SLOT (createNewFile(const QDate &)));

    MyPathLineEditWorker = new PathLineEditWorker (this,  parentMainWindow->ui->folderlineEdit);

    this->setupSetting();
    this->setupWorkingDAate(QDate::currentDate());
    this->setupDataFiles();

}

void Creator::Setup(QString filenames, QDate endDate)
{
    QDate nowDate =QDate::currentDate();
    parentMainWindow->ui->calendarWidget->setSelectedDate(nowDate);

}

QString Creator::getFileName(const QString & filename)
{
    QStringList list;
    list = filename.split(FILEEXTENSION);
    QString resilt = list.at(0);
    //    for (int i=0; i<list.size()-1; i++)
    //    {
    //        resilt.append(list.at(i));
    //    }
    return resilt;
}



void Creator::CNewpushButtonCliked(bool)
{
    QString str;
    QDate date = this->MyCalendarWorker->getSelectedDate();
    QString strdate=date.toString("dd.MM.yyyy");
    //QDate dateFromlist;
    QMapIterator<QString, QString> it(foldermap);
    bool existFileOnDate = false;
    while (it.hasNext())
    {
        it.next();
        str = it.key();
        str = Creator::getFileName(str);
        if (strdate == str)
        {
            existFileOnDate = true;
            break;
        }
    }
    if (existFileOnDate)
    {
        QMessageBox msgBox;
        msgBox.setText("Выберете другую дату");
        msgBox.exec();
    }
    else
    {
        emit  CNewpushButtonCliked(this->MyCalendarWorker->getSelectedDate());
        //qDebug() <<" + NEW datw - CNewpushButtonCliked(bool)";
        //emit clearwidgetSignal();
    }
}

void Creator::CDellpushButtonCliked(bool)
{
    emit CDelpushButtonCliked(this->MyCalendarWorker->getSelectedDate());
}

void Creator::CSavepushButtonCliked(bool)
{
    emit CSaveFile(this->MyCalendarWorker->getSelectedDate());
}

void Creator::CSelectDate(const QDate & date)
{
    // qDebug() << "CSelectDate(const QDate & date)";
    QString str;
    QString strdate=date.toString("dd.MM.yyyy");
    //QDate dateFromlist;
    QMapIterator<QString, QString> it(foldermap);
    bool existFileOnDate = false;
    while (it.hasNext())
    {
        it.next();
        str = it.key();
        str = Creator::getFileName(str);
        if (strdate == str)
        {
            existFileOnDate = true;
            break;
        }

    }
    if (existFileOnDate)
    {
        emit setDate(date);
        //qDebug ()<<"emit setDate(date)";
    }
    else
    {
        //emit clearwidgetSignal();
        emit setDate(date);
    }
}

void Creator::pathChangesSlot(const QString &path)
{

    //QString path =this->MyPathLineEditWorker->getPath();
    this->setupDataFiles();
    emit CpathChanges(path);
}

void Creator::pathChangesSlot(const QDate& date)
{
    QString path =this->MyPathLineEditWorker->getPath();
    this->setupDataFiles();
    emit CpathChanges(path);
    //qDebug ()<<"emit selectDate(date)"<< date;
    emit selectDate(date);//не помогло
}


void Creator::CTextEditWorkerLoadFile()
{

}

void Creator::debugSlot()
{
    qDebug() << "This is the debugSlot()";
}

void Creator::setLCDNumber(const int& numberLCD)
{
    this-> parentMainWindow->ui->lcdNumber->display(QString::number(numberLCD));
}

void Creator::debugSlot2()
{

}

void Creator::setupSetting()
{
    //    //create file Seting or open it
    QString path = QDir::currentPath();
    QString FolderPath = "/test/response/";
    QString FilePath = "Setting.txt";
    //    QDir dir;
    //    QFile file (path +FolderPath + FilePath);
    //    //qDebug()<<file.fileName();
    //    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate |  QIODevice::ReadWrite))
    //    {
    //        //file.open(QIODevice::Truncate);
    //        file.close();
    //    }
    //    else if (!dir.exists(path + FolderPath))
    //    {
    //        //qDebug()<<"dir.exists";
    //        dir.mkpath(path + FolderPath);
    //        //qDebug()<<" directory "<< path +" <<" now exists";
    //        if ( file.open(QIODevice::ReadWrite) )
    //        {
    //            //qDebug()<<"file now exists";
    //        }
    //    }
    //    file.open(QIODevice::WriteOnly);

    QMultiMap <QString, QString> ::iterator it;
    QString fullPath = path +FolderPath + FilePath;
    OpenSetting(fullPath);

    it = SettingMap.find("folderlineEdit");
    this->MyPathLineEditWorker->setPath(it.value());

    it = SettingMap.find("progressBarStartDate");
    this->parentMainWindow->ui->progressBar->setMinimum(0);
    QDate startDate = QDate::fromString(it.value(),"dd.MM.yyyy");

    it = SettingMap.find("progressBarEndDate");
    QDate endDate = QDate::fromString(it.value(),"dd.MM.yyyy");
    this->parentMainWindow->ui->progressBar->setMaximum(startDate.daysTo(endDate));
    this->parentMainWindow->ui->progressBar->setValue(startDate.daysTo(QDate::currentDate()));
    this->parentMainWindow->ui->progressBar->setFormat("Осталось дней "+QString::number(QDate::currentDate().daysTo(endDate)));
    //this->MyPathLineEditWorker->setPath(it.value());


}

void Creator::setupDataFiles()
{
    foldermap.clear();
    //QDir currentFolder(this->MyPathLineEditWorker->getPath());
    QString path = this->MyPathLineEditWorker->getPath();
    QDir currentFolder(path);
    // currentFolder.setFilter(QDir::Dirs | QDir::Files);
    currentFolder.setFilter(QDir::Files);
    currentFolder.setSorting(QDir::Name);
    QFileInfoList folderitems(currentFolder.entryInfoList());

    foreach (QFileInfo i_file, folderitems)
    {
        QString i_filename(i_file.fileName());
        if (i_filename == "." || i_filename == ".." || i_filename.isEmpty())
            continue;

        // if (i_file.isDir()) //обработка папок - на будущее
        //    qDebug ()<< i_file.fileName();
        // searching(path + "/" + i_filename);
        //else //
        {

            foldermap.insert(i_file.fileName(), i_file.filePath());
            // qDebug ()<< i_file.fileName();
            //QString full_filename = path + "/" + i_filename;

            //недопилил еще
            //TagLib::FileRef ref([B]full_filename.toStdWString().c_str()[/B]); // только с таким преобразованием не игнорируются папки с нелатинскими буквами
            //                if (!ref.isNull() && ref.tag() != NULL)
            //                {
            //                }
        }
    }
    //to anather widget
    // qDebug ()<<"emit setupDateList(this->foldermap)";
    emit setupDateList(this->foldermap);
}


void Creator::OpenSetting(QString &filename)
{

    //QMultiMap <QString, QString> Param;
    //int MainViewWidth;
    //double value;
    QFile file (filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString str;

        while (!stream.atEnd())
        {
            str = stream.readLine().simplified();
            //   bool yt=str.contains("//",Qt::CaseInsensitive);
            if (str.isEmpty() || str.contains("//",Qt::CaseInsensitive)){}
            else {
                QStringList list=str.split('-');
                int i=0;
                QString str1=list[i].simplified();
                QString str2=list[i+1].simplified();

                if (str1.contains("folderlineEdit",Qt::CaseInsensitive))
                {
                    SettingMap.insert(str1,str2);
                    emit CpathChanges(str2 + "/");
                }
                else if (str1.contains("progressBarStartDate",Qt::CaseInsensitive))
                {
                    SettingMap.insert(str1,str2);
                }
                else if (str1.contains("progressBarEndDate",Qt::CaseInsensitive))
                {
                    SettingMap.insert(str1,str2);
                }

            }
            if(stream.status()!= QTextStream::Ok)
            {
                //qDebug() << "No file";
            }
            file.close();
        }
    }
    //file.close();
    else {
        //дописать вставку файла с нулевыми значениями
        //file.close();
    }
    //return Param;
    file.close();
}

void Creator::setupWorkingDAate(const QDate & date)
{

}
