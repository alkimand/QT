#pragma once
#include <QObject>
#include <QWidget>
#include <QString>
#include <QList>
#include <QCryptographicHash>
#include <engine_global.h>

class ENGINE_EXPORT Engine : public QObject {
    Q_OBJECT

public:
    Engine(QWidget* parent = nullptr) {};
    ~Engine();
    void setFiles(QStringList  file_list);
    void compareFiles();

private:
    QByteArray getCheckSum(const QString& fileName, QCryptographicHash::Algorithm hashAlgorithm);

private:
    QStringList  file_list_;

signals:
    void compareFinished(QList<QList<QString>>);
};
