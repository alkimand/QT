#include <QFile>
#include <QTextCodec>
#include <QMultiMap>
#include <QByteArray>
#include <QtConcurrent>

#include <engine.h>

void Engine::compareFiles(QStringList file_list) {
    stopWorkingThread();
    workerking_thread_ = new WorkingThread();
    QObject::connect(workerking_thread_, &WorkingThread::threadFinished, this, &Engine::compareFinished);
    QObject::connect(workerking_thread_, &WorkingThread::parseProgress, this, &Engine::setProgress);
    workerking_thread_->setFiles(file_list);
    workerking_thread_->start();
}


void Engine::stopWorkingThread() {
    if (workerking_thread_ != nullptr)
        workerking_thread_->terminate();
}


