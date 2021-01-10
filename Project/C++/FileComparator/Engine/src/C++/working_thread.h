#pragma once
#include <QObject>
#include <QWidget>

#include <QString>
#include <QList>
#include <QPair>
#include <QCryptographicHash>

#include <QThread>

class WorkingThread : public QThread {
    Q_OBJECT

public:
    void setFiles(const QStringList file_list);

private:
    void run() override;
    QByteArray getCheckSum(const QString& fileName, QCryptographicHash::Algorithm hashAlgorithm);

signals:
    void threadFinished(const QList <QList<QString>>);
    void parseProgress(QPair <int, int> curent_progress);
private:
    QStringList  file_list_;
};
