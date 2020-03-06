#ifndef MODELSERVISEBASECLASS_H
#define MODELSERVISEBASECLASS_H
#include "settingmap.h"
#include "workerbaseclass.h"

#include <QObject>
#include <QAbstractTableModel>

class QProcess;
//Proxi model
//https://stackoverrun.com/ru/q/10878631
//https://doc.qt.io/qt-5/qtwidgets-itemviews-customsortfiltermodel-example.html
//https://doc.qt.io/archives/qt-4.8/qsortfilterproxyModel.html

//https://evileg.com/ru/forum/topic/785/
//class QDir;


class  ModelServiseBaseClass: public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit  ModelServiseBaseClass(WorkerBaseClass *, CLIENT_TYPE const &);


     virtual  void data_model_handler(QStringList &) = 0;
     virtual void clearDataPool();
     virtual void saveAs();
     virtual void save();
     virtual ~ModelServiseBaseClass();
     QString fileName;
     QString defoultFileName;
     QString filePath;
     bool getSaveFileName();
     void saveData();
     void openInExplorer();
     void openInDesktopServices();
     void setFilePath(const QString &);
     void setFileName(const QString &);
     bool fileExists(QString & path);

protected:
    CLIENT_TYPE type;
    QVector <QStringList> l_data; //change to list
    QProcess *process;
    WorkerBaseClass *worker;
    ModelServiseBaseClass *parent;
    ModelServiseBaseClass *child;




//    //virtual void create_connect_to_worker() = 0;
//    //QString first_line;
//   // QString last_line;
//   // QStringList str_data_list;


//signals:

//void model_sendData(QStringList & );

private:


//   // virtual  QStringList sl_parse_line(QString ) = 0;
//CLIENT_TYPE type;
};



#endif // MODELSERVISEBASECLASS_H
