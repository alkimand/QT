#pragma once

#include <QObject>
#include <QWidget>
#include <QString>
#include <QList>
#include <QCryptographicHash>

#include <engine_global.h>
#include <engine.h>
#include <working_thread.h>

class ENGINE_EXPORT Engine : public QObject {
    Q_OBJECT

public:
    Engine(QWidget* parent = nullptr) {};
    void compareFiles(QStringList file_list);
    void stopWorkingThread();

private:
    WorkingThread *workerking_thread_ = nullptr;


signals:
    void compareFinished(QList<QList<QString>>);
    void setProgress(const QPair <int, int> curent_progress);
};
