#ifndef TEXTEDITWORKER_H
#define TEXTEDITWORKER_H

#include <QWidget>
#include "worker.h"

class QTextEdit;
class Creator;

class TextEditWorker: public Worker
{
    Q_OBJECT
public:

    explicit TextEditWorker(Creator *parent, QWidget* widget);
    void setworkingdirectory(const QString &);//--
    int getNum();//--

signals:
    void TextEditWorkerLoadFile();
    void createNewFileSignal(const QDate&);
    void setLCDNumber(const int&);
private:
    QTextEdit * workingwidget;
    QString workingdirectory;

private slots:
    void setDate(const QDate&);
    void clearSlot();
    void setWorkingDirectorySlot(const QString &);
    void createNewFile(const QDate &);
    void deleteFile(const QDate &);
    void SaveFile(const QDate &);


};

#endif // TEXTEDITWORKER_H
