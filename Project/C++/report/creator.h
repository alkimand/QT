#ifndef CREATOR_H
#define CREATOR_H
#include <QWidget>
#include <QObject>
#include <QMap>

class MainWindow;
class DialWorker;
class ListWidgetWorker;
class TextEditWorker;
class CalendarWorker;
class PathLineEditWorker;

#include "mainwindow.h"
#include "creator.h"
#include "ui_mainwindow.h"

class Creator:public QObject
{
    Q_OBJECT
public:
    explicit Creator(MainWindow *parent);
    void Setup(QString filenames, QDate endDate);
    static QString getFileName(const QString &);

signals:
    void addNewResponse(QDate date);
    void setDate(const QDate&);
    void setupDateList(const QMap <QString,QString>&);
    void selectDate(const QDate &);
    void clearwidgetSignal();
    void CpathChanges(const QString &);
    void CNewpushButtonCliked(const QDate &);
    void CDelpushButtonCliked(const QDate &);
    void CSaveFile(const QDate &);

public slots:

private slots:
    void setLCDNumber(const int&);
    void CNewpushButtonCliked(bool);
    void CDellpushButtonCliked(bool);
    void CSavepushButtonCliked(bool);
    void CSelectDate(const QDate &);
    void pathChangesSlot(const QString &);
    void pathChangesSlot(const QDate &);
    void CTextEditWorkerLoadFile();
    void debugSlot();
    void debugSlot2();

private :
    //metods
    void setupSetting();
    void setupDataFiles();
    void OpenSetting(QString &filename);
    void setupWorkingDAate(const QDate &);
    // void setSetWorkingDirectory(const QString &);

    QDate workingDAate;
    MainWindow* parentMainWindow;
    DialWorker*  MyDialWorker;
    CalendarWorker*  MyCalendarWorker;
    ListWidgetWorker* MyListWidgetWorker;
    TextEditWorker*  MyTextEditWorker;
    PathLineEditWorker*  MyPathLineEditWorker;
    QMap <QString, QString> SettingMap;
    QMap <QString,QString> foldermap;
};

#endif // CREATOR_H
